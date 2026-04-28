#include <string>
#include <memory>

namespace webkit {
namespace ppapi {

class PluginDelegate {
public:
    class PlatformVideoCapture {};
    class PlatformVideoCaptureEventHandler;
};

}  // namespace ppapi
}  // namespace webkit

class GURL;

template<typename T>
class WeakPtr {
public:
    T* get() const { return nullptr; }
};

class PepperPluginDelegateImpl;

class PepperPlatformVideoCaptureImpl : public webkit::ppapi::PluginDelegate::PlatformVideoCapture {
public:
    PepperPlatformVideoCaptureImpl(WeakPtr<PepperPluginDelegateImpl>,
                                  const std::string&,
                                  const GURL&,
                                  webkit::ppapi::PluginDelegate::PlatformVideoCaptureEventHandler*);
    PepperPlatformVideoCaptureImpl(WeakPtr<PepperPluginDelegateImpl>,
                                  const std::string&,
                                  webkit::ppapi::PluginDelegate::PlatformVideoCaptureEventHandler*);
};

class PepperPluginDelegateImpl {
public:
    using PlatformVideoCaptureEventHandler = webkit::ppapi::PluginDelegate::PlatformVideoCaptureEventHandler;
    WeakPtr<PepperPluginDelegateImpl> AsWeakPtr();
    
    webkit::ppapi::PluginDelegate::PlatformVideoCapture* CreateVideoCapture(
        const std::string& device_id,
        const GURL& document_url,
        PlatformVideoCaptureEventHandler* handler);
        
    webkit::ppapi::PluginDelegate::PlatformVideoCapture* CreateVideoCapture(
        const std::string& device_id,
        PlatformVideoCaptureEventHandler* handler);
};