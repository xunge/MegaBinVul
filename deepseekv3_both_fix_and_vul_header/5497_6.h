#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef uint64_t guint64;
typedef char gchar;
typedef bool gboolean;

struct header_field_info {
    int display;
    void *strings;
};

struct fvalue {
    guint64 value;
};

typedef struct {
    struct header_field_info *hfinfo;
    struct fvalue value;
} field_info;

typedef void (*custom_fmt_func_64_t)(gchar *, guint64);

#define ITEM_LABEL_LENGTH 256
#define BASE_CUSTOM 0
#define BASE_NONE 0
#define FIELD_DISPLAY_E_MASK 0
#define IS_BASE_DUAL(x) 0

const char *hf_try_val64_to_str_const(guint64 value, const struct header_field_info *hfinfo, const char *default_str);
const char *hfinfo_number_vals_format64(const struct header_field_info *hfinfo, char *buf, guint64 value);
const char *hfinfo_number_value_format64(const struct header_field_info *hfinfo, char *buf, guint64 value);
const char *hfinfo_int64_format(const struct header_field_info *hfinfo);
const char *hfinfo_uint64_format(const struct header_field_info *hfinfo);
void label_fill(gchar *label_str, int col, const struct header_field_info *hfinfo, const char *value);
void label_fill_descr(gchar *label_str, int col, const struct header_field_info *hfinfo, const char *value, const char *descr);
guint64 fvalue_get_sinteger64(const struct fvalue *fv);
guint64 fvalue_get_uinteger64(const struct fvalue *fv);
#define DISSECTOR_ASSERT(x)
int g_snprintf(char *str, size_t size, const char *format, ...);

typedef struct header_field_info header_field_info;