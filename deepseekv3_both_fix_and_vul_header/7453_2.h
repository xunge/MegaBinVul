#include <string>
#include <vector>

class QString;
template<typename T> class QList;

class VpnDbus {
public:
    void connect(const QString &preferredServer, const QList<QString> &servers, const QString &username, const QString &passwd);
    void connect(const QString &preferredServer, const QList<QString> &servers, const QString &username, const QString &passwd, const QString &extraArgs);
private:
    struct Inner {
        void connect(const QString &preferredServer, const QString &username, const QString &passwd);
        void connect(const QString &preferredServer, const QString &username, const QString &passwd, const QString &extraArgs);
    };
    Inner *inner;
};