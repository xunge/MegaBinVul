#include <stddef.h>
#include <time.h>
#include <string.h>

#define DCHECK_EQ(a, b) ((void)0)
#define DCHECK_LE(a, b) ((void)0)
#define DCHECK_GE(a, b) ((void)0)
#define CHECK_GT(a, b) ((void)0)

#define ERR_CONNECTION_CLOSED -100
#define ERR_EMPTY_RESPONSE -101
#define ERR_RESPONSE_HEADERS_TRUNCATED -102
#define ERR_RESPONSE_HEADERS_TOO_BIG -103
#define OK 0

#define STATE_DONE 0
#define STATE_READ_BODY_COMPLETE 1
#define STATE_BODY_PENDING 2
#define STATE_READ_HEADERS 3
#define STATE_REQUEST_SENT 4

#define kMaxHeaderBufSize 1024

class URL {
public:
    bool SchemeIsSecure();
};

class IOBuffer {
public:
    int offset();
    void set_offset(int offset);
    int capacity();
    char* StartOfBuffer();
    void SetCapacity(int capacity);
};

class HttpRequestHeaders {
public:
    int response_code();
};

class HttpResponseInfo {
public:
    time_t response_time;
    HttpRequestHeaders* headers;
};

class Connection {
public:
    bool is_reused();
};

class base {
public:
    class Time {
    public:
        static time_t Now();
    };
};

class HttpRequestInfo {
public:
    URL url;
};

class HttpStreamParser {
private:
    int read_buf_unused_offset_;
    int io_state_;
    IOBuffer* read_buf_;
    int response_header_start_offset_;
    int response_body_length_;
    HttpRequestInfo* request_;
    HttpResponseInfo* response_;
    Connection* connection_;

    int ParseResponseHeaders();
    int DoParseResponseHeaders(int end_offset);
    void CalculateResponseBodySize();

public:
    int DoReadHeadersComplete(int result);
};