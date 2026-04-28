#include <stddef.h>
#include <stdio.h>

typedef int htp_status_t;
#define HTP_OK 0
#define HTP_ERROR -1

typedef enum {
    HTP_STREAM_CLOSED,
    HTP_STREAM_OPEN
} htp_stream_status_t;

typedef enum {
    HTP_REQUEST_TRAILER
} htp_request_progress_t;

#define HTP_LOG_MARK NULL
#define HTP_LOG_WARNING 1
#define HTP_INVALID_FOLDING (1 << 0)
#define LF '\n'

typedef struct {
    htp_request_progress_t request_progress;
    int flags;
} htp_tx_t;

typedef struct {
    unsigned char *ptr;
    size_t len;
} bstr;

typedef struct {
    htp_status_t (*process_request_header)(void *, const char *, size_t);
} htp_cfg_t;

typedef struct {
    htp_stream_status_t in_status;
    bstr *in_header;
    htp_cfg_t *cfg;
    htp_tx_t *in_tx;
    int in_next_byte;
} htp_connp_t;

#define IN_COPY_BYTE_OR_RETURN(connp) 
#define IN_PEEK_NEXT(connp) 

void bstr_free(bstr *b);
bstr *bstr_dup_mem(const void *mem, size_t len);
bstr *bstr_add_mem(bstr *b, const void *mem, size_t len);
const char *bstr_ptr(const bstr *b);
size_t bstr_len(const bstr *b);

htp_status_t htp_connp_req_consolidate_data(htp_connp_t *connp, unsigned char **data, size_t *len);
int htp_connp_is_line_terminator(htp_connp_t *connp, const unsigned char *data, size_t len);
void htp_chomp(unsigned char *data, size_t *len);
int htp_connp_is_line_folded(const unsigned char *data, size_t len);
int htp_is_folding_char(int c);
void htp_log(htp_connp_t *connp, const char *mark, int level, int flags, const char *format, ...);
void htp_connp_req_clear_buffer(htp_connp_t *connp);
htp_status_t htp_tx_state_request_headers(htp_tx_t *tx);