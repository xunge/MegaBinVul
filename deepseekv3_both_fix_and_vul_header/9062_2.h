#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct file;

#define DIGI_GETDD 0
#define DIGI_GETBD 1
#define DIGI_GET_NI_INFO 2

#define DGNC_CHANNEL_MAGIC 0x44474E43
#define DG_PART "DGNC"
#define BOARD_FAILED 0

#define UART_MCR_DTR 0x01
#define UART_MCR_RTS 0x02
#define UART_MSR_CTS 0x10
#define UART_MSR_RI 0x40
#define UART_MSR_DCD 0x80
#define UART_MSR_DSR 0x20

#define TIOCM_DTR 0x002
#define TIOCM_RTS 0x004
#define TIOCM_CTS 0x020
#define TIOCM_RI 0x080
#define TIOCM_CD 0x040
#define TIOCM_DSR 0x010

#define CTSPACE 0x01
#define CRTSCTS 0x80000000

#define CH_STOPI 0x0001
#define CH_FORCED_STOPI 0x0002
#define CH_STOP 0x0004
#define CH_FORCED_STOP 0x0008

typedef unsigned long ulong;
typedef unsigned int uint;

struct digi_dinfo {
    int dinfo_nboards;
    char dinfo_version[32];
};

struct digi_info {
    int info_bdnum;
    int info_bdtype;
    int info_bdstate;
    int info_ioport;
    ulong info_physaddr;
    ulong info_physsize;
    int info_nports;
};

struct ni_info {
    uint board;
    uint channel;
    uint mstat;
    uint dtr;
    uint rts;
    uint cts;
    uint ri;
    uint dcd;
    uint iflag;
    uint oflag;
    uint cflag;
    uint lflag;
    uint hflow;
    uint recv_stopped;
    uint xmit_stopped;
    uint curtx;
    uint currx;
    uint baud;
};

struct channel_t {
    uint magic;
    uint ch_lock;
    unsigned char ch_mostat;
    unsigned char ch_mistat;
    uint ch_c_iflag;
    uint ch_c_oflag;
    uint ch_c_cflag;
    uint ch_c_lflag;
    struct {
        uint digi_flags;
    } ch_digi;
    uint ch_flags;
    uint ch_txcount;
    uint ch_rxcount;
    uint ch_old_baud;
};

struct board_t {
    uint bd_lock;
    int dpatype;
    int dpastatus;
    void *membase;
    ulong membase_end;
    int state;
    int nasync;
    struct channel_t **channels;
};

extern uint dgnc_global_lock;
extern int dgnc_NumBoards;
extern struct board_t **dgnc_Board;

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define copy_to_user(to, from, size) (0)
#define copy_from_user(to, from, size) (0)
#define __user
#define EFAULT (-1)
#define ENODEV (-2)