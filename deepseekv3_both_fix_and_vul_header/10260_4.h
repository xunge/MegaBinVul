#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>

typedef int32_t status_t;

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) {}
    T* get() const { return nullptr; }
    T& operator*() const { return *static_cast<T*>(nullptr); }
};

class BBinder {
public:
    virtual status_t onTransact(uint32_t code, const struct Parcel& data, struct Parcel* reply, uint32_t flags);
};

class IHDCPObserver {};
class GraphicBuffer {};
class IHDCP {};

struct Parcel {
    int32_t readInt32() const;
    int64_t readInt64() const;
    const char* readCString() const;
    status_t read(void* data, size_t size) const;
    status_t read(GraphicBuffer& buffer) const;
    void writeInt32(int32_t value);
    void writeInt64(int64_t value);
    void write(const void* data, size_t size);
    sp<BBinder> readStrongBinder() const;
};

template<typename T>
T* interface_cast(const sp<BBinder>& binder) {
    return nullptr;
}

#define CHECK_INTERFACE(interface, data, reply)

enum {
    HDCP_SET_OBSERVER,
    HDCP_INIT_ASYNC,
    HDCP_SHUTDOWN_ASYNC,
    HDCP_GET_CAPS,
    HDCP_ENCRYPT,
    HDCP_ENCRYPT_NATIVE,
    HDCP_DECRYPT
};

class BnHDCP : public BBinder {
public:
    virtual status_t setObserver(const sp<IHDCPObserver>& observer) = 0;
    virtual status_t initAsync(const char* host, unsigned port) = 0;
    virtual status_t shutdownAsync() = 0;
    virtual status_t getCaps() = 0;
    virtual status_t encrypt(const void* inData, size_t size, uint32_t streamCTR, uint64_t* inputCTR, void* outData) = 0;
    virtual status_t encryptNative(const sp<GraphicBuffer>& graphicBuffer, size_t offset, size_t size, uint32_t streamCTR, uint64_t* inputCTR, void* outData) = 0;
    virtual status_t decrypt(const void* inData, size_t size, uint32_t streamCTR, uint64_t inputCTR, void* outData) = 0;
    
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};

constexpr status_t OK = 0;
constexpr status_t ERROR_OUT_OF_RANGE = -1;