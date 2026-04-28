#include <stdlib.h>
#include <stdint.h>
#include <cmath>
#include <memory>

class DecimalQuantity;
class CharString;

enum UErrorCode {
    U_MEMORY_ALLOCATION_ERROR
};

#define U_FAILURE(status) (0)

struct CharString {
    CharString* append(const char*, int, UErrorCode&);
    CharString* appendInvariantChars(const char*, UErrorCode&);
};

class DecimalQuantity {
public:
    bool isZero();
    int32_t getMagnitude();
    const char* toPlainString();
    const char* toScientificString();
};

template<typename T>
class LocalPointer {
private:
    T* ptr;
public:
    LocalPointer(T* p, UErrorCode&) : ptr(p) {}
    ~LocalPointer() { delete ptr; }
    T* orphan() { T* p = ptr; ptr = nullptr; return p; }
    T* operator->() { return ptr; }
    T& operator*() { return *ptr; }
};

class Formattable {
private:
    CharString* fDecimalStr;
    DecimalQuantity* fDecimalQuantity;
public:
    CharString* internalGetCharString(UErrorCode& status);
    void populateDecimalQuantity(DecimalQuantity& dq, UErrorCode& status);
};