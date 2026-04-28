#include <stddef.h>

#define LF '\n'
#define CR '\r'

typedef int htp_status_t;
typedef struct htp_connp htp_connp_t;
typedef struct bstr bstr;

#define HTP_OK 0
#define HTP_ERROR -1
#define HTP_DATA_BUFFER -2
#define HTP_STREAM_CLOSED -3
#define HTP_LOG_MARK 0
#define HTP_LOG_WARNING 1
#define HTP_RESPONSE_HEADERS 0
#define HTP_INVALID_FOLDING 1

enum {
    htp_connp_RES_BODY_DETERMINE,
    htp_connp_RES_FINALIZE
};

#define OUT_COPY_BYTE_OR_RETURN(x)
#define OUT_PEEK_NEXT(x)

struct htp_connp {
    int out_status;
    int out_state;
    int out_next_byte;
    bstr *out_header;
    struct {
        int (*process_response_header)(htp_connp_t *, const char *, size_t);
        int hook_response_trailer;
    } *cfg;
    struct {
        int response_progress;
        int flags;
    } *out_tx;
};

htp_status_t htp_connp_res_receiver_finalize_clear(htp_connp_t *connp);
htp_status_t htp_hook_run_all(int hook, void *tx);
int htp_connp_is_line_terminator(htp_connp_t *connp, unsigned char *data, size_t len);
int htp_connp_is_line_folded(unsigned char *data, size_t len);
int htp_is_folding_char(int c);
void htp_chomp(unsigned char *data, size_t *len);
void htp_connp_res_clear_buffer(htp_connp_t *connp);
void htp_log(htp_connp_t *connp, int mark, int level, int code, const char *msg);
bstr *bstr_dup_mem(const void *data, size_t len);
void bstr_free(bstr *b);
bstr *bstr_add_mem(bstr *b, const void *data, size_t len);
const char *bstr_ptr(const bstr *b);
size_t bstr_len(const bstr *b);
htp_status_t htp_connp_res_consolidate_data(htp_connp_t *connp, unsigned char **data, size_t *len);