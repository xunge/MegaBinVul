struct list_head {
    struct list_head *next, *prev;
};

struct scsi_device {
    void *sdev_target;
    unsigned int lun;
};

struct scsi_cmnd {
    struct scsi_device *device;
    struct list_head eh_entry;
};

void sas_eh_defer_cmd(struct scsi_cmnd *cmd);

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(pos))((head)->next), \
         n = (typeof(n))(pos->member.next); \
         &pos->member != (head); \
         pos = (typeof(pos))(n), \
         n = (typeof(n))(n->member.next))