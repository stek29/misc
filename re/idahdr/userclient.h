typedef void OSObject;

typedef uint64_t io_user_reference_t;

typedef OSObject IOMemoryDescriptor;
typedef kern_return_t IOReturn;

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

typedef IOReturn (*IOExternalMethodAction)(OSObject * target, void * reference, IOExternalMethodArguments * arguments);

struct IOExternalMethodDispatch {
    IOExternalMethodAction function;
    uint32_t           checkScalarInputCount;
    uint32_t           checkStructureInputSize;
    uint32_t           checkScalarOutputCount;
    uint32_t           checkStructureOutputSize;
};
