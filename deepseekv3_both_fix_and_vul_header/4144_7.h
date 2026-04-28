#include <string>
#include <memory>
#include <functional>

#define OS_WIN
#define OS_ANDROID

namespace base {
class TimeTicks {
public:
    static TimeTicks Now() { return TimeTicks(); }
};
enum TerminationStatus {
    TERMINATION_STATUS_STILL_RUNNING
};
class string16 {};
template <typename T>
class Unretained {
public:
    explicit Unretained(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
private:
    T* ptr_;
};
template <typename T, typename U>
static std::function<void()> Bind(T t, U u) {
    return [t, u](){ (u.get()->*t)(); };
}
}  // namespace base

namespace net {
enum LOAD_STATE { LOAD_STATE_IDLE };
}  // namespace net

#define SK_ColorTRANSPARENT 0
#define MSG_ROUTING_NONE 0

class BrowserContext {};
class NavigatorImpl {
public:
    NavigatorImpl(void*, void*) {}
};
class GeolocationServiceContext {
public:
    GeolocationServiceContext() {}
};
class BrowserAccessibilityStateImpl {
public:
    static BrowserAccessibilityStateImpl* GetInstance() { return nullptr; }
    int accessibility_mode() { return 0; }
};
class MediaWebContentsObserver {
public:
    MediaWebContentsObserver(void*) {}
};
class MediaWebContentsObserverAndroid : public MediaWebContentsObserver {
public:
    MediaWebContentsObserverAndroid(void* p) : MediaWebContentsObserver(p) {}
};
class WakeLockServiceContext {
public:
    WakeLockServiceContext(void*) {}
};

class WebContentsImpl {
public:
    struct Controller {
        Controller(WebContentsImpl*, BrowserContext*) {}
    };
    struct AudioStreamMonitor {
        explicit AudioStreamMonitor(WebContentsImpl*) {}
    };
    struct WeakFactory {
        explicit WeakFactory(WebContentsImpl* p = nullptr) : ptr(p) {}
        WebContentsImpl* ptr;
    };

    explicit WebContentsImpl(BrowserContext* browser_context);
    void OnFrameRemoved();
    
    class FrameTree {
    public:
        FrameTree(NavigatorImpl*, void*, void*, void*, void*) {}
        void SetFrameRemoveListener(std::function<void()> f) { f(); }
    };

private:
    void* delegate_;
    Controller controller_;
    void* render_view_host_delegate_view_;
    bool created_with_opener_;
    void* accessible_parent_;
    FrameTree frame_tree_;
    bool is_loading_;
    bool is_load_to_different_document_;
    base::TerminationStatus crashed_status_;
    int crashed_error_code_;
    bool waiting_for_response_;
    std::pair<net::LOAD_STATE, base::string16> load_state_;
    int upload_size_;
    int upload_position_;
    bool is_resume_pending_;
    bool displayed_insecure_content_;
    bool has_accessed_initial_document_;
    int theme_color_;
    int last_sent_theme_color_;
    bool did_first_visually_non_empty_paint_;
    int capturer_count_;
    bool should_normally_be_visible_;
    bool is_being_destroyed_;
    bool notify_disconnection_;
    void* dialog_manager_;
    bool is_showing_before_unload_dialog_;
    base::TimeTicks last_active_time_;
    bool closed_by_user_gesture_;
    int minimum_zoom_percent_;
    int maximum_zoom_percent_;
    int zoom_scroll_remainder_;
    void* render_view_message_source_;
    void* render_frame_message_source_;
    int fullscreen_widget_routing_id_;
    bool fullscreen_widget_had_focus_at_shutdown_;
    bool is_subframe_;
    bool force_disable_overscroll_content_;
    bool last_dialog_suppressed_;
    std::unique_ptr<GeolocationServiceContext> geolocation_service_context_;
    int accessibility_mode_;
    AudioStreamMonitor audio_stream_monitor_;
    bool virtual_keyboard_requested_;
    bool page_scale_factor_is_one_;
    WeakFactory loading_weak_factory_;
    WeakFactory weak_factory_;
    std::unique_ptr<MediaWebContentsObserver> media_web_contents_observer_;
    std::unique_ptr<WakeLockServiceContext> wake_lock_service_context_;
    static constexpr float kMinimumZoomFactor = 0.0f;
    static constexpr float kMaximumZoomFactor = 0.0f;
};