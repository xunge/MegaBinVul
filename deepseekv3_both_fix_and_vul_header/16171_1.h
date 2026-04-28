#include <string>
#include <cstring>
#include <cctype>

class XmlRpcUtil {
public:
    static bool nextTagIs(const char* tag, std::string const& xml, int* offset);
};