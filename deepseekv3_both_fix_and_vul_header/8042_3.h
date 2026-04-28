#include <string>
#include <memory>

namespace webstore_install {
    enum Result {
        INSTALL_IN_PROGRESS
    };
    const std::string kInstallInProgressError = "Install in progress";
}

class Profile;

class InstallTracker {
public:
    static InstallTracker* Get(Profile* profile);
    const class ActiveInstallData* GetActiveInstall(const std::string& id);
};

class ActiveInstallData {
public:
    ActiveInstallData(const std::string& id);
};

class ScopedActiveInstall {
public:
    ScopedActiveInstall(InstallTracker* tracker, const ActiveInstallData& data);
};

class WebstoreStandaloneInstaller {
public:
    bool EnsureUniqueInstall(webstore_install::Result* reason, std::string* error);
    
private:
    Profile* profile_;
    std::string id_;
    std::unique_ptr<ScopedActiveInstall> scoped_active_install_;
    void InitInstallData(ActiveInstallData* install_data);
};

#define DCHECK(condition) ((void)0)

using namespace webstore_install;