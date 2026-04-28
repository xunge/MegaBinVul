#include <stddef.h>
#include <string.h>
#include <errno.h>

typedef unsigned char u8;

struct dvb_frontend {
    void *demodulator_priv;
};

struct dvb_diseqc_master_cmd {
    unsigned char msg_len;
    unsigned char msg[6];
};

struct ttusbdecfe_state {
    struct {
        int (*send_command)(struct dvb_frontend*, int, int, u8*, void*, void*);
    } *config;
};