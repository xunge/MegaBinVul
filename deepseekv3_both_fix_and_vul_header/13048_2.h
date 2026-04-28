#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct str {
    char *s;
    unsigned int len;
} str;

struct cancel_reason {
    unsigned int cause;
    union {
        str text;
        str packed_hdrs;
        char *e2e_cancel;
    } u;
};

typedef struct sr_cfgenv_t {
    str uac_cseq_auth;
    str uac_cseq_refresh;
} sr_cfgenv_t;

typedef struct request_t {
    char *buffer;
    short buffer_len;
    unsigned int msg_flags;
} request_t;

typedef struct uac_t {
    request_t request;
    unsigned int flags;
    char *e2e_cancel;
} uac_t;

typedef struct tm_cell_t {
    uac_t *uac;
    unsigned int flags;
    struct {
        request_t *request;
    } uas;
} tm_cell_t;

struct hdr_field {
    str name;
    unsigned int len;
    struct hdr_field *next;
};

enum _hdr_types_t {
    HDR_EOH_T,
    HDR_CSEQ_T,
    HDR_VIA_T,
    HDR_TO_T,
    HDR_FROM_T,
    HDR_CALLID_T,
    HDR_ROUTE_T,
    HDR_MAXFORWARDS_T,
    HDR_REQUIRE_T,
    HDR_PROXYREQUIRE_T,
    HDR_CONTENTLENGTH_T,
    HDR_REASON_T,
    HDR_EOH_F
};

#define CANCEL_REAS_UNKNOWN 0
#define CANCEL_REAS_PACKED_HDRS 1
#define CANCEL_REAS_RCVD_CANCEL 2
#define CANCEL_REAS_MIN 0

#define REASON_PREFIX "Reason: SIP;cause="
#define REASON_PREFIX_LEN (sizeof(REASON_PREFIX)-1)
#define REASON_TEXT ";text="
#define REASON_TEXT_LEN (sizeof(REASON_TEXT)-1)
#define CRLF "\r\n"
#define CRLF_LEN (sizeof(CRLF)-1)

#define USHORT2SBUF_MAX_LEN 5

#define T_NO_E2E_CANCEL_REASON (1<<0)
#define FL_UAC_AUTH (1<<0)

#define LM_ERR(fmt, ...)
#define LM_WARN(fmt, ...)
#define LM_BUG(fmt, ...)
#define LM_DBG(fmt, ...)

#define likely(x) (x)
#define unlikely(x) (x)

#define SHM_MEM_ERROR

typedef struct {
    int local_cancel_reason;
    str ac_extra_hdrs;
} tm_cfg_t;

extern tm_cfg_t *tm_cfg;

static inline char *eat_line(char *s, int len) { return s + len; }
static inline char *lw_get_hf_name(char *s, int len, enum _hdr_types_t *type) { return s; }
static inline char *lw_next_line(char *s, int len) { return s + len; }
static inline void append_str(char **d, const char *s, int len) { memcpy(*d, s, len); *d += len; }
static inline int ushort2sbuf(unsigned short n, char *buf, int len) { return snprintf(buf, len, "%hu", n); }
static inline struct hdr_field *get_hdr(char *msg, enum _hdr_types_t type) { return NULL; }
static inline struct hdr_field *next_sibling_hdr(struct hdr_field *hdr) { return hdr->next; }
static inline int parse_headers(char *msg, int flags, int foo) { return 0; }

static inline void *shm_malloc(size_t size) { return malloc(size); }
static inline void shm_free(void *p) { free(p); }

#define cfg_get(type, cfg, field) (cfg->field)
static inline sr_cfgenv_t *sr_cfgenv_get() { return NULL; }

#define HDR_CSEQ_F (1<<0)
#define HDR_TO_F (1<<1)
#define HDR_FROM_F (1<<2)
#define HDR_CALLID_F (1<<3)

typedef unsigned int hdr_flags_t;