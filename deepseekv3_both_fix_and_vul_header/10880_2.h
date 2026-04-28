#include <iostream>
#include <string>

enum Msg {
    MSG_UNKNOWN,
    AUTHENTICATED
};

class QProcessEnvironment {
public:
    QProcessEnvironment();
};

class QString {
public:
    QString();
    bool isEmpty() const;
};

class QIODevice;

class SafeDataStream {
public:
    SafeDataStream(QIODevice* device);
    void send();
    void receive();
    SafeDataStream& operator<<(Msg msg);
    SafeDataStream& operator<<(const QString& str);
    SafeDataStream& operator>>(Msg& msg);
    SafeDataStream& operator>>(QProcessEnvironment& env);
    SafeDataStream& operator>>(QString& str);
};

class HelperApp {
private:
    QString m_cookie;
    QIODevice* m_socket;
public:
    QProcessEnvironment authenticated(const QString &user);
};

std::ostream& qCritical();