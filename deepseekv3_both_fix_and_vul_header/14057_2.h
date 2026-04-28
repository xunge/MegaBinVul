#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#define DOS_MAGIC 0xaa55
#define TSK_ERR_VS_READ 1
#define TSK_ERR_VS_MAGIC 2
#define TSK_VS_PART_FLAG_META 1
#define TSK_VS_PART_FLAG_ALLOC 2

#define PRIuDADDR PRIu64

typedef uint64_t TSK_DADDR_T;

typedef struct TSK_IMG_INFO {
    uint64_t size;
} TSK_IMG_INFO;

typedef struct TSK_VS_INFO {
    TSK_IMG_INFO *img_info;
    uint64_t offset;
    uint32_t block_size;
    uint8_t endian;
} TSK_VS_INFO;

typedef struct dos_part {
    uint8_t start_sec[4];
    uint8_t size_sec[4];
    uint8_t ptype;
    uint8_t unused[7];
} dos_part;

typedef struct dos_sect {
    uint8_t magic[2];
    dos_part ptable[4];
    uint8_t unused[446];
} dos_sect;

extern int tsk_verbose;
extern ssize_t tsk_vs_read_block(TSK_VS_INFO *vs, TSK_DADDR_T addr, void *buf, size_t len);
extern uint16_t tsk_getu16(uint8_t endian, const uint8_t *buf);
extern uint32_t tsk_getu32(uint8_t endian, const uint8_t *buf);
extern void *tsk_malloc(size_t len);
extern void tsk_error_reset(void);
extern void tsk_error_set_errno(int err);
extern void tsk_error_set_errstr(const char *fmt, ...);
extern void tsk_error_set_errstr2(const char *fmt, ...);
extern void *tsk_vs_part_add(TSK_VS_INFO *vs, TSK_DADDR_T start, TSK_DADDR_T len, int flags, const char *desc, int table, int num);
extern int tsk_fprintf(FILE *stream, const char *fmt, ...);
extern int dos_is_ext(uint8_t ptype);
extern const char *dos_get_desc(uint8_t ptype);