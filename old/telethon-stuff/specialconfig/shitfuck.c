#include <stdio.h>
#include <openssl/crypto.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/pem.h>

char PUBKEY[] = "\
-----BEGIN RSA PUBLIC KEY-----\n\
MIIBCgKCAQEAyr+18Rex2ohtVy8sroGPBwXD3DOoKCSpjDqYoXgCqB7ioln4eDCF\n\
fOBUlfXUEvM/fnKCpF46VkAftlb4VuPDeQSS/ZxZYEGqHaywlroVnXHIjgqoxiAd\n\
192xRGreuXIaUKmkwlM9JID9WS2jUsTpzQ91L8MEPLJ/4zrBwZua8W5fECwCCh2c\n\
9G5IzzBm+otMS/YKwmR1olzRCyEkyAEjXWqBI9Ftv5eG8m0VkBzOG655WIYdyV0H\n\
fDK/NWcvGqa0w/nriMD6mDjKOryamw0OP9QuYgMN0C9xMW9y8SmP4h92OAWodTYg\n\
Y1hZCxdv6cs5UnW9+PWvS+WIbkh+GaWYxwIDAQAB\n\
-----END RSA PUBLIC KEY-----\
";

static const int AesKeySize = 32;
static const int AesIvecSize = 16;

int main(void) {
  RSA *rsa = PEM_read_bio_RSAPublicKey(BIO_new_mem_buf(PUBKEY, sizeof(PUBKEY)), 0, 0, 0);

  if (rsa == NULL)
    return 1;

  unsigned char data[256];
  unsigned char decrypted[256];

  for (int i=0; i<256; i++)
    data[i] = getchar();

  int res = RSA_public_decrypt(256, data, decrypted, rsa, RSA_NO_PADDING);

  if (res < 0 || res > 256)
    return 2;

//  for (int i=0; i<256; i++)
//    putchar(decrypted[i]);

  unsigned char *aesDecrypted = decrypted + AesKeySize;
  AES_KEY aeskey;
  AES_set_decrypt_key(&decrypted[0], AesKeySize * CHAR_BIT, &aeskey);
  AES_cbc_encrypt(aesDecrypted, aesDecrypted, 256-AesKeySize, &aeskey, decrypted + AesKeySize - AesIvecSize, AES_DECRYPT);

  for (int i = 0; i < 256 - AesKeySize; i++)
    putchar(aesDecrypted[i]);
  exit(0);

  const int kDigestSize = 16;
  const int kDataSize = 256 - AesKeySize - kDigestSize;
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, aesDecrypted, kDataSize);
  SHA256_Final(hash, &sha256);

  for (int i=0; i<kDigestSize; i++) {
    if (aesDecrypted[kDataSize + i] != hash[i]) {
      fprintf(stderr, "DIGEST MISMATCH ON %d\n", i);
      return 4;
    }
  }

  fprintf(stderr, "Digest check pass\n");

  uint32_t len = *(uint32_t*) aesDecrypted;
  fprintf(stderr, "len = %d\n", len);
  if (!len || len >= kDataSize || len & 3) {
    fprintf(stderr, "Weird fucked up len check failed\n");
    return 5;
  }

  for (int i = sizeof(uint32_t); i<len; i++) {
    putchar(aesDecrypted[i]);
  }

  return 0;
}
