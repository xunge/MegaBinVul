#include <memory>

struct Bounds {
    int x;
    int y;
    int width;
    int height;
};

class Widget;

struct InitParams;

namespace internal {
class NativeWidgetPrivate {
public:
    static NativeWidgetPrivate* CreateNativeWidget(Widget* widget) { return nullptr; }
    virtual bool IsMouseButtonDown() { return false; }
    virtual void InitNativeWidget(const InitParams& params) {}
};
}  // namespace internal

struct InitParams {
    enum Type {
        TYPE_MENU,
        TYPE_WINDOW
    };
    Type type;
    class WidgetDelegate* delegate;
    int ownership;
    class NativeWidget* native_widget;
    Bounds bounds;
};

class WidgetDelegate {
public:
    virtual ~WidgetDelegate() = default;
    virtual void* CreateClientView(Widget* widget) = 0;
};

class DefaultWidgetDelegate : public WidgetDelegate {
public:
    DefaultWidgetDelegate(Widget* widget) {}
    DefaultWidgetDelegate() {}
    void* CreateClientView(Widget* widget) override { return nullptr; }
};

class NativeWidget {
public:
    virtual ~NativeWidget() = default;
    virtual internal::NativeWidgetPrivate* AsNativeWidgetPrivate() = 0;
};

class NonClientView {
public:
    void SetFrameView(void* view) {}
    void set_client_view(void* view) {}
};

class DefaultThemeProvider {};

class Widget {
protected:
    WidgetDelegate* widget_delegate_;
    int ownership_;
    internal::NativeWidgetPrivate* native_widget_;
    std::unique_ptr<DefaultThemeProvider> default_theme_provider_;
    bool is_mouse_button_pressed_;
    NonClientView* non_client_view_;

public:
    void Init(const InitParams& params);
    void* GetRootView() { return nullptr; }
    void SetContentsView(void* view) {}
    void SetInitialBounds(const Bounds& bounds) {}
    void UpdateWindowTitle() {}
    void* CreateNonClientFrameView() { return nullptr; }
};