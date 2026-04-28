#include <stddef.h>
#include <sys/types.h>

struct mspack_system {
    int (*read)(struct mspack_file *, void *, int);
    int (*seek)(struct mspack_file *, off_t, int);
    off_t (*tell)(struct mspack_file *);
    void (*message)(struct mspack_file *, const char *, ...);
    void *(*alloc)(struct mspack_system *, size_t);
    void (*free)(void *);
    void (*copy)(void *, void *, size_t);
};

struct mspack_file;

struct mschmd_section_base {
    struct mschmd_header *chm;
    int id;
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
};

#define chmhead_SIZEOF 0x58
#define chmhead_Signature 0
#define chmhead_GUID1 4
#define chmhead_Version 36
#define chmhead_Timestamp 40
#define chmhead_LanguageID 44

#define chmhst3_SIZEOF 0x54
#define chmhst_OffsetHS0 0
#define chmhst_OffsetHS1 8
#define chmhst3_OffsetCS0 16

#define chmhs0_SIZEOF 8
#define chmhs0_FileLen 0

#define chmhs1_SIZEOF 0x14
#define chmhs1_ChunkSize 0
#define chmhs1_Density 4
#define chmhs1_Depth 8
#define chmhs1_IndexRoot 12
#define chmhs1_NumChunks 16
#define chmhs1_FirstPMGL 20
#define chmhs1_LastPMGL 24

#define pmgl_Signature 0
#define pmgl_QuickRefSize 4
#define pmgl_Entries 8

#define MSPACK_ERR_OK 0
#define MSPACK_ERR_READ 1
#define MSPACK_ERR_SIGNATURE 2
#define MSPACK_ERR_DATAFORMAT 3
#define MSPACK_ERR_SEEK 4
#define MSPACK_ERR_NOMEMORY 5

#define MSPACK_SYS_SEEK_START 0
#define MSPACK_SYS_SEEK_CUR 1

static const unsigned char guids[32];
static const char content_name[41];
static const char control_name[44];
static const char spaninfo_name[41];
static const char rtable_name[75];

static unsigned int EndGetI32(const unsigned char *buf);
static unsigned int EndGetM32(const unsigned char *buf);
static unsigned short EndGetI16(const unsigned char *buf);
static int mspack_memcmp(const void *s1, const void *s2, size_t n);
static int read_off64(off_t *var, const unsigned char *buf,
                     struct mspack_system *sys, struct mspack_file *fh);

#define READ_ENCINT(var) \
    if (p >= end) goto chunk_end; \
    var = *p & 0x7F; \
    if (*p++ & 0x80) { \
        int shift = 7; \
        for (;;) { \
            if (p >= end) goto chunk_end; \
            var |= (*p & 0x7F) << shift; \
            if (!(*p++ & 0x80)) break; \
            shift += 7; \
        } \
    }

#define D(x)