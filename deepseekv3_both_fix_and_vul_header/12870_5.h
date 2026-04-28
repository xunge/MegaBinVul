#include <string>
#include <vector>
#include <algorithm>

class Application {
public:
    void handleEditLocally(const class QUrl &url) const;
};

class QString {
public:
    QString();
    QString(const char* str);
    QString(char ch);
    friend QString operator+(const char* lhs, const QString& rhs);
    class QStringList split(const QString& sep, int behavior) const;
    QString join(const QStringList& list) const;
};

class QStringList {
public:
    QString takeFirst();
    QString join(const QString& separator) const;
    size_t size() const;
};

class QUrl {
public:
    QString path() const;
};

class QUrlQuery {
public:
    QUrlQuery(const QUrl& url);
    bool hasQueryItem(const QString& key) const;
    QString queryItemValue(const QString& key) const;
};

class FolderMan {
public:
    static FolderMan* instance();
    void editFileLocally(const QString& accountDisplayName, const QString& fileRemotePath, const QString& token = QString());
};

class QLoggingCategory {
public:
    QLoggingCategory(const char* category);
};

class QDebug {
public:
    QDebug(int type);
    QDebug& operator<<(const QString&);
};

namespace Qt {
    enum { SkipEmptyParts = 0 };
}

QLoggingCategory lcApplication("application");
#define qCWarning(category) QDebug(0)
#define QStringLiteral(str) QString(str)