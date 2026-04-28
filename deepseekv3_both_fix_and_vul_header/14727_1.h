#include <stdbool.h>

struct Browser {
    bool is_app() const;
    struct {
        bool should_use_web_app_frame();
    } *hosted_app_controller_;
    struct {
        bool should_use_web_app_frame();
    } *bookmark_app_controller_;
    
    bool ShouldUseWebAppFrame() const;
};