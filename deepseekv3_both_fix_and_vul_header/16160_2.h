#include <string.h>
#include <stdlib.h>

typedef struct packet_info {
    const char *match_string;
} packet_info;

typedef struct http_message_info_t {
    char *media_str;
} http_message_info_t;

typedef struct multipart_info_t {
    const char *type;
    char *boundary;
    unsigned int boundary_length;
    char *protocol;
    int protocol_length;
    char *orig_content_type;
    char *orig_parameters;
} multipart_info_t;

typedef int gint;
typedef unsigned int guint;

char *unfold_and_compact_mime_header(char *str, gint *dummy);
char *ws_find_media_type_parameter(void *scope, char *parameters, const char *param);
void *wmem_packet_scope(void);
void *wmem_new(void *scope, size_t size);
void g_free(void *ptr);

#define wmem_new(scope, type) ((type *)malloc(sizeof(type)))