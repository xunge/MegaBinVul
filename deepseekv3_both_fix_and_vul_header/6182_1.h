#include <string>
#include <map>

const int kerInvalidLangAltValue = 1;

class Error {
public:
    Error(int, const std::string&);
};

class LangAltValue {
private:
    std::map<std::string, std::string> value_;
public:
    int read(const std::string& buf);
};