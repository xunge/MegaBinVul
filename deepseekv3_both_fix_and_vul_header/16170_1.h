#include <string>
#include <cstring>

class XmlRpcUtil {
public:
    static std::string parseTag(const char* tag, std::string const& xml, int* offset);
};