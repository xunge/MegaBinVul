#include <cstddef>
#include <cwchar>
#include <string>

typedef unsigned char uint8;
class UTFstring {
private:
    wchar_t* _Data;
    size_t _Length;
    std::string UTF8string;
    unsigned int UTFCharLength(uint8 lead);
public:
    void UpdateFromUTF8();
};