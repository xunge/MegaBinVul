#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pdfio_dict_s pdfio_dict_t;
typedef struct _pdfio_pair_s _pdfio_pair_t;

enum pdfio_valtype_e {
    PDFIO_VALTYPE_BINARY
};

struct _pdfio_value_s {
    enum pdfio_valtype_e type;
    union {
        struct {
            void *data;
        } binary;
    } value;
};

typedef struct _pdfio_value_s _pdfio_value_t;

struct _pdfio_pair_s {
    const char *key;
    _pdfio_value_t value;
};

struct _pdfio_dict_s {
    size_t num_pairs;
    size_t alloc_pairs;
    _pdfio_pair_t *pairs;
};

int compare_pairs(const void *a, const void *b);

#define PDFIO_DEBUG(fmt, ...)
#define PDFIO_DEBUG_DICT(dict)