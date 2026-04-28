#include <stdint.h>

#define DCHECK(condition) ((void)0)
#define SLOW_DCHECK(condition) ((void)0)
#define STATIC_ASSERT(condition) ((void)0)

typedef uintptr_t Address;

class Object {
public:
    virtual ~Object() = default;
};

class Smi : public Object {
public:
    static Smi* FromInt(int value);
};

class Map : public Object {
public:
    bool operator!=(Map* other);
};

class HeapObject : public Object {
public:
    static Object** RawField(HeapObject* obj, int offset);
    static HeapObject* FromAddress(Address address);
    Address address();
};

class FixedArrayBase : public HeapObject {
public:
    static const int kMapOffset = 0;
    static const int kLengthOffset = sizeof(void*);
    static const int kHeaderSize = 2 * sizeof(void*);
    
    Map* map();
    int length();
    bool IsFixedArray();
    bool IsFixedTypedArrayBase();
    bool IsByteArray();
    bool IsFixedDoubleArray();
    int Size();
    static FixedArrayBase* cast(HeapObject* obj);
};

class Marking {
public:
    static void TransferMark(void* heap, Address from, Address to);
};

class Heap {
public:
    enum AllocatorMode {
        CONCURRENT_TO_SWEEPER
    };

    bool Contains(FixedArrayBase* object);
    Map* fixed_cow_array_map();
    void CreateFillerObjectAt(Address address, int size, int clear);
    bool CanMoveObjectStart(FixedArrayBase* object);
    void ClearRecordedSlot(HeapObject* object, Object** slot);
    void AdjustLiveBytes(HeapObject* object, int bytes, AllocatorMode mode);
    void OnMoveEvent(HeapObject* new_obj, HeapObject* old_obj, int size);
    int CountHandlesForObject(FixedArrayBase* object);
    FixedArrayBase* LeftTrimFixedArray(FixedArrayBase* object, int elements_to_trim);
};

enum ClearRecordedSlots {
    kYes,
    kNo
};

const int kPointerSize = sizeof(void*);
const int kDoubleSize = sizeof(double);