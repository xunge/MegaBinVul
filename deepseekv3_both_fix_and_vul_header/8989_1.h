#include <string>
#include <cstdint>

class WebURL {
public:
    std::string spec() const;
    const char* data() const;
};

class WebString {
public:
    WebString(const std::string&);
};

class StringBuilder {
public:
    void append(const std::string&);
    WebString toString();
};

class String {
public:
    static WebString format(const char*, ...);
};

class PageSerializer {
public:
    static std::string markOfTheWebDeclaration(const WebURL&);
};

class WebPageSerializer {
public:
    WebString generateMarkOfTheWebDeclaration(const WebURL&);
};