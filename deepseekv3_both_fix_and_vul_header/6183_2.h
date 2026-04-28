#include <string>
#include <iostream>

class CommentValue {
public:
    int read(const std::string& comment);
};

enum CharsetId {
    undefined,
    unicode,
    invalidCharsetId
};

class CharsetInfo {
public:
    static CharsetId charsetIdByName(const std::string& name);
    static const char* code(CharsetId charsetId);
};

class Error {
public:
    Error(int kerInvalidCharset, const std::string& name);
    friend std::ostream& operator<<(std::ostream& os, const Error& error);
};

class StringValueBase {
public:
    static int read(const std::string& str);
};

extern int kerInvalidCharset;
extern int SUPPRESS_WARNINGS;
extern std::ostream EXV_WARNING;

enum ByteOrder {
    littleEndian,
    bigEndian
};
extern ByteOrder byteOrder_;

void convertStringCharset(std::string& str, const char* from, const char* to);

std::ostream& operator<<(std::ostream& os, const Error& error);