#include <cstddef>
#include <utility>
#include <string>
#include <set>

class String {
public:
    String();
    bool empty() const;
    const char* get() const;
};

class Variant {
public:
    bool isArray() const;
    void* getArrayData() const;
    String toString() const;
};

class Array {
public:
    void set(const String&, const Variant&);
};

class VarEnv {
public:
    void* lookup(const char*) const;
};

class ArrayIter {
public:
    ArrayIter(void*);
    operator bool() const;
    ArrayIter& operator++();
    Variant second() const;
    Variant& secondRef() const;
};

class PointerSet : public std::set<void*> {
public:
    std::pair<std::set<void*>::iterator, bool> insert(void* ptr);
    void erase(void* ptr);
};

bool couldRecur(const Variant&, void*);
void raise_warning(const char*);