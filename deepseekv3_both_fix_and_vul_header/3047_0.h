#include <string>
#include <memory>
#include <functional>

namespace base {
template <typename T>
class WeakPtr {
public:
    T* get() const { return nullptr; }
    T* operator->() const { return nullptr; }
};

template <typename F, typename... Args>
void* Bind(F&& f, Args&&... args) {
    static auto callback = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
    return reinterpret_cast<void*>(&callback);
}
} // namespace base

namespace webkit {
namespace ppapi {
class PluginDelegate {
public:
    class PlatformAudioInputClient {};
};
} // namespace ppapi
} // namespace webkit

namespace media {
enum ChannelLayout {
    CHANNEL_LAYOUT_MONO
};

class AudioParameters {
public:
    enum Format { AUDIO_PCM_LINEAR };
    void Reset(Format, ChannelLayout, int, int, int, int, int) {}
};

class AudioManagerBase {
public:
    static const char* kDefaultDeviceId;
};
const char* AudioManagerBase::kDefaultDeviceId = "";
} // namespace media

class GURL {};

class PepperPluginDelegateImpl {
public:
    int GetRoutingID() const;
    void OpenDevice(int device_type, const std::string& device_id, const GURL& document_url, void* callback);
    void OpenDevice(int device_type, const std::string& device_id, void* callback);
};

class AudioInputIPC;
class AudioInputMessageFilter {
public:
    AudioInputIPC* CreateAudioInputIPC(int routing_id);
};

class RenderThreadImpl {
public:
    static RenderThreadImpl* current();
    AudioInputMessageFilter* audio_input_message_filter();
};

class PepperPlatformAudioInputImpl {
public:
    bool Initialize(
        const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
        const std::string& device_id,
        const GURL& document_url,
        int sample_rate,
        int frames_per_buffer,
        webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
    bool Initialize(
        const base::WeakPtr<PepperPluginDelegateImpl>& plugin_delegate,
        const std::string& device_id,
        int sample_rate,
        int frames_per_buffer,
        webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client);
    void OnDeviceOpened();
    
private:
    void* main_message_loop_proxy_;
    AudioInputIPC* ipc_;
    base::WeakPtr<PepperPluginDelegateImpl> plugin_delegate_;
    webkit::ppapi::PluginDelegate::PlatformAudioInputClient* client_;
    media::AudioParameters params_;
};

#define PP_DEVICETYPE_DEV_AUDIOCAPTURE 0
#define DCHECK(expr)