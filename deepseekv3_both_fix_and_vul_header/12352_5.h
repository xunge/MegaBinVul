#include <set>
#include <cstdint>

typedef std::set<void*> PointerSet;

class Array;
class ArrNR;

enum class AccessFlags {
    Key
};

class Variant {
public:
    bool isArray() const;
    Array toArray() const;
    ArrNR toArrNR() const;
    Variant& operator=(const Array&);
    void* get() const;
};

class Array {
public:
    void* get() const;
    bool exists(const Variant& key, bool strict) const;
    Variant& lvalAt(const Variant& key, AccessFlags flags);
    void set(const Variant& key, const Variant& value, bool overwrite);
    void setWithRef(const Variant& key, const Variant& value, bool overwrite);
};

class ArrayIter {
public:
    ArrayIter(const Array& arr);
    operator bool() const;
    ArrayIter& operator++();
    Variant first() const;
    const Variant& secondRef() const;
};

class ArrNR {
public:
    operator Array() const;
    void* get() const;
};

bool couldRecur(const Variant& v, const Array& arr);
bool couldRecur(const Variant& v, void* arr);
void raise_warning(const char* msg);