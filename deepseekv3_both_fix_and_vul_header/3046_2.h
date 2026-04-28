#include <string>

class MockPluginDelegate {
public:
    class PlatformVideoCapture;
    static PlatformVideoCapture* CreateVideoCapture(
        const std::string& device_id,
        const class GURL& document_url,
        class PlatformVideoCaptureEventHandler* handler);
    static PlatformVideoCapture* CreateVideoCapture(
        const std::string& device_id,
        class PlatformVideoCaptureEventHandler* handler);
};

class PlatformVideoCaptureEventHandler;
class GURL;