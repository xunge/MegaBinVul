#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

enum status_t {
    OK = 0
};

class IBinder {
public:
    virtual ~IBinder() {}
};

class IMemory : public IBinder {
public:
    virtual size_t size() const = 0;
    virtual ~IMemory() {}
};

template<typename T>
class sp {
public:
    sp(T* ptr) : mPtr(ptr) {}
    sp(const sp<T>& other) : mPtr(other.mPtr) {}
    T* operator->() const { return mPtr; }
    T* get() const { return mPtr; }
private:
    T* mPtr;
};

class Parcel {
public:
    int32_t readInt32() const;
    void writeInt32(int32_t);
    void read(void*, size_t) const;
    void write(const void*, size_t);
    const char* readCString() const;
    void writeCString(const char*);
    sp<IBinder> readStrongBinder() const;
    int64_t readInt64() const;
};

class BBinder : public IBinder {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};

template<typename T>
class Vector {
public:
    size_t size() const;
    void setCapacity(size_t size);
    T* array();
    void readFromParcel(const Parcel& data) {
        size_t size = data.readInt32();
        if (size > 0) {
            setCapacity(size);
            data.read(array(), size);
        }
    }
};

class AString {
public:
    const char* c_str() const;
};

class ICrypto {
};

class IDrm {
};

class CryptoPlugin {
public:
    enum Mode {
    };

    struct SubSample {
        size_t mNumBytesOfClearData;
        size_t mNumBytesOfEncryptedData;
    };
};

template<typename INTERFACE>
class BnInterface : public BBinder {
};

class BnCrypto : public BnInterface<ICrypto> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
    int32_t initCheck();
    int32_t isCryptoSchemeSupported(const uint8_t[16]);
    int32_t createPlugin(const uint8_t[16], void*, size_t);
    int32_t destroyPlugin();
    int32_t requiresSecureDecoderComponent(const char*);
    ssize_t decrypt(bool, const uint8_t[16], const uint8_t[16], CryptoPlugin::Mode,
                    const sp<IMemory>&, int32_t, const CryptoPlugin::SubSample*, int32_t,
                    void*, AString*);
    void notifyResolution(int32_t, int32_t);
    int32_t setMediaDrmSession(const Vector<uint8_t>&);
    bool isCryptoError(ssize_t);
};

template<typename T>
T* interface_cast(const sp<IBinder>& binder) {
    return dynamic_cast<T*>(binder.get());
}

enum {
    INIT_CHECK,
    IS_CRYPTO_SUPPORTED,
    CREATE_PLUGIN,
    DESTROY_PLUGIN,
    REQUIRES_SECURE_COMPONENT,
    DECRYPT,
    NOTIFY_RESOLUTION,
    SET_MEDIADRM_SESSION
};

#define CHECK_INTERFACE(interface, data, reply)
#define CHECK_LE(a, b)
#define readVector(data, vec) vec.readFromParcel(data)