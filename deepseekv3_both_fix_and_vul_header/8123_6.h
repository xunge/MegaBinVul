#include <stdint.h>
#include <string.h>

class MediaPlayer;

typedef int32_t status_t;
#define NO_ERROR 0
#define BAD_VALUE (-1)

template<typename T> class sp {
public:
    T* operator->() const { return nullptr; }
    void clear() {}
    operator bool() const { return false; }
};

template<typename KEY, typename VALUE> class KeyedVector {
public:
    void clear() {}
};

class String8 {};
class IMediaHTTPService {};
class IMediaPlayer {
public:
    status_t setDataSource(const sp<IMediaHTTPService>&, const char*, const KeyedVector<String8, String8>*) { return NO_ERROR; }
};
class IMediaPlayerService {
public:
    sp<IMediaPlayer> create(MediaPlayer*, int) { return sp<IMediaPlayer>(); }
};

class MediaPlayer {
public:
    status_t setDataSource(const sp<IMediaHTTPService>& httpService,
                          const char* url,
                          const KeyedVector<String8, String8>* headers);
    status_t doSetRetransmitEndpoint(const sp<IMediaPlayer>& player) { return NO_ERROR; }
    status_t attachNewPlayer(const sp<IMediaPlayer>& player) { return NO_ERROR; }
    int mAudioSessionId = 0;
};

sp<IMediaPlayerService> getMediaPlayerService() { return sp<IMediaPlayerService>(); }

#define ALOGV(...)