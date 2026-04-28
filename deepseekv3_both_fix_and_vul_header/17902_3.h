#include <stddef.h>
#include <stdbool.h>

typedef enum {
  CURLE_OK = 0,
  CURLE_OUT_OF_MEMORY
} CURLcode;

#define TRUE true

struct pop3_conn {
    char *mailbox;
};

struct SessionHandle {
    struct {
        const char *path;
    } state;
};

struct connectdata {
    struct {
        struct pop3_conn pop3c;
    } proto;
    struct SessionHandle *data;
};

char *curl_easy_unescape(struct SessionHandle *data, const char *path, int length, int *outlength);
CURLcode Curl_urldecode(struct SessionHandle *data, const char *path, int length, char **output, int *outlength, bool reject_ctrl);