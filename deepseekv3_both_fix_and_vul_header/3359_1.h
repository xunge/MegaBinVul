#include <cstddef>

struct HttpError {
    HttpError(int code, const char* message);
};

#define HTTP_REQUEST_ENTITY_TOO_LARGE 413

struct Messageheader {
    struct Parser {
        void checkHeaderspace(unsigned chars) const;
        const char* headerdataPtr;
        struct Header {
            mutable char rawdata[1024];
        } header;
    };
};