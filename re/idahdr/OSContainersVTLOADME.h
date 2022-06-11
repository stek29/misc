

typedef void OSMetaClassBase;



typedef OSMetaClassBase OSMetaClass;


typedef void OSSerialize;

typedef OSMetaClass OSCollection;








struct VTB_OSMetaClassBase;
 typedef struct { struct VTB_OSMetaClassBase *vtab;
 } OSMetaClassBase;

struct VTB_OSObject;
 typedef struct { struct VTB_OSObject *vtab;
 } OSObject;

struct VTB_OSString;
 typedef struct { struct VTB_OSString *vtab;
 } OSString;

struct VTB_OSSymbol;
 typedef struct { struct VTB_OSSymbol *vtab;
 } OSSymbol;

struct VTB_OSBoolean;
 typedef struct { struct VTB_OSBoolean *vtab;
 } OSBoolean;

struct VTB_OSData;
 typedef struct { struct VTB_OSData *vtab;
 } OSData;

struct VTB_OSDictionary;
 typedef struct { struct VTB_OSDictionary *vtab;
 } OSDictionary;

struct VTB_OSArray;
 typedef struct { struct VTB_OSArray *vtab;
 } OSArray;

struct VTB_OSSet;
 typedef struct { struct VTB_OSSet *vtab;
 } OSSet;

struct VTB_OSOrderedSet;
 typedef struct { struct VTB_OSOrderedSet *vtab;
 } OSOrderedSet;

struct VTB_OSNumber;
 typedef struct { struct VTB_OSNumber *vtab;
 } OSNumber;

struct VTB_OSIterator;
 typedef struct { struct VTB_OSIterator *vtab;
 } OSIterator;

struct VTB_OSCollectionIterator;
 typedef struct { struct VTB_OSCollectionIterator *vtab;
 } OSCollectionIterator;








struct VTB_OSMetaClassBase {
 void (*destr1)(OSMetaClassBase*);
  void (*destr0)(OSMetaClassBase*);
  void (*release_int)(OSMetaClassBase*, int freeWhen);
  int (*getRetainCount)(OSMetaClassBase*);
  void (*retain)(OSMetaClassBase*);
  void (*release)(OSMetaClassBase*);
  bool (*serialize_)(OSMetaClassBase*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSMetaClassBase*);
  bool (*isEqualTo_)(OSMetaClassBase*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSMetaClassBase*, const void *tag);
  void (*taggedRelease_)(OSMetaClassBase*, const void *tag);
  void (*taggedRelease__int)(OSMetaClassBase*, const void *tag, int freeWhen);
 

};


struct VTB_OSObject {






 void (*destr1)(OSObject*);
  void (*destr0)(OSObject*);
  void (*release_int)(OSObject*, int freeWhen);
  int (*getRetainCount)(OSObject*);
  void (*retain)(OSObject*);
  void (*release)(OSObject*);
  bool (*serialize_)(OSObject*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSObject*);
  bool (*isEqualTo_)(OSObject*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSObject*, const void *tag);
  void (*taggedRelease_)(OSObject*, const void *tag);
  void (*taggedRelease__int)(OSObject*, const void *tag, int freeWhen);
  bool (*init)(OSObject*);
  void (*free)(OSObject*);
 

};

struct VTB_OSDictionary {
 void (*destr1)(OSDictionary*);
  void (*destr0)(OSDictionary*);
  void (*release_int)(OSDictionary*, int freeWhen);
  int (*getRetainCount)(OSDictionary*);
  void (*retain)(OSDictionary*);
  void (*release)(OSDictionary*);
  bool (*serialize_)(OSDictionary*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSDictionary*);
  bool (*isEqualTo_)(OSDictionary*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSDictionary*, const void *tag);
  void (*taggedRelease_)(OSDictionary*, const void *tag);
  void (*taggedRelease__int)(OSDictionary*, const void *tag, int freeWhen);
  bool (*init)(OSDictionary*);
  void (*free)(OSDictionary*);
  int (*iteratorSize)(OSDictionary*);
  bool (*initIterator_)(OSDictionary*, void *iterator);
  bool (*getNextObjectForIterator__)(OSDictionary*, void *iterator, OSObject **nextObject);
  unsigned int (*getCount)(OSDictionary*);
  unsigned int (*getCapacity)(OSDictionary*);
  unsigned int (*getCapacityIncrement)(OSDictionary*);
  unsigned int (*setCapacityIncrement_)(OSDictionary*, unsigned int increment);
  unsigned int (*ensureCapacity_)(OSDictionary*, unsigned int newCapacity);
  void (*flushCollection)(OSDictionary*);
  unsigned (*setOptions___)(OSDictionary*, unsigned options, unsigned mask, void* context);
  OSDictionary * (*copyCollection_)(OSDictionary*, OSDictionary* cycleDict);
  bool (*initWithCapacity_)(OSDictionary*, unsigned int);
  bool (*initWithObjects__OSSymbol__)(OSDictionary*, const OSObject * objects[], const OSSymbol * keys[], unsigned int count, unsigned int capacity);
  bool (*initWithObjects__OSString__)(OSDictionary*, const OSObject * objects[], const OSString * keys[], unsigned int count, unsigned int capacity);
  bool (*initWithDictionary__)(OSDictionary*, const OSDictionary* dict, unsigned int capacity);
  bool (*setObject_OSSymbol_)(OSDictionary*, const OSSymbol *aKey, const OSMetaClassBase *anObject);
  bool (*setObject_OSString_)(OSDictionary*, const OSString *aKey, const OSMetaClassBase *anObject);
  bool (*setObject_cstring_)(OSDictionary*, const char *aKey, const OSMetaClassBase *anObject);
  void (*removeObject_OSSymbol)(OSDictionary*, const OSSymbol *aKey);
  void (*removeObject_OSString)(OSDictionary*, const OSString *aKey);
  void (*removeObject_cstring)(OSDictionary*, const char *aKey);
  bool (*merge_)(OSDictionary*, OSDictionary* aDictionary);
  OSObject* (*getObject_OSSymbol)(OSDictionary*, const OSSymbol *aKey);
  OSObject* (*getObject_OSString)(OSDictionary*, const OSString *aKey);
  OSObject* (*getObject_cstring)(OSDictionary*, const char *aKey);
  bool (*isEqualTo_dict)(OSDictionary*, const OSDictionary* aDictionary);
  bool (*isEqualTo_dict_keys)(OSDictionary*, const OSDictionary* aDictionary, OSCollection* keys);
 

};


struct VTB_OSArray {
 void (*destr1)(OSArray*);
  void (*destr0)(OSArray*);
  void (*release_int)(OSArray*, int freeWhen);
  int (*getRetainCount)(OSArray*);
  void (*retain)(OSArray*);
  void (*release)(OSArray*);
  bool (*serialize_)(OSArray*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSArray*);
  bool (*isEqualTo_)(OSArray*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSArray*, const void *tag);
  void (*taggedRelease_)(OSArray*, const void *tag);
  void (*taggedRelease__int)(OSArray*, const void *tag, int freeWhen);
  bool (*init)(OSArray*);
  void (*free)(OSArray*);
  int (*iteratorSize)(OSArray*);
  bool (*initIterator_)(OSArray*, void *iterator);
  bool (*getNextObjectForIterator__)(OSArray*, void *iterator, OSObject **nextObject);
  unsigned int (*getCount)(OSArray*);
  unsigned int (*getCapacity)(OSArray*);
  unsigned int (*getCapacityIncrement)(OSArray*);
  unsigned int (*setCapacityIncrement_)(OSArray*, unsigned int increment);
  unsigned int (*ensureCapacity_)(OSArray*, unsigned int newCapacity);
  void (*flushCollection)(OSArray*);
  unsigned (*setOptions___)(OSArray*, unsigned options, unsigned mask, void* context);
  OSArray * (*copyCollection_)(OSArray*, OSDictionary* cycleDict);
  bool (*initWithCapacity_)(OSArray*, unsigned int);
  bool (*initWithObjects___)(OSArray*, const OSObject *objects[], unsigned int count, unsigned int capacity);
  bool (*initWithArray_)(OSArray*, const OSArray* anArray, unsigned capacity);
  bool (*setObject_)(OSArray*, OSMetaClassBase* anObject);
  bool (*setObject_int_)(OSArray*, unsigned int index, OSMetaClassBase* anObject);
  bool (*merge_)(OSArray*, const OSArray* anArray);
  bool (*replaceObject_int_)(OSArray*, unsigned int index, OSMetaClassBase* anObject);
  void (*removeObject_)(OSArray*, unsigned int index);
  bool (*isEqualTo_array)(OSArray*, const OSArray* anArray);
  OSObject* (*getObject_)(OSArray*, unsigned int index);
  OSObject* (*getLastObject)(OSArray*);
  unsigned int (*getNextIndexOfObject__)(OSArray*, const OSMetaClassBase* anObject, unsigned int index);
 

};


struct VTB_OSSet {
 void (*destr1)(OSSet*);
  void (*destr0)(OSSet*);
  void (*release_int)(OSSet*, int freeWhen);
  int (*getRetainCount)(OSSet*);
  void (*retain)(OSSet*);
  void (*release)(OSSet*);
  bool (*serialize_)(OSSet*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSSet*);
  bool (*isEqualTo_)(OSSet*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSSet*, const void *tag);
  void (*taggedRelease_)(OSSet*, const void *tag);
  void (*taggedRelease__int)(OSSet*, const void *tag, int freeWhen);
  bool (*init)(OSSet*);
  void (*free)(OSSet*);
  int (*iteratorSize)(OSSet*);
  bool (*initIterator_)(OSSet*, void *iterator);
  bool (*getNextObjectForIterator__)(OSSet*, void *iterator, OSObject **nextObject);
  unsigned int (*getCount)(OSSet*);
  unsigned int (*getCapacity)(OSSet*);
  unsigned int (*getCapacityIncrement)(OSSet*);
  unsigned int (*setCapacityIncrement_)(OSSet*, unsigned int increment);
  unsigned int (*ensureCapacity_)(OSSet*, unsigned int newCapacity);
  void (*flushCollection)(OSSet*);
  unsigned (*setOptions___)(OSSet*, unsigned options, unsigned mask, void* context);
  OSSet * (*copyCollection_)(OSSet*, OSDictionary* cycleDict);
  bool (*initWithCapacity_)(OSSet*, unsigned int);
  bool (*initWithObjects___)(OSSet*, const OSObject *objects[], unsigned int count, unsigned int capacity);
  bool (*initWithArray_)(OSSet*, const OSArray* anArray, unsigned capacity);
  bool (*initWithSet_)(OSSet*, const OSSet* aSet, unsigned capacity);
  bool (*setObject_)(OSSet*, OSMetaClassBase* anObject);
  bool (*merge_array)(OSSet*, const OSArray* anArray);
  bool (*merge_set)(OSSet*, const OSSet* aSet);
  void (*removeObject_)(OSSet*, const OSMetaClassBase* anObject);
  bool (*containsObject_)(OSSet*, const OSMetaClassBase* anObject);
  bool (*member_)(OSSet*, const OSMetaClassBase* anObject);
  OSObject* (*getAnyObject)(OSSet*);
  bool (*isEqualTo_set)(OSSet*, const OSSet* aSet);
 

};



typedef int (*OSOrderFunction)(const OSMetaClassBase * obj1, const OSMetaClassBase * obj2, void * context);

struct VTB_OSOrderedSet {
 void (*destr1)(OSOrderedSet*);
  void (*destr0)(OSOrderedSet*);
  void (*release_int)(OSOrderedSet*, int freeWhen);
  int (*getRetainCount)(OSOrderedSet*);
  void (*retain)(OSOrderedSet*);
  void (*release)(OSOrderedSet*);
  bool (*serialize_)(OSOrderedSet*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSOrderedSet*);
  bool (*isEqualTo_)(OSOrderedSet*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSOrderedSet*, const void *tag);
  void (*taggedRelease_)(OSOrderedSet*, const void *tag);
  void (*taggedRelease__int)(OSOrderedSet*, const void *tag, int freeWhen);
  bool (*init)(OSOrderedSet*);
  void (*free)(OSOrderedSet*);
  int (*iteratorSize)(OSOrderedSet*);
  bool (*initIterator_)(OSOrderedSet*, void *iterator);
  bool (*getNextObjectForIterator__)(OSOrderedSet*, void *iterator, OSObject **nextObject);
  unsigned int (*getCount)(OSOrderedSet*);
  unsigned int (*getCapacity)(OSOrderedSet*);
  unsigned int (*getCapacityIncrement)(OSOrderedSet*);
  unsigned int (*setCapacityIncrement_)(OSOrderedSet*, unsigned int increment);
  unsigned int (*ensureCapacity_)(OSOrderedSet*, unsigned int newCapacity);
  void (*flushCollection)(OSOrderedSet*);
  unsigned (*setOptions___)(OSOrderedSet*, unsigned options, unsigned mask, void* context);
  OSOrderedSet * (*copyCollection_)(OSOrderedSet*, OSDictionary* cycleDict);
  bool (*initWithCapacity___)(OSOrderedSet*, unsigned int capacity, OSOrderFunction orderFunc, void *orderContext);
  bool (*setObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*setFirstObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*setLastObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*removeObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*containsObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*member_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  OSObject* (*getFirstObject)(OSOrderedSet*);
  OSObject* (*getLastObject)(OSOrderedSet*);
  int (*orderObject_)(OSOrderedSet*, const OSMetaClassBase* anObject);
  bool (*setObject_int_)(OSOrderedSet*, unsigned int index, OSMetaClassBase* anObject);
  OSObject* (*getObject_)(OSOrderedSet*, unsigned int index);
  void* (*getOrderingRef)(OSOrderedSet*);
  bool (*isEqualTo_orderedset)(OSOrderedSet*);
 

};


struct VTB_OSString {
 void (*destr1)(OSString*);
  void (*destr0)(OSString*);
  void (*release_int)(OSString*, int freeWhen);
  int (*getRetainCount)(OSString*);
  void (*retain)(OSString*);
  void (*release)(OSString*);
  bool (*serialize_)(OSString*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSString*);
  bool (*isEqualTo_)(OSString*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSString*, const void *tag);
  void (*taggedRelease_)(OSString*, const void *tag);
  void (*taggedRelease__int)(OSString*, const void *tag, int freeWhen);
  bool (*init)(OSString*);
  void (*free)(OSString*);
  bool (*initWithString_)(OSString*, const OSString* aString);
  bool (*initWithCString_)(OSString*, const char*);
  bool (*initWithCStringNoCopy_)(OSString*, const char*);
  unsigned int (*getLength)(OSString*);
  char (*getChar_)(OSString*, unsigned int index);
  char (*setChar__)(OSString*, char aChar, unsigned int index);
  char* (*getCStringNoCopy)(OSString*);
  bool (*isEqualTo_string)(OSString*, const OSString* aString);
  bool (*isEqualTo_cstring)(OSString*, const char* aString);
  bool (*isEqualTo_data)(OSString*, const OSData* aDataObject);
 

};


struct VTB_OSSymbol {





 void (*destr1)(OSSymbol*);
  void (*destr0)(OSSymbol*);
  void (*release_int)(OSSymbol*, int freeWhen);
  int (*getRetainCount)(OSSymbol*);
  void (*retain)(OSSymbol*);
  void (*release)(OSSymbol*);
  bool (*serialize_)(OSSymbol*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSSymbol*);
  bool (*isEqualTo_)(OSSymbol*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSSymbol*, const void *tag);
  void (*taggedRelease_)(OSSymbol*, const void *tag);
  void (*taggedRelease__int)(OSSymbol*, const void *tag, int freeWhen);
  bool (*init)(OSSymbol*);
  void (*free)(OSSymbol*);
  bool (*initWithString_)(OSSymbol*, const OSString* aString);
  bool (*initWithCString_)(OSSymbol*, const char*);
  bool (*initWithCStringNoCopy_)(OSSymbol*, const char*);
  unsigned int (*getLength)(OSSymbol*);
  char (*getChar_)(OSSymbol*, unsigned int index);
  char (*setChar__)(OSSymbol*, char aChar, unsigned int index);
  char* (*getCStringNoCopy)(OSSymbol*);
  bool (*isEqualTo_string)(OSSymbol*, const OSString* aString);
  bool (*isEqualTo_cstring)(OSSymbol*, const char* aString);
  bool (*isEqualTo_data)(OSSymbol*, const OSData* aDataObject);
  bool (*isEqualTo_symbol)(OSSymbol*, const OSSymbol* aSymbol);
 

};


struct VTB_OSBoolean {
 void (*destr1)(OSBoolean*);
  void (*destr0)(OSBoolean*);
  void (*release_int)(OSBoolean*, int freeWhen);
  int (*getRetainCount)(OSBoolean*);
  void (*retain)(OSBoolean*);
  void (*release)(OSBoolean*);
  bool (*serialize_)(OSBoolean*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSBoolean*);
  bool (*isEqualTo_)(OSBoolean*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSBoolean*, const void *tag);
  void (*taggedRelease_)(OSBoolean*, const void *tag);
  void (*taggedRelease__int)(OSBoolean*, const void *tag, int freeWhen);
  bool (*init)(OSBoolean*);
  void (*free)(OSBoolean*);
  bool (*isTrue)(OSBoolean*);
  bool (*isFalse)(OSBoolean*);
  bool (*getValue)(OSBoolean*);
  bool (*isEqualTo_boolean)(OSBoolean*, const OSBoolean* aBoolean);
 

};


struct VTB_OSData {
 void (*destr1)(OSData*);
  void (*destr0)(OSData*);
  void (*release_int)(OSData*, int freeWhen);
  int (*getRetainCount)(OSData*);
  void (*retain)(OSData*);
  void (*release)(OSData*);
  bool (*serialize_)(OSData*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSData*);
  bool (*isEqualTo_)(OSData*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSData*, const void *tag);
  void (*taggedRelease_)(OSData*, const void *tag);
  void (*taggedRelease__int)(OSData*, const void *tag, int freeWhen);
  bool (*init)(OSData*);
  void (*free)(OSData*);
  bool (*initWithCapacity_)(OSData*, unsigned int capacity);
  bool (*initWithBytes__)(OSData*, const void *bytes, unsigned int numBytes);
  bool (*initWithBytesNoCopy__)(OSData*, void *bytes, unsigned int numBytes);
  bool (*initWithData_)(OSData*, const OSData* inData);
  bool (*initWithData___)(OSData*, const OSData* inData, unsigned int start, unsigned int numBytes);
  unsigned int (*getLength)(OSData*);
  unsigned int (*getCapacity)(OSData*);
  unsigned int (*getCapacityIncrement)(OSData*);
  unsigned int (*setCapacityIncrement_)(OSData*, unsigned int increment);
  unsigned int (*ensureCapacity_)(OSData*, unsigned int newCapacity);
  bool (*appendBytes__)(OSData*, const void* bytes, unsigned int numBytes);
  bool (*appendBytes_)(OSData*, const OSData* aDataObj);
  const void* (*getBytesNoCopy)(OSData*);
  const void* (*getBytesNoCopy__)(OSData*, unsigned int start, unsigned int numBytes);
  bool (*isEqualTo_data)(OSData*, const OSData* aDataObj);
  bool (*isEqualTo_bytes_)(OSData*, const void* bytes, unsigned int numBytes);
  bool (*isEqualTo_string)(OSData*, const OSString* aBoolean);
  bool (*appendByte__)(OSData*, unsigned char byte, unsigned int numBytes);
  void (*setDeallocFunction_)(OSData*, void (*)(void * ptr, unsigned int length));
 

};



struct VTB_OSNumber {
 void (*destr1)(OSNumber*);
  void (*destr0)(OSNumber*);
  void (*release_int)(OSNumber*, int freeWhen);
  int (*getRetainCount)(OSNumber*);
  void (*retain)(OSNumber*);
  void (*release)(OSNumber*);
  bool (*serialize_)(OSNumber*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSNumber*);
  bool (*isEqualTo_)(OSNumber*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSNumber*, const void *tag);
  void (*taggedRelease_)(OSNumber*, const void *tag);
  void (*taggedRelease__int)(OSNumber*, const void *tag, int freeWhen);
  bool (*init)(OSNumber*);
  void (*free)(OSNumber*);
  bool (*init_value_)(OSNumber*, unsigned long long value, unsigned int numberOfBits);
  bool (*init_valueString_)(OSNumber*, const char* valueString, unsigned int numberOfBits);
  unsigned int (*numberOfBits)(OSNumber*);
  unsigned int (*numberOfBytes)(OSNumber*);
  unsigned char (*unsigned8BitValue)(OSNumber*);
  unsigned short (*unsigned16BitValue)(OSNumber*);
  unsigned int (*unsigned32BitValue)(OSNumber*);
  unsigned long long (*unsigned64BitValue)(OSNumber*);
  void (*addValue_)(OSNumber*, signed long long);
  void (*setValue_)(OSNumber*, unsigned long long);
  void (*isEqualTo_number)(OSNumber*, const OSNumber* aNumber);
 

};


struct VTB_OSIterator {







 void (*destr1)(OSIterator*);
  void (*destr0)(OSIterator*);
  void (*release_int)(OSIterator*, int freeWhen);
  int (*getRetainCount)(OSIterator*);
  void (*retain)(OSIterator*);
  void (*release)(OSIterator*);
  bool (*serialize_)(OSIterator*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSIterator*);
  bool (*isEqualTo_)(OSIterator*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSIterator*, const void *tag);
  void (*taggedRelease_)(OSIterator*, const void *tag);
  void (*taggedRelease__int)(OSIterator*, const void *tag, int freeWhen);
  bool (*init)(OSIterator*);
  void (*free)(OSIterator*);
  void (*reset)(OSIterator*);
  bool (*isValid)(OSIterator*);
  OSObject* (*getNextObject)(OSIterator*);
 

};


struct VTB_OSCollectionIterator {





 void (*destr1)(OSCollectionIterator*);
  void (*destr0)(OSCollectionIterator*);
  void (*release_int)(OSCollectionIterator*, int freeWhen);
  int (*getRetainCount)(OSCollectionIterator*);
  void (*retain)(OSCollectionIterator*);
  void (*release)(OSCollectionIterator*);
  bool (*serialize_)(OSCollectionIterator*, OSSerialize *serializer);
  const OSMetaClass* (*getMetaClass)(OSCollectionIterator*);
  bool (*isEqualTo_)(OSCollectionIterator*, const OSMetaClassBase *anObject);
  void (*taggedRetain_)(OSCollectionIterator*, const void *tag);
  void (*taggedRelease_)(OSCollectionIterator*, const void *tag);
  void (*taggedRelease__int)(OSCollectionIterator*, const void *tag, int freeWhen);
  bool (*init)(OSCollectionIterator*);
  void (*free)(OSCollectionIterator*);
  void (*reset)(OSCollectionIterator*);
  bool (*isValid)(OSCollectionIterator*);
  OSObject* (*getNextObject)(OSCollectionIterator*);
  void (*initWithCollection_)(OSCollectionIterator*, const OSCollection* inColl);
 

};

