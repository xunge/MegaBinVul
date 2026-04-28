#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;
#define NO_ERROR 0
#define UNKNOWN_ERROR (-1)

class MediaPlayer;

class IMediaPlayer {
public:
    virtual status_t setDataSource(int fd, int64_t offset, int64_t length) = 0;
};

class IMediaPlayerService {
public:
    virtual IMediaPlayer* create(MediaPlayer* client, int audioSessionId) = 0;
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : m_ptr(ptr) {}
    sp(const sp<T>& other) : m_ptr(other.m_ptr) {}
    ~sp() {}
    
    T* operator->() const { return m_ptr; }
    operator bool() const { return m_ptr != nullptr; }
    void clear() { m_ptr = nullptr; }
    
private:
    T* m_ptr;
};

class MediaPlayer {
public:
    status_t setDataSource(int fd, int64_t offset, int64_t length);
private:
    int mAudioSessionId = 0;
    sp<IMediaPlayerService> getMediaPlayerService() { return nullptr; }
    status_t doSetRetransmitEndpoint(const sp<IMediaPlayer>& player) { return NO_ERROR; }
    status_t attachNewPlayer(const sp<IMediaPlayer>& player) { return NO_ERROR; }
};

#define ALOGV(...)
#define PRId64 "lld"