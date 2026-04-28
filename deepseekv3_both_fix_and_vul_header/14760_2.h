#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef int status_t;
#define NO_ERROR 0
#define BAD_VALUE (-1)
#define NO_MEMORY (-2)
#define FDS_NOT_ALLOWED (-3)

typedef uintptr_t binder_size_t;

#define BINDER_TYPE_FD 2

struct flat_binder_object {
    int type;
    int handle;
    int cookie;
};

class ProcessState {
public:
    static ProcessState* self();
};

template<typename T>
class sp {
public:
    sp(T* ptr) : mPtr(ptr) {}
    T* operator->() { return mPtr; }
private:
    T* mPtr;
};

class Parcel {
private:
    uint8_t* mData;
    binder_size_t* mObjects;
    size_t mObjectsSize;
    size_t mObjectsCapacity;
    size_t mDataSize;
    size_t mDataCapacity;
    int mDataPos;
    bool mHasFds;
    bool mFdsKnown;
    bool mAllowFds;

public:
    status_t appendFrom(const Parcel *parcel, size_t offset, size_t len);
    status_t growData(size_t len);
    void acquire_object(const sp<ProcessState>& proc, const flat_binder_object& obj, Parcel* parcel);
};