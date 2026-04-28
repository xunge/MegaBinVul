#include <stddef.h>
#include <string.h>
#include <sys/types.h>

struct mspack_file;

#define MSPACK_ERR_OK 0
#define MSPACK_ERR_READ 1
#define MSPACK_ERR_SIGNATURE 2
#define MSPACK_ERR_DATAFORMAT 3
#define MSPACK_ERR_SEEK 4
#define MSPACK_ERR_NOMEMORY 5

#define MSPACK_SYS_SEEK_START 0
#define MSPACK_SYS_SEEK_CUR 1

#define chmhead_SIZEOF 0x58
#define chmhead_Signature 0x00
#define chmhead_GUID1 0x08
#define chmhead_Version 0x28
#define chmhead_Timestamp 0x2C
#define chmhead_LanguageID 0x30

#define chmhst3_SIZEOF 0x54
#define chmhst_OffsetHS0 0x00
#define chmhst_OffsetHS1 0x08
#define chmhst3_OffsetCS0 0x10

#define chmhs0_SIZEOF 0x18
#define chmhs0_FileLen 0x00

#define chmhs1_SIZEOF 0x14
#define chmhs1_ChunkSize 0x00
#define chmhs1_Density 0x04
#define chmhs1_Depth 0x08
#define chmhs1_IndexRoot 0x0C
#define chmhs1_NumChunks 0x10
#define chmhs1_FirstPMGL 0x14
#define chmhs1_LastPMGL 0x18

#define pmgl_Signature 0x00
#define pmgl_QuickRefSize 0x04
#define pmgl_Entries 0x08

#define READ_ENCINT(var) \
    do { \
        var = 0; \
        do { \
            if (p >= end) goto chunk_end; \
            var = (var << 7) | (*p & 0x7F); \
        } while (*p++ & 0x80); \
    } while (0)

#define D(x)

struct mspack_system {
    int (*read)(struct mspack_file *, void *, int);
    int (*seek)(struct mspack_file *, off_t, int);
    off_t (*tell)(struct mspack_file *);
    void (*message)(struct mspack_file *, const char *, ...);
    void *(*alloc)(struct mspack_system *, size_t);
    void (*free)(void *);
    void (*copy)(void *, void *, size_t);
};

struct mschmd_section_base {
    struct mschmd_header *chm;
    unsigned int id;
};

struct mschmd_section {
    struct mschmd_section_base base;
    off_t offset;
};

struct mschmd_file {
    struct mschmd_file *next;
    char *filename;
    struct mschmd_section *section;
    off_t offset;
    off_t length;
};

struct mschmd_header {
    unsigned int version;
    unsigned int timestamp;
    unsigned int language;
    off_t dir_offset;
    off_t length;
    unsigned int chunk_size;
    unsigned int density;
    unsigned int depth;
    unsigned int index_root;
    unsigned int num_chunks;
    unsigned int first_pmgl;
    unsigned int last_pmgl;
    struct mschmd_file *files;
    struct mschmd_file *sysfiles;
    void *chunk_cache;
    struct {
        struct mschmd_section_base base;
        off_t offset;
    } sec0;
    struct {
        struct mschmd_section_base base;
        struct mschmd_file *content;
        struct mschmd_file *control;
        struct mschmd_file *spaninfo;
        struct mschmd_file *rtable;
    } sec1;
};

static const unsigned char guids[32] = {
    0x7D, 0xFC, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90,
    0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98,
    0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0,
    0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8
};

static const char content_name[40] = "::DataSpace/Storage/MSCompressed/Content";
static const char control_name[44] = "::DataSpace/Storage/MSCompressed/ControlData";
static const char spaninfo_name[41] = "::DataSpace/Storage/MSCompressed/SpanInfo";
static const char rtable_name[105] = "::DataSpace/Storage/MSCompressed/Transform/{7FC28940-9D31-11D0-9B27-00A0C91E9C7C}/InstanceData/ResetTable";

static int read_off64(off_t *var, unsigned char *data, struct mspack_system *sys, struct mspack_file *fh) {
    return 0;
}

static unsigned int EndGetI32(unsigned char *data) {
    return (data[0]) | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

static unsigned int EndGetM32(unsigned char *data) {
    return (data[3]) | (data[2] << 8) | (data[1] << 16) | (data[0] << 24);
}

static unsigned int EndGetI16(unsigned char *data) {
    return (data[0]) | (data[1] << 8);
}