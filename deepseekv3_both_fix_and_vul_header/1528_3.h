#include <map>
#include <string>
#include <variant>

using QVariant = std::variant<bool, std::string>;
using QVariantMap = std::map<std::string, QVariant>;
using QStringLiteral = std::string;

class QFile {
public:
    QFile(const std::string& path) {}
    bool open(int mode) { return true; }
    void write(const char* data) {}
    void close() {}
    std::string errorString() { return ""; }
};

class QIODevice {
public:
    static const int WriteOnly;
    static const int Text;
};

const int QIODevice::WriteOnly = 1;
const int QIODevice::Text = 2;

class Helper {
public:
    bool isCallerAuthorized() { return true; }
    QVariantMap flushPageCache();
};