#include "OSContainersVT.h"

DECL_CLASS(IORegistryEntry);
DECL_CLASS(IOService);

typedef OSObject IOWorkLoop;  // sigh
typedef unsigned long IOPMPowerFlags;

typedef OSObject IORegistryPlane;
typedef uint32_t IOOptionBits;
typedef kern_return_t IOReturn;

typedef IOReturn (*IOService_Action)(OSObject *target,
                                     void *arg0, void *arg1,
                                     void *arg2, void *arg3);

typedef void (*IORegistryEntryApplierFunction)(IORegistryEntry *entry,
                                               void *context);

typedef IOReturn (*IOServiceInterestHandler)(void *target, void *refCon,
                                             uint32_t messageType, IOService *provider,
                                             void *messageArgument, vm_size_t argSize);

typedef void (*IOServiceApplierFunction)(IOService *service, void *context);
typedef void (*OSObjectApplierFunction)(OSObject *object, void *context);

struct VTB_IORegistryEntry {
#define CURRENT_CLASS_NAME IORegistryEntry
#define DVT_IORegistryEntry                                                                                      \
    DVT_OSObject                                                                                                 \
    DEF_FUNC(OSObject *, copyProperty_cstring_plane_, const char *, const IORegistryPlane *, IOOptionBits);      \
    DEF_FUNC(OSObject *, copyProperty_string_plane_, const OSString *, const IORegistryPlane *, IOOptionBits);   \
    DEF_FUNC(OSObject *, copyProperty_symbol_plane_, const OSSymbol *, const IORegistryPlane *, IOOptionBits);   \
    DEF_FUNC(IORegistryEntry *, copyParentEntry_, const IORegistryPlane *);                                      \
    DEF_FUNC(IORegistryEntry *, copyChildEntry_, const IORegistryPlane *);                                       \
    DEF_FUNC(IOReturn, runPropertyAction______, IOService_Action *, OSObject *, void *, void *, void *, void *); \
    DEF_FUNC(bool, init_withDictionary, OSDictionary *);                                                         \
    DEF_FUNC(void, setPropertyTable_, OSDictionary *);                                                           \
    DEF_FUNC(bool, setProperty_symbol_, const OSSymbol *, OSObject *);                                           \
    DEF_FUNC(bool, setProperty_string_, const OSString *, OSObject *);                                           \
    DEF_FUNC(bool, setProperty_cstring_, const char *, OSObject *);                                              \
    DEF_FUNC(bool, setProperty_cstring_cstring, const char *, const char *);                                     \
    DEF_FUNC(bool, setProperty_cstring_bool, const char *, bool);                                                \
    DEF_FUNC(bool, setProperty_cstring_val_bits, const char *, unsigned long long, unsigned int);                \
    DEF_FUNC(bool, setProperty_cstring_bytes_, const char *, void *, unsigned int);                              \
    DEF_FUNC(OSObject *, getProperty_symbol, const OSSymbol *);                                                  \
    DEF_FUNC(OSObject *, getProperty_string, const OSString *);                                                  \
    DEF_FUNC(OSObject *, getProperty_cstring, const char *);                                                     \
    DEF_FUNC(OSObject *, getProperty_symbol__, const OSSymbol *, const IORegistryPlane *, IOOptionBits);         \
    DEF_FUNC(OSObject *, getProperty_string__, const OSString *, const IORegistryPlane *, IOOptionBits);         \
    DEF_FUNC(OSObject *, getProperty_cstring__, const char *, const IORegistryPlane *, IOOptionBits);            \
    DEF_FUNC(void, removeProperty_symbol, const OSSymbol *);                                                     \
    DEF_FUNC(void, removeProperty_string, const OSString *);                                                     \
    DEF_FUNC(void, removeProperty_cstring, const char *);                                                        \
    DEF_FUNC(OSObject *, copyProperty_symbol, const OSSymbol *);                                                 \
    DEF_FUNC(OSObject *, copyProperty_string, const OSString *);                                                 \
    DEF_FUNC(OSObject *, copyProperty_cstring, const char *);                                                    \
    DEF_FUNC(OSDictionary *, dictionaryWithProperties);                                                          \
    DEF_FUNC(bool, serializeProperties_, OSSerialize *);                                                         \
    DEF_FUNC(IOReturn, setProperties_object, OSObject *);                                                        \
    DEF_FUNC(OSIterator *, getParentIterator_, IORegistryPlane *);                                               \
    DEF_FUNC(void, applyToParents___, IORegistryEntryApplierFunction *, void *, IORegistryPlane *);              \
    DEF_FUNC(IORegistryEntry *, getParentEntry_, const IORegistryPlane *);                                       \
    DEF_FUNC(OSIterator *, getChildIterator_, IORegistryPlane *);                                                \
    DEF_FUNC(void, applyToChildren___, IORegistryEntryApplierFunction *, void *, IORegistryPlane *);             \
    DEF_FUNC(IORegistryEntry *, getChildEntry_, const IORegistryPlane *);                                        \
    DEF_FUNC(bool, isChild___, IORegistryEntry *, IORegistryPlane const *, bool);                                \
    DEF_FUNC(bool, isParent___, IORegistryEntry *, IORegistryPlane const *, bool);                               \
    DEF_FUNC(bool, inPlane_, IORegistryPlane *);                                                                 \
    DEF_FUNC(unsigned int, getDepth_, IORegistryPlane *);                                                        \
    DEF_FUNC(bool, attachToParent__, IORegistryEntry *, const IORegistryPlane *);                                \
    DEF_FUNC(void, detachFromParent__, IORegistryEntry *, const IORegistryPlane *);                              \
    DEF_FUNC(bool, attachToChild__, IORegistryEntry *, const IORegistryPlane *);                                 \
    DEF_FUNC(void, detachFromChild__, IORegistryEntry *, const IORegistryPlane *);                               \
    DEF_FUNC(void, detachAbove_, const IORegistryPlane *);                                                       \
    DEF_FUNC(void, detachAll_, const IORegistryPlane *);                                                         \
    DEF_FUNC(const char *, getName_, const IORegistryPlane *);                                                   \
    DEF_FUNC(const OSSymbol *, copyName_, const IORegistryPlane *);                                              \
    DEF_FUNC(bool, compareNames_object_, OSObject *, OSString **);                                               \
    DEF_FUNC(bool, compareName_string_, OSString *, OSString **);                                                \
    DEF_FUNC(void, setName_symbol_, OSSymbol *, IORegistryPlane *);                                              \
    DEF_FUNC(void, setName_cstring_, const char *, IORegistryPlane *);                                           \
    DEF_FUNC(const char *, getLocation_, IORegistryPlane *);                                                     \
    DEF_FUNC(const OSSymbol *, copyLocation_, IORegistryPlane *);                                                \
    DEF_FUNC(void, setLocation_symbol_, OSSymbol *, IORegistryPlane *);                                          \
    DEF_FUNC(void, setLocation_cstring_, const char *, IORegistryPlane *);                                       \
    DEF_FUNC(bool, getPath___, char *, int *, IORegistryPlane *);                                                \
    DEF_FUNC(bool, getPathComponent___, char *, int *, IORegistryPlane *);                                       \
    DEF_FUNC(IORegistryEntry *, childFromPath____, const char *, IORegistryPlane *, char *, int *);              \
    DEF_FUNC(const char *, init_entry_, IORegistryEntry *, IORegistryPlane *);

    DVT_IORegistryEntry
#undef CURRENT_CLASS_NAME
};

// configuration actions generally change future behavior
typedef enum : uint32_t {
    // basics (in common operational order)
    kIOReportEnable = 0x01,
    kIOReportGetDimensions = 0x02,
    kIOReportDisable = 0x00,

    // Enable/disable modifiers
    kIOReportNotifyHubOnChange = 0x10,  // triggered polling

    kIOReportTraceOnChange = 0x20  // kdebug.h tracing
} IOReportConfigureAction;

// update actions should not have observable side effects
typedef enum : uint32_t {
    kIOReportCopyChannelData = 1,
    kIOReportTraceChannelData = 2
} IOReportUpdateAction;

typedef struct {
    uint8_t report_format;  // Histogram, StateResidency, etc.
    uint8_t reserved;       // must be zero
    uint16_t categories;    // power, traffic, etc (omnibus obs.)
    uint16_t nelements;     // internal size of channel

    // only meaningful in the data pipeline
    int16_t element_idx;  // 0..nelements-1
                          // -1..-(nelements) = invalid (13127884)
} __attribute__((packed)) IOReportChannelType;

typedef struct {
    uint64_t channel_id;
    IOReportChannelType channel_type;
} IOReportChannel;

typedef struct {
    uint32_t nchannels;
    IOReportChannel channels[];
} IOReportChannelList;

typedef struct {
    uint64_t provider_id;
    IOReportChannel channel;
} IOReportInterest;

typedef struct {
    uint32_t ninterests;
    IOReportInterest interests[];
} IOReportInterestList;

#define IOR_VALUES_PER_ELEMENT 4
typedef struct {
    uint64_t v[IOR_VALUES_PER_ELEMENT];
} __attribute__((packed)) IOReportElementValues;

typedef struct {
    uint64_t provider_id;
    uint64_t channel_id;
    IOReportChannelType channel_type;
    uint64_t timestamp;  // mach_absolute_time()
    IOReportElementValues values;
} __attribute__((packed)) IOReportElement;

typedef uint32_t IOItemCount;

typedef OSObject IODeviceMemory;
typedef OSObject IOMemoryMap;
typedef OSObject IONotifier;

typedef IOService IOPowerConnection;
class IOUserClient;

typedef struct {
    unsigned long version;
    IOPMPowerFlags capabilityFlags;
    IOPMPowerFlags outputPowerCharacter;
    IOPMPowerFlags inputPowerRequirement;
    unsigned long staticPower;
    unsigned long stateOrder;
    unsigned long powerToAttain;
    unsigned long timeToAttain;
    unsigned long settleUpTime;
    unsigned long timeToLower;
    unsigned long settleDownTime;
    unsigned long powerDomainBudget;
} IOPMPowerState;

typedef unsigned long IOPMPowerFlags;

typedef void (*IOInterruptAction)(OSObject *target, void *refCon,
                                  IOService *nub, int source);
typedef bool (*IOServiceNotificationHandler)(void *target, void *refCon,
                                             IOService *newService);

typedef bool (*IOServiceMatchingNotificationHandler)(void *target, void *refCon,
                                                     IOService *newService,
                                                     IONotifier *notifier);

struct VTB_IOService {
#define CURRENT_CLASS_NAME IOService

#define DVT_IOService                                                                                             \
    DVT_IORegistryEntry                                                                                           \
    DEF_FUNC(bool, requestTerminate__, IOService *, IOOptionBits);                                                \
    DEF_FUNC(bool, willTerminate__, IOService *, IOOptionBits);                                                   \
    DEF_FUNC(bool, didTerminate__, IOService *, IOOptionBits, bool *);                                            \
    DEF_FUNC(int32_t, nextIdleTimeout__, uint64_t, uint64_t, unsigned int);                                       \
    DEF_FUNC(void, systemWillShutdown_, IOOptionBits);                                                            \
    DEF_FUNC(IOService *, copyClientWithCategory_, const OSSymbol *);                                             \
    DEF_FUNC(IOReturn, configureReport____, IOReportChannelList *, IOReportConfigureAction, void *, void *);      \
    DEF_FUNC(void, updateReport____, IOReportChannelList *, IOReportUpdateAction, void *, void *);                \
    DEF_FUNC(IOOptionBits, getState);                                                                             \
    DEF_FUNC(void, registerService_, IOOptionBits);                                                               \
    DEF_FUNC(IOService *, probe__, IOService *, int32_t *);                                                       \
    DEF_FUNC(bool, start_, IOService *);                                                                          \
    DEF_FUNC(bool, stop_, IOService *);                                                                           \
    DEF_FUNC(bool, open__, IOService *, IOOptionBits, void *);                                                    \
    DEF_FUNC(void, close_, IOService *, IOOptionBits);                                                            \
    DEF_FUNC(bool, isOpen_, const IOService *);                                                                   \
    DEF_FUNC(bool, handleOpen___, IOService *, IOOptionBits, void *);                                             \
    DEF_FUNC(void, handleClose__, IOService *, IOOptionBits);                                                     \
    DEF_FUNC(bool, handleIsOpen_, const IOService *);                                                             \
    DEF_FUNC(bool, terminate_, IOOptionBits);                                                                     \
    DEF_FUNC(bool, finalize_, IOOptionBits);                                                                      \
    DEF_FUNC(bool, lockForArbitration_, bool);                                                                    \
    DEF_FUNC(void, unlockForArbitration);                                                                         \
    DEF_FUNC(bool, terminateClient__, IOService *, IOOptionBits);                                                 \
    DEF_FUNC(uint32_t, getBusyState);                                                                             \
    DEF_FUNC(void, adjustBusy_, int32_t);                                                                         \
    DEF_FUNC(bool, matchPropertyTable__score, OSDictionary *, int32_t *);                                         \
    DEF_FUNC(bool, matchPropertyTable_, OSDictionary *);                                                          \
    DEF_FUNC(IOService *, matchLocation_, IOService *);                                                           \
    DEF_FUNC(bool, addNeededResource_, const char *);                                                             \
    DEF_FUNC(bool, compareProperty__cstring, OSDictionary *, const char *);                                       \
    DEF_FUNC(bool, compareProperty__string, OSDictionary *, const OSString *);                                    \
    DEF_FUNC(bool, compareProperties__collection, OSDictionary *, OSCollection *);                                \
    DEF_FUNC(bool, attach_, IOService *);                                                                         \
    DEF_FUNC(void, detach_, IOService *);                                                                         \
    DEF_FUNC(IOService *, getProvider);                                                                           \
    DEF_FUNC(IOWorkLoop *, getWorkLoop);                                                                          \
    DEF_FUNC(OSIterator *, getProviderIterator);                                                                  \
    DEF_FUNC(OSIterator *, getOpenProviderIterator);                                                              \
    DEF_FUNC(IOService *, getClient);                                                                             \
    DEF_FUNC(OSIterator *, getClientIterator);                                                                    \
    DEF_FUNC(OSIterator *, getOpenClientIterator);                                                                \
    DEF_FUNC(IOReturn, callPlatformFunction_symbol_____, const OSSymbol *, bool, void *, void *, void *, void *); \
    DEF_FUNC(IOReturn, callPlatformFunction_cstring_____, const char *, bool, void *, void *, void *, void *);    \
    DEF_FUNC(IOReturn, getResources);                                                                             \
    DEF_FUNC(IOItemCount, getDeviceMemoryCount);                                                                  \
    DEF_FUNC(IODeviceMemory *, getDeviceMemoryWithIndex_, unsigned int);                                          \
    DEF_FUNC(IOMemoryMap *, mapDeviceMemoryWithIndex_, unsigned int, unsigned int);                               \
    DEF_FUNC(OSArray *, getDeviceMemory);                                                                         \
    DEF_FUNC(void, setDeviceMemory_, OSArray *);                                                                  \
    DEF_FUNC(IOReturn, registerInterrupt___, int, OSObject *, IOInterruptAction, void *);                         \
    DEF_FUNC(IOReturn, unregisterInterrupt_, int);                                                                \
    DEF_FUNC(IOReturn, getInterruptType__, int, int *);                                                           \
    DEF_FUNC(IOReturn, enableInterrupt_, int);                                                                    \
    DEF_FUNC(IOReturn, disableInterrupt_, int);                                                                   \
    DEF_FUNC(IOReturn, causeInterrupt_, int);                                                                     \
    DEF_FUNC(IOReturn, requestProbe_, IOOptionBits);                                                              \
    DEF_FUNC(IOReturn, message___, uint32_t, IOService *, void *);                                                \
    DEF_FUNC(IOReturn, messageClient____, uint32_t, OSObject *, void *, vm_size_t);                               \
    DEF_FUNC(IOReturn, messageClients___, uint32_t, void *, vm_size_t);                                           \
    DEF_FUNC(IONotifier *, registerInterest____, const OSSymbol *, IOServiceInterestHandler, void *, void *);     \
    DEF_FUNC(void, applyToProviders__, IOServiceApplierFunction, void *);                                         \
    DEF_FUNC(void, applyToClients__, IOServiceApplierFunction, void *);                                           \
    DEF_FUNC(void, applyToInterested__, const OSSymbol *, OSObjectApplierFunction, void *);                       \
    DEF_FUNC(IOReturn, acknowledgeNotification__, /*IONotificationRef*/ void *, IOOptionBits);                    \
    DEF_FUNC(IOReturn, newUserClient___properties__, task *, void *, uint32_t, OSDictionary *, IOUserClient **);  \
    DEF_FUNC(IOReturn, newUserClient____, task *, void *, uint32_t, IOUserClient **);                             \
    DEF_FUNC(const char *, stringFromReturn_, IOReturn);                                                          \
    DEF_FUNC(int, errnoFromReturn_, IOReturn);                                                                    \
    DEF_FUNC(void, PMinit);                                                                                       \
    DEF_FUNC(void, PMstop);                                                                                       \
    DEF_FUNC(void, joinPMtree_, IOService *);                                                                     \
    DEF_FUNC(IOReturn, registerPowerDriver___, IOService *, IOPMPowerState *, unsigned long);                     \
    DEF_FUNC(IOReturn, requestPowerDomainState___, IOPMPowerFlags, IOPowerConnection *, unsigned long);           \
    DEF_FUNC(bool, activityTickle__, unsigned long, unsigned long);                                               \
    DEF_FUNC(IOReturn, setAggressiveness__, unsigned long, unsigned long);                                        \
    DEF_FUNC(IOReturn, getAggressiveness__, unsigned long, unsigned long *);                                      \
    DEF_FUNC(IOReturn, addPowerChild_, IOService *);                                                              \
    DEF_FUNC(IOReturn, removePowerChild_, IOPowerConnection *);                                                   \
    DEF_FUNC(IOReturn, setIdleTimerPeriod_, unsigned long);                                                       \
    DEF_FUNC(IOReturn, setPowerState__, unsigned long, IOService *);                                              \
    DEF_FUNC(unsigned long, maxCapabilityForDomainState_, IOPMPowerFlags);                                        \
    DEF_FUNC(unsigned long, initialPowerStateForDomainState_, IOPMPowerFlags);                                    \
    DEF_FUNC(unsigned long, powerStateForDomainState_, IOPMPowerFlags);                                           \
    DEF_FUNC(IOReturn, powerStateWillChangeTo___, IOPMPowerFlags, unsigned long, IOService *);                    \
    DEF_FUNC(IOReturn, powerStateDidChangeTo___, IOPMPowerFlags, unsigned long, IOService *);                     \
    DEF_FUNC(bool, askChangeDown_, unsigned long);                                                                \
    DEF_FUNC(bool, tellChangeDown_, unsigned long);                                                               \
    DEF_FUNC(void, tellNoChangeDown_, unsigned long);                                                             \
    DEF_FUNC(void, tellChangeUp_, unsigned long);                                                                 \
    DEF_FUNC(IOReturn, allowPowerChange_, unsigned long);                                                         \
    DEF_FUNC(IOReturn, cancelPowerChange_, unsigned long);                                                        \
    DEF_FUNC(void, powerChangeDone_, unsigned long);

    DVT_IOService

#undef CURRENT_CLASS_NAME
};

struct ipc_port;
typedef uint64_t io_user_reference_t;
typedef uint32_t UInt32;
struct semaphore;
typedef struct semaphore *semaphore_t;
typedef IOMemoryDescriptor OSObject;

struct VTB_IOUserClient {
#define CURRENT_CLASS_NAME IOUserClient

#define DVT_IOUserClient                                                                                                                                                \
    DVT_IOService                                                                                                                                                       \
    DEF_FUNC(IOReturn, externalMethod, uint32_t selector, IOExternalMethodArguments *arguments, IOExternalMethodDispatch *dispatch, OSObject *target, void *reference); \
    DEF_FUNC(IOReturn, registerNotificationPort_refCon, ipc_port *port, UInt32 type, io_user_reference_t refCon);                                                       \
    DEF_FUNC(bool, initWithTask_properties, task_t owningTask, void *securityToken, UInt32 type, OSDictionary *properties);                                             \
    DEF_FUNC(bool, initWithTask, task_t owningTask, void *securityToken, UInt32 type);                                                                                  \
    DEF_FUNC(IOReturn, clientClose);                                                                                                                                    \
    DEF_FUNC(IOReturn, clientDied);                                                                                                                                     \
    DEF_FUNC(IOService *, getService);                                                                                                                                  \
    DEF_FUNC(IOReturn, registerNotificationPort_uint32, mach_port_t, UInt32 type, UInt32 refCon);                                                                       \
    DEF_FUNC(IOReturn, getNotificationSemaphore, UInt32 notification_type, semaphore_t *semaphore);                                                                     \
    DEF_FUNC(IOReturn, connectClient, IOUserClient *);                                                                                                                  \
    DEF_FUNC(IOReturn, clientMemoryForType, UInt32 type, IOOptionBits *options, IOMemoryDescriptor **memory);                                                           \
    DEF_FUNC(IOReturn, exportObjectToClient, task_t task, OSObject *obj, OSObject **clientObj);                                                                         \
    DEF_FUNC(IOExternalMethod *, getExternalMethodForIndex, UInt32 index);                                                                                              \
    DEF_FUNC(IOExternalAsyncMethod *, getExternalAsyncMethodForIndex, UInt32 index);                                                                                    \
    DEF_FUNC(IOExternalMethod *, getTargetAndMethodForIndex, IOService **targetP, UInt32 index);                                                                        \
    DEF_FUNC(IOExternalAsyncMethod *, getAsyncTargetAndMethodForIndex, IOService **targetP, UInt32 index);                                                              \
    DEF_FUNC(IOExternalTrap *, getExternalTrapForIndex, UInt32 index);                                                                                                  \
    DEF_FUNC(IOExternalTrap *, getTargetAndTrapForIndex, IOService **targetP, UInt32 index);

    DVT_IOUserClient

#undef CURRENT_CLASS_NAME
};
