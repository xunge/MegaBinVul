#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MOBI_CP1252 1252
#define MOBI_UTF8 65001
#define MOBI_NOTSET 0
#define EXTH_CREATORSOFT 1
#define EXTH_CREATORMAJOR 2
#define EXTH_CREATORMINOR 3
#define EXTH_CREATORBUILD 4
#define EXTH_CREATORBUILDREV 5

typedef struct MOBIPdbHeader {
    char type[5];
    char creator[5];
} MOBIPdbHeader;

typedef struct MOBIMobiHeader {
    uint32_t *text_encoding;
    uint32_t *dict_input_lang;
    uint32_t *dict_output_lang;
} MOBIMobiHeader;

typedef struct MOBIExthHeader {
    unsigned char *data;
    uint32_t size;
} MOBIExthHeader;

typedef struct MOBIData {
    MOBIPdbHeader *ph;
    MOBIMobiHeader *mh;
    struct MOBIData *next;
} MOBIData;

char *mobi_meta_get_title(const MOBIData *m);
char *mobi_meta_get_author(const MOBIData *m);
char *mobi_meta_get_contributor(const MOBIData *m);
char *mobi_meta_get_subject(const MOBIData *m);
char *mobi_meta_get_publisher(const MOBIData *m);
char *mobi_meta_get_publishdate(const MOBIData *m);
char *mobi_meta_get_description(const MOBIData *m);
char *mobi_meta_get_review(const MOBIData *m);
char *mobi_meta_get_imprint(const MOBIData *m);
char *mobi_meta_get_copyright(const MOBIData *m);
char *mobi_meta_get_isbn(const MOBIData *m);
char *mobi_meta_get_asin(const MOBIData *m);
char *mobi_meta_get_language(const MOBIData *m);
bool mobi_is_dictionary(const MOBIData *m);
const char *mobi_get_locale_string(uint32_t lang);
size_t mobi_get_fileversion(const MOBIData *m);
bool mobi_is_hybrid(const MOBIData *m);
bool mobi_is_replica(const MOBIData *m);
bool mobi_is_encrypted(const MOBIData *m);
MOBIExthHeader *mobi_get_exthrecord_by_tag(const MOBIData *m, uint32_t tag);
uint32_t mobi_decode_exthvalue(const unsigned char *data, uint32_t size);
char *mobi_decode_exthstring(const MOBIData *m, const unsigned char *data, uint32_t size);