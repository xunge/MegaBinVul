#include <stdint.h>
#include <sys/types.h>
#include <cstddef>

typedef int32_t status_t;
#define OK 0
#define BAD_VALUE (-1)

class Mutex {
public:
    class Autolock {
    public:
        Autolock(Mutex& mutex) {}
    };
};

class IMediaPlayer {
public:
    virtual ~IMediaPlayer() {}
};

class AudioOutput {
public:
    void setNextOutput(AudioOutput* output) {}
};

class Player {
public:
    bool hardwareOutput() { return false; }
    void setNextPlayer(Player* player) {}
};

template<typename T>
class sp {
public:
    sp(T* ptr = nullptr) : mPtr(ptr) {}
    T* get() const { return mPtr; }
    operator bool() const { return mPtr != nullptr; }
    T* operator->() const { return mPtr; }
    T& operator*() const { return *mPtr; }
    T* mPtr;
};

class MediaPlayerService {
public:
    class Client;
    bool hasClient(const sp<Client>& client) { return false; }
    
    class Client : public IMediaPlayer {
    public:
        status_t setNextPlayer(const sp<IMediaPlayer>& player);
        sp<Client> mNextClient;
        AudioOutput* mAudioOutput;
        Player* mPlayer;
        Mutex mLock;
        MediaPlayerService* mService;

        Player* getPlayer() { return mPlayer; }
    };
};

#define ALOGV(...)
#define ALOGE(...)