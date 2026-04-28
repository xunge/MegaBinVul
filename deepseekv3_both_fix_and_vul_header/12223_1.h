#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define QUERYMAXLEN 4096
#define MID_BUF 1024
#define CUSTOM_ENC 2048
#define LOG_DEBUG 7

struct MHD_Connection;
typedef struct t_client {
    char *cpi_query;
} t_client;

extern int send_error(struct MHD_Connection *connection, int code);
extern void *safe_calloc(size_t size);
extern char *safe_strdup(const char *s);
extern int safe_asprintf(char **strp, const char *fmt, ...);
extern void debug(int level, const char *format, ...);
extern void uh_urlencode(char *dest, size_t dest_len, const char *src, size_t src_len);
extern void get_query(struct MHD_Connection *connection, char **query, const char *separator);
extern char *construct_querystring(struct MHD_Connection *connection, t_client *client, const char *originurl, char *querystr);
extern int encode_and_redirect_to_splashpage(struct MHD_Connection *connection, t_client *client, const char *originurl, const char *querystr);