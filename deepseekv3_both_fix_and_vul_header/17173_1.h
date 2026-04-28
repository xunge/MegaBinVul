#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct sas_ha_struct {
    struct list_head eh_ata_q;
    struct list_head eh_done_q;
};

struct domain_device;
struct sas_task;
struct scsi_cmnd {
    struct list_head eh_entry;
    struct {
        struct {
            struct sas_ha_struct *hostdata;
        } *host;
        struct domain_device *hostdata;
    } *device;
    struct sas_task *host_scribble;
};

#define SHOST_TO_SAS_HA(shost) ((struct sas_ha_struct *)(shost)->hostdata)
#define cmd_to_domain_dev(cmd) ((struct domain_device *)(cmd)->device->hostdata)
#define TO_SAS_TASK(cmd) ((struct sas_task *)(cmd)->host_scribble)

void list_move_tail(struct list_head *list, struct list_head *head);
int dev_is_sata(struct domain_device *dev);
void sas_end_task(struct scsi_cmnd *cmd, struct sas_task *task);
void scsi_eh_finish_cmd(struct scsi_cmnd *cmd, struct list_head *list);