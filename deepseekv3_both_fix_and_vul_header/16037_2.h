#include <stddef.h>

struct timer_list {
    // 最小化的timer_list结构定义
    void *dummy;
};
struct pci_dev {
    // 最小化的pci_dev结构定义
    void *dummy;
};
struct v4l2_ctrl_handler {
    // 最小化的v4l2_ctrl_handler结构定义
    void *dummy;
};

struct saa7134_dev {
    struct pci_dev *pci;
    struct {
        struct timer_list timeout;
        void *pt;
    } video_q;
    struct {
        void *pt;
    } vbi_q;
    struct v4l2_ctrl_handler ctrl_handler;
    struct v4l2_ctrl_handler radio_ctrl_handler;
};

int card_has_radio(struct saa7134_dev *dev);
void saa7134_pgtable_free(struct pci_dev *pci, void *pt);
void del_timer_sync(struct timer_list *timer);
void v4l2_ctrl_handler_free(struct v4l2_ctrl_handler *hdl);