#include <stddef.h>
#include <assert.h>

#define DCHECK_EQ(a, b) assert((a) == (b))

struct OneClickSigninSyncStarter {
  enum SyncConfiguration {
    SYNC_WITH_DEFAULT_SETTINGS,
    UNDO_SYNC
  };
};

class OneClickSigninBubbleView {
public:
  void WindowClosing();
  static OneClickSigninBubbleView* bubble_view_;
  bool is_sync_dialog_;
  struct {
    bool is_null() const { return false; }
    void Run(OneClickSigninSyncStarter::SyncConfiguration) {}
  } start_sync_callback_;
};

namespace base {
  template <typename T>
  T ResetAndReturn(T* callback) { return *callback; }
}

OneClickSigninBubbleView* OneClickSigninBubbleView::bubble_view_ = nullptr;