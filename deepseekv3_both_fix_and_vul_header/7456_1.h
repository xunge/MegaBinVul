#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef size_t pj_size_t;

typedef struct pj_str_t {
    const char *ptr;
    int slen;
} pj_str_t;

typedef struct pjmedia_sdp_media {
    struct {
        pj_str_t media;
        unsigned port;
        unsigned port_count;
        pj_str_t transport;
        pj_str_t *fmt;
        unsigned fmt_count;
    } desc;
    void *conn;
    void **bandw;
    unsigned bandw_count;
    void **attr;
    unsigned attr_count;
} pjmedia_sdp_media;

static int print_connection_info(void *conn, char *buf, int len);
static int print_bandw(void *bandw, char *buf, size_t len);
static int print_attr(void *attr, char *buf, size_t len);
static int pj_utoa(unsigned num, char *buf);

#define pj_memcpy memcpy