#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#define OK 0
#define ERROR_OUT_OF_RANGE (-1)

enum {
    HDCP_SET_OBSERVER,
    HDCP_INIT_ASYNC,
    HDCP_SHUTDOWN_ASYNC,
    HDCP_GET_CAPS,
    HDCP_ENCRYPT,
    HDCP_ENCRYPT_NATIVE,
    HDCP_DECRYPT
};

#define CHECK_INTERFACE(interface, data, reply)

typedef int32_t status_t;

class BBinder {
public:
    virtual ~BBinder() = default;
    virtual status_t onTransact(uint32_t code, const struct Parcel& data, 
                              struct Parcel* reply, uint32_t flags);
};

class IHDCPObserver {
public:
    virtual ~IHDCPObserver() = default;
};

class IHDCP {
public:
    virtual ~IHDCP() = default;
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : m_ptr(ptr) {}
    T* operator->() const { return m_ptr; }
    T& operator*() const { return *m_ptr; }
    T* get() const { return m_ptr; }
private:
    T* m_ptr;
};

class GraphicBuffer {
public:
    GraphicBuffer();
    ~GraphicBuffer();
};

class Parcel {
public:
    int32_t readInt32() const;
    int64_t readInt64() const;
    const char* readCString() const;
    void read(void* buffer, size_t len) const;
    status_t writeInt32(int32_t value);
    status_t writeInt64(int64_t value);
    status_t write(const void* buffer, size_t len);
    sp<BBinder> readStrongBinder() const;
    status_t read(GraphicBuffer& buffer) const;
};

class BnHDCP : public BBinder {
public:
    virtual ~BnHDCP() = default;
    virtual status_t onTransact(uint32_t code, const Parcel& data, 
                              Parcel* reply, uint32_t flags) override;
    virtual status_t setObserver(const sp<IHDCPObserver>& observer) = 0;
    virtual status_t initAsync(const char* host, unsigned port) = 0;
    virtual status_t shutdownAsync() = 0;
    virtual status_t getCaps() = 0;
    virtual status_t encrypt(void* inData, size_t size, uint32_t streamCTR, 
                           uint64_t* inputCTR, void* outData) = 0;
    virtual status_t encryptNative(const sp<GraphicBuffer>& buffer, size_t offset, 
                                 size_t size, uint32_t streamCTR, uint64_t* inputCTR, 
                                 void* outData) = 0;
    virtual status_t decrypt(void* inData, size_t size, uint32_t streamCTR, 
                           uint64_t inputCTR, void* outData) = 0;
};

template<typename T>
T* interface_cast(const sp<BBinder>& binder) {
    return dynamic_cast<T*>(binder.get());
}