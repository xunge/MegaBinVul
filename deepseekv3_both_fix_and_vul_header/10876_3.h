#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#define SIGNAL(x) #x
#define SLOT(x) #x

namespace Auth {
    enum HelperError {
        HELPER_OTHER_ERROR
    };
}

class QString {
public:
    QString() {}
    QString(const char* str) {}
    QString(const std::string& str) {}
    long long toLongLong() const { return 0; }
    bool isEmpty() const { return true; }
};

class QStringList : public std::vector<QString> {
public:
    int indexOf(const QString& str) const { return -1; }
    size_t length() const { return size(); }
};

class QIODevice {
public:
    enum OpenMode {
        ReadWrite,
        Unbuffered
    };
};

class QObject {
public:
    void connect(QObject*, const char*, QObject*, const char*) {}
    void setPath(const QString&) {}
    void setAutologin(bool) {}
    void setGreeter(bool) {}
    void connectToServer(const QString&, int) {}
};

class QCoreApplication {
public:
    static QStringList arguments() { return QStringList(); }
};

class QDebug {
public:
    QDebug& operator<<(const char*) { return *this; }
};

QDebug qCritical() { return QDebug(); }

class HelperApp : public QObject {
public:
    void setUp();
    void doAuth() {}
    void sessionFinished(int) {}
    long long m_id = 0;
    QString m_user;
    QObject* m_session = nullptr;
    QObject* m_backend = nullptr;
    QObject* m_socket = nullptr;
};