#include <stdbool.h>
#include <stdint.h>

namespace gfx {
    struct Point { int x; int y; };
}

namespace ui {
    struct Accelerator {};
    enum EventType { ET_MOUSE_RELEASED };
    enum EventFlags { EF_LEFT_MOUSE_BUTTON };
    uint64_t EventTimeForNow();

    struct MouseEvent {
        EventType type;
        gfx::Point location;
        gfx::Point root_location;
        uint64_t time;
        EventFlags flags;
        EventFlags changed_button_flags;
        
        MouseEvent(EventType type, gfx::Point loc, gfx::Point root_loc,
                  uint64_t time, EventFlags flags, EventFlags changed_flags)
            : type(type), location(loc), root_location(root_loc),
              time(time), flags(flags), changed_button_flags(changed_flags) {}
    };
}

class CustomButton {
public:
    enum State { STATE_NORMAL };
    bool IsChildWidget();
    bool FocusInChildWidget();
    struct Widget { bool IsActive(); };
    Widget* GetWidget();
    void SetState(State state);
    void NotifyClick(const ui::MouseEvent& event);
    bool AcceleratorPressed(const ui::Accelerator& accelerator);
};