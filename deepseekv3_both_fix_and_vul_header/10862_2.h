#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;

#define RPEL_REQ_SIZE 32
#define RPEL_RESP_SIZE 32
#define SMP_REPORT_PHY_ERR_LOG 0x11
#define ENOMEM 12

struct device {
    struct device *parent;
};

struct sas_phy {
    int number;
    struct device dev;
    uint32_t invalid_dword_count;
    uint32_t running_disparity_error_count;
    uint32_t loss_of_dword_sync_count;
    uint32_t phy_reset_problem_count;
};

struct sas_rphy;
struct domain_device;

struct sas_rphy *dev_to_rphy(struct device *dev);
struct domain_device *sas_find_dev_by_rphy(struct sas_rphy *rphy);
u8 *alloc_smp_req(int size);
u8 *alloc_smp_resp(int size);
int smp_execute_task(struct domain_device *dev, u8 *req, int req_size, u8 *resp, int resp_size);
uint32_t scsi_to_u32(u8 *resp);
void kfree(void *ptr);