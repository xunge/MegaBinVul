#include <stdatomic.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/queue.h>

#define NCI_UNREG        0
#define NCI_UP           1
#define NCI_INIT         2
#define NCI_FEATURE_DISABLE 0
#define NCI_VER_2_MASK   0x02
#define NCI_IDLE         0
#define ENODEV           19
#define EALREADY         114
#define EIO              5
#define NCI_RESET_TIMEOUT 5000
#define NCI_INIT_TIMEOUT 5000

struct nci_dev;
struct nci_ops;

struct nci_core_init_v2_cmd {
    uint8_t feature1;
    uint8_t feature2;
};

struct nci_dev {
    pthread_mutex_t req_lock;
    unsigned long flags;
    struct nci_ops *ops;
    atomic_int cmd_cnt;
    atomic_int state;
    uint8_t nci_ver;
    STAILQ_HEAD(, sk_buff) cmd_q;
    STAILQ_HEAD(, sk_buff) rx_q;
    STAILQ_HEAD(, sk_buff) tx_q;
};

struct nci_ops {
    int (*open)(struct nci_dev *dev);
    int (*close)(struct nci_dev *dev);
    int (*init)(struct nci_dev *dev);
    int (*setup)(struct nci_dev *dev);
    int (*post_setup)(struct nci_dev *dev);
};

struct sk_buff {
    STAILQ_ENTRY(sk_buff) next;
};

int __nci_request(struct nci_dev *ndev, void *req, const void *opt, unsigned long timeout);
void nci_clear_target_list(struct nci_dev *ndev);
void nci_reset_req(struct nci_dev *ndev, const void *opt);
void nci_init_req(struct nci_dev *ndev, const void *opt);
void nci_init_complete_req(struct nci_dev *ndev, const void *opt);