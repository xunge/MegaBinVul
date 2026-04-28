#include <cstring>
#include <vector>
#include <cassert>

class String {
public:
    String();
    String(int len, int reserve);
    const char* data() const;
    char* mutableData();
    int size() const;
    void setSize(int len);
};

class Variant {
public:
    String toString() const;
};

class ArrayIter {
public:
    ArrayIter(const Variant&);
    explicit operator bool() const;
    ArrayIter& operator++();
    Variant second() const;
};

namespace StringUtil {
    String Implode(const Variant& items, const String& delim, const bool checkIsContainer);
}

namespace req {
template<typename T> using vector = std::vector<T>;
}

const String& empty_string();
void throw_param_is_not_container();
bool isContainer(const Variant& items);
int getContainerSize(const Variant& items);

const int ReserveString = 0;