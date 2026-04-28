#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <inttypes.h>
#include <sys/uio.h>

#define TCMU_STS_OK 0
#define TCMU_STS_NO_RESOURCE 1
#define TCMU_STS_INVALID_PARAM_LIST 2
#define TCMU_STS_INVALID_PARAM_LIST_LEN 3
#define TCMU_STS_CP_TGT_DEV_NOTCONN 4
#define TCMU_STS_INVALID_CP_TGT_DEV_TYPE 5
#define TCMU_STS_RANGE 6

#define RCR_OP_MAX_DESC_LIST_LEN 1024
#define XCOPY_HDR_LEN 16

struct tcmu_device;
struct tcmulib_cmd {
    uint8_t *cdb;
    struct iovec *iovec;
    size_t iov_cnt;
};

struct xcopy {
    struct tcmu_device *src_dev;
    struct tcmu_device *dst_dev;
    uint64_t src_lba;
    uint64_t dst_lba;
    uint32_t lba_cnt;
};

size_t tcmu_cdb_get_xfer_length(uint8_t *cdb);
void tcmu_memcpy_from_iovec(void *buf, size_t len, struct iovec *iov, size_t iov_cnt);
void tcmu_dev_err(struct tcmu_device *dev, const char *fmt, ...);
void tcmu_dev_dbg(struct tcmu_device *dev, const char *fmt, ...);
unsigned int tcmu_dev_get_block_size(struct tcmu_device *dev);
uint64_t tcmu_dev_get_num_lbas(struct tcmu_device *dev);
int xcopy_parse_segment_descs(uint8_t *seg_desc, struct xcopy *xcopy, uint16_t sdll);
int xcopy_parse_target_descs(struct tcmu_device *dev, struct xcopy *xcopy, uint8_t *tgt_desc, uint16_t tdll);