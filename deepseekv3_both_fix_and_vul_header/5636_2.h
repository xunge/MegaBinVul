#include <iostream>
#include <memory>

namespace blink {
class WebMediaStreamSource {
public:
    void setExtraData(void* data);
    void addAudioConsumer(void* consumer);
};
}

template <typename T>
class scoped_refptr {
public:
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};

class WebAudioCapturerSource {
public:
    WebAudioCapturerSource();
    explicit WebAudioCapturerSource(blink::WebMediaStreamSource& source);
};

class MediaStreamAudioSource {
public:
    void SetAudioCapturer(void* capturer);
    void SetLocalAudioSource(void* source);
};

class WebRtcAudioDevice {
public:
    void* GetDefaultCapturer();
};

class PeerConnectionDependencyFactory {
public:
    WebRtcAudioDevice* GetWebRtcAudioDevice();
    scoped_refptr<MediaStreamAudioSource> CreateLocalAudioSource(void* config);
    scoped_refptr<WebAudioCapturerSource> CreateWebAudioSource(blink::WebMediaStreamSource* source);
};

#define DVLOG(level) std::cout