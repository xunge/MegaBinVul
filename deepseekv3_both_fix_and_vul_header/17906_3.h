#include <stddef.h>
#include <stdbool.h>

typedef enum {
    CURLE_OK,
    CURLE_OUT_OF_MEMORY
} CURLcode;

#define TRUE true

struct imap_conn {
    char *mailbox;
};

struct SessionHandle {
    struct {
        const char *path;
    } state;
};

struct connectdata {
    struct {
        struct imap_conn imapc;
    } proto;
    struct SessionHandle *data;
};

CURLcode Curl_urldecode(struct SessionHandle *data, const char *input, int length,
                        char **output, size_t *outlen, int reject_ctrl);
char *curl_easy_unescape(struct SessionHandle *data, const char *string,
                         int length, int *outlength);