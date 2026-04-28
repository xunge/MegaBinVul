#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

enum parser_state {
    P_STATE_CODE,
    P_STATE_COMMENT_C
};

struct parser_buf {
    int f_indx;
    int tmp_indx;
    int f_read_size;
};

struct trans_config {
    // add necessary fields here
};

int p_buf_refill(struct parser_buf *pbuf, int src_fd);
void p_buf_push_tmp_char(struct parser_buf *pbuf, char c);
void p_buf_write_tmp(struct parser_buf *pbuf, int tmp_fd);
void p_buf_write_f_char(struct parser_buf *pbuf, int tmp_fd);

#define PBUF_F_REMD(pbuf) ((pbuf).f_indx < (pbuf).f_read_size)
#define PBUF_F_CHAR(pbuf) ((pbuf).f_indx < (pbuf).f_read_size ? /* get char from buffer */ : 0)
#define PBUF_TMP_PREV_CHAR(pbuf) ((pbuf).tmp_indx > 0 ? /* get previous tmp char */ : 0)