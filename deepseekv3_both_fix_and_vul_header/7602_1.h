#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

#define SC_PATH_TYPE_PATH 0

typedef struct sc_path {
    u8 *value;
    size_t len;
    int idx;
    unsigned int count;
    unsigned int type;
    struct {
        const char *value;
        size_t len;
    } aid;
} sc_path_t;

typedef struct sc_file {
    size_t size;
} sc_file_t;

typedef struct sc_context {
    // context members
} sc_context_t;

typedef struct sc_card {
    void *drv_data;
    sc_context_t *ctx;
    // other card members
} sc_card_t;

typedef struct idprime_private_data {
    int tinfo_present;
    u8 tinfo_df[2];
    // other private data members
} idprime_private_data_t;

typedef struct iso_operations {
    int (*select_file)(sc_card_t*, sc_path_t*, sc_file_t**);
    int (*read_binary)(sc_card_t*, unsigned int, u8*, size_t, unsigned long);
    // other ISO operations
} iso_operations_t;

extern iso_operations_t *iso_ops;

static inline void sc_file_free(sc_file_t *file) {
    free(file);
}

#define LOG_FUNC_CALLED(ctx)
#define LOG_FUNC_RETURN(ctx, r) return (r)
#define SC_ERROR_INVALID_ARGUMENTS (-1)
#define SC_ERROR_NOT_SUPPORTED (-2)
#define SC_ERROR_OUT_OF_MEMORY (-3)
#define SC_SUCCESS 0