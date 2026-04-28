#include <cstdint>
#include <string>

class String;
class Array;
class ArrayData;

struct Variant {
    Variant() {}
    Variant(bool) {}
    Variant(ArrayData*) {}
    bool isArray() const { return false; }
    bool isString() const { return false; }
    Array toArray() const;
    String toString() const;
    String toCStrRef() const;
};

struct Array {};
struct ArrayData {
    static ArrayData* Create();
};
struct ArrayIter {
    ArrayIter(const Array&);
    operator bool() const;
    ArrayIter& operator++();
    Variant first() const;
    Variant second() const;
};
struct String {};

struct apcExtension {
    static bool Enable;
};

struct apc_store {
    void set(const String&, const Variant&, int64_t);
    static apc_store& get();
};

void throw_invalid_argument(const char*);
bool isKeyInvalid(const String&);