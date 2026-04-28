#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace content {
class WebContents {
public:
    class BrowserContext* GetBrowserContext();
};
class BrowserContext;

enum MediaStreamType {
    MEDIA_NO_SERVICE,
    MEDIA_DEVICE_AUDIO_CAPTURE,
    MEDIA_DEVICE_VIDEO_CAPTURE,
    MEDIA_OPEN_DEVICE
};

struct MediaStreamRequest {
    MediaStreamType audio_type;
    MediaStreamType video_type;
    MediaStreamType request_type;
};

struct MediaStreamUI;
using MediaResponseCallback = std::function<void(
    const std::vector<std::string>&,
    int,
    std::unique_ptr<MediaStreamUI>)>;
}  // namespace content

class Profile {
public:
    static Profile* FromBrowserContext(content::BrowserContext* context);
};

class TabSpecificContentSettings {
public:
    static TabSpecificContentSettings* FromWebContents(content::WebContents* web_contents);
};

namespace prefs {
extern const char kAudioCaptureAllowed[];
extern const char kAudioCaptureAllowedUrls[];
extern const char kVideoCaptureAllowed[];
extern const char kVideoCaptureAllowedUrls[];
}

enum DevicePolicy { ALWAYS_DENY, ALWAYS_ALLOW, ASK };

class MediaStreamDevicesController {
private:
    content::WebContents* web_contents_;
    const content::MediaStreamRequest& request_;
    const content::MediaResponseCallback& callback_;
    bool microphone_requested_;
    bool webcam_requested_;
    Profile* profile_;
    TabSpecificContentSettings* content_settings_;
public:
    MediaStreamDevicesController(
        content::WebContents* web_contents,
        const content::MediaStreamRequest& request,
        const content::MediaResponseCallback& callback);
    DevicePolicy GetDevicePolicy(const char* allowed_pref, const char* allowed_urls_pref);
};