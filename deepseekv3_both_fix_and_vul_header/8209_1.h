#include <stdlib.h>
#include <string.h>
#include <unicode/uloc.h>
#include <unicode/ustring.h>
#include <unicode/utypes.h>
#include <unicode/uchar.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_C
#define TSRMLS_DC
#define ZEND_NUM_ARGS() ht
#define FAILURE (-1)
#define ULOC_FULLNAME_CAPACITY 157
#define DISP_NAME "name"
#define LOC_LANG_TAG "language"
#define LOC_SCRIPT_TAG "script"
#define LOC_REGION_TAG "region"
#define LOC_VARIANT_TAG "variant"
#define LOC_GRANDFATHERED "grandfathered"
#define RETURN_FALSE return
#define RETVAL_FALSE
#define RETVAL_STRINGL(str, len, dup)
#define FALSE 0

typedef unsigned short UChar;
typedef struct _zval_struct {
    char *value;
    int length;
    int type;
} zval;

extern void intl_error_reset(void *);
extern void intl_error_set(void *, int, const char *, int);
extern const char *intl_locale_get_default(void);
extern int findOffset(const char *, const char *);
extern char *getPreferredTag(const char *);
extern void intl_convert_utf16_to_utf8(char **, int *, const UChar *, int32_t, UErrorCode *);
extern char *estrndup(const char *, size_t);
extern char *estrdup(const char *);
extern void *erealloc(void *, size_t);
extern void efree(void *);
extern int spprintf(char **, size_t, const char *, ...);
extern int zend_parse_parameters(int, const char *, ...);