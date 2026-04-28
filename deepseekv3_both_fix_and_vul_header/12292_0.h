#include <stdint.h>
#include <stdlib.h>

typedef struct URLContext URLContext;
typedef struct HTTPContext HTTPContext;

struct HTTPContext {
    int icy_metaint;
    int icy_data_read;
    // other members...
};

struct URLContext {
    HTTPContext *priv_data;
    // other members...
};

int http_read_stream_all(URLContext *h, void *buf, int size);
int av_opt_set(void *obj, const char *name, const char *val, int search_flags);
void update_metadata(HTTPContext *s, const char *data);

#define AVERROR_INVALIDDATA (-1)
#define FFMIN(a, b) ((a) < (b) ? (a) : (b))