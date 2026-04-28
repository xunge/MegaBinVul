#include <memory>

template<typename T> class sp {
public:
    sp() : ptr_(nullptr) {}
    sp(T* ptr) : ptr_(ptr) {}
    operator T*() const { return ptr_; }
    T* operator->() const { return ptr_; }
    bool operator==(const sp<T>& other) const { return ptr_ == other.ptr_; }
    bool operator==(T* other) const { return ptr_ == other; }
private:
    T* ptr_;
};

struct IMediaPlayerService {
    sp<struct IMediaMetadataRetriever> createMetadataRetriever();
};

struct IMediaMetadataRetriever {};

sp<IMediaPlayerService> getService();

#define ALOGV(...)
#define ALOGE(...)

struct MediaMetadataRetriever {
    sp<IMediaMetadataRetriever> mRetriever;
    MediaMetadataRetriever();
};