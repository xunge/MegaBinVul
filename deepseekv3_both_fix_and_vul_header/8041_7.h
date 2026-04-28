#include <memory>
#include <functional>

namespace webstore_install {
enum InstallResult { INVALID_MANIFEST };
const char kInvalidManifestError[] = "";
}  // namespace webstore_install

namespace base {
template <typename F, typename T>
std::function<void()> Bind(F f, T* t) { return {}; }
}  // namespace base

class Extension {};

class ExtensionInstallPrompt {
public:
    using ShowDialogCallback = std::function<void()>;
    void ShowDialog(ShowDialogCallback, const Extension*, int*, std::unique_ptr<ExtensionInstallPrompt>, ShowDialogCallback);
    static ShowDialogCallback GetDefaultShowDialogCallback() { return {}; }
};

template <typename T>
class scoped_refptr {
public:
    T* get() { return nullptr; }
    scoped_refptr() = default;
    explicit scoped_refptr(T*) {}
};

class WebstoreStandaloneInstaller {
public:
    void ShowInstallUI();
    void CompleteInstall(webstore_install::InstallResult, const char*);
    scoped_refptr<const Extension> GetLocalizedExtensionForDisplay();
    ExtensionInstallPrompt* CreateInstallUI();
    void OnInstallPromptDone();

private:
    ExtensionInstallPrompt* install_ui_;
    std::unique_ptr<ExtensionInstallPrompt> install_prompt_;
    int icon_;
};

using namespace webstore_install;