#include <set>
#include <cstddef>

class Array;
class Variant;
class ArrayIter;

enum AccessFlags {
    Key
};

class PointerSet : public std::set<void*> {};

class Variant {
public:
    bool isNumeric() const;
    bool isReferenced() const;
    Array toArray() const;
    void unset();
    Variant& operator=(const Array& arr);
};

class Array {
public:
    void* get() const;
    void appendWithRef(const Variant& value);
    bool exists(const Variant& key, bool strict) const;
    Variant& lvalAt(const Variant& key, int flags);
    void setWithRef(const Variant& key, const Variant& value, bool strict);
    Array copy() const;
};

class ArrayIter {
public:
    ArrayIter(const Array& array);
    operator bool() const;
    ArrayIter& operator++();
    Variant first() const;
    const Variant& secondRef() const;
};

bool couldRecur(const Variant& v, const Array& arr);
void raise_warning(const char* message);