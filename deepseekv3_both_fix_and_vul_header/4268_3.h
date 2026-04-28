#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;

template<typename T> class sp {
public:
    sp() : m_ptr(0) {}
    sp(T* other) : m_ptr(other) {}
    ~sp() {}
    T* get() const { return m_ptr; }
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
    bool operator!=(const T* other) const { return m_ptr != other; }
    bool operator==(const T* other) const { return m_ptr == other; }
private:
    T* m_ptr;
};

class IBinder {
public:
    virtual ~IBinder() {}
    virtual status_t transact(uint32_t code, const class Parcel& data, class Parcel* reply, uint32_t flags = 0) = 0;
};

class IMemoryHeap {
public:
    virtual ~IMemoryHeap() {}
    virtual size_t getSize() const = 0;
    static sp<IMemoryHeap> asInterface(const sp<IBinder>& obj);
};

class IMemory {
public:
    static const char* getInterfaceDescriptor();
};

class Parcel {
public:
    void writeInterfaceToken(const char*);
    sp<IBinder> readStrongBinder();
    int32_t readInt32();
};

class BpMemory {
private:
    mutable sp<IMemoryHeap> mHeap;
    mutable ssize_t mOffset;
    mutable size_t mSize;
public:
    sp<IBinder> remote() const;
    sp<IMemoryHeap> getMemory(ssize_t* offset, size_t* size) const;
};

template<typename INTERFACE>
inline sp<INTERFACE> interface_cast(const sp<IBinder>& obj) {
    return INTERFACE::asInterface(obj);
}

enum {
    NO_ERROR = 0,
    GET_MEMORY = 0
};

void android_errorWriteWithInfoLog(uint32_t tag, const char* subTag, int32_t uid, const char* data, uint32_t dataLen);