#include <memory>
#include <string>
#include <cassert>

#define DCHECK(condition) assert(condition)

namespace webstore_install {
enum Result {
  USER_CANCELLED,
  ABORTED,
  SUCCESS,
  BLACKLISTED
};

const char kUserCancelledError[] = "";
const char kExtensionIsBlacklisted[] = "";
}  // namespace webstore_install

struct Profile {};

class Extension {
public:
  std::string id() const;
};

class ExtensionPrefs {
public:
  static ExtensionPrefs* Get(Profile* profile);
  bool IsExtensionBlacklisted(const std::string& id);
};

class ExtensionService {
public:
  const Extension* GetExtensionById(const std::string& id, bool include_disabled);
  bool IsExtensionEnabled(const std::string& id);
  void EnableExtension(const std::string& id);
};

class ExtensionSystem {
public:
  static ExtensionSystem* Get(Profile* profile);
  ExtensionService* extension_service();
};

class WebContents {};

template <typename T>
class scoped_refptr {
public:
  scoped_refptr(T* ptr) : ptr_(ptr) {}
  T* get() const { return ptr_; }
  T* operator->() const { return ptr_; }

private:
  T* ptr_;
};

namespace ExtensionInstallPrompt {
enum class Result {
  USER_CANCELED,
  ABORTED,
  ACCEPTED
};
}  // namespace ExtensionInstallPrompt

class WebstoreInstaller {
public:
  struct Approval {};
  WebstoreInstaller(Profile* profile, void* context, WebContents* web_contents,
                   const std::string& id, std::unique_ptr<Approval> approval,
                   int install_source);
  void Start();
};

class WebstoreStandaloneInstaller {
protected:
  Profile* profile_;
  std::string id_;
  int install_source_;

  virtual bool CheckRequestorAlive();
  virtual void CompleteInstall(webstore_install::Result result, 
                              const std::string& error);
  virtual std::unique_ptr<WebstoreInstaller::Approval> CreateApproval();
  virtual WebContents* GetWebContents();
  virtual void OnInstallPromptDone(ExtensionInstallPrompt::Result result);
};

using webstore_install::kUserCancelledError;
using webstore_install::kExtensionIsBlacklisted;