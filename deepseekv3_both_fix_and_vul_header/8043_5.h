#include <string>
#include <memory>

namespace crx_file {
namespace id_util {
bool IdIsValid(const std::string& id);
}  // namespace id_util
}  // namespace crx_file

namespace webstore_install {
enum Result {
  INVALID_ID,
  OTHER_ERROR
};
const char kInvalidWebstoreItemId[] = "";
}  // namespace webstore_install

class WebstoreStandaloneInstaller;

class Profile {
public:
    void* GetRequestContext();
};

class WebstoreDataFetcher {
public:
  WebstoreDataFetcher(WebstoreStandaloneInstaller* context, void* request_context, const std::string& url, const std::string& id);
  void Start();
};

class WebstoreStandaloneInstaller {
public:
  void AddRef();
  void BeginInstall();
  void CompleteInstall(webstore_install::Result result, const std::string& error);
  bool EnsureUniqueInstall(webstore_install::Result* result, std::string* error);
  std::string GetRequestorURL();
  std::string id_;
  Profile* profile_;
  std::unique_ptr<WebstoreDataFetcher> webstore_data_fetcher_;
};

using webstore_install::kInvalidWebstoreItemId;