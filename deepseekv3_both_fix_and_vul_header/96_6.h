#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_INIT_FAILED,
    MOBI_MALLOC_FAILED
} MOBI_RET;

typedef struct {
    uint32_t *uid;
    uint32_t *locale;
    uint32_t *dict_input_lang;
    uint32_t *dict_output_lang;
} MOBIMobiHeader;

typedef struct {
    MOBIMobiHeader *mh;
    void *eh;
} MOBIData;

typedef struct {
    char *orth_index_name;
} MOBIOrth;

typedef struct {
    MOBIOrth *orth;
} MOBIRawml;

typedef struct OPFmeta {
    char *id;
    char *value;
} OPFmeta;

typedef struct {
    OPFmeta **identifier;
    char **title;
    char **language;
} OPFdcmeta;

typedef struct {
    char **dictionary_in_lang;
    char **dictionary_out_lang;
    char **default_lookup_index;
} OPFxmeta;

typedef struct {
    OPFmeta **meta;
    OPFdcmeta *dc_meta;
    OPFxmeta *x_meta;
} OPFmetadata;

typedef struct {
    OPFmetadata *metadata;
} OPF;

enum {
    OPF_META_MAX_TAGS,
    OPFidentifier
};

#define FIELD_VALUE 0
#define FIELD_ID 1

static const int value = FIELD_VALUE;
static const int id = FIELD_ID;

void debug_print(const char *format, const char *message);
char *mobi_meta_get_title(const MOBIData *m);
const char *mobi_get_locale_string(uint32_t lang_code);
bool mobi_is_dictionary(const MOBIData *m);
MOBI_RET mobi_get_opf_from_exth(OPFmetadata *metadata, const MOBIData *m);
void mobi_opf_set_tagtype(int type, OPFmeta **identifier, int field_type, const char *value);