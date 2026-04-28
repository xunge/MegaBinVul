#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_DEBUG 0
#define STATUS_BUF 256
#define MID_BUF 512
#define SMALL_BUF 128

typedef struct {
    unsigned long incoming;
    unsigned long outgoing;
    time_t last_updated;
} t_counters;

typedef struct {
    char *mac;
    t_counters counters;
    time_t session_start;
    time_t session_end;
    char *token;
    char *hid;
    char *custom;
    char *client_type;
    char *cpi_query;
    char *cid;
} t_client;

void debug(int level, const char *format, ...);
void *safe_calloc(size_t size);
char *safe_strdup(const char *s);
int safe_snprintf(char *str, size_t size, const char *format, ...);
void hash_str(char *dest, size_t dest_size, const char *src);
unsigned short rand16(void);
void write_client_info(char *msg, size_t msg_size, const char *action, const char *cid, const char *info);