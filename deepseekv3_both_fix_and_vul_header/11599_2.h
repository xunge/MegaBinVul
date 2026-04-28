#include <stdint.h>
#include <sys/types.h>
#include <cstddef>

class Parcel {
public:
    int32_t readInt32() const;
    ssize_t read(void* data, size_t size) const;
};

template<typename T>
class Vector {
public:
    ssize_t insertAt(size_t index, size_t count);
    void clear();
    T* editArray();
};

class BnCrypto {
public:
    void readVector(const Parcel &data, Vector<uint8_t> &vector) const;
};

enum {
    NO_ERROR = 0
};

void android_errorWriteWithInfoLog(uint32_t tag, const char* subTag, int32_t uid, const char* data, uint32_t dataLen);