#include <stddef.h>
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
#define MSPACK_SYS_SEEK_END 2

#define chmhead_SIZEOF 0x58
#define chmhead_Signature 0
#define chmhead_GUID1 0x38
#define chmhead_Version 0x4C
#define chmhead_Timestamp 0x50
#define chmhead_LanguageID 0x54

#define chmhst3_SIZEOF 0x54
#define chmhst_OffsetHS0 0x18
#define chmhst_OffsetHS1 0x20
#define chmhst3_OffsetCS0 0x28

#define chmhs0_SIZEOF 0x18
#define chmhs0_FileLen 0x10

#define chmhs1_SIZEOF 0x14
#define chmhs1_ChunkSize 0x04
#define chmhs1_Density 0x08
#define chmhs1_Depth 0x0C
#define chmhs1_IndexRoot 0x10
#define chmhs1_NumChunks 0x14
#define chmhs1_FirstPMGL 0x18
#define chmhs1_LastPMGL 0x1C

#define pmgl_Signature 0
#define pmgl_QuickRefSize 4
#define pmgl_Entries 8

struct mspack_system {
    int (*read)(struct mspack_file *, void *, int);
    int (*seek)(struct mspack_file *, off_t, int);
    off_t (*tell)(struct mspack_file *);
    void *(*alloc)(struct mspack_system *, size_t);
    void (*free)(void *);
    void (*copy)(void *, void *, size_t);
    void (*message)(struct mspack_file *, const char *, ...);
};

struct mschmd_section {
    struct mschmd_section *next;
    struct mschmd_header *chm;
    unsigned int id;
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
        struct mschmd_section base;
        off_t offset;
    } sec0;
    struct {
        struct mschmd_section base;
        struct mschmd_file *content;
        struct mschmd_file *control;
        struct mschmd_file *spaninfo;
        struct mschmd_file *rtable;
    } sec1;
};

static unsigned char guids[32];
static unsigned char content_name[41];
static unsigned char control_name[44];
static unsigned char spaninfo_name[41];
static unsigned char rtable_name[74];

#define READ_ENCINT(var) do { \
    (var) = 0; \
    do { \
        if (p >= end) goto chunk_end; \
        (var) = ((var) << 7) | (*p & 0x7F); \
    } while (*p++ & 0x80); \
} while (0)

static int EndGetI32(const unsigned char *buf) {
    return (buf[0]) | (buf[1] << 8) | (buf[2] << 16) | (buf[3] << 24);
}

static unsigned int EndGetM32(const unsigned char *buf) {
    return (buf[3]) | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);
}

static int EndGetI16(const unsigned char *buf) {
    return (buf[0]) | (buf[1] << 8);
}

static int mspack_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1, *p2 = s2;
    while (n--) {
        if (*p1 != *p2) return (*p1 - *p2);
        p1++; p2++;
    }
    return 0;
}

static int read_off64(off_t *var, const unsigned char *buf,
                     struct mspack_system *sys, struct mspack_file *fh) {
    unsigned char tmp[8];
    if (sys->read(fh, tmp, 8) != 8) return 1;
    *var = ((off_t)EndGetI32(&tmp[0])) | (((off_t)EndGetI32(&tmp[4])) << 32);
    return 0;
}

#define D(x)