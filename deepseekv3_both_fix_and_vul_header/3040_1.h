#include <stdbool.h>

struct content {
    enum {
        MEDIA_OPEN_DEVICE,
        MEDIA_TAB_AUDIO_CAPTURE,
        MEDIA_TAB_VIDEO_CAPTURE
    } request_type;
    int audio_type;
    int video_type;
    struct {
        bool is_empty();
    } security_origin;
};

struct MediaStreamDevicesController {
    struct content request_;
    bool Accept(bool);
    bool Deny(bool);
    bool HasAnyAvailableDevice();
    bool IsRequestAllowedByDefault();
    bool IsRequestBlockedByDefault();
    bool IsDefaultMediaAccessBlocked();
    bool DismissInfoBarAndTakeActionOnSettings();
};