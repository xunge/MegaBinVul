#include <unordered_set>
#include <cstddef>

using PointerSet = std::unordered_set<void*>;

enum class AccessFlags {
    Key
};

struct Variant;
struct ArrNR;
struct ArrayIter;

struct Array {
    void* get() const;
    bool exists(const Variant& key, bool) const;
    Variant& lvalAt(const Variant& key, AccessFlags);
    void set(const Variant& key, const Variant& value, bool);
    void setWithRef(const Variant& key, const Variant& value, bool);
};

struct Variant {
    bool isArray() const;
    bool isReferenced() const;
    Array toArray() const;
    ArrNR toArrNR() const;
    Variant& operator=(const Array&);
};

struct ArrayIter {
    ArrayIter(const Array&);
    operator bool() const;
    ArrayIter& operator++();
    Variant first() const;
    const Variant& secondRef() const;
};

struct ArrNR {
    operator Array() const;
};

bool couldRecur(const Variant& v, const Array& subarr1);
void raise_warning(const char* msg);