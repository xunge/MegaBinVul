#include <string>

namespace webstore_install {
    const std::string kWebstoreRequestError = "Webstore request error";
    enum InstallResult {
        WEBSTORE_REQUEST_ERROR
    };
}

using namespace webstore_install;

class WebstoreStandaloneInstaller {
public:
    void OnWebStoreDataFetcherDone();
    void CompleteInstall(InstallResult, const std::string&);
    void OnWebstoreRequestFailure();
};