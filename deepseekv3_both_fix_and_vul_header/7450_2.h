#include <string>

class SettingsDialog {
public:
    std::string clientos();
    std::string extraArgs();
};

class GPClient {
public:
    void onSettingsAccepted();
};

extern SettingsDialog* settingsDialog;

namespace settings {
    void save(const std::string& key, const std::string& value);
}