#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

struct file {
    int f_flags;
};

typedef uint8_t u8;
typedef uint16_t u16;

#define __user
#define O_NONBLOCK 04000
#define ERESTARTSYS 512

struct MPT3SAS_ADAPTER {
    int ioc_number;
    pthread_mutex_t pci_access_mutex;
    struct {
        pthread_mutex_t mutex;
    } ctl_cmds;
    int shost_recovery;
    int pci_error_recovery;
    int is_driver_loading;
    int remove_host;
};

struct mpt3_ioctl_header {
    int ioc_number;
};

struct mpt3_ioctl_command {
    struct mpt3_ioctl_header hdr;
    void *mf;
};

struct mpt3_ioctl_iocinfo {};
struct mpt3_ioctl_eventquery {};
struct mpt3_ioctl_eventenable {};
struct mpt3_ioctl_diag_reset {};
struct mpt3_ioctl_btdh_mapping {};
struct mpt3_diag_register {};
struct mpt3_diag_unregister {};
struct mpt3_diag_query {};
struct mpt3_diag_release {};
struct mpt3_diag_read_buffer {};

enum block_state {
    BLOCKING,
    NON_BLOCKING
};

#define MPT3IOCINFO 1
#define MPT3COMMAND 2
#define MPT3COMMAND32 3
#define MPT3EVENTQUERY 4
#define MPT3EVENTENABLE 5
#define MPT3EVENTREPORT 6
#define MPT3HARDRESET 7
#define MPT3BTDHMAPPING 8
#define MPT3DIAGREGISTER 9
#define MPT3DIAGUNREGISTER 10
#define MPT3DIAGQUERY 11
#define MPT3DIAGRELEASE 12
#define MPT3DIAGREADBUFFER 13

#define _IOC_SIZE(x) sizeof(struct mpt3_ioctl_command)
#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dctlprintk(ioc, fmt) printf(fmt)
#define ioc_info(ioc, fmt, ...) fmt
#define copy_from_user(to, from, size) memcpy(to, from, size)

static inline int _ctl_verify_adapter(int ioc_number, struct MPT3SAS_ADAPTER **ioc, u16 mpi_version) { return 0; }
static inline long _ctl_getiocinfo(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_do_mpt_command(struct MPT3SAS_ADAPTER *ioc, struct mpt3_ioctl_command karg, void *mf) { return 0; }
static inline long _ctl_eventquery(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_eventenable(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_eventreport(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_do_reset(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_btdh_mapping(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_diag_register(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_diag_unregister(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_diag_query(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_diag_release(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_diag_read_buffer(struct MPT3SAS_ADAPTER *ioc, void *arg) { return 0; }
static inline long _ctl_compat_mpt_command(struct MPT3SAS_ADAPTER *ioc, unsigned int cmd, void *arg) { return 0; }

static inline int mutex_lock(pthread_mutex_t *lock) { return pthread_mutex_lock(lock); }
static inline int mutex_unlock(pthread_mutex_t *lock) { return pthread_mutex_unlock(lock); }
static inline int mutex_trylock(pthread_mutex_t *lock) { return pthread_mutex_trylock(lock); }
static inline int mutex_lock_interruptible(pthread_mutex_t *lock) { return pthread_mutex_lock(lock); }