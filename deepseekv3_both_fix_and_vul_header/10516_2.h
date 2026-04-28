#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef int status_t;
#define OK 0
#define ERROR_MALFORMED -1
#define ALOGE printf

template<typename T> class sp;

class ABuffer {
public:
    static sp<ABuffer> CreateAsCopy(const uint8_t* data, size_t size);
    void setInt32Data(int32_t data);
};

template<typename T>
class Vector {
public:
    void push(const T& item);
};

template<typename T>
class sp {
public:
    sp(T* ptr);
    T* operator->() const;
};

class HevcParameterSets {
public:
    status_t addNalUnit(const uint8_t* data, size_t size);
private:
    Vector<sp<ABuffer>> mNalUnits;
    status_t parseVps(const uint8_t* data, size_t size);
    status_t parseSps(const uint8_t* data, size_t size);
    status_t parsePps(const uint8_t* data, size_t size);
};