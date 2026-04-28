#include <stdlib.h>
#include <string.h>

#define CIFS_NO_BUFFER 0

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct sess_data {
    struct kvec *iov;
    int buf0_type;
};

void free_rsp_buf(int type, void *buf);
void kfree_sensitive(void *ptr);
void kfree(void *ptr);
void memzero_explicit(void *s, size_t count);