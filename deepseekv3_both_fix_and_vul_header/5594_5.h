#include <algorithm>
#include <functional>
#include <cstring>

class QByteArray {
public:
    QByteArray();
    QByteArray(const char*);
    int size() const;
    QByteArray left(int) const;
    QByteArray mid(int, int) const;
    int lastIndexOf(char, int) const;
    int count() const;
};

class QString {
public:
    QString();
    QString(const char*);
    int count() const;
    int lastIndexOf(char, int) const;
    QString left(int) const;
    QString mid(int) const;
};

template<typename T> class QList {
public:
    QList();
    QList<T>& operator<<(const T&);
    QList<T> mid(int, int) const;
};

class UserInputHandler {
public:
    int lastParamOverrun(const char*, const QList<QByteArray>&);
};

class CoreNetwork {
public:
    QByteArray serverEncode(const QString&);
    QByteArray userEncode(const QString&, const QString&);
    void putCmd(const QString&, const QList<QByteArray>&);
    QList<QByteArray> splitMessage(const QString&, const QString&, std::function<QList<QByteArray>(QString&)>);
    UserInputHandler* userInputHandler();
};

class CtcpParser {
public:
    void query(CoreNetwork*, const QString&, const QString&, const QString&);
};

QByteArray lowLevelQuote(const QByteArray&);
QByteArray pack(const QByteArray&, const QByteArray&);

template<typename T>
const T& qMax(const T& a, const T& b) {
    return (a < b) ? b : a;
}