#include <string.h>
#include <ctype.h>

typedef unsigned char guint8;

#define ISUP_ITU_STANDARD_VARIANT 0
#define ISUP_FRENCH_VARIANT 1 
#define ISUP_ISRAELI_VARIANT 2
#define ANSI_STANDARD 0
#define ITU_STANDARD 1
#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0

typedef struct {
    char *media_str;
} http_message_info_t;

typedef struct {
    int cinfo;
} packet_info;

typedef struct {} tvbuff_t;
typedef struct {} proto_tree;
typedef struct {} proto_item;

extern int proto_isup;
extern int ett_isup;
extern const void *ansi_isup_message_type_value_acro_ext;
extern const void *isup_message_type_value_acro_ext;
extern const void *french_isup_message_type_value_acro_ext;
extern const void *israeli_isup_message_type_value_acro_ext;
extern int isup_standard;

static int g_ascii_strncasecmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && *s2) {
        int c1 = tolower(*s1++);
        int c2 = tolower(*s2++);
        if (c1 != c2) return c1 - c2;
    }
    return 0;
}

static int g_ascii_strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int c1 = tolower(*s1++);
        int c2 = tolower(*s2++);
        if (c1 != c2) return c1 - c2;
    }
    return *s1 - *s2;
}

static void g_free(void *ptr) {
    free(ptr);
}

static char* ws_find_media_type_parameter(const char *media_str, const char *param) {
    return NULL;
}

static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) {
    return 0;
}

static tvbuff_t* tvb_new_subset_remaining(tvbuff_t *tvb, int offset) {
    return NULL;
}

static int tvb_reported_length(tvbuff_t *tvb) {
    return 0;
}

static void col_append_str(packet_info *pinfo, int col, const char *str) {}

static void col_append_sep_fstr(packet_info *pinfo, int col, const char *sep, const char *fmt, ...) {}

static const char* val_to_str_ext_const(int val, const void *vs, const char *default_str) {
    return default_str;
}

static proto_item* proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, int encoding) {
    return NULL;
}

static proto_tree* proto_item_add_subtree(proto_item *ti, int ett) {
    return NULL;
}

static void dissect_ansi_isup_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int variant, int cic) {}

static void dissect_isup_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int variant, int cic) {}