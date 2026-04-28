#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef size_t pj_size_t;
typedef uint8_t pj_uint8_t;

typedef struct {
    char peer_sdes_buf_[256];
} pjmedia_rtcp_session_stat;

typedef struct {
    pjmedia_rtcp_session_stat stat;
    const char *name;
} pjmedia_rtcp_session;

#define PJ_MIN(a, b) ((a) < (b) ? (a) : (b))
#define PJ_LOG(level, args)