#include <string>

class String {
public:
    void clear();
    void append(char c);
    bool empty() const;
    char back() const;
    void pop_back();
};

class StringListEnumeration {
public:
    const char* next();
};

class StringList {
public:
    StringListEnumeration elements_obj() const;
};