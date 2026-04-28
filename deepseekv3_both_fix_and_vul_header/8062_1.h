#include <stddef.h>

class Object;
class HeapObject;

class Scavenger {
public:
    static void ScavengeObject(HeapObject** p, HeapObject* object);
};

class Heap {
public:
    bool InNewSpace(Object* object);
    bool PurgeLeftTrimmedObject(Object** p);
};

class ScavengeVisitor {
private:
    Heap* heap_;
public:
    void ScavengePointer(Object** p);
};