#include <stdint.h>

namespace content {
enum InvalidateTypes {
  INVALIDATE_TYPE_URL,
  INVALIDATE_TYPE_LOAD
};
}  // namespace content

namespace tracked_objects {
class ScopedTracker {
 public:
  ScopedTracker(const char* function);
  ~ScopedTracker();
};
}  // namespace tracked_objects

#define FROM_HERE_WITH_EXPLICIT_FUNCTION(x) x

class WebContents;
class Browser {
 public:
  void NavigationStateChanged(WebContents* source, content::InvalidateTypes changed_flags);
  void ScheduleUIUpdate(WebContents* source, content::InvalidateTypes changed_flags);
  void TabStateChanged();

  class CommandController {
   public:
    void TabStateChanged();
  };
  CommandController* command_controller_;

  class HostedAppController {
   public:
    void UpdateLocationBarVisibility(bool visible);
  };
  HostedAppController* hosted_app_controller_;

  class BookmarkAppController {
   public:
    void UpdateLocationBarVisibility(bool visible);
  };
  BookmarkAppController* bookmark_app_controller_;
};