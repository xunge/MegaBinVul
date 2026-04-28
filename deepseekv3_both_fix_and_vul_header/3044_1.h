#include <string>
#include <memory>
#include <functional>

class PP_DeviceType_Dev {};
class GURL {
public:
    GURL() {}
    GURL GetOrigin() const { return GURL(); }
};
class OpenDeviceCallback {};

class PepperDeviceEnumerationEventHandler {
public:
    int RegisterOpenDeviceCallback(const OpenDeviceCallback& callback);
    static int FromPepperDeviceType(PP_DeviceType_Dev type);
    void OnDeviceOpenFailed(int request_id);
    std::weak_ptr<PepperDeviceEnumerationEventHandler> AsWeakPtr();
    std::shared_ptr<PepperDeviceEnumerationEventHandler> get();
};

class MediaStreamDispatcher {
public:
    void OpenDevice(int request_id,
                   std::weak_ptr<PepperDeviceEnumerationEventHandler> handler,
                   const std::string& device_id,
                   int type,
                   GURL url);
};

class RenderView {
public:
    MediaStreamDispatcher* media_stream_dispatcher();
};

class PepperPluginDelegateImpl {
public:
    int OpenDevice(PP_DeviceType_Dev type,
                  const std::string& device_id,
                  const OpenDeviceCallback& callback);
    int OpenDevice(PP_DeviceType_Dev type,
                  const std::string& device_id,
                  const GURL& document_url,
                  const OpenDeviceCallback& callback);
private:
    std::shared_ptr<PepperDeviceEnumerationEventHandler> device_enumeration_event_handler_;
    RenderView* render_view_;
};

#define ENABLE_WEBRTC
#define FROM_HERE ""

namespace base {
class MessageLoop {
public:
    static MessageLoop* current();
    void PostTask(const std::string& from_here, const std::function<void()>& task);
};
template <typename F, typename... Args>
auto Bind(F&& f, Args&&... args) {
    return std::bind(std::forward<F>(f), std::forward<Args>(args)...);
}
}