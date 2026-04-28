#include <stddef.h>

class Object;
class HeapObject;
class Map;
class Marking;
class MarkCompactMarkingVisitor {
public:
    static void IterateBody(Map* map, HeapObject* object);
};

struct MarkBit {
    bool value;
};

class Collector {
public:
    void SetMark(HeapObject* object, MarkBit mark_bit);
    void MarkObject(Map* map, MarkBit map_mark);
    void EmptyMarkingDeque();
    class Heap* heap();
};

class Heap {
public:
    bool PurgeLeftTrimmedObject(Object** p);
};

class Object {
public:
    bool IsHeapObject();
};

class HeapObject : public Object {
public:
    static HeapObject* cast(Object* obj);
    Map* map();
};

class Marking {
public:
    static MarkBit MarkBitFrom(void* obj);
    static bool IsBlackOrGrey(MarkBit mark_bit);
};

extern Collector* collector_;