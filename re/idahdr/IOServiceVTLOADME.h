

typedef void OSMetaClassBase;


typedef OSMetaClassBase OSMetaClass;

typedef void OSSerialize;
typedef OSMetaClass OSCollection;







struct VTB_OSMetaClassBase; typedef struct { struct VTB_OSMetaClassBase *vtab; } OSMetaClassBase;
struct VTB_OSObject; typedef struct { struct VTB_OSObject *vtab; } OSObject;
struct VTB_OSString; typedef struct { struct VTB_OSString *vtab; } OSString;
struct VTB_OSSymbol; typedef struct { struct VTB_OSSymbol *vtab; } OSSymbol;
struct VTB_OSBoolean; typedef struct { struct VTB_OSBoolean *vtab; } OSBoolean;
struct VTB_OSData; typedef struct { struct VTB_OSData *vtab; } OSData;
struct VTB_OSDictionary; typedef struct { struct VTB_OSDictionary *vtab; } OSDictionary;
struct VTB_OSArray; typedef struct { struct VTB_OSArray *vtab; } OSArray;
struct VTB_OSSet; typedef struct { struct VTB_OSSet *vtab; } OSSet;
struct VTB_OSOrderedSet; typedef struct { struct VTB_OSOrderedSet *vtab; } OSOrderedSet;
struct VTB_OSNumber; typedef struct { struct VTB_OSNumber *vtab; } OSNumber;
struct VTB_OSIterator; typedef struct { struct VTB_OSIterator *vtab; } OSIterator;
struct VTB_OSCollectionIterator; typedef struct { struct VTB_OSCollectionIterator *vtab; } OSCollectionIterator;







struct VTB_OSMetaClassBase {
 void (*destr1)(OSMetaClassBase*); void (*destr0)(OSMetaClassBase*); void (*release_int)(OSMetaClassBase*, int freeWhen); int (*getRetainCount)(OSMetaClassBase*); void (*retain)(OSMetaClassBase*); void (*release)(OSMetaClassBase*); bool (*serialize_)(OSMetaClassBase*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSMetaClassBase*); bool (*isEqualTo_)(OSMetaClassBase*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSMetaClassBase*, const void *tag); void (*taggedRelease_)(OSMetaClassBase*, const void *tag); void (*taggedRelease__int)(OSMetaClassBase*, const void *tag, int freeWhen);

};

struct VTB_OSObject {






 void (*destr1)(OSObject*); void (*destr0)(OSObject*); void (*release_int)(OSObject*, int freeWhen); int (*getRetainCount)(OSObject*); void (*retain)(OSObject*); void (*release)(OSObject*); bool (*serialize_)(OSObject*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSObject*); bool (*isEqualTo_)(OSObject*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSObject*, const void *tag); void (*taggedRelease_)(OSObject*, const void *tag); void (*taggedRelease__int)(OSObject*, const void *tag, int freeWhen); bool (*init)(OSObject*); void (*free)(OSObject*);

};
struct VTB_OSDictionary {
 void (*destr1)(OSDictionary*); void (*destr0)(OSDictionary*); void (*release_int)(OSDictionary*, int freeWhen); int (*getRetainCount)(OSDictionary*); void (*retain)(OSDictionary*); void (*release)(OSDictionary*); bool (*serialize_)(OSDictionary*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSDictionary*); bool (*isEqualTo_)(OSDictionary*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSDictionary*, const void *tag); void (*taggedRelease_)(OSDictionary*, const void *tag); void (*taggedRelease__int)(OSDictionary*, const void *tag, int freeWhen); bool (*init)(OSDictionary*); void (*free)(OSDictionary*); int (*iteratorSize)(OSDictionary*); bool (*initIterator_)(OSDictionary*, void *iterator); bool (*getNextObjectForIterator__)(OSDictionary*, void *iterator, OSObject **nextObject); unsigned int (*getCount)(OSDictionary*); unsigned int (*getCapacity)(OSDictionary*); unsigned int (*getCapacityIncrement)(OSDictionary*); unsigned int (*setCapacityIncrement_)(OSDictionary*, unsigned int increment); unsigned int (*ensureCapacity_)(OSDictionary*, unsigned int newCapacity); void (*flushCollection)(OSDictionary*); unsigned (*setOptions___)(OSDictionary*, unsigned options, unsigned mask, void* context); OSDictionary * (*copyCollection_)(OSDictionary*, OSDictionary* cycleDict); bool (*initWithCapacity_)(OSDictionary*, unsigned int); bool (*initWithObjects__OSSymbol__)(OSDictionary*, const OSObject * objects[], const OSSymbol * keys[], unsigned int count, unsigned int capacity); bool (*initWithObjects__OSString__)(OSDictionary*, const OSObject * objects[], const OSString * keys[], unsigned int count, unsigned int capacity); bool (*initWithDictionary__)(OSDictionary*, const OSDictionary* dict, unsigned int capacity); bool (*setObject_OSSymbol_)(OSDictionary*, const OSSymbol *aKey, const OSMetaClassBase *anObject); bool (*setObject_OSString_)(OSDictionary*, const OSString *aKey, const OSMetaClassBase *anObject); bool (*setObject_cstring_)(OSDictionary*, const char *aKey, const OSMetaClassBase *anObject); void (*removeObject_OSSymbol)(OSDictionary*, const OSSymbol *aKey); void (*removeObject_OSString)(OSDictionary*, const OSString *aKey); void (*removeObject_cstring)(OSDictionary*, const char *aKey); bool (*merge_)(OSDictionary*, OSDictionary* aDictionary); OSObject* (*getObject_OSSymbol)(OSDictionary*, const OSSymbol *aKey); OSObject* (*getObject_OSString)(OSDictionary*, const OSString *aKey); OSObject* (*getObject_cstring)(OSDictionary*, const char *aKey); bool (*isEqualTo_dict)(OSDictionary*, const OSDictionary* aDictionary); bool (*isEqualTo_dict_keys)(OSDictionary*, const OSDictionary* aDictionary, OSCollection* keys);

};

struct VTB_OSArray {
 void (*destr1)(OSArray*); void (*destr0)(OSArray*); void (*release_int)(OSArray*, int freeWhen); int (*getRetainCount)(OSArray*); void (*retain)(OSArray*); void (*release)(OSArray*); bool (*serialize_)(OSArray*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSArray*); bool (*isEqualTo_)(OSArray*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSArray*, const void *tag); void (*taggedRelease_)(OSArray*, const void *tag); void (*taggedRelease__int)(OSArray*, const void *tag, int freeWhen); bool (*init)(OSArray*); void (*free)(OSArray*); int (*iteratorSize)(OSArray*); bool (*initIterator_)(OSArray*, void *iterator); bool (*getNextObjectForIterator__)(OSArray*, void *iterator, OSObject **nextObject); unsigned int (*getCount)(OSArray*); unsigned int (*getCapacity)(OSArray*); unsigned int (*getCapacityIncrement)(OSArray*); unsigned int (*setCapacityIncrement_)(OSArray*, unsigned int increment); unsigned int (*ensureCapacity_)(OSArray*, unsigned int newCapacity); void (*flushCollection)(OSArray*); unsigned (*setOptions___)(OSArray*, unsigned options, unsigned mask, void* context); OSArray * (*copyCollection_)(OSArray*, OSDictionary* cycleDict); bool (*initWithCapacity_)(OSArray*, unsigned int); bool (*initWithObjects___)(OSArray*, const OSObject *objects[], unsigned int count, unsigned int capacity); bool (*initWithArray_)(OSArray*, const OSArray* anArray, unsigned capacity); bool (*setObject_)(OSArray*, OSMetaClassBase* anObject); bool (*setObject_int_)(OSArray*, unsigned int index, OSMetaClassBase* anObject); bool (*merge_)(OSArray*, const OSArray* anArray); bool (*replaceObject_int_)(OSArray*, unsigned int index, OSMetaClassBase* anObject); void (*removeObject_)(OSArray*, unsigned int index); bool (*isEqualTo_array)(OSArray*, const OSArray* anArray); OSObject* (*getObject_)(OSArray*, unsigned int index); OSObject* (*getLastObject)(OSArray*); unsigned int (*getNextIndexOfObject__)(OSArray*, const OSMetaClassBase* anObject, unsigned int index);

};

struct VTB_OSSet {
 void (*destr1)(OSSet*); void (*destr0)(OSSet*); void (*release_int)(OSSet*, int freeWhen); int (*getRetainCount)(OSSet*); void (*retain)(OSSet*); void (*release)(OSSet*); bool (*serialize_)(OSSet*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSSet*); bool (*isEqualTo_)(OSSet*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSSet*, const void *tag); void (*taggedRelease_)(OSSet*, const void *tag); void (*taggedRelease__int)(OSSet*, const void *tag, int freeWhen); bool (*init)(OSSet*); void (*free)(OSSet*); int (*iteratorSize)(OSSet*); bool (*initIterator_)(OSSet*, void *iterator); bool (*getNextObjectForIterator__)(OSSet*, void *iterator, OSObject **nextObject); unsigned int (*getCount)(OSSet*); unsigned int (*getCapacity)(OSSet*); unsigned int (*getCapacityIncrement)(OSSet*); unsigned int (*setCapacityIncrement_)(OSSet*, unsigned int increment); unsigned int (*ensureCapacity_)(OSSet*, unsigned int newCapacity); void (*flushCollection)(OSSet*); unsigned (*setOptions___)(OSSet*, unsigned options, unsigned mask, void* context); OSSet * (*copyCollection_)(OSSet*, OSDictionary* cycleDict); bool (*initWithCapacity_)(OSSet*, unsigned int); bool (*initWithObjects___)(OSSet*, const OSObject *objects[], unsigned int count, unsigned int capacity); bool (*initWithArray_)(OSSet*, const OSArray* anArray, unsigned capacity); bool (*initWithSet_)(OSSet*, const OSSet* aSet, unsigned capacity); bool (*setObject_)(OSSet*, OSMetaClassBase* anObject); bool (*merge_array)(OSSet*, const OSArray* anArray); bool (*merge_set)(OSSet*, const OSSet* aSet); void (*removeObject_)(OSSet*, const OSMetaClassBase* anObject); bool (*containsObject_)(OSSet*, const OSMetaClassBase* anObject); bool (*member_)(OSSet*, const OSMetaClassBase* anObject); OSObject* (*getAnyObject)(OSSet*); bool (*isEqualTo_set)(OSSet*, const OSSet* aSet);

};


typedef int (*OSOrderFunction)(const OSMetaClassBase * obj1, const OSMetaClassBase * obj2, void * context);
struct VTB_OSOrderedSet {
 void (*destr1)(OSOrderedSet*); void (*destr0)(OSOrderedSet*); void (*release_int)(OSOrderedSet*, int freeWhen); int (*getRetainCount)(OSOrderedSet*); void (*retain)(OSOrderedSet*); void (*release)(OSOrderedSet*); bool (*serialize_)(OSOrderedSet*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSOrderedSet*); bool (*isEqualTo_)(OSOrderedSet*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSOrderedSet*, const void *tag); void (*taggedRelease_)(OSOrderedSet*, const void *tag); void (*taggedRelease__int)(OSOrderedSet*, const void *tag, int freeWhen); bool (*init)(OSOrderedSet*); void (*free)(OSOrderedSet*); int (*iteratorSize)(OSOrderedSet*); bool (*initIterator_)(OSOrderedSet*, void *iterator); bool (*getNextObjectForIterator__)(OSOrderedSet*, void *iterator, OSObject **nextObject); unsigned int (*getCount)(OSOrderedSet*); unsigned int (*getCapacity)(OSOrderedSet*); unsigned int (*getCapacityIncrement)(OSOrderedSet*); unsigned int (*setCapacityIncrement_)(OSOrderedSet*, unsigned int increment); unsigned int (*ensureCapacity_)(OSOrderedSet*, unsigned int newCapacity); void (*flushCollection)(OSOrderedSet*); unsigned (*setOptions___)(OSOrderedSet*, unsigned options, unsigned mask, void* context); OSOrderedSet * (*copyCollection_)(OSOrderedSet*, OSDictionary* cycleDict); bool (*initWithCapacity___)(OSOrderedSet*, unsigned int capacity, OSOrderFunction orderFunc, void *orderContext); bool (*setObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*setFirstObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*setLastObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*removeObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*containsObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*member_)(OSOrderedSet*, const OSMetaClassBase* anObject); OSObject* (*getFirstObject)(OSOrderedSet*); OSObject* (*getLastObject)(OSOrderedSet*); int (*orderObject_)(OSOrderedSet*, const OSMetaClassBase* anObject); bool (*setObject_int_)(OSOrderedSet*, unsigned int index, OSMetaClassBase* anObject); OSObject* (*getObject_)(OSOrderedSet*, unsigned int index); void* (*getOrderingRef)(OSOrderedSet*); bool (*isEqualTo_orderedset)(OSOrderedSet*);

};

struct VTB_OSString {
 void (*destr1)(OSString*); void (*destr0)(OSString*); void (*release_int)(OSString*, int freeWhen); int (*getRetainCount)(OSString*); void (*retain)(OSString*); void (*release)(OSString*); bool (*serialize_)(OSString*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSString*); bool (*isEqualTo_)(OSString*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSString*, const void *tag); void (*taggedRelease_)(OSString*, const void *tag); void (*taggedRelease__int)(OSString*, const void *tag, int freeWhen); bool (*init)(OSString*); void (*free)(OSString*); bool (*initWithString_)(OSString*, const OSString* aString); bool (*initWithCString_)(OSString*, const char*); bool (*initWithCStringNoCopy_)(OSString*, const char*); unsigned int (*getLength)(OSString*); char (*getChar_)(OSString*, unsigned int index); char (*setChar__)(OSString*, char aChar, unsigned int index); char* (*getCStringNoCopy)(OSString*); bool (*isEqualTo_string)(OSString*, const OSString* aString); bool (*isEqualTo_cstring)(OSString*, const char* aString); bool (*isEqualTo_data)(OSString*, const OSData* aDataObject);

};

struct VTB_OSSymbol {





 void (*destr1)(OSSymbol*); void (*destr0)(OSSymbol*); void (*release_int)(OSSymbol*, int freeWhen); int (*getRetainCount)(OSSymbol*); void (*retain)(OSSymbol*); void (*release)(OSSymbol*); bool (*serialize_)(OSSymbol*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSSymbol*); bool (*isEqualTo_)(OSSymbol*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSSymbol*, const void *tag); void (*taggedRelease_)(OSSymbol*, const void *tag); void (*taggedRelease__int)(OSSymbol*, const void *tag, int freeWhen); bool (*init)(OSSymbol*); void (*free)(OSSymbol*); bool (*initWithString_)(OSSymbol*, const OSString* aString); bool (*initWithCString_)(OSSymbol*, const char*); bool (*initWithCStringNoCopy_)(OSSymbol*, const char*); unsigned int (*getLength)(OSSymbol*); char (*getChar_)(OSSymbol*, unsigned int index); char (*setChar__)(OSSymbol*, char aChar, unsigned int index); char* (*getCStringNoCopy)(OSSymbol*); bool (*isEqualTo_string)(OSSymbol*, const OSString* aString); bool (*isEqualTo_cstring)(OSSymbol*, const char* aString); bool (*isEqualTo_data)(OSSymbol*, const OSData* aDataObject); bool (*isEqualTo_symbol)(OSSymbol*, const OSSymbol* aSymbol);

};

struct VTB_OSBoolean {
 void (*destr1)(OSBoolean*); void (*destr0)(OSBoolean*); void (*release_int)(OSBoolean*, int freeWhen); int (*getRetainCount)(OSBoolean*); void (*retain)(OSBoolean*); void (*release)(OSBoolean*); bool (*serialize_)(OSBoolean*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSBoolean*); bool (*isEqualTo_)(OSBoolean*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSBoolean*, const void *tag); void (*taggedRelease_)(OSBoolean*, const void *tag); void (*taggedRelease__int)(OSBoolean*, const void *tag, int freeWhen); bool (*init)(OSBoolean*); void (*free)(OSBoolean*); bool (*isTrue)(OSBoolean*); bool (*isFalse)(OSBoolean*); bool (*getValue)(OSBoolean*); bool (*isEqualTo_boolean)(OSBoolean*, const OSBoolean* aBoolean);

};

struct VTB_OSData {
 void (*destr1)(OSData*); void (*destr0)(OSData*); void (*release_int)(OSData*, int freeWhen); int (*getRetainCount)(OSData*); void (*retain)(OSData*); void (*release)(OSData*); bool (*serialize_)(OSData*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSData*); bool (*isEqualTo_)(OSData*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSData*, const void *tag); void (*taggedRelease_)(OSData*, const void *tag); void (*taggedRelease__int)(OSData*, const void *tag, int freeWhen); bool (*init)(OSData*); void (*free)(OSData*); bool (*initWithCapacity_)(OSData*, unsigned int capacity); bool (*initWithBytes__)(OSData*, const void *bytes, unsigned int numBytes); bool (*initWithBytesNoCopy__)(OSData*, void *bytes, unsigned int numBytes); bool (*initWithData_)(OSData*, const OSData* inData); bool (*initWithData___)(OSData*, const OSData* inData, unsigned int start, unsigned int numBytes); unsigned int (*getLength)(OSData*); unsigned int (*getCapacity)(OSData*); unsigned int (*getCapacityIncrement)(OSData*); unsigned int (*setCapacityIncrement_)(OSData*, unsigned int increment); unsigned int (*ensureCapacity_)(OSData*, unsigned int newCapacity); bool (*appendBytes__)(OSData*, const void* bytes, unsigned int numBytes); bool (*appendBytes_)(OSData*, const OSData* aDataObj); const void* (*getBytesNoCopy)(OSData*); const void* (*getBytesNoCopy__)(OSData*, unsigned int start, unsigned int numBytes); bool (*isEqualTo_data)(OSData*, const OSData* aDataObj); bool (*isEqualTo_bytes_)(OSData*, const void* bytes, unsigned int numBytes); bool (*isEqualTo_string)(OSData*, const OSString* aBoolean); bool (*appendByte__)(OSData*, unsigned char byte, unsigned int numBytes); void (*setDeallocFunction_)(OSData*, void (*)(void * ptr, unsigned int length));

};


struct VTB_OSNumber {
 void (*destr1)(OSNumber*); void (*destr0)(OSNumber*); void (*release_int)(OSNumber*, int freeWhen); int (*getRetainCount)(OSNumber*); void (*retain)(OSNumber*); void (*release)(OSNumber*); bool (*serialize_)(OSNumber*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSNumber*); bool (*isEqualTo_)(OSNumber*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSNumber*, const void *tag); void (*taggedRelease_)(OSNumber*, const void *tag); void (*taggedRelease__int)(OSNumber*, const void *tag, int freeWhen); bool (*init)(OSNumber*); void (*free)(OSNumber*); bool (*init_value_)(OSNumber*, unsigned long long value, unsigned int numberOfBits); bool (*init_valueString_)(OSNumber*, const char* valueString, unsigned int numberOfBits); unsigned int (*numberOfBits)(OSNumber*); unsigned int (*numberOfBytes)(OSNumber*); unsigned char (*unsigned8BitValue)(OSNumber*); unsigned short (*unsigned16BitValue)(OSNumber*); unsigned int (*unsigned32BitValue)(OSNumber*); unsigned long long (*unsigned64BitValue)(OSNumber*); void (*addValue_)(OSNumber*, signed long long); void (*setValue_)(OSNumber*, unsigned long long); void (*isEqualTo_number)(OSNumber*, const OSNumber* aNumber);

};

struct VTB_OSIterator {







 void (*destr1)(OSIterator*); void (*destr0)(OSIterator*); void (*release_int)(OSIterator*, int freeWhen); int (*getRetainCount)(OSIterator*); void (*retain)(OSIterator*); void (*release)(OSIterator*); bool (*serialize_)(OSIterator*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSIterator*); bool (*isEqualTo_)(OSIterator*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSIterator*, const void *tag); void (*taggedRelease_)(OSIterator*, const void *tag); void (*taggedRelease__int)(OSIterator*, const void *tag, int freeWhen); bool (*init)(OSIterator*); void (*free)(OSIterator*); void (*reset)(OSIterator*); bool (*isValid)(OSIterator*); OSObject* (*getNextObject)(OSIterator*);

};

struct VTB_OSCollectionIterator {





 void (*destr1)(OSCollectionIterator*); void (*destr0)(OSCollectionIterator*); void (*release_int)(OSCollectionIterator*, int freeWhen); int (*getRetainCount)(OSCollectionIterator*); void (*retain)(OSCollectionIterator*); void (*release)(OSCollectionIterator*); bool (*serialize_)(OSCollectionIterator*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(OSCollectionIterator*); bool (*isEqualTo_)(OSCollectionIterator*, const OSMetaClassBase *anObject); void (*taggedRetain_)(OSCollectionIterator*, const void *tag); void (*taggedRelease_)(OSCollectionIterator*, const void *tag); void (*taggedRelease__int)(OSCollectionIterator*, const void *tag, int freeWhen); bool (*init)(OSCollectionIterator*); void (*free)(OSCollectionIterator*); void (*reset)(OSCollectionIterator*); bool (*isValid)(OSCollectionIterator*); OSObject* (*getNextObject)(OSCollectionIterator*); void (*initWithCollection_)(OSCollectionIterator*, const OSCollection* inColl);

};

struct VTB_IORegistryEntry; typedef struct { struct VTB_IORegistryEntry *vtab; } IORegistryEntry;
struct VTB_IOService; typedef struct { struct VTB_IOService *vtab; } IOService;

typedef OSObject IOWorkLoop;
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
    void (*destr1)(IORegistryEntry*); void (*destr0)(IORegistryEntry*); void (*release_int)(IORegistryEntry*, int freeWhen); int (*getRetainCount)(IORegistryEntry*); void (*retain)(IORegistryEntry*); void (*release)(IORegistryEntry*); bool (*serialize_)(IORegistryEntry*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(IORegistryEntry*); bool (*isEqualTo_)(IORegistryEntry*, const OSMetaClassBase *anObject); void (*taggedRetain_)(IORegistryEntry*, const void *tag); void (*taggedRelease_)(IORegistryEntry*, const void *tag); void (*taggedRelease__int)(IORegistryEntry*, const void *tag, int freeWhen); bool (*init)(IORegistryEntry*); void (*free)(IORegistryEntry*); OSObject * (*copyProperty_cstring_plane_)(IORegistryEntry*, const char *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_string_plane_)(IORegistryEntry*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_symbol_plane_)(IORegistryEntry*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); IORegistryEntry * (*copyParentEntry_)(IORegistryEntry*, const IORegistryPlane *); IORegistryEntry * (*copyChildEntry_)(IORegistryEntry*, const IORegistryPlane *); IOReturn (*runPropertyAction______)(IORegistryEntry*, IOService_Action *, OSObject *, void *, void *, void *, void *); bool (*init_withDictionary)(IORegistryEntry*, OSDictionary *); void (*setPropertyTable_)(IORegistryEntry*, OSDictionary *); bool (*setProperty_symbol_)(IORegistryEntry*, const OSSymbol *, OSObject *); bool (*setProperty_string_)(IORegistryEntry*, const OSString *, OSObject *); bool (*setProperty_cstring_)(IORegistryEntry*, const char *, OSObject *); bool (*setProperty_cstring_cstring)(IORegistryEntry*, const char *, const char *); bool (*setProperty_cstring_bool)(IORegistryEntry*, const char *, bool); bool (*setProperty_cstring_val_bits)(IORegistryEntry*, const char *, unsigned long long, unsigned int); bool (*setProperty_cstring_bytes_)(IORegistryEntry*, const char *, void *, unsigned int); OSObject * (*getProperty_symbol)(IORegistryEntry*, const OSSymbol *); OSObject * (*getProperty_string)(IORegistryEntry*, const OSString *); OSObject * (*getProperty_cstring)(IORegistryEntry*, const char *); OSObject * (*getProperty_symbol__)(IORegistryEntry*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_string__)(IORegistryEntry*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_cstring__)(IORegistryEntry*, const char *, const IORegistryPlane *, IOOptionBits); void (*removeProperty_symbol)(IORegistryEntry*, const OSSymbol *); void (*removeProperty_string)(IORegistryEntry*, const OSString *); void (*removeProperty_cstring)(IORegistryEntry*, const char *); OSObject * (*copyProperty_symbol)(IORegistryEntry*, const OSSymbol *); OSObject * (*copyProperty_string)(IORegistryEntry*, const OSString *); OSObject * (*copyProperty_cstring)(IORegistryEntry*, const char *); OSDictionary * (*dictionaryWithProperties)(IORegistryEntry*); bool (*serializeProperties_)(IORegistryEntry*, OSSerialize *); IOReturn (*setProperties_object)(IORegistryEntry*, OSObject *); OSIterator * (*getParentIterator_)(IORegistryEntry*, IORegistryPlane *); void (*applyToParents___)(IORegistryEntry*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getParentEntry_)(IORegistryEntry*, const IORegistryPlane *); OSIterator * (*getChildIterator_)(IORegistryEntry*, IORegistryPlane *); void (*applyToChildren___)(IORegistryEntry*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getChildEntry_)(IORegistryEntry*, const IORegistryPlane *); bool (*isChild___)(IORegistryEntry*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*isParent___)(IORegistryEntry*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*inPlane_)(IORegistryEntry*, IORegistryPlane *); unsigned int (*getDepth_)(IORegistryEntry*, IORegistryPlane *); bool (*attachToParent__)(IORegistryEntry*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromParent__)(IORegistryEntry*, IORegistryEntry *, const IORegistryPlane *); bool (*attachToChild__)(IORegistryEntry*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromChild__)(IORegistryEntry*, IORegistryEntry *, const IORegistryPlane *); void (*detachAbove_)(IORegistryEntry*, const IORegistryPlane *); void (*detachAll_)(IORegistryEntry*, const IORegistryPlane *); const char * (*getName_)(IORegistryEntry*, const IORegistryPlane *); const OSSymbol * (*copyName_)(IORegistryEntry*, const IORegistryPlane *); bool (*compareNames_object_)(IORegistryEntry*, OSObject *, OSString **); bool (*compareName_string_)(IORegistryEntry*, OSString *, OSString **); void (*setName_symbol_)(IORegistryEntry*, OSSymbol *, IORegistryPlane *); void (*setName_cstring_)(IORegistryEntry*, const char *, IORegistryPlane *); const char * (*getLocation_)(IORegistryEntry*, IORegistryPlane *); const OSSymbol * (*copyLocation_)(IORegistryEntry*, IORegistryPlane *); void (*setLocation_symbol_)(IORegistryEntry*, OSSymbol *, IORegistryPlane *); void (*setLocation_cstring_)(IORegistryEntry*, const char *, IORegistryPlane *); bool (*getPath___)(IORegistryEntry*, char *, int *, IORegistryPlane *); bool (*getPathComponent___)(IORegistryEntry*, char *, int *, IORegistryPlane *); IORegistryEntry * (*childFromPath____)(IORegistryEntry*, const char *, IORegistryPlane *, char *, int *); const char * (*init_entry_)(IORegistryEntry*, IORegistryEntry *, IORegistryPlane *);

};


typedef enum : uint32_t {

    kIOReportEnable = 0x01,
    kIOReportGetDimensions = 0x02,
    kIOReportDisable = 0x00,


    kIOReportNotifyHubOnChange = 0x10,

    kIOReportTraceOnChange = 0x20
} IOReportConfigureAction;


typedef enum : uint32_t {
    kIOReportCopyChannelData = 1,
    kIOReportTraceChannelData = 2
} IOReportUpdateAction;

typedef struct {
    uint8_t report_format;
    uint8_t reserved;
    uint16_t categories;
    uint16_t nelements;


    int16_t element_idx;

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


typedef struct {
    uint64_t v[4];
} __attribute__((packed)) IOReportElementValues;

typedef struct {
    uint64_t provider_id;
    uint64_t channel_id;
    IOReportChannelType channel_type;
    uint64_t timestamp;
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
    void (*destr1)(IOService*); void (*destr0)(IOService*); void (*release_int)(IOService*, int freeWhen); int (*getRetainCount)(IOService*); void (*retain)(IOService*); void (*release)(IOService*); bool (*serialize_)(IOService*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(IOService*); bool (*isEqualTo_)(IOService*, const OSMetaClassBase *anObject); void (*taggedRetain_)(IOService*, const void *tag); void (*taggedRelease_)(IOService*, const void *tag); void (*taggedRelease__int)(IOService*, const void *tag, int freeWhen); bool (*init)(IOService*); void (*free)(IOService*); OSObject * (*copyProperty_cstring_plane_)(IOService*, const char *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_string_plane_)(IOService*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_symbol_plane_)(IOService*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); IORegistryEntry * (*copyParentEntry_)(IOService*, const IORegistryPlane *); IORegistryEntry * (*copyChildEntry_)(IOService*, const IORegistryPlane *); IOReturn (*runPropertyAction______)(IOService*, IOService_Action *, OSObject *, void *, void *, void *, void *); bool (*init_withDictionary)(IOService*, OSDictionary *); void (*setPropertyTable_)(IOService*, OSDictionary *); bool (*setProperty_symbol_)(IOService*, const OSSymbol *, OSObject *); bool (*setProperty_string_)(IOService*, const OSString *, OSObject *); bool (*setProperty_cstring_)(IOService*, const char *, OSObject *); bool (*setProperty_cstring_cstring)(IOService*, const char *, const char *); bool (*setProperty_cstring_bool)(IOService*, const char *, bool); bool (*setProperty_cstring_val_bits)(IOService*, const char *, unsigned long long, unsigned int); bool (*setProperty_cstring_bytes_)(IOService*, const char *, void *, unsigned int); OSObject * (*getProperty_symbol)(IOService*, const OSSymbol *); OSObject * (*getProperty_string)(IOService*, const OSString *); OSObject * (*getProperty_cstring)(IOService*, const char *); OSObject * (*getProperty_symbol__)(IOService*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_string__)(IOService*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_cstring__)(IOService*, const char *, const IORegistryPlane *, IOOptionBits); void (*removeProperty_symbol)(IOService*, const OSSymbol *); void (*removeProperty_string)(IOService*, const OSString *); void (*removeProperty_cstring)(IOService*, const char *); OSObject * (*copyProperty_symbol)(IOService*, const OSSymbol *); OSObject * (*copyProperty_string)(IOService*, const OSString *); OSObject * (*copyProperty_cstring)(IOService*, const char *); OSDictionary * (*dictionaryWithProperties)(IOService*); bool (*serializeProperties_)(IOService*, OSSerialize *); IOReturn (*setProperties_object)(IOService*, OSObject *); OSIterator * (*getParentIterator_)(IOService*, IORegistryPlane *); void (*applyToParents___)(IOService*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getParentEntry_)(IOService*, const IORegistryPlane *); OSIterator * (*getChildIterator_)(IOService*, IORegistryPlane *); void (*applyToChildren___)(IOService*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getChildEntry_)(IOService*, const IORegistryPlane *); bool (*isChild___)(IOService*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*isParent___)(IOService*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*inPlane_)(IOService*, IORegistryPlane *); unsigned int (*getDepth_)(IOService*, IORegistryPlane *); bool (*attachToParent__)(IOService*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromParent__)(IOService*, IORegistryEntry *, const IORegistryPlane *); bool (*attachToChild__)(IOService*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromChild__)(IOService*, IORegistryEntry *, const IORegistryPlane *); void (*detachAbove_)(IOService*, const IORegistryPlane *); void (*detachAll_)(IOService*, const IORegistryPlane *); const char * (*getName_)(IOService*, const IORegistryPlane *); const OSSymbol * (*copyName_)(IOService*, const IORegistryPlane *); bool (*compareNames_object_)(IOService*, OSObject *, OSString **); bool (*compareName_string_)(IOService*, OSString *, OSString **); void (*setName_symbol_)(IOService*, OSSymbol *, IORegistryPlane *); void (*setName_cstring_)(IOService*, const char *, IORegistryPlane *); const char * (*getLocation_)(IOService*, IORegistryPlane *); const OSSymbol * (*copyLocation_)(IOService*, IORegistryPlane *); void (*setLocation_symbol_)(IOService*, OSSymbol *, IORegistryPlane *); void (*setLocation_cstring_)(IOService*, const char *, IORegistryPlane *); bool (*getPath___)(IOService*, char *, int *, IORegistryPlane *); bool (*getPathComponent___)(IOService*, char *, int *, IORegistryPlane *); IORegistryEntry * (*childFromPath____)(IOService*, const char *, IORegistryPlane *, char *, int *); const char * (*init_entry_)(IOService*, IORegistryEntry *, IORegistryPlane *); bool (*requestTerminate__)(IOService*, IOService *, IOOptionBits); bool (*willTerminate__)(IOService*, IOService *, IOOptionBits); bool (*didTerminate__)(IOService*, IOService *, IOOptionBits, bool *); int32_t (*nextIdleTimeout__)(IOService*, uint64_t, uint64_t, unsigned int); void (*systemWillShutdown_)(IOService*, IOOptionBits); IOService * (*copyClientWithCategory_)(IOService*, const OSSymbol *); IOReturn (*configureReport____)(IOService*, IOReportChannelList *, IOReportConfigureAction, void *, void *); void (*updateReport____)(IOService*, IOReportChannelList *, IOReportUpdateAction, void *, void *); IOOptionBits (*getState)(IOService*); void (*registerService_)(IOService*, IOOptionBits); IOService * (*probe__)(IOService*, IOService *, int32_t *); bool (*start_)(IOService*, IOService *); bool (*stop_)(IOService*, IOService *); bool (*open__)(IOService*, IOService *, IOOptionBits, void *); void (*close_)(IOService*, IOService *, IOOptionBits); bool (*isOpen_)(IOService*, const IOService *); bool (*handleOpen___)(IOService*, IOService *, IOOptionBits, void *); void (*handleClose__)(IOService*, IOService *, IOOptionBits); bool (*handleIsOpen_)(IOService*, const IOService *); bool (*terminate_)(IOService*, IOOptionBits); bool (*finalize_)(IOService*, IOOptionBits); bool (*lockForArbitration_)(IOService*, bool); void (*unlockForArbitration)(IOService*); bool (*terminateClient__)(IOService*, IOService *, IOOptionBits); uint32_t (*getBusyState)(IOService*); void (*adjustBusy_)(IOService*, int32_t); bool (*matchPropertyTable__score)(IOService*, OSDictionary *, int32_t *); bool (*matchPropertyTable_)(IOService*, OSDictionary *); IOService * (*matchLocation_)(IOService*, IOService *); bool (*addNeededResource_)(IOService*, const char *); bool (*compareProperty__cstring)(IOService*, OSDictionary *, const char *); bool (*compareProperty__string)(IOService*, OSDictionary *, const OSString *); bool (*compareProperties__collection)(IOService*, OSDictionary *, OSCollection *); bool (*attach_)(IOService*, IOService *); void (*detach_)(IOService*, IOService *); IOService * (*getProvider)(IOService*); IOWorkLoop * (*getWorkLoop)(IOService*); OSIterator * (*getProviderIterator)(IOService*); OSIterator * (*getOpenProviderIterator)(IOService*); IOService * (*getClient)(IOService*); OSIterator * (*getClientIterator)(IOService*); OSIterator * (*getOpenClientIterator)(IOService*); IOReturn (*callPlatformFunction_symbol_____)(IOService*, const OSSymbol *, bool, void *, void *, void *, void *); IOReturn (*callPlatformFunction_cstring_____)(IOService*, const char *, bool, void *, void *, void *, void *); IOReturn (*getResources)(IOService*); IOItemCount (*getDeviceMemoryCount)(IOService*); IODeviceMemory * (*getDeviceMemoryWithIndex_)(IOService*, unsigned int); IOMemoryMap * (*mapDeviceMemoryWithIndex_)(IOService*, unsigned int, unsigned int); OSArray * (*getDeviceMemory)(IOService*); void (*setDeviceMemory_)(IOService*, OSArray *); IOReturn (*registerInterrupt___)(IOService*, int, OSObject *, IOInterruptAction, void *); IOReturn (*unregisterInterrupt_)(IOService*, int); IOReturn (*getInterruptType__)(IOService*, int, int *); IOReturn (*enableInterrupt_)(IOService*, int); IOReturn (*disableInterrupt_)(IOService*, int); IOReturn (*causeInterrupt_)(IOService*, int); IOReturn (*requestProbe_)(IOService*, IOOptionBits); IOReturn (*message___)(IOService*, uint32_t, IOService *, void *); IOReturn (*messageClient____)(IOService*, uint32_t, OSObject *, void *, vm_size_t); IOReturn (*messageClients___)(IOService*, uint32_t, void *, vm_size_t); IONotifier * (*registerInterest____)(IOService*, const OSSymbol *, IOServiceInterestHandler, void *, void *); void (*applyToProviders__)(IOService*, IOServiceApplierFunction, void *); void (*applyToClients__)(IOService*, IOServiceApplierFunction, void *); void (*applyToInterested__)(IOService*, const OSSymbol *, OSObjectApplierFunction, void *); IOReturn (*acknowledgeNotification__)(IOService*, void *, IOOptionBits); IOReturn (*newUserClient___properties__)(IOService*, task *, void *, uint32_t, OSDictionary *, IOUserClient **); IOReturn (*newUserClient____)(IOService*, task *, void *, uint32_t, IOUserClient **); const char * (*stringFromReturn_)(IOService*, IOReturn); int (*errnoFromReturn_)(IOService*, IOReturn); void (*PMinit)(IOService*); void (*PMstop)(IOService*); void (*joinPMtree_)(IOService*, IOService *); IOReturn (*registerPowerDriver___)(IOService*, IOService *, IOPMPowerState *, unsigned long); IOReturn (*requestPowerDomainState___)(IOService*, IOPMPowerFlags, IOPowerConnection *, unsigned long); bool (*activityTickle__)(IOService*, unsigned long, unsigned long); IOReturn (*setAggressiveness__)(IOService*, unsigned long, unsigned long); IOReturn (*getAggressiveness__)(IOService*, unsigned long, unsigned long *); IOReturn (*addPowerChild_)(IOService*, IOService *); IOReturn (*removePowerChild_)(IOService*, IOPowerConnection *); IOReturn (*setIdleTimerPeriod_)(IOService*, unsigned long); IOReturn (*setPowerState__)(IOService*, unsigned long, IOService *); unsigned long (*maxCapabilityForDomainState_)(IOService*, IOPMPowerFlags); unsigned long (*initialPowerStateForDomainState_)(IOService*, IOPMPowerFlags); unsigned long (*powerStateForDomainState_)(IOService*, IOPMPowerFlags); IOReturn (*powerStateWillChangeTo___)(IOService*, IOPMPowerFlags, unsigned long, IOService *); IOReturn (*powerStateDidChangeTo___)(IOService*, IOPMPowerFlags, unsigned long, IOService *); bool (*askChangeDown_)(IOService*, unsigned long); bool (*tellChangeDown_)(IOService*, unsigned long); void (*tellNoChangeDown_)(IOService*, unsigned long); void (*tellChangeUp_)(IOService*, unsigned long); IOReturn (*allowPowerChange_)(IOService*, unsigned long); IOReturn (*cancelPowerChange_)(IOService*, unsigned long); void (*powerChangeDone_)(IOService*, unsigned long);


};

struct ipc_port;
typedef uint64_t io_user_reference_t;
typedef uint32_t UInt32;
struct semaphore;
typedef struct semaphore *semaphore_t;
typedef IOMemoryDescriptor OSObject;

struct VTB_IOUserClient {
    void (*destr1)(IOUserClient*); void (*destr0)(IOUserClient*); void (*release_int)(IOUserClient*, int freeWhen); int (*getRetainCount)(IOUserClient*); void (*retain)(IOUserClient*); void (*release)(IOUserClient*); bool (*serialize_)(IOUserClient*, OSSerialize *serializer); const OSMetaClass* (*getMetaClass)(IOUserClient*); bool (*isEqualTo_)(IOUserClient*, const OSMetaClassBase *anObject); void (*taggedRetain_)(IOUserClient*, const void *tag); void (*taggedRelease_)(IOUserClient*, const void *tag); void (*taggedRelease__int)(IOUserClient*, const void *tag, int freeWhen); bool (*init)(IOUserClient*); void (*free)(IOUserClient*); OSObject * (*copyProperty_cstring_plane_)(IOUserClient*, const char *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_string_plane_)(IOUserClient*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*copyProperty_symbol_plane_)(IOUserClient*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); IORegistryEntry * (*copyParentEntry_)(IOUserClient*, const IORegistryPlane *); IORegistryEntry * (*copyChildEntry_)(IOUserClient*, const IORegistryPlane *); IOReturn (*runPropertyAction______)(IOUserClient*, IOService_Action *, OSObject *, void *, void *, void *, void *); bool (*init_withDictionary)(IOUserClient*, OSDictionary *); void (*setPropertyTable_)(IOUserClient*, OSDictionary *); bool (*setProperty_symbol_)(IOUserClient*, const OSSymbol *, OSObject *); bool (*setProperty_string_)(IOUserClient*, const OSString *, OSObject *); bool (*setProperty_cstring_)(IOUserClient*, const char *, OSObject *); bool (*setProperty_cstring_cstring)(IOUserClient*, const char *, const char *); bool (*setProperty_cstring_bool)(IOUserClient*, const char *, bool); bool (*setProperty_cstring_val_bits)(IOUserClient*, const char *, unsigned long long, unsigned int); bool (*setProperty_cstring_bytes_)(IOUserClient*, const char *, void *, unsigned int); OSObject * (*getProperty_symbol)(IOUserClient*, const OSSymbol *); OSObject * (*getProperty_string)(IOUserClient*, const OSString *); OSObject * (*getProperty_cstring)(IOUserClient*, const char *); OSObject * (*getProperty_symbol__)(IOUserClient*, const OSSymbol *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_string__)(IOUserClient*, const OSString *, const IORegistryPlane *, IOOptionBits); OSObject * (*getProperty_cstring__)(IOUserClient*, const char *, const IORegistryPlane *, IOOptionBits); void (*removeProperty_symbol)(IOUserClient*, const OSSymbol *); void (*removeProperty_string)(IOUserClient*, const OSString *); void (*removeProperty_cstring)(IOUserClient*, const char *); OSObject * (*copyProperty_symbol)(IOUserClient*, const OSSymbol *); OSObject * (*copyProperty_string)(IOUserClient*, const OSString *); OSObject * (*copyProperty_cstring)(IOUserClient*, const char *); OSDictionary * (*dictionaryWithProperties)(IOUserClient*); bool (*serializeProperties_)(IOUserClient*, OSSerialize *); IOReturn (*setProperties_object)(IOUserClient*, OSObject *); OSIterator * (*getParentIterator_)(IOUserClient*, IORegistryPlane *); void (*applyToParents___)(IOUserClient*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getParentEntry_)(IOUserClient*, const IORegistryPlane *); OSIterator * (*getChildIterator_)(IOUserClient*, IORegistryPlane *); void (*applyToChildren___)(IOUserClient*, IORegistryEntryApplierFunction *, void *, IORegistryPlane *); IORegistryEntry * (*getChildEntry_)(IOUserClient*, const IORegistryPlane *); bool (*isChild___)(IOUserClient*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*isParent___)(IOUserClient*, IORegistryEntry *, IORegistryPlane const *, bool); bool (*inPlane_)(IOUserClient*, IORegistryPlane *); unsigned int (*getDepth_)(IOUserClient*, IORegistryPlane *); bool (*attachToParent__)(IOUserClient*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromParent__)(IOUserClient*, IORegistryEntry *, const IORegistryPlane *); bool (*attachToChild__)(IOUserClient*, IORegistryEntry *, const IORegistryPlane *); void (*detachFromChild__)(IOUserClient*, IORegistryEntry *, const IORegistryPlane *); void (*detachAbove_)(IOUserClient*, const IORegistryPlane *); void (*detachAll_)(IOUserClient*, const IORegistryPlane *); const char * (*getName_)(IOUserClient*, const IORegistryPlane *); const OSSymbol * (*copyName_)(IOUserClient*, const IORegistryPlane *); bool (*compareNames_object_)(IOUserClient*, OSObject *, OSString **); bool (*compareName_string_)(IOUserClient*, OSString *, OSString **); void (*setName_symbol_)(IOUserClient*, OSSymbol *, IORegistryPlane *); void (*setName_cstring_)(IOUserClient*, const char *, IORegistryPlane *); const char * (*getLocation_)(IOUserClient*, IORegistryPlane *); const OSSymbol * (*copyLocation_)(IOUserClient*, IORegistryPlane *); void (*setLocation_symbol_)(IOUserClient*, OSSymbol *, IORegistryPlane *); void (*setLocation_cstring_)(IOUserClient*, const char *, IORegistryPlane *); bool (*getPath___)(IOUserClient*, char *, int *, IORegistryPlane *); bool (*getPathComponent___)(IOUserClient*, char *, int *, IORegistryPlane *); IORegistryEntry * (*childFromPath____)(IOUserClient*, const char *, IORegistryPlane *, char *, int *); const char * (*init_entry_)(IOUserClient*, IORegistryEntry *, IORegistryPlane *); bool (*requestTerminate__)(IOUserClient*, IOService *, IOOptionBits); bool (*willTerminate__)(IOUserClient*, IOService *, IOOptionBits); bool (*didTerminate__)(IOUserClient*, IOService *, IOOptionBits, bool *); int32_t (*nextIdleTimeout__)(IOUserClient*, uint64_t, uint64_t, unsigned int); void (*systemWillShutdown_)(IOUserClient*, IOOptionBits); IOService * (*copyClientWithCategory_)(IOUserClient*, const OSSymbol *); IOReturn (*configureReport____)(IOUserClient*, IOReportChannelList *, IOReportConfigureAction, void *, void *); void (*updateReport____)(IOUserClient*, IOReportChannelList *, IOReportUpdateAction, void *, void *); IOOptionBits (*getState)(IOUserClient*); void (*registerService_)(IOUserClient*, IOOptionBits); IOService * (*probe__)(IOUserClient*, IOService *, int32_t *); bool (*start_)(IOUserClient*, IOService *); bool (*stop_)(IOUserClient*, IOService *); bool (*open__)(IOUserClient*, IOService *, IOOptionBits, void *); void (*close_)(IOUserClient*, IOService *, IOOptionBits); bool (*isOpen_)(IOUserClient*, const IOService *); bool (*handleOpen___)(IOUserClient*, IOService *, IOOptionBits, void *); void (*handleClose__)(IOUserClient*, IOService *, IOOptionBits); bool (*handleIsOpen_)(IOUserClient*, const IOService *); bool (*terminate_)(IOUserClient*, IOOptionBits); bool (*finalize_)(IOUserClient*, IOOptionBits); bool (*lockForArbitration_)(IOUserClient*, bool); void (*unlockForArbitration)(IOUserClient*); bool (*terminateClient__)(IOUserClient*, IOService *, IOOptionBits); uint32_t (*getBusyState)(IOUserClient*); void (*adjustBusy_)(IOUserClient*, int32_t); bool (*matchPropertyTable__score)(IOUserClient*, OSDictionary *, int32_t *); bool (*matchPropertyTable_)(IOUserClient*, OSDictionary *); IOService * (*matchLocation_)(IOUserClient*, IOService *); bool (*addNeededResource_)(IOUserClient*, const char *); bool (*compareProperty__cstring)(IOUserClient*, OSDictionary *, const char *); bool (*compareProperty__string)(IOUserClient*, OSDictionary *, const OSString *); bool (*compareProperties__collection)(IOUserClient*, OSDictionary *, OSCollection *); bool (*attach_)(IOUserClient*, IOService *); void (*detach_)(IOUserClient*, IOService *); IOService * (*getProvider)(IOUserClient*); IOWorkLoop * (*getWorkLoop)(IOUserClient*); OSIterator * (*getProviderIterator)(IOUserClient*); OSIterator * (*getOpenProviderIterator)(IOUserClient*); IOService * (*getClient)(IOUserClient*); OSIterator * (*getClientIterator)(IOUserClient*); OSIterator * (*getOpenClientIterator)(IOUserClient*); IOReturn (*callPlatformFunction_symbol_____)(IOUserClient*, const OSSymbol *, bool, void *, void *, void *, void *); IOReturn (*callPlatformFunction_cstring_____)(IOUserClient*, const char *, bool, void *, void *, void *, void *); IOReturn (*getResources)(IOUserClient*); IOItemCount (*getDeviceMemoryCount)(IOUserClient*); IODeviceMemory * (*getDeviceMemoryWithIndex_)(IOUserClient*, unsigned int); IOMemoryMap * (*mapDeviceMemoryWithIndex_)(IOUserClient*, unsigned int, unsigned int); OSArray * (*getDeviceMemory)(IOUserClient*); void (*setDeviceMemory_)(IOUserClient*, OSArray *); IOReturn (*registerInterrupt___)(IOUserClient*, int, OSObject *, IOInterruptAction, void *); IOReturn (*unregisterInterrupt_)(IOUserClient*, int); IOReturn (*getInterruptType__)(IOUserClient*, int, int *); IOReturn (*enableInterrupt_)(IOUserClient*, int); IOReturn (*disableInterrupt_)(IOUserClient*, int); IOReturn (*causeInterrupt_)(IOUserClient*, int); IOReturn (*requestProbe_)(IOUserClient*, IOOptionBits); IOReturn (*message___)(IOUserClient*, uint32_t, IOService *, void *); IOReturn (*messageClient____)(IOUserClient*, uint32_t, OSObject *, void *, vm_size_t); IOReturn (*messageClients___)(IOUserClient*, uint32_t, void *, vm_size_t); IONotifier * (*registerInterest____)(IOUserClient*, const OSSymbol *, IOServiceInterestHandler, void *, void *); void (*applyToProviders__)(IOUserClient*, IOServiceApplierFunction, void *); void (*applyToClients__)(IOUserClient*, IOServiceApplierFunction, void *); void (*applyToInterested__)(IOUserClient*, const OSSymbol *, OSObjectApplierFunction, void *); IOReturn (*acknowledgeNotification__)(IOUserClient*, void *, IOOptionBits); IOReturn (*newUserClient___properties__)(IOUserClient*, task *, void *, uint32_t, OSDictionary *, IOUserClient **); IOReturn (*newUserClient____)(IOUserClient*, task *, void *, uint32_t, IOUserClient **); const char * (*stringFromReturn_)(IOUserClient*, IOReturn); int (*errnoFromReturn_)(IOUserClient*, IOReturn); void (*PMinit)(IOUserClient*); void (*PMstop)(IOUserClient*); void (*joinPMtree_)(IOUserClient*, IOService *); IOReturn (*registerPowerDriver___)(IOUserClient*, IOService *, IOPMPowerState *, unsigned long); IOReturn (*requestPowerDomainState___)(IOUserClient*, IOPMPowerFlags, IOPowerConnection *, unsigned long); bool (*activityTickle__)(IOUserClient*, unsigned long, unsigned long); IOReturn (*setAggressiveness__)(IOUserClient*, unsigned long, unsigned long); IOReturn (*getAggressiveness__)(IOUserClient*, unsigned long, unsigned long *); IOReturn (*addPowerChild_)(IOUserClient*, IOService *); IOReturn (*removePowerChild_)(IOUserClient*, IOPowerConnection *); IOReturn (*setIdleTimerPeriod_)(IOUserClient*, unsigned long); IOReturn (*setPowerState__)(IOUserClient*, unsigned long, IOService *); unsigned long (*maxCapabilityForDomainState_)(IOUserClient*, IOPMPowerFlags); unsigned long (*initialPowerStateForDomainState_)(IOUserClient*, IOPMPowerFlags); unsigned long (*powerStateForDomainState_)(IOUserClient*, IOPMPowerFlags); IOReturn (*powerStateWillChangeTo___)(IOUserClient*, IOPMPowerFlags, unsigned long, IOService *); IOReturn (*powerStateDidChangeTo___)(IOUserClient*, IOPMPowerFlags, unsigned long, IOService *); bool (*askChangeDown_)(IOUserClient*, unsigned long); bool (*tellChangeDown_)(IOUserClient*, unsigned long); void (*tellNoChangeDown_)(IOUserClient*, unsigned long); void (*tellChangeUp_)(IOUserClient*, unsigned long); IOReturn (*allowPowerChange_)(IOUserClient*, unsigned long); IOReturn (*cancelPowerChange_)(IOUserClient*, unsigned long); void (*powerChangeDone_)(IOUserClient*, unsigned long); IOReturn (*externalMethod)(IOUserClient*, uint32_t selector, IOExternalMethodArguments *arguments, IOExternalMethodDispatch *dispatch, OSObject *target, void *reference); IOReturn (*registerNotificationPort_refCon)(IOUserClient*, ipc_port *port, UInt32 type, io_user_reference_t refCon); bool (*initWithTask_properties)(IOUserClient*, task_t owningTask, void *securityToken, UInt32 type, OSDictionary *properties); bool (*initWithTask)(IOUserClient*, task_t owningTask, void *securityToken, UInt32 type); IOReturn (*clientClose)(IOUserClient*); IOReturn (*clientDied)(IOUserClient*); IOService * (*getService)(IOUserClient*); IOReturn (*registerNotificationPort_uint32)(IOUserClient*, mach_port_t, UInt32 type, UInt32 refCon); IOReturn (*getNotificationSemaphore)(IOUserClient*, UInt32 notification_type, semaphore_t *semaphore); IOReturn (*connectClient)(IOUserClient*, IOUserClient *); IOReturn (*clientMemoryForType)(IOUserClient*, UInt32 type, IOOptionBits *options, IOMemoryDescriptor **memory); IOReturn (*exportObjectToClient)(IOUserClient*, task_t task, OSObject *obj, OSObject **clientObj); IOExternalMethod * (*getExternalMethodForIndex)(IOUserClient*, UInt32 index); IOExternalAsyncMethod * (*getExternalAsyncMethodForIndex)(IOUserClient*, UInt32 index); IOExternalMethod * (*getTargetAndMethodForIndex)(IOUserClient*, IOService **targetP, UInt32 index); IOExternalAsyncMethod * (*getAsyncTargetAndMethodForIndex)(IOUserClient*, IOService **targetP, UInt32 index); IOExternalTrap * (*getExternalTrapForIndex)(IOUserClient*, UInt32 index); IOExternalTrap * (*getTargetAndTrapForIndex)(IOUserClient*, IOService **targetP, UInt32 index);


};
