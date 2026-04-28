#include <stddef.h>
#include <assert.h>
#include <memory>

class AudioBus {
public:
    void zero();
    class Bus {
    public:
        AudioBus* bus();
    };
};

class AudioSourceProvider {
public:
    void provideInput(AudioBus*, size_t);
};

class MutexTryLocker {
public:
    MutexTryLocker(void*);
    bool locked();
};

class WebMediaPlayer {
public:
    bool didPassCORSAccessCheck();
};

class SecurityOrigin {
public:
    bool canRequest(const char*);
};

class MediaElementAudioSourceNode {
public:
    void process(size_t numberOfFrames);
    AudioBus::Bus* output(size_t index);
    class Context {
    public:
        SecurityOrigin* securityOrigin();
    };
    Context* context();
    class HTMLMediaElement {
    public:
        AudioSourceProvider* audioSourceProvider();
        WebMediaPlayer* webMediaPlayer();
        const char* currentSrc();
    };
    HTMLMediaElement* mediaElement();

private:
    size_t m_sourceNumberOfChannels;
    double m_sourceSampleRate;
    MutexTryLocker m_processLock;
    class MultiChannelResampler {
    public:
        void process(AudioSourceProvider*, AudioBus*, size_t);
    };
    std::shared_ptr<MultiChannelResampler> m_multiChannelResampler;
    double sampleRate();
};

#define ASSERT assert