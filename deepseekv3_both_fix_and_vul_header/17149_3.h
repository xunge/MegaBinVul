#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define ENC_ASCII 0
#define ENC_NA 0
#define DECRYPT_GSSAPI_NORMAL 0

typedef int gint;
typedef unsigned char guint8;
typedef int gboolean;
typedef char gchar;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    const char *match_string;
} packet_info;
typedef struct proto_item proto_item;

typedef struct {
    gint type;
    gchar *media_str;
} http_message_info_t;

typedef struct {
    const gchar *boundary;
    gint boundary_length;
    gchar *protocol;
    gchar *orig_content_type;
    gchar *orig_parameters;
} multipart_info_t;

typedef struct {
    tvbuff_t *gssapi_decrypted_tvb;
    tvbuff_t *gssapi_encrypted_tvb;
    gint decrypt_gssapi_tvb;
} gssapi_encrypt_info_t;

enum {
    POS_ORIGINALCONTENT,
    POS_CONTENT_TYPE,
    POS_CONTENT_TRANSFER_ENCODING,
    POS_CONTENT_DISPOSITION
};

extern gboolean remove_base64_encoding;
extern void *media_handle;
extern void *media_type_dissector_table;
extern void *multipart_media_subdissector_table;
extern int hf_multipart_part;
extern int hf_multipart_boundary;
extern int hf_multipart_last_boundary;
extern int *hf_header_array;
extern int ett_multipart_body;
extern void *ei_multipart_decryption_not_possible;

char *g_strdup(const char *str);
void g_free(void *ptr);
int g_ascii_strncasecmp(const char *s1, const char *s2, int n);