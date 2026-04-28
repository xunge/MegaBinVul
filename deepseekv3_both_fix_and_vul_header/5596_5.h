#include <string>
#include <vector>
#include <functional>
#include <cstddef>

#define Q_UNUSED(x) (void)(x)

struct BufferInfo {};
struct QString : public std::string {
    using std::string::string;
    bool contains(char c) const { return find(c) != npos; }
    QString section(char sep, int start, int end = -1) const { 
        size_t pos = find(sep);
        return pos != npos ? QString(substr(0, pos).c_str()) : QString();
    }
};
struct QByteArray : public std::vector<char> {};

class CoreUserInputHandler {
public:
    void handleMsg(const BufferInfo& bufferInfo, const QString& msg);
protected:
    QByteArray userEncode(const QString& target, const QString& message);
    QString serverEncode(const QString& target);
    void putPrivmsg(const QString& target, const QString& msg, std::function<QByteArray(const QString&, const QString&)> encodeFunc);
    void putPrivmsg(const QString& target, const QByteArray& msg);
#ifdef HAVE_QCA2
    void putPrivmsg(const QString& target, const QString& msg, std::function<QByteArray(const QString&, const QString&)> encodeFunc, void* cipher);
    void putPrivmsg(const QString& target, const QByteArray& msg, void* cipher);
    void* cipher(const QString& target);
#endif
    class Network {
    public:
#ifdef HAVE_QCA2
        void* cipher(const QString& target);
#endif
    };
    Network* network();
};