#include <string>
#include <vector>
#include <cstdio>

struct QString {
    QString();
    QString(const char *str);
    bool isEmpty() const;
    QString arg(const QString &a) const;
    QString arg(const QString &a1, const QString &a2) const;
    QString arg(const QString &a1, const QString &a2, const QString &a3) const;
    const char* qPrintable() const;
    std::string toStdString() const;
};

inline const char* qPrintable(const QString &str) {
    return str.qPrintable();
}

class QStringList : public std::vector<QString> {
public:
    bool isEmpty() const { return empty(); }
    const QString& first() const { return front(); }
};

class QStandardPaths {
public:
    enum StandardLocation {
        TempLocation,
        RuntimeLocation
    };
    static QStringList standardLocations(StandardLocation type);
};

class QDir {
public:
    static QDir current();
    bool mkpath(const QString &dirPath) const;
};

class QCoreApplication {
public:
    QString applicationName() const;
};

class Helper {
public:
    QString temporaryMountDevice(const QString &device, const QString &name, bool readonly);
};

extern QCoreApplication *qApp;
void dCError(const char *format, ...);
QString mountPoint(const QString &device);
bool mountDevice(const QString &device, const QString &mount_point, bool readonly);