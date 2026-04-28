#include <stdint.h>
#include <stdlib.h>

typedef int32_t status_t;
#define NO_ERROR 0
#define NO_MEMORY -12
#define MAX_ITEMS_PER_LIST 100

enum {
    LIST_MODULES,
    ATTACH,
    SET_CAPTURE_STATE
};

struct sound_trigger_module_descriptor {
    // Add necessary fields here
};
typedef int sound_trigger_module_handle_t;

class Parcel {
public:
    int32_t readInt32() const;
    void writeInt32(int32_t);
    void write(const void*, size_t);
    bool read(void*, size_t) const;
    void* readStrongBinder() const;
    void writeStrongBinder(void*);
};

template<typename T> class sp {
public:
    sp(T* = nullptr);
    T* operator->() const;
    T* get() const;
    bool operator!=(int) const;
    operator T*() const;
};

class ISoundTriggerHwService {};
class ISoundTriggerClient {};
class ISoundTrigger {};
class IInterface {
public:
    static void* asBinder(ISoundTrigger*);
};
class BBinder {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
};
class BnSoundTriggerHwService : public BBinder {
public:
    virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);
    virtual status_t listModules(sound_trigger_module_descriptor*, unsigned int*);
    virtual status_t attach(sound_trigger_module_handle_t, const sp<ISoundTriggerClient>&, sp<ISoundTrigger>&);
    virtual status_t setCaptureState(bool);
};

template<typename T> T* interface_cast(void*);

#define CHECK_INTERFACE(interface, data, reply)
#define ALOGV(...)