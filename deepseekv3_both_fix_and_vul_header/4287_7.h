#include <stdint.h>
#include <sys/types.h>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <memory>

#define OK 0
#define NO_ERROR 0
#define PERMISSION_DENIED -1

typedef int32_t status_t;

class String8 {
public:
    String8();
    explicit String8(const char* str);
    const char* string() const;
    size_t size() const;
};

template<typename T>
class Vector {
public:
    size_t size() const;
    const T* array() const;
    T* editArray();
    void setCapacity(size_t size);
};

template<typename KEY, typename VALUE>
class KeyedVector {
public:
    size_t size() const;
    const KEY& keyAt(size_t index) const;
    const VALUE& valueAt(size_t index) const;
    void add(const KEY& key, const VALUE& value);
};

template<typename T>
class List {
public:
    class iterator {
    public:
        iterator& operator++();
        iterator operator++(int);
        T& operator*();
        bool operator!=(const iterator& other);
        T* operator->();
    };
    iterator begin();
    iterator end();
    size_t size() const;
};

class IBinder;

template<typename T>
class sp {
public:
    sp(T* other);
    T* get() const;
};

class Parcel {
public:
    int32_t readInt32() const;
    void writeInt32(int32_t val);
    String8 readString8() const;
    void writeString8(const String8& str);
    void read(void* outData, size_t len) const;
    void write(const void* data, size_t len);
    bool enforceInterface(const String8& interface) const;
    sp<IBinder> readStrongBinder() const;
};

class BBinder {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};

class IBinder {
public:
    virtual status_t transact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0) = 0;
};

template<typename INTERFACE>
INTERFACE* interface_cast(const sp<IBinder>& obj);

class IDrmClient {};

class DrmPlugin {
public:
    enum KeyType {
        kKeyType_Streaming,
        kKeyType_Offline,
        kKeyType_Release
    };
    enum KeyRequestType {
        kKeyRequestType_Initial,
        kKeyRequestType_Renewal,
        kKeyRequestType_Release,
        kKeyRequestType_Unknown
    };
};

class IDrm {
public:
    static String8 getInterfaceDescriptor();
    virtual status_t initCheck() = 0;
    virtual status_t isCryptoSchemeSupported(const uint8_t uuid[16], const String8& mimeType) = 0;
    virtual status_t createPlugin(const uint8_t uuid[16]) = 0;
    virtual status_t destroyPlugin() = 0;
    virtual status_t openSession(Vector<uint8_t>& sessionId) = 0;
    virtual status_t closeSession(const Vector<uint8_t>& sessionId) = 0;
    virtual status_t getKeyRequest(const Vector<uint8_t>& scope,
                                  const Vector<uint8_t>& initData,
                                  const String8& mimeType,
                                  DrmPlugin::KeyType keyType,
                                  const KeyedVector<String8, String8>& optionalParameters,
                                  Vector<uint8_t>& request,
                                  String8& defaultUrl,
                                  DrmPlugin::KeyRequestType *keyRequestType) = 0;
    virtual status_t provideKeyResponse(const Vector<uint8_t>& scope,
                                       const Vector<uint8_t>& response,
                                       Vector<uint8_t>& keySetId) = 0;
    virtual status_t removeKeys(const Vector<uint8_t>& keySetId) = 0;
    virtual status_t restoreKeys(const Vector<uint8_t>& sessionId,
                                const Vector<uint8_t>& keySetId) = 0;
    virtual status_t queryKeyStatus(const Vector<uint8_t>& sessionId,
                                   KeyedVector<String8, String8>& infoMap) const = 0;
    virtual status_t getProvisionRequest(String8& certType,
                                        String8& certAuthority,
                                        Vector<uint8_t>& request,
                                        String8& defaultUrl) = 0;
    virtual status_t provideProvisionResponse(const Vector<uint8_t>& response,
                                             Vector<uint8_t>& certificate,
                                             Vector<uint8_t>& wrappedKey) = 0;
    virtual status_t unprovisionDevice() = 0;
    virtual status_t getSecureStops(List<Vector<uint8_t> >& secureStops) = 0;
    virtual status_t getSecureStop(const Vector<uint8_t>& ssid,
                                  Vector<uint8_t>& secureStop) = 0;
    virtual status_t releaseSecureStops(const Vector<uint8_t>& ssRelease) = 0;
    virtual status_t releaseAllSecureStops() = 0;
    virtual status_t getPropertyString(const String8& name,
                                      String8& value) const = 0;
    virtual status_t getPropertyByteArray(const String8& name,
                                         Vector<uint8_t>& value) const = 0;
    virtual status_t setPropertyString(const String8& name,
                                      const String8& value) = 0;
    virtual status_t setPropertyByteArray(const String8& name,
                                         const Vector<uint8_t>& value) = 0;
    virtual status_t setCipherAlgorithm(const Vector<uint8_t>& sessionId,
                                       const String8& algorithm) = 0;
    virtual status_t setMacAlgorithm(const Vector<uint8_t>& sessionId,
                                    const String8& algorithm) = 0;
    virtual status_t encrypt(const Vector<uint8_t>& sessionId,
                             const Vector<uint8_t>& keyId,
                             const Vector<uint8_t>& input,
                             const Vector<uint8_t>& iv,
                             Vector<uint8_t>& output) = 0;
    virtual status_t decrypt(const Vector<uint8_t>& sessionId,
                             const Vector<uint8_t>& keyId,
                             const Vector<uint8_t>& input,
                             const Vector<uint8_t>& iv,
                             Vector<uint8_t>& output) = 0;
    virtual status_t sign(const Vector<uint8_t>& sessionId,
                          const Vector<uint8_t>& keyId,
                          const Vector<uint8_t>& message,
                          Vector<uint8_t>& signature) = 0;
    virtual status_t verify(const Vector<uint8_t>& sessionId,
                            const Vector<uint8_t>& keyId,
                            const Vector<uint8_t>& message,
                            const Vector<uint8_t>& signature,
                            bool& match) = 0;
    virtual status_t signRSA(const Vector<uint8_t>& sessionId,
                             const String8& algorithm,
                             const Vector<uint8_t>& message,
                             const Vector<uint8_t>& wrappedKey,
                             Vector<uint8_t>& signature) = 0;
    virtual status_t setListener(const sp<IDrmClient>& listener) = 0;
};

class BnDrm : public BBinder, public IDrm {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);
};

template<typename T>
void writeVector(Parcel* reply, const Vector<T>& vec) {
    reply->writeInt32(vec.size());
    reply->write(vec.array(), vec.size());
}

template<typename T>
void readVector(const Parcel& data, Vector<T>& vec) {
    size_t size = data.readInt32();
    vec.setCapacity(size);
    data.read(vec.editArray(), size);
}

#define CHECK_INTERFACE(interface, data, reply) \
    do { if (!data.enforceInterface(interface::getInterfaceDescriptor())) { \
        return PERMISSION_DENIED; \
    } } while (0)

enum {
    INIT_CHECK,
    IS_CRYPTO_SUPPORTED,
    CREATE_PLUGIN,
    DESTROY_PLUGIN,
    OPEN_SESSION,
    CLOSE_SESSION,
    GET_KEY_REQUEST,
    PROVIDE_KEY_RESPONSE,
    REMOVE_KEYS,
    RESTORE_KEYS,
    QUERY_KEY_STATUS,
    GET_PROVISION_REQUEST,
    PROVIDE_PROVISION_RESPONSE,
    UNPROVISION_DEVICE,
    GET_SECURE_STOPS,
    GET_SECURE_STOP,
    RELEASE_SECURE_STOPS,
    RELEASE_ALL_SECURE_STOPS,
    GET_PROPERTY_STRING,
    GET_PROPERTY_BYTE_ARRAY,
    SET_PROPERTY_STRING,
    SET_PROPERTY_BYTE_ARRAY,
    SET_CIPHER_ALGORITHM,
    SET_MAC_ALGORITHM,
    ENCRYPT,
    DECRYPT,
    SIGN,
    VERIFY,
    SIGN_RSA,
    SET_LISTENER
};