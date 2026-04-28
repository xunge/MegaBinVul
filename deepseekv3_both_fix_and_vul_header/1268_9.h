#include <cstddef>

struct http_parser {
    void* data;
};

class HTTPParser : public http_parser {
};

// 注意：现在HTTPParser继承自http_parser，可以直接转换