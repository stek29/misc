typedef void OSObject;

typedef uint64_t io_user_reference_t;

typedef OSObject IOMemoryDescriptor;
typedef kern_return_t IOReturn;

typedef uint64_t IOByteCount;
enum {
    kOSAsyncRefCount	= 8,
    kOSAsyncRefSize 	= 32
};
typedef natural_t OSAsyncReference[kOSAsyncRefCount];

typedef IOReturn (*IOMethod)(void *p1, void *p2, void *p3,
                             void *p4, void *p5, void *p6);

typedef IOReturn (*IOAsyncMethod)(OSAsyncReference asyncRef,
                                  void *p1, void *p2, void *p3,
                                  void *p4, void *p5, void *p6);

typedef IOReturn (*IOTrap)(void *p1, void *p2, void *p3,
                           void *p4, void *p5, void *p6);

struct IOExternalMethod {
    IOService *object;
    IOMethod func;
    IOOptionBits flags;
    IOByteCount count0;
    IOByteCount count1;
};

struct IOExternalAsyncMethod {
    IOService *object;
    IOAsyncMethod func;
    IOOptionBits flags;
    IOByteCount count0;
    IOByteCount count1;
};

struct IOExternalTrap {
    IOService *object;
    IOTrap func;
};

struct IOExternalMethodArguments {
    uint32_t version;
    uint32_t selector;
    mach_port_t asyncWakePort;
    io_user_reference_t *asyncReference;
    uint32_t asyncReferenceCount;
    const uint64_t *scalarInput;
    uint32_t scalarInputCount;
    const void *structureInput;
    uint32_t structureInputSize;
    IOMemoryDescriptor *structureInputDescriptor;
    uint64_t *scalarOutput;
    uint32_t scalarOutputCount;
    void *structureOutput;
    uint32_t structureOutputSize;
    IOMemoryDescriptor *structureOutputDescriptor;
    uint32_t structureOutputDescriptorSize;
    OSObject **structureVariableOutputData;
};

typedef IOReturn (*IOExternalMethodAction)(OSObject *target, void *reference, IOExternalMethodArguments *arguments);

struct IOExternalMethodDispatch {
    IOExternalMethodAction function;
    uint32_t checkScalarInputCount;
    uint32_t checkStructureInputSize;
    uint32_t checkScalarOutputCount;
    uint32_t checkStructureOutputSize;
};
