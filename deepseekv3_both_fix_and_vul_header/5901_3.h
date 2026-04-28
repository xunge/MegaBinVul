#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

struct vhost_scsi_evt {
    struct {
        uint8_t lun[8];
    } event;
    struct vhost_scsi_evt *next;
    struct vhost_scsi_evt *list;
};

struct vhost_work {
    void *data;
};

struct vhost_dev {
    void *priv;
};

struct vhost_scsi {
    struct vhost_scsi_evt *vs_event_list;
    struct vhost_work vs_event_work;
    struct vhost_dev dev;
};

struct vhost_scsi_tpg {
    uint16_t tport_tpgt;
};

struct se_lun {
    uint16_t unpacked_lun;
};

static struct vhost_scsi_evt *vhost_scsi_allocate_evt(struct vhost_scsi *vs, u32 event, u32 reason) {
    return malloc(sizeof(struct vhost_scsi_evt));
}

static void llist_add(struct vhost_scsi_evt **list, struct vhost_scsi_evt *evt) {
    evt->next = *list;
    *list = evt;
}

static void vhost_work_queue(struct vhost_dev *dev, struct vhost_work *work) {
    // dummy implementation
}