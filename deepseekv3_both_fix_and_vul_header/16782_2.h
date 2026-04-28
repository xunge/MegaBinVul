#include <string>

#define emit

enum OAuthResult { NotSupported };

class QString {
public:
    QString();
    QString(const char *);
};

class QUrl {
public:
    bool isEmpty() const;
};

class QDesktopServices {
public:
    static bool openUrl(const QUrl &url);
};

class Utility {
public:
    static bool openBrowser(const QUrl &url);
};

class OAuth {
public:
    QUrl authorisationLink() const;
    void result(OAuthResult, const QString &);
    bool openBrowser();
};