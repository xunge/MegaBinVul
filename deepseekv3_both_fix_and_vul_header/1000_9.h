#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define MH_FILESET 0x0C
#define R_CF_OPTION_SKIP_NSDATA 1

typedef uint64_t ut64;

typedef struct RBuffer RBuffer;
typedef struct Sdb Sdb;
typedef struct RIO RIO;
typedef struct RList RList;
typedef struct RCFValueDict RCFValueDict;
typedef struct RRebaseInfo RRebaseInfo;

struct MACH0_opts_t {
    // Add necessary fields here
};

struct MACH0_obj_t {
    struct {
        uint32_t filetype;
    } hdr;
    void *chained_starts;
    // Add other necessary fields
};

typedef struct RBinFile {
    struct {
        struct {
            struct RIO *io;
        } iob;
    } *rbin;
    // Add other necessary fields
} RBinFile;

typedef struct RPrelinkRange {
    struct {
        ut64 offset;
        ut64 size;
    } range;
    ut64 pa2va_exec;
    ut64 pa2va_data;
} RPrelinkRange;

typedef struct RKernelCacheObj {
    struct MACH0_obj_t *mach0;
    struct RRebaseInfo *rebase_info;
    struct RCFValueDict *prelink_info;
    struct RBuffer *cache_buf;
    ut64 pa2va_exec;
    ut64 pa2va_data;
} RKernelCacheObj;

static struct RList *pending_bin_files = NULL;

// Function prototypes for non-standard functions
struct RBuffer* r_buf_ref(struct RBuffer*);
void MACH0_opts_set_default(struct MACH0_opts_t*, struct RBinFile*);
struct MACH0_obj_t* MACH0_new_buf(struct RBuffer*, struct MACH0_opts_t*);
struct RRebaseInfo* r_rebase_info_new_from_mach0(struct RBuffer*, struct MACH0_obj_t*);
struct RPrelinkRange* get_prelink_info_range_from_mach0(struct MACH0_obj_t*);
void* R_NEW0(size_t);
void R_FREE(void*);
struct RCFValueDict* r_cf_value_dict_parse(struct RBuffer*, ut64, ut64, int);
struct RList* r_list_new(void);
void r_list_push(struct RList*, void*);
void r_buf_free(struct RBuffer*);
void MACH0_mach0_free(struct MACH0_obj_t*);
void swizzle_io_read(struct RKernelCacheObj*, struct RIO*);

// Macro definitions for MACH0_ prefixed functions
#define MACH0_(name) MACH0_##name
#define R_NEW0(type) calloc(1, sizeof(type))