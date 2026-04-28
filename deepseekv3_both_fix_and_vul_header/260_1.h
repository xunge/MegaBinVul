#include <stdint.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct buffer {
    char *buffer;
    size_t size;
    size_t len;
} BUFFER;

typedef struct rrdhost RRDHOST;
typedef struct rrdset {
    time_t last_accessed_time;
    struct timeval last_updated;
} RRDSET;

typedef struct web_client {
    unsigned long long id;
    struct {
        BUFFER *data;
        BUFFER *header;
    } response;
} web_client;

#define D_WEB_CLIENT 0
#define D_WEB_CLIENT_ACCESS 0

#define RRDR_GROUPING_AVERAGE 0
#define DATASOURCE_JSON 0
#define DATASOURCE_DATATABLE_JSONP 1
#define DATASOURCE_JSONP 2

BUFFER *buffer_create(size_t size);
void buffer_flush(BUFFER *buf);
void buffer_strcat(BUFFER *buf, const char *str);
void buffer_strcat_htmlescape(BUFFER *buf, const char *str);
void buffer_sprintf(BUFFER *buf, const char *fmt, ...);
char *buffer_tostring(BUFFER *buf);
void buffer_free(BUFFER *buf);

char *mystrsep(char **string, const char *delim);
long str2l(const char *s);
int str2i(const char *s);

time_t now_realtime_sec(void);

int web_client_api_request_v1_data_group(const char *name, int def);
uint32_t web_client_api_request_v1_data_format(const char *name);
uint32_t web_client_api_request_v1_data_options(const char *name);
uint32_t web_client_api_request_v1_data_google_format(const char *name);
int rrdset2anything_api_v1(RRDSET *st, BUFFER *buf, BUFFER *dimensions, uint32_t format, int points, long long after, long long before, int group, long group_time, uint32_t options, time_t *last_timestamp);

RRDSET *rrdset_find(RRDHOST *host, const char *id);
RRDSET *rrdset_find_byname(RRDHOST *host, const char *name);

void debug(int type, const char *fmt, ...);