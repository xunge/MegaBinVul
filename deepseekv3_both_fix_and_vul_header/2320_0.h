#include <stdio.h>
#include <assert.h>
#include <arpa/inet.h>

struct net_hdr {
    int nh_len;
    int nh_type;
};

int net_read_exact(int s, void *buf, int len);