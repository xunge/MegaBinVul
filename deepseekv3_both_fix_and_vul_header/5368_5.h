#include <cstdint>
#include <cassert>

#define DCHECK(condition) assert(condition)

enum ArrayStorageAllocationMode {
  DONT_INITIALIZE_ARRAY_ELEMENTS,
  INITIALIZE_ARRAY_ELEMENTS_WITH_HOLE
};

enum ElementsKind {
  FAST_DOUBLE_ELEMENTS,
  FAST_SMI_ELEMENTS,
  FAST_OBJECT_ELEMENTS
};

class Smi {
public:
  static Smi FromInt(int value);
};

class FixedArrayBase {};
class FixedArray : public FixedArrayBase {};
class FixedDoubleArray : public FixedArrayBase {};

class HandleScope {
public:
  HandleScope(void* isolate);
};

template<typename T> class Handle;

class HandleBase {
public:
  template<typename T> operator Handle<T>() { return Handle<T>(); }
};

template<typename T>
class Handle : public HandleBase {
public:
  Handle() = default;
  template<typename U> Handle(Handle<U> other) {}
  T* operator->() { return nullptr; }
  T& operator*() { static T t; return t; }
  template<typename U> Handle<T>& operator=(Handle<U> other) { return *this; }
};

class JSArray {
public:
  void set_length(Smi length) {}
  void set_elements(FixedArrayBase& elements) {}
  ElementsKind GetElementsKind() { return FAST_SMI_ELEMENTS; }
};

class Factory {
public:
  void* isolate() { return nullptr; }
  Handle<FixedArrayBase> empty_fixed_array() { return Handle<FixedArrayBase>(); }
  Handle<FixedArrayBase> NewFixedDoubleArray(int capacity) { return Handle<FixedArrayBase>(); }
  Handle<FixedArrayBase> NewFixedDoubleArrayWithHoles(int capacity) { return Handle<FixedArrayBase>(); }
  Handle<FixedArrayBase> NewUninitializedFixedArray(int capacity) { return Handle<FixedArrayBase>(); }
  Handle<FixedArrayBase> NewFixedArrayWithHoles(int capacity) { return Handle<FixedArrayBase>(); }
  void NewJSArrayStorage(Handle<JSArray> array, int length, int capacity, ArrayStorageAllocationMode mode);
};

bool IsFastDoubleElementsKind(ElementsKind kind) { return kind == FAST_DOUBLE_ELEMENTS; }
bool IsFastSmiOrObjectElementsKind(ElementsKind kind) { return kind == FAST_SMI_ELEMENTS || kind == FAST_OBJECT_ELEMENTS; }