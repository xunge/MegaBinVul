#include <vector>
#include <string>

class StringList;
class StringListEnumeration;

class String {
public:
    bool empty() const;
    char back() const;
    void push_back(char c);
    void swap(String& other);
    size_t size() const;
    String& operator+=(const String& str);
    String& operator+=(char c);
    String& operator=(const char* str);
};

class StringList {
public:
    StringListEnumeration elements_obj() const;
};

class StringListEnumeration {
public:
    const char* next();
};

bool file_exists(const String& path);