#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <unistd.h>

typedef enum _pdfio_valtype_e {
    PDFIO_VALTYPE_NULL,
    PDFIO_VALTYPE_BOOLEAN,
    PDFIO_VALTYPE_NUMBER,
    PDFIO_VALTYPE_STRING,
    PDFIO_VALTYPE_NAME,
    PDFIO_VALTYPE_ARRAY,
    PDFIO_VALTYPE_DICT,
    PDFIO_VALTYPE_OBJ
} _pdfio_valtype_t;

typedef struct _pdfio_value_s _pdfio_value_t;
typedef struct _pdfio_dict_s pdfio_dict_t;
typedef struct _pdfio_array_s pdfio_array_t;
typedef struct _pdfio_obj_s pdfio_obj_t;
typedef struct _pdfio_stream_s pdfio_stream_t;
typedef struct _pdfio_file_s pdfio_file_t;

struct _pdfio_value_s {
    _pdfio_valtype_t type;
    union {
        bool boolean;
        double number;
        char *string;
        char *name;
        pdfio_array_t *array;
        pdfio_dict_t *dict;
        pdfio_obj_t *obj;
    } value;
};

struct _pdfio_dict_s {
    size_t num_entries;
    struct {
        char *key;
        _pdfio_value_t value;
    } *entries;
};

struct _pdfio_array_s {
    size_t num_values;
    _pdfio_value_t *values;
};

struct _pdfio_obj_s {
    size_t number;
    unsigned short generation;
    off_t offset;
    off_t stream_offset;
    pdfio_file_t *pdf;
    _pdfio_value_t value;
};

struct _pdfio_stream_s {
    pdfio_obj_t *obj;
};

struct _pdfio_file_s {
    pdfio_dict_t *trailer_dict;
    pdfio_obj_t *info_obj;
    pdfio_obj_t *encrypt_obj;
    pdfio_obj_t *root_obj;
    pdfio_array_t *id_array;
};

typedef struct _pdfio_token_s {
    pdfio_file_t *pdf;
    void *data;
    int (*consume)(void *data, char *buffer, size_t bufsize);
    int (*peek)(void *data, char *buffer, size_t bufsize);
    char stack[16];
    size_t stack_count;
} _pdfio_token_t;

typedef bool (*pdfio_password_cb_t)(const char *prompt, char *buffer, size_t bufsize, void *data);
typedef int (*_pdfio_tconsume_cb_t)(void *data, char *buffer, size_t bufsize);
typedef int (*_pdfio_tpeek_cb_t)(void *data, char *buffer, size_t bufsize);

#define PDFIO_DEBUG(fmt, ...)
#define PDFIO_DEBUG_VALUE(v)

extern off_t _pdfioFileSeek(pdfio_file_t *pdf, off_t offset, int whence);
extern void _pdfioFileError(pdfio_file_t *pdf, const char *message, ...);
extern off_t _pdfioFileTell(pdfio_file_t *pdf);
extern bool _pdfioFileGets(pdfio_file_t *pdf, char *buffer, size_t bufsize);
extern int _pdfioFileRead(pdfio_file_t *pdf, char *buffer, size_t bytes);
extern int _pdfioFileConsume(void *data, char *buffer, size_t bufsize);
extern int _pdfioFilePeek(void *data, char *buffer, size_t bufsize);
extern void _pdfioTokenInit(_pdfio_token_t *tb, pdfio_file_t *pdf, _pdfio_tconsume_cb_t consume, _pdfio_tpeek_cb_t peek, void *data);
extern bool _pdfioValueRead(pdfio_file_t *pdf, pdfio_obj_t *obj, _pdfio_token_t *tb, _pdfio_value_t *value, int flags);
extern bool _pdfioTokenGet(_pdfio_token_t *tb, char *buffer, size_t bufsize);
extern void _pdfioTokenFlush(_pdfio_token_t *tb);
extern bool _pdfioCryptoUnlock(pdfio_file_t *pdf, pdfio_password_cb_t password_cb, void *password_data);
extern pdfio_obj_t *add_obj(pdfio_file_t *pdf, size_t number, unsigned short generation, off_t offset);
extern pdfio_dict_t *pdfioObjGetDict(pdfio_obj_t *obj);
extern pdfio_obj_t *pdfioFileFindObj(pdfio_file_t *pdf, size_t number);
extern pdfio_array_t *pdfioDictGetArray(pdfio_dict_t *dict, const char *key);
extern pdfio_obj_t *pdfioDictGetObj(pdfio_dict_t *dict, const char *key);
extern double pdfioDictGetNumber(pdfio_dict_t *dict, const char *key);
extern double pdfioArrayGetNumber(pdfio_array_t *array, size_t n);
extern pdfio_stream_t *pdfioObjOpenStream(pdfio_obj_t *obj, bool raw);
extern size_t pdfioStreamRead(pdfio_stream_t *st, unsigned char *buffer, size_t bytes);
extern void pdfioStreamClose(pdfio_stream_t *st);
extern bool load_obj_stream(pdfio_obj_t *obj);
extern bool load_pages(pdfio_file_t *pdf, pdfio_obj_t *pages_obj, int depth);