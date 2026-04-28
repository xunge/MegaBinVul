#include <stdio.h>
#include <unistd.h>

struct dvb_frontend {
    void *demodulator_priv;
};

struct dvb_diseqc_master_cmd {
    unsigned char msg[6];
    unsigned char msg_len;
};

struct cx24116_state {
    struct {
        unsigned char args[32];
        int len;
    } dsec_cmd;
};

#define debug 0
#define toneburst 0
#define CX24116_ARGLEN 32
#define CX24116_DISEQC_MSGOFS 3
#define CX24116_DISEQC_MSGLEN 2
#define CX24116_DISEQC_BURST 1
#define CX24116_DISEQC_MESGCACHE 0
#define CX24116_DISEQC_TONEOFF 1
#define CX24116_DISEQC_TONECACHE 2
#define EINVAL 1

static inline int cx24116_wait_for_lnb(struct dvb_frontend *fe) { return 0; }
static inline int cx24116_cmd_execute(struct dvb_frontend *fe, void *cmd) { return 0; }

#define msleep(x) usleep((x)*1000)
#define printk printf
#define KERN_INFO ""
#define dprintk(...)