#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int gboolean;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef uint32_t guint32;
typedef char gchar;
typedef size_t gsize;

#define FALSE 0
#define TRUE 1

#define WTAP_ERR_BAD_FILE 0
#define WTAP_ENCAP_SOCKETCAN 0
#define WTAP_ENCAP_FLEXRAY 1
#define WTAP_ENCAP_LIN 2
#define WTAP_ENCAP_ETHERNET 3
#define WTAP_ENCAP_IEEE_802_11 4

#define BLF_APPTEXT_CHANNEL 0
#define BLF_BUSTYPE_CAN 0
#define BLF_BUSTYPE_FLEXRAY 1
#define BLF_BUSTYPE_LIN 2
#define BLF_BUSTYPE_ETHERNET 3
#define BLF_BUSTYPE_WLAN 4

typedef struct blf_params_t blf_params_t;
typedef struct blf_apptext_t {
    guint32 source;
    guint32 textLength;
    guint32 reservedAppText1;
} blf_apptext_t;

static inline void* g_try_malloc0(size_t size) { return calloc(1, size); }
static inline void g_free(void* ptr) { free(ptr); }
static inline char** g_strsplit_set(const char* str, const char* delimiters, int max_tokens) {
    char* copy = strdup(str);
    char** tokens = malloc(sizeof(char*) * (max_tokens + 1));
    char* token = strtok(copy, delimiters);
    int i = 0;
    while (token != NULL && i < max_tokens) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    tokens[i] = NULL;
    free(copy);
    return tokens;
}
static inline void g_strfreev(char** str_array) {
    if (str_array) {
        for (char** p = str_array; *p; p++) {
            free(*p);
        }
        free(str_array);
    }
}

char* ws_strdup_printf(const char *format, ...);
void ws_debug(const char *format, ...);
gboolean blf_read_bytes(blf_params_t *params, gint64 offset, void *buf, size_t count, int *err, gchar **err_info);
void fix_endianness_blf_apptext_header(blf_apptext_t *apptextheader);
void blf_lookup_interface(blf_params_t *params, int pkt_encap, guint32 channel, const gchar *name);

#define _U_ __attribute__((unused))