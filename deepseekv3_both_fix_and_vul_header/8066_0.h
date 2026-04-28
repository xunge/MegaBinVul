#include <stdint.h>

typedef uintptr_t Address;
typedef intptr_t word;

class Object;
class HeapObject;
class Map;
class Heap;
class MarkCompactCollector;
class MarkCompactMarkingVisitor;

class Object {
 public:
  bool IsHeapObject();
};

class HeapObject : public Object {
 public:
  static HeapObject* cast(Object* obj);
  bool IsFiller();
  Map* map();
  int Size();
};

class Map : public HeapObject {
};

class Heap {
 public:
  Map* one_pointer_filler_map();
  Map* two_pointer_filler_map();
};

class Marking {
 public:
  static bool IsBlackOrGrey(int mark_bit);
  static int MarkBitFrom(HeapObject* obj);
};

class MarkCompactCollector {
 public:
  Heap* heap();
  void SetMark(HeapObject* obj, int mark_bit);
  void MarkObject(Map* map, int map_mark);
  void EmptyMarkingDeque();
};

class MarkCompactMarkingVisitor {
 public:
  static void IterateBody(Map* map, HeapObject* obj);
};

extern MarkCompactCollector* collector_;
extern const int kPointerSize;
typedef int MarkBit;