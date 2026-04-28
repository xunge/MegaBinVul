#include <stdio.h>
#include <regex.h>
#include <string.h>

struct sip_msg {
    char *buf;
};

struct sdp_stream_cell;

typedef struct {
    char *s;
    int len;
} str;

typedef struct sdp_payload_attr {
    struct sdp_payload_attr *next;
    int id;
    str rtp_payload;
    str rtp_enc;
    str rtp_clock;
    str fmtp_string;
    str rtcp_fb;
} sdp_payload_attr_t;

typedef struct lump {
    union {
        char *value;
        void *ptr;
    } u;
    int len;
} lump_t;

struct sdp_stream_cell {
    sdp_payload_attr_t *payload_attr;
    str port;
};

#define LM_ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define DESC_REGEXP 0
#define DESC_REGEXP_COMPLEMENT 1
#define DESC_NAME 2
#define DESC_NAME_AND_CLOCK 3
#define FIND 0
#define DELETE 1
#define ADD_TO_FRONT 2
#define ADD_TO_BACK 3

extern lump_t *get_associated_lump(struct sip_msg *msg, struct sdp_stream_cell *cell);
extern int delete_sdp_line(struct sip_msg *msg, char *s, struct sdp_stream_cell *cell);
extern lump_t *del_lump(struct sip_msg *msg, int offset, int len, int type);
extern int insert_new_lump_after(lump_t *lmp, char *s, int len, int type);
extern void *pkg_malloc(size_t size);
extern void *pkg_realloc(void *ptr, size_t size);
extern void pkg_free(void *ptr);