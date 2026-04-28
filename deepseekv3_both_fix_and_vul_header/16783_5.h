#include <string>

class QString {
public:
    QString(const char* str);
    QString operator+(const QString& other) const;
    QString operator+(const char* other) const;
    friend QString operator+(const char* lhs, const QString& rhs);
    const char* toString() const;
    std::string toStdString() const;
};

class QUrl {
public:
    QUrl(const QString& url);
    QUrl(const char* url);
};

class Theme {
public:
    static Theme* instance();
    QString wizardUrlPostfix() const;
};

class Utility {
public:
    static void openBrowser(const QUrl& url);
};

class QDesktopServices {
public:
    static void openUrl(const QUrl& url);
};

class OwncloudWizardResultPage {
public:
    QString field(const char* name);
    void slotOpenServer();
};