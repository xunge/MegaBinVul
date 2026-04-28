#include <stdbool.h>

#define MUST_USE_RESULT __attribute__((warn_unused_result))

class Object;
class JSArray;
class Arguments;
class Isolate;
class HandleScope;
class DisallowHeapAllocation;
class JSObject;
class Map;

template<typename T>
class Handle {
 public:
  T* operator->() const;
  T* operator*() const;
  static Handle<T> cast(Handle<Object> obj);
};

enum ElementsKind {
  FAST_DOUBLE_ELEMENTS,
  FAST_ELEMENTS,
  DICTIONARY_ELEMENTS_KIND
};

class Arguments {
 public:
  int length();
  Object** arguments();
};

class Object {
 public:
  bool IsJSArray();
  bool IsHeapObject();
  bool IsHeapNumber();
};

class Map {
 public:
  bool is_observed();
  bool is_extensible();
  ElementsKind elements_kind();
};

class JSArray {
 public:
  ElementsKind GetElementsKind();
  Map* map();
};

class Isolate {
 public:
  bool IsAnyInitialArrayPrototype(Handle<JSArray> array);
};

class JSObject {
 public:
  static void TransitionElementsKind(Handle<JSArray> array, ElementsKind kind);
};

class DisallowHeapAllocation {
 public:
  DisallowHeapAllocation();
};

class HandleScope {
 public:
  HandleScope(Isolate* isolate);
};

bool IsJSArrayFastElementMovingAllowed(Isolate* isolate, JSArray* array);
bool IsDictionaryElementsKind(ElementsKind kind);
bool IsFastObjectElementsKind(ElementsKind kind);