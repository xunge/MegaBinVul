#include <netinet/in.h>

struct chan_iax2_pvt {
    struct sockaddr_in addr;
    struct sockaddr_in transfer;
    unsigned short peercallno;
    unsigned short callno;
    unsigned short transfercallno;
    int transferring;
};

#define TRANSFER_MEDIAPASS 1