#include <stdlib.h>
#include <string.h>

#define UPLOAD_BUFSIZE 16384
#define SMTP_EOB_LEN 5
#define SMTP_EOB_FIND_LEN 3
#define SMTP_EOB_REPL_LEN 5
#define TRUE 1
#define FALSE 0
#define CURLE_OK 0
#define CURLE_OUT_OF_MEMORY 27

typedef int CURLcode;

static const char SMTP_EOB[] = "\r\n.\r\n";
static const char SMTP_EOB_REPL[] = "\r\n..\r\n";

struct connectdata {
    struct Curl_easy *data;
};

struct SMTP {
    size_t eob;
    int trailing_crlf;
};

struct Curl_transfer {
    char *upload_fromhere;
    size_t upload_present;
    void *protop;
};

struct Curl_state {
    char *scratch;
};

struct Curl_set {
    int crlf;
    size_t buffer_size;
};

struct Curl_easy {
    struct Curl_transfer req;
    struct Curl_state state;
    struct Curl_set set;
};

void failf(struct Curl_easy *data, const char *format);