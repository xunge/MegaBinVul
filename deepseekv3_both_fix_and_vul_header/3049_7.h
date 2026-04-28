#include <stdint.h>
#include <string>
#include <memory>

#define PP_OK_COMPLETIONPENDING 0
#define PP_ERROR_FAILED -1

struct PP_VideoCaptureDeviceInfo_Dev;

namespace ppapi {
namespace host {
class HostMessageContext {
public:
    HostMessageContext* MakeReplyMessageContext();
};
}  // namespace host
}  // namespace ppapi

namespace webkit {
namespace ppapi {
class PluginDelegate {
public:
    std::shared_ptr<void> CreateVideoCapture(const std::string& device_id, void* host);
    std::shared_ptr<void> CreateVideoCapture(const std::string& device_id, const std::string& url, void* host);
};

class PluginInstance {
public:
    struct Container {
        struct Element {
            struct Document {
                std::string url();
            };
            Document document();
        };
        Element element();
    };
    Container* container();
};
}  // namespace ppapi
}  // namespace webkit

class RendererPpapiHost {
public:
    webkit::ppapi::PluginInstance* GetPluginInstance(void* pp_instance);
};

class PepperVideoCaptureHost {
public:
    int32_t OnOpen(ppapi::host::HostMessageContext* context,
                  const std::string& device_id,
                  const PP_VideoCaptureDeviceInfo_Dev& requested_info,
                  uint32_t buffer_count);
protected:
    webkit::ppapi::PluginDelegate* GetPluginDelegate();
    void SetRequestedInfo(const PP_VideoCaptureDeviceInfo_Dev& requested_info, uint32_t buffer_count);
    void OnInitialized(void* platform_video_capture, bool success);
    ppapi::host::HostMessageContext* open_reply_context_;
    std::shared_ptr<void> platform_video_capture_;
    RendererPpapiHost* renderer_ppapi_host_;
    void* pp_instance();
};