#include <string>

class QUrl {
public:
    QUrl(const std::string &url);
};

class QDesktopServices {
public:
    static bool openUrl(const QUrl &url);
};

class Utility {
public:
    static void openBrowser(const QUrl &url);
};

class UserAppsModel {
public:
    void openAppUrl(const QUrl &url);
};