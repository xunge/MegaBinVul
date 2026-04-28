#include <functional>
#include <string>

#define emit

class QString {
public:
    bool isEmpty() const;
};

class QByteArray {};

struct BufferInfo {
    QString bufferName() const;
    bool acceptsRegularMessages() const;
    int type() const;
};

class Message {
public:
    enum Type { Plain };
    enum Flag { Self };
};

class Network {
public:
    QString myNick() const;
    void *cipher(const QString &) const;
};

class CoreUserInputHandler {
public:
    void handleSay(const BufferInfo &bufferInfo, const QString &msg);
protected:
    QByteArray channelEncode(const QString &target, const QString &message);
    QString serverEncode(const QString &target);
    void putPrivmsg(const QString &target, const QString &msg, std::function<QByteArray(const QString &, const QString &)> encodeFunc);
    void putPrivmsg(const QString &target, const QString &msg);
    void putPrivmsg(const QString &target, const QString &msg, std::function<QByteArray(const QString &, const QString &)> encodeFunc, void *cipher);
    void putPrivmsg(const QString &target, const QByteArray &msg);
    void putPrivmsg(const QString &target, const QByteArray &msg, void *cipher);
    Network* network() const;
    void displayMsg(Message::Type, int, const QString &, const QString &, const QString &, Message::Flag);
};