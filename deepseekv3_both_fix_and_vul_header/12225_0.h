#include <stdlib.h>
#include <string.h>

#define SMALL_BUF 256
#define MID_BUF 512

typedef struct s_client {
    char *cid;
    char *token;
    char *hid;
    char *custom;
    char *client_type;
    char *cpi_query;
} t_client;

extern void *safe_calloc(size_t size);
extern int safe_snprintf(char *str, size_t size, const char *format, ...);
extern void write_client_info(char *msg, size_t buf_size, const char *action, const char *cid, const char *cidinfo);