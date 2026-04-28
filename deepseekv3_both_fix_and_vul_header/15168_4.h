#include <string>
#include <vector>
#include <algorithm>

const int kMaxTooltipLength = 1024;
const unsigned int TTM_GETMARGIN = 0x0418;

typedef void* HWND;
typedef long LPARAM;
typedef unsigned long WPARAM;

struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};

class View;

class ChromeFont {
public:
    int GetStringWidth(const std::wstring& text);
};

namespace gfx {
    class Rect {
    public:
        Rect(int x, int y, int width, int height) 
            : x_(x), y_(y), width_(width), height_(height) {}
        int width() const { return width_; }
        int x_;
        int y_;
        int width_;
        int height_;
    };
    std::wstring ElideText(const std::wstring& text, const ChromeFont& font, int width);
}

namespace win_util {
    gfx::Rect GetMonitorBoundsForRect(const gfx::Rect& rect);
}

class CPoint {
public:
    CPoint(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

class TooltipManager {
public:
    void TrimTooltipToFit(std::wstring* text, int* max_width, int* line_count, int position_x, int position_y, HWND window);
    void SplitTooltipString(const std::wstring& text, std::vector<std::wstring>* lines);
    std::wstring GetLineSeparator();
    ChromeFont GetDefaultFont();
    View* view_container_;
};

class View {
public:
    View* GetRootView();
    static void ConvertPointToScreen(View* view, CPoint* point);
};

long SendMessage(HWND hWnd, unsigned int Msg, WPARAM wParam, LPARAM lParam);