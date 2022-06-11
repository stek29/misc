// cc -E this-file | grep -v '^#' > header-for-ida.h

typedef void OSMetaClassBase;

// why not, it has same set of virtual funcs
typedef OSMetaClassBase OSMetaClass;

typedef void OSSerialize;
typedef OSMetaClass OSCollection;

#define DECL_CLASS(name)\
	struct VTB_##name; \
	typedef struct { \
		struct VTB_##name *vtab; \
	} name

DECL_CLASS(OSMetaClassBase);
DECL_CLASS(OSObject);
DECL_CLASS(OSString);
DECL_CLASS(OSSymbol);
DECL_CLASS(OSBoolean);
DECL_CLASS(OSData);
DECL_CLASS(OSDictionary);
DECL_CLASS(OSArray);
DECL_CLASS(OSSet);
DECL_CLASS(OSOrderedSet);
DECL_CLASS(OSNumber);
DECL_CLASS(OSIterator);
DECL_CLASS(OSCollectionIterator);

#define DEF_FUNC(type, name, ...) type (*name)(CURRENT_CLASS_NAME*, ##__VA_ARGS__)

#define DVT_CPP_OBJ\
	DEF_FUNC(void, destr1);\
	DEF_FUNC(void, destr0);

struct VTB_OSMetaClassBase {
#define CURRENT_CLASS_NAME OSMetaClassBase
#define DVT_OSMetaClassBase\
	DVT_CPP_OBJ\
	DEF_FUNC(void, release_int, int freeWhen);\
	DEF_FUNC(int, getRetainCount);\
	DEF_FUNC(void, retain);\
	DEF_FUNC(void, release);\
	DEF_FUNC(bool, serialize_, OSSerialize *serializer);\
	DEF_FUNC(const OSMetaClass*, getMetaClass);\
	DEF_FUNC(bool, isEqualTo_, const OSMetaClassBase *anObject);\
	DEF_FUNC(void, taggedRetain_, const void *tag);\
	DEF_FUNC(void, taggedRelease_, const void *tag);\
	DEF_FUNC(void, taggedRelease__int, const void *tag, int freeWhen);

	DVT_OSMetaClassBase
#undef CURRENT_CLASS_NAME
};

struct VTB_OSObject {
#define CURRENT_CLASS_NAME OSObject
#define DVT_OSObject\
	DVT_OSMetaClassBase\
	DEF_FUNC(bool, init);\
	DEF_FUNC(void, free);

	DVT_OSObject
#undef CURRENT_CLASS_NAME
};

#define DVT_OSCollection\
	DVT_OSObject\
	DEF_FUNC(int, iteratorSize);\
	DEF_FUNC(bool, initIterator_, void *iterator);\
	DEF_FUNC(bool, getNextObjectForIterator__, void *iterator, OSObject **nextObject);\
	DEF_FUNC(unsigned int, getCount);\
	DEF_FUNC(unsigned int, getCapacity);\
	DEF_FUNC(unsigned int, getCapacityIncrement);\
	DEF_FUNC(unsigned int, setCapacityIncrement_, unsigned int increment);\
	DEF_FUNC(unsigned int, ensureCapacity_, unsigned int newCapacity);\
	DEF_FUNC(void, flushCollection);\
	DEF_FUNC(unsigned, setOptions___, unsigned options, unsigned mask, void* context);\
	DEF_FUNC(CURRENT_CLASS_NAME *, copyCollection_, OSDictionary* cycleDict);

struct VTB_OSDictionary {
#define CURRENT_CLASS_NAME OSDictionary
#define DVT_OSDictionary\
	DVT_OSCollection\
	DEF_FUNC(bool, initWithCapacity_, unsigned int);\
	DEF_FUNC(bool, initWithObjects__OSSymbol__, const OSObject * objects[], const OSSymbol * keys[], unsigned int count, unsigned int capacity);\
	DEF_FUNC(bool, initWithObjects__OSString__, const OSObject * objects[], const OSString * keys[], unsigned int count, unsigned int capacity);\
	DEF_FUNC(bool, initWithDictionary__, const OSDictionary* dict, unsigned int capacity);\
	DEF_FUNC(bool, setObject_OSSymbol_, const OSSymbol *aKey, const OSMetaClassBase *anObject);\
	DEF_FUNC(bool, setObject_OSString_, const OSString *aKey, const OSMetaClassBase *anObject);\
	DEF_FUNC(bool, setObject_cstring_, const char *aKey, const OSMetaClassBase *anObject);\
	DEF_FUNC(void, removeObject_OSSymbol, const OSSymbol *aKey);\
	DEF_FUNC(void, removeObject_OSString, const OSString *aKey);\
	DEF_FUNC(void, removeObject_cstring, const char *aKey);\
	DEF_FUNC(bool, merge_, OSDictionary* aDictionary);\
	DEF_FUNC(OSObject*, getObject_OSSymbol, const OSSymbol *aKey);\
	DEF_FUNC(OSObject*, getObject_OSString, const OSString *aKey);\
	DEF_FUNC(OSObject*, getObject_cstring, const char *aKey);\
	DEF_FUNC(bool, isEqualTo_dict, const OSDictionary* aDictionary);\
	DEF_FUNC(bool, isEqualTo_dict_keys, const OSDictionary* aDictionary, OSCollection* keys);

	DVT_OSDictionary
#undef CURRENT_CLASS_NAME
};

struct VTB_OSArray {
#define CURRENT_CLASS_NAME OSArray
#define DVT_OSArray\
	DVT_OSCollection\
	DEF_FUNC(bool, initWithCapacity_, unsigned int);\
	DEF_FUNC(bool, initWithObjects___, const OSObject *objects[], unsigned int count, unsigned int capacity);\
	DEF_FUNC(bool, initWithArray_, const OSArray* anArray, unsigned capacity);\
	DEF_FUNC(bool, setObject_, OSMetaClassBase* anObject);\
	DEF_FUNC(bool, setObject_int_, unsigned int index, OSMetaClassBase* anObject);\
	DEF_FUNC(bool, merge_, const OSArray* anArray);\
	DEF_FUNC(bool, replaceObject_int_, unsigned int index, OSMetaClassBase* anObject);\
	DEF_FUNC(void, removeObject_, unsigned int index);\
	DEF_FUNC(bool, isEqualTo_array, const OSArray* anArray);\
	DEF_FUNC(OSObject*, getObject_, unsigned int index);\
	DEF_FUNC(OSObject*, getLastObject);\
	DEF_FUNC(unsigned int, getNextIndexOfObject__, const OSMetaClassBase* anObject, unsigned int index);

	DVT_OSArray
#undef CURRENT_CLASS_NAME
};

struct VTB_OSSet {
#define CURRENT_CLASS_NAME OSSet
#define DVT_OSSet\
	DVT_OSCollection\
	DEF_FUNC(bool, initWithCapacity_, unsigned int);\
	DEF_FUNC(bool, initWithObjects___, const OSObject *objects[], unsigned int count, unsigned int capacity);\
	DEF_FUNC(bool, initWithArray_, const OSArray* anArray, unsigned capacity);\
	DEF_FUNC(bool, initWithSet_, const OSSet* aSet, unsigned capacity);\
	DEF_FUNC(bool, setObject_, OSMetaClassBase* anObject);\
	DEF_FUNC(bool, merge_array, const OSArray* anArray);\
	DEF_FUNC(bool, merge_set, const OSSet* aSet);\
	DEF_FUNC(void, removeObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, containsObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, member_, const OSMetaClassBase* anObject);\
	DEF_FUNC(OSObject*, getAnyObject);\
	DEF_FUNC(bool, isEqualTo_set, const OSSet* aSet);

	DVT_OSSet
#undef CURRENT_CLASS_NAME
};


typedef int (*OSOrderFunction)(const OSMetaClassBase * obj1, const OSMetaClassBase * obj2, void * context);
struct VTB_OSOrderedSet {
#define CURRENT_CLASS_NAME OSOrderedSet
#define DVT_OSOrderedSet\
	DVT_OSCollection\
	DEF_FUNC(bool, initWithCapacity___, unsigned int capacity, OSOrderFunction orderFunc, void *orderContext);\
	DEF_FUNC(bool, setObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, setFirstObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, setLastObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, removeObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, containsObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, member_, const OSMetaClassBase* anObject);\
	DEF_FUNC(OSObject*, getFirstObject);\
	DEF_FUNC(OSObject*, getLastObject);\
	DEF_FUNC(int, orderObject_, const OSMetaClassBase* anObject);\
	DEF_FUNC(bool, setObject_int_, unsigned int index, OSMetaClassBase* anObject);\
	DEF_FUNC(OSObject*, getObject_, unsigned int index);\
	DEF_FUNC(void*, getOrderingRef);\
	DEF_FUNC(bool, isEqualTo_orderedset);

	DVT_OSOrderedSet
#undef CURRENT_CLASS_NAME
};

struct VTB_OSString {
#define CURRENT_CLASS_NAME OSString
#define DVT_OSString\
	DVT_OSObject\
	DEF_FUNC(bool, initWithString_, const OSString* aString);\
	DEF_FUNC(bool, initWithCString_, const char*);\
	DEF_FUNC(bool, initWithCStringNoCopy_, const char*);\
	DEF_FUNC(unsigned int, getLength);\
	DEF_FUNC(char, getChar_, unsigned int index);\
	DEF_FUNC(char, setChar__, char aChar, unsigned int index);\
	DEF_FUNC(char*, getCStringNoCopy);\
	DEF_FUNC(bool, isEqualTo_string, const OSString* aString);\
	DEF_FUNC(bool, isEqualTo_cstring, const char* aString);\
	DEF_FUNC(bool, isEqualTo_data, const OSData* aDataObject);
	
	DVT_OSString
#undef CURRENT_CLASS_NAME
};

struct VTB_OSSymbol {
#define CURRENT_CLASS_NAME OSSymbol
#define DVT_OSSymbol\
	DVT_OSString\
	DEF_FUNC(bool, isEqualTo_symbol, const OSSymbol* aSymbol);

	DVT_OSSymbol
#undef CURRENT_CLASS_NAME
};

struct VTB_OSBoolean {
#define CURRENT_CLASS_NAME OSBoolean
#define DVT_OSBoolean\
	DVT_OSObject\
	DEF_FUNC(bool, isTrue);\
	DEF_FUNC(bool, isFalse);\
	DEF_FUNC(bool, getValue);\
	DEF_FUNC(bool, isEqualTo_boolean, const OSBoolean* aBoolean);
	
	DVT_OSBoolean
#undef CURRENT_CLASS_NAME
};

struct VTB_OSData {
#define CURRENT_CLASS_NAME OSData
#define DVT_OSData\
	DVT_OSObject\
	DEF_FUNC(bool, initWithCapacity_, unsigned int capacity);\
	DEF_FUNC(bool, initWithBytes__, const void *bytes, unsigned int numBytes);\
	DEF_FUNC(bool, initWithBytesNoCopy__, void *bytes, unsigned int numBytes);\
	DEF_FUNC(bool, initWithData_, const OSData* inData);\
	DEF_FUNC(bool, initWithData___, const OSData* inData, unsigned int start, unsigned int numBytes);\
	DEF_FUNC(unsigned int, getLength);\
	DEF_FUNC(unsigned int, getCapacity);\
	DEF_FUNC(unsigned int, getCapacityIncrement);\
	DEF_FUNC(unsigned int, setCapacityIncrement_, unsigned int increment);\
	DEF_FUNC(unsigned int, ensureCapacity_, unsigned int newCapacity);\
	DEF_FUNC(bool, appendBytes__, const void* bytes, unsigned int numBytes);\
	DEF_FUNC(bool, appendBytes_, const OSData* aDataObj);\
	DEF_FUNC(const void*, getBytesNoCopy);\
	DEF_FUNC(const void*, getBytesNoCopy__, unsigned int start, unsigned int numBytes);\
	DEF_FUNC(bool, isEqualTo_data, const OSData* aDataObj);\
	DEF_FUNC(bool, isEqualTo_bytes_, const void* bytes, unsigned int numBytes);\
	DEF_FUNC(bool, isEqualTo_string, const OSString* aBoolean);\
	DEF_FUNC(bool, appendByte__, unsigned char byte, unsigned int numBytes);\
	DEF_FUNC(void, setDeallocFunction_, void (*)(void * ptr, unsigned int length));

	
	DVT_OSData
#undef CURRENT_CLASS_NAME
};


struct VTB_OSNumber {
#define CURRENT_CLASS_NAME OSNumber
#define DVT_OSNumber\
	DVT_OSObject\
	DEF_FUNC(bool, init_value_, unsigned long long value, unsigned int numberOfBits);\
	DEF_FUNC(bool, init_valueString_, const char* valueString, unsigned int numberOfBits);\
	DEF_FUNC(unsigned int, numberOfBits);\
	DEF_FUNC(unsigned int, numberOfBytes);\
	DEF_FUNC(unsigned char, unsigned8BitValue);\
	DEF_FUNC(unsigned short, unsigned16BitValue);\
	DEF_FUNC(unsigned int, unsigned32BitValue);\
	DEF_FUNC(unsigned long long, unsigned64BitValue);\
	DEF_FUNC(void, addValue_, signed long long);\
	DEF_FUNC(void, setValue_, unsigned long long);\
	DEF_FUNC(void, isEqualTo_number, const OSNumber* aNumber);
	
	DVT_OSNumber
#undef CURRENT_CLASS_NAME
};

struct VTB_OSIterator {
#define CURRENT_CLASS_NAME OSIterator
#define DVT_OSIterator\
	DVT_OSObject\
	DEF_FUNC(void, reset);\
	DEF_FUNC(bool, isValid);\
	DEF_FUNC(OSObject*, getNextObject);

	DVT_OSIterator
#undef CURRENT_CLASS_NAME
};

struct VTB_OSCollectionIterator {
#define CURRENT_CLASS_NAME OSCollectionIterator
#define DVT_OSCollectionIterator\
	DVT_OSIterator\
	DEF_FUNC(void, initWithCollection_, const OSCollection* inColl);
	
	DVT_OSCollectionIterator
#undef CURRENT_CLASS_NAME
};

