#if 0
kEntitlementSeatbeltProfiles -- "seatbelt-profiles"
kEntitlementSigningIdentifier -- "com.apple.private.signing-identifier"
kEntitlementPlatformApplication -- "platform-application"
kEntitlementInternalInstaller -- "com.apple.rootless.internal-installer-equivalent"
#endif

// copy entitlements from ucred
// => get amfi's perpolicy && retain it
OSDictionary *copyEntitlements(ucred *u);

// set a1 to userspace amfid daemon port
// return 0 on success
int getDaemonPort(mach_port_t *a1);

class  AppleMobileFileIntegrity {
	// retain entitlement for key and return it if exists
	// safe to call if there are no entitlements at all on this ucred
	OSObject* copyEntitlement(ucred* u, const char *key);

	// copyEntitlement(u, kEntitlementSigningIdentifier->getCStringNoCopy())
	OSString* copySigningIdentifier(ucred *u);
};
