#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define CHUNK_CAPACITY 4096
#define MSC_REQBODY_DISK 1
#define REQUEST_BODY_FORCEBUF_ON 1

typedef struct modsec_rec modsec_rec;
typedef struct msc_data_chunk msc_data_chunk;
typedef struct apr_pool_t apr_pool_t;
typedef int apr_status_t;
typedef unsigned int apr_size_t;

struct msc_data_chunk {
    char *data;
    unsigned int length;
    int is_permanent;
};

struct apr_array_header_t {
    void *elts;
    int nelts;
    int nalloc;
    apr_size_t elt_size;
};

struct modsec_rec {
    int msc_reqbody_spilltodisk;
    struct {
        int reqbody_buffering;
        int reqbody_inmemory_limit;
    } *txcfg;
    apr_size_t msc_reqbody_length;
    int msc_reqbody_storage;
    struct apr_array_header_t *msc_reqbody_chunks;
    msc_data_chunk *msc_reqbody_chunk_current;
    apr_pool_t *msc_reqbody_mp;
    apr_pool_t *mp;
};

static void apr_pool_clear(apr_pool_t *pool) {}
static void *apr_pcalloc(apr_pool_t *pool, size_t size) { return calloc(1, size); }
static void *apr_array_push(struct apr_array_header_t *arr) { return NULL; }
static char *apr_psprintf(apr_pool_t *pool, const char *fmt, ...) { return NULL; }
static void msr_log(modsec_rec *msr, int level, const char *msg, ...) {}
static int modsecurity_request_body_store_disk(modsec_rec *msr, const char *data, apr_size_t length, char **error_msg) { return 0; }
static int modsecurity_request_body_start_init(modsec_rec *msr, char **error_msg) { return 0; }