#include <string>
#include <vector>

class QString {
public:
    QString();
    QString(const char* str);
    QString(const std::string& str);
    QString& operator<<(const QString& other);
    QString arg(int value);
    QString arg(const char* value);
    bool isEmpty() const;
};

class QStringList : public std::vector<QString> {
public:
    QStringList& operator<<(const QString& str);
};

class QProcess {
public:
    void start(const QString& program, const QStringList& args);
};

class SocketServer {
public:
    static SocketServer* instance();
    QString fullServerName();
};

class Auth {
public:
    void start();
private:
    struct Private {
        int id;
        QString sessionPath;
        QString user;
        bool autologin;
        bool greeter;
        QProcess* child;
    };
    Private* d;
};

#define LIBEXEC_INSTALL_DIR "/usr/libexec"