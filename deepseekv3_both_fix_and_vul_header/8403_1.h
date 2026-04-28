#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class AString {
public:
    const char* c_str() const;
    void clear();
};

class ASessionDescription {
public:
    void getFormat(size_t index, AString* format) const;
    bool findAttribute(size_t index, const char* key, AString* value) const;
    void getFormatType(size_t index, unsigned long* PT, AString* desc, AString* params) const;
};

#define CHECK(expr)
#define CHECK_GT(a, b)
#define CHECK_EQ(a, b)