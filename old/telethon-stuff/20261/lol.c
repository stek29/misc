#include <stdio.h>
#include <inttypes.h>

int main(void) {
  int32_t val = 0;
  uint32_t valu = 0;

  scanf(" %" SCNd32, &val);

  valu = *(uint32_t*) &val;

  valu>>=32;

  val = *(int32_t*) &valu;

  printf("%" PRId32 " 0x%" PRIX32 "\n", val, val);


  int64_t l = 0xfFFffFFff;
  int32_t i = (int32_t) l;

  printf("%" PRId64 " %" PRId32 "\n", l, i);

  return 0;
}
