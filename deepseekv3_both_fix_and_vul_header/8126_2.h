#include <stdint.h>
#include <string>

class String16 {
public:
    explicit String16(const char16_t* o);
    explicit String16(const std::u16string& o);
};

template<typename T> class sp {
    T* m_ptr;
public:
    sp() : m_ptr(nullptr) {}
    sp(T* other) : m_ptr(other) {}
    T* operator->() const { return m_ptr; }
    operator T*() const { return m_ptr; }
};

enum media_recorder_states {
    MEDIA_RECORDER_IDLE,
};

class IMediaPlayerService {
public:
    sp<class IMediaRecorder> createMediaRecorder(const String16& opPackageName);
};

class IMediaRecorder {};

class MediaRecorder {
public:
    MediaRecorder(const String16& opPackageName);
private:
    void* mSurfaceMediaSource;
    sp<IMediaRecorder> mMediaRecorder;
    media_recorder_states mCurrentState;
    void doCleanUp();
    sp<IMediaPlayerService> getMediaPlayerService();
};

#define ALOGV(...)