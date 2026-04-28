#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pdfio_dict_s pdfio_dict_t;
typedef struct _pdfio_file_s pdfio_file_t;
typedef struct _pdfio_obj_s pdfio_obj_t;
typedef struct _pdfio_token_s _pdfio_token_t;

struct _pdfio_value_s {
    // Add necessary fields for value structure
    int type;
    void *value;
};
typedef struct _pdfio_value_s _pdfio_value_t;

#define PDFIO_DEBUG(fmt, ...)

pdfio_dict_t *pdfioDictCreate(pdfio_file_t *pdf);
int _pdfioTokenGet(_pdfio_token_t *tb, char *key, size_t keysize);
void _pdfioFileError(pdfio_file_t *pdf, const char *message, ...);
int _pdfioDictGetValue(pdfio_dict_t *dict, const char *key);
int _pdfioValueRead(pdfio_file_t *pdf, pdfio_obj_t *obj, _pdfio_token_t *tb, _pdfio_value_t *value, size_t depth);
int _pdfioDictSetValue(pdfio_dict_t *dict, void *string, _pdfio_value_t *value);
void *pdfioStringCreate(pdfio_file_t *pdf, const char *str);