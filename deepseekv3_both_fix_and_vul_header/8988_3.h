#include <string>

class String {
public:
    String(const char*);
    String(const std::string&);
    String operator+(const String&) const;
    friend String operator+(const char*, const String&);
    operator std::string() const;
};

class WebString {
public:
    WebString(const String&);
    WebString(const std::string&);
    bool isEmpty() const;
    operator String() const;
};

class WebPageSerializer {
public:
    WebString generateBaseTagDeclaration(const WebString& baseTarget);
};