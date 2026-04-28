#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_GT(a, b) ((a) > (b))
#define CHECK_EQ(a, b) ((a) == (b))

class AString {
public:
    const char* c_str() const { return nullptr; }
};

class ASessionDescription {
public:
    bool getDimensions(size_t index, unsigned long PT, int32_t* width, int32_t* height) const;
    bool findAttribute(size_t index, const char* key, AString* value) const { return false; }
};

void android_errorWriteLog(uint32_t tag, const char* msg) {}