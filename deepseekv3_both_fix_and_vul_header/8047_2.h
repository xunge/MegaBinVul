#include <string>
#include <memory>

namespace webstore_install {
enum Result {
    SUCCESS,
    USER_CANCELLED,
    NOT_PERMITTED,
    ABORTED
};
}

class ExtensionReenabler {
public:
    enum ReenableResult {
        REENABLE_SUCCESS,
        USER_CANCELED,
        NOT_ALLOWED,
        ABORTED
    };
};

class TabHelper {
public:
    void OnReenableComplete(int install_id, int return_route_id, const std::string& extension_id,
                           ExtensionReenabler::ReenableResult result);
    void OnReenableComplete(int install_id, int return_route_id,
                           ExtensionReenabler::ReenableResult result);
    void OnInlineInstallComplete(int install_id, int return_route_id, const std::string& extension_id,
                               bool success, const std::string& error, webstore_install::Result result);
    void OnInlineInstallComplete(int install_id, int return_route_id, bool success,
                               const std::string& error, webstore_install::Result result);
    std::unique_ptr<ExtensionReenabler> extension_reenabler_;
};