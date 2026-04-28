#include <string>

using WebString = std::string;
using String = std::string;

class WebPageSerializer {
public:
    WebString generateMetaCharsetDeclaration(const WebString& charset);
};