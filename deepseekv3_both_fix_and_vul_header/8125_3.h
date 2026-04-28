#include <stdint.h>
#include <sys/types.h>

typedef int32_t status_t;
#define NO_ERROR 0
#define UNKNOWN_ERROR (-1)

template<typename T> class sp {
public:
    sp(T* other = nullptr);
    void clear();
    T* operator->() const;
    bool operator!=(int) const;
};

class IStreamSource {};
class MediaPlayer;
class IMediaPlayer;
class IMediaPlayerService {
public:
    sp<IMediaPlayer> create(MediaPlayer*, int);
};

class IMediaPlayer {
public:
    status_t setDataSource(const sp<IStreamSource>&);
};

#define ALOGV(...)

class MediaPlayer {
public:
    status_t setDataSource(const sp<IStreamSource> &source);
private:
    int mAudioSessionId;
    sp<IMediaPlayerService> getMediaPlayerService();
    status_t doSetRetransmitEndpoint(const sp<IMediaPlayer>&);
    status_t attachNewPlayer(const sp<IMediaPlayer>&);
};