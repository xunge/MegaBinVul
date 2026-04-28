#include <stddef.h>
#include <stdint.h>

#define DCHECK_EQ(a, b) ((void)0)

class HttpUtil {
public:
    static int LocateStartOfStatusLine(const char* buf, int buf_len);
    static int LocateEndOfHeaders(const char* buf, int buf_len, int status_line_offset);
};

class IOBuffer {
public:
    char* StartOfBuffer();
    int offset();
};

class HttpStreamParser {
private:
    IOBuffer* read_buf_;
    int read_buf_unused_offset_;
    int response_header_start_offset_;
    int DoParseResponseHeaders(int end_offset);

public:
    int ParseResponseHeaders();
};