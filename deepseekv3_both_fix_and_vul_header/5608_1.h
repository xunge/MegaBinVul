#include <memory>
#include <cassert>

#define DCHECK(condition) assert(condition)

namespace ui {
class MotionEvent {
 public:
  std::unique_ptr<MotionEvent> Cancel() const;
};
}  // namespace ui

class GestureProvider {
 public:
  const ui::MotionEvent* GetCurrentDownEvent() const;
  void ResetDetection();
};

class RenderWidgetHostViewAndroid {
 public:
  void ResetGestureDetection();
  void OnTouchEvent(const ui::MotionEvent& event);
  GestureProvider gesture_provider_;
};

template <typename T>
using scoped_ptr = std::unique_ptr<T>;