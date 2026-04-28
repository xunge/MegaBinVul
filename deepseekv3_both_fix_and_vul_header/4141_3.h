#include <memory>

namespace content {
class BrowserThread {
public:
    static constexpr int UI = 0;
};
class WebContents;
}  // namespace content

namespace gfx {
class NativeWindow {};
}  // namespace gfx

class Profile;

class ExtensionInstallPrompt {
public:
    class Delegate {};
    class Prompt {
    public:
        bool ShouldUseTabModalDialog();
    };
};

template <typename T>
class scoped_refptr {
public:
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    T* operator->() { return ptr_; }
    T* get() { return ptr_; }
private:
    T* ptr_;
};

class ExtensionInstallDialogView {
public:
    ExtensionInstallDialogView(Profile* profile,
                             content::WebContents* web_contents,
                             ExtensionInstallPrompt::Delegate* delegate,
                             scoped_refptr<ExtensionInstallPrompt::Prompt> prompt);
    void Show();
};

namespace constrained_window {
void ShowWebModalDialogViews(ExtensionInstallDialogView* dialog,
                            content::WebContents* parent_web_contents);
ExtensionInstallDialogView* CreateBrowserModalDialogViews(
    ExtensionInstallDialogView* dialog,
    gfx::NativeWindow parent_window);
}  // namespace constrained_window

class ExtensionInstallPromptShowParams {
public:
    Profile* profile();
    content::WebContents* GetParentWebContents();
    gfx::NativeWindow GetParentWindow();
};

#define DCHECK_CURRENTLY_ON(x)