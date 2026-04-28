#include <string>
#include <cctype>

class XmlRpcUtil {
public:
    static std::string getNextTag(std::string const& xml, int* offset);
};