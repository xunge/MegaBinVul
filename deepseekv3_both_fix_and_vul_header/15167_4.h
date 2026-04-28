#include <string>

const size_t kMaxTooltipLength = 1024;
#define TTM_POP 0
#define TTM_POPUP 0

inline bool IsWindow(void* hwnd) { return false; }
inline void* SendMessage(void* hwnd, int msg, int wparam, int lparam) { return nullptr; }

class RenderWidgetHostHWND {
public:
    void SetTooltipText(const std::wstring& tooltip_text);
private:
    std::wstring tooltip_text_;
    void* tooltip_hwnd_;
    bool tooltip_showing_;
};