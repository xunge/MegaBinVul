#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    RTSP_REPLY,
    RTSP_REQUEST,
    RTSP_NOT_FIRST_LINE
} rtsp_type_t;

#define RTSP_NMETHODS 10
static const char *rtsp_methods[RTSP_NMETHODS] = {
    "DESCRIBE", "ANNOUNCE", "GET_PARAMETER", "OPTIONS", "PAUSE",
    "PLAY", "RECORD", "REDIRECT", "SETUP", "TEARDOWN"
};

typedef struct {
    uint32_t response_code;
    char *request_method;
} rtsp_stat_info_t;

#define TRUE 1
#define FALSE 0
typedef int gboolean;
typedef unsigned char guchar;
typedef uint32_t guint;
typedef char gchar;

extern rtsp_stat_info_t *rtsp_stat_info;
extern int get_token_len(const unsigned char *start, const unsigned char *end, const unsigned char **next_token);
extern char *wmem_strndup(void *scope, const char *str, size_t len);
extern void *wmem_packet_scope(void);

static int g_ascii_strncasecmp(const char *s1, const char *s2, size_t n) {
    while (n--) {
        int c1 = tolower(*s1++);
        int c2 = tolower(*s2++);
        if (c1 != c2) return c1 - c2;
        if (c1 == '\0') break;
    }
    return 0;
}