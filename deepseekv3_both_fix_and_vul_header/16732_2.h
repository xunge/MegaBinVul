#include <stddef.h>
#include <stdint.h>

typedef uint16_t u16;

class String {};

class StringView {
public:
    size_t length() const;
    char operator[](size_t index) const;
};

class StringBuilder {
public:
    StringBuilder(size_t);
    void append_code_point(u16);
    String to_string();
};

class UTF16BEDecoder {
public:
    String to_utf8(const StringView& input);
};