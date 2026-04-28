#include <stdio.h>

struct sip_msg {
    char *buf;
};

struct sdp_stream_cell {
    struct {
        char *s;
        int len;
    } body;
};

int del_lump(struct sip_msg *msg, int offset, int len, int flags);