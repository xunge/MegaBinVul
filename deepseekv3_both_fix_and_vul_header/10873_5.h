class QLocalSocket;
class QString;

class Display {
public:
    void login(QLocalSocket *socket, const QString &user, const QString &password, const QString &session);
private:
    QLocalSocket *m_socket;
    void startAuth(const QString &user, const QString &password, const QString &session);
};

bool operator==(const QString &lhs, const char *rhs);