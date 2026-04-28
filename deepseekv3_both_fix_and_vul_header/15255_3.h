#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    char* pv;
    size_t cur;
    bool utf8;
} SV;

typedef struct {
    // dummy HV structure
} HV;

#define EXTERN extern
#define pTHX_
#define aTHX_
#define STRLEN size_t
#define SvPV_force(sv, len) ((sv)->pv)
#define SvPVX(sv) ((sv)->pv)
#define SvCUR_set(sv, len) ((sv)->cur = (len))
#define SvUTF8(sv) ((sv)->utf8)
#define SvUTF8_on(sv) ((sv)->utf8 = true)
#define SvPV(sv, len) ((len) = strlen((sv)->pv), (sv)->pv)
#define hv_fetch(hv, key, klen, lval) NULL
#define PL_hexdigit "0123456789abcdefABCDEF"
#define isDIGIT(c) isdigit(c)
#define isALNUM(c) isalnum(c)
#define UV uint32_t
#define U8 uint8_t
#define UTF8_MAXLEN 6
#define UNICODE_HTML_PARSER

static inline char* uvuni_to_utf8(U8* buf, UV num) {
    if (num <= 0x7F) {
        buf[0] = num;
        return (char*)buf + 1;
    }
    return (char*)buf;
}

static inline U8* bytes_to_utf8(U8* p, STRLEN* len) {
    return p;
}

#define sv_setpvn(sv, p, len) do { \
    free((sv)->pv); \
    (sv)->pv = strndup(p, len); \
    (sv)->cur = len; \
} while(0)

#define sv_catpvn(sv, p, len) do { \
    char* new_pv = malloc((sv)->cur + len + 1); \
    memcpy(new_pv, (sv)->pv, (sv)->cur); \
    memcpy(new_pv + (sv)->cur, p, len); \
    new_pv[(sv)->cur + len] = '\0'; \
    free((sv)->pv); \
    (sv)->pv = new_pv; \
    (sv)->cur += len; \
} while(0)

#define Safefree(p) free(p)

static inline void grow_gap(pTHX_ SV* sv, STRLEN len, char** t, char** s, char** end) {
    size_t new_size = (*end - SvPVX(sv)) + len + 1;
    char* new_pv = realloc(SvPVX(sv), new_size);
    *t = new_pv + (*t - SvPVX(sv));
    *s = new_pv + (*s - SvPVX(sv));
    *end = new_pv + new_size - 1;
    sv->pv = new_pv;
}