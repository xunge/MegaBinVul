#include <string>

class QUrl {
public:
    bool isValid() const;
};

class QDesktopServices {
public:
    static void openUrl(const QUrl &url);
};

class Utility {
public:
    static void openBrowser(const QUrl &url);
};

class AccountSettings {
public:
    void slotOpenOC();
private:
    QUrl _OCUrl;
};