#include <stdlib.h>
#include <stdint.h>

typedef struct packet_info {
    struct {
        int num;
    } *fd;
} packet_info;

typedef struct tvbuff_t {
    uint32_t (*get_ntohl)(struct tvbuff_t *tvb, int offset);
    char* (*get_ptr)(struct tvbuff_t *tvb, int offset, int length);
} tvbuff_t;

typedef struct {
    uint32_t cookie_len;
    char *cookie;
    uint32_t req_frame;
    unsigned int ns;
} nlm_msg_res_unmatched_data;

typedef struct {
    uint32_t req_frame;
    uint32_t rep_frame;
    unsigned int ns;
} nlm_msg_res_matched_data;

typedef void* gpointer;
typedef const void* gconstpointer;

extern void* nlm_msg_res_unmatched;
extern void* nlm_msg_res_matched;

#define GINT_TO_POINTER(i) ((gpointer)(long)(i))
#define g_malloc malloc
#define g_free free

static inline uint32_t tvb_get_ntohl(tvbuff_t *tvb, int offset) {
    return tvb->get_ntohl(tvb, offset);
}

static inline char* tvb_get_ptr(tvbuff_t *tvb, int offset, int length) {
    return tvb->get_ptr(tvb, offset, length);
}