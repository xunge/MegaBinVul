#include <string>
#include <cstring>

class XmlRpcUtil {
public:
    static bool findTag(const char* tag, std::string const& xml, int* offset);
};