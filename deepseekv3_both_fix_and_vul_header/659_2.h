#include <stdint.h>
#include <errno.h>

#define HNAE3_MAX_TC 8

typedef uint8_t u8;
typedef uint16_t u16;

struct hnae3_knic_private_info {
    u8 num_tc;
};

struct hclge_tm_tc_info {
    u8 tc_sch_mode;
};

struct hclge_tm_info {
    struct hclge_tm_tc_info tc_info[HNAE3_MAX_TC];
};

struct hclge_dev {
    struct hclge_tm_info tm_info;
};

struct hclge_nic {
    struct hnae3_knic_private_info kinfo;
};

struct hclge_vport {
    struct hclge_nic nic;
    struct hclge_dev *back;
    u16 vport_id;
    u16 qs_offset;
};

int hclge_tm_pri_schd_mode_cfg(struct hclge_dev *hdev, u16 vport_id);
int hclge_tm_qs_schd_mode_cfg(struct hclge_dev *hdev, u16 qs_id, u8 sch_mode);