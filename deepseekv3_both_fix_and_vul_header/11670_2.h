#include <stdlib.h>

typedef int CURLcode;
#define CURLE_OK 0
#define FALSE 0
#define CURL_LOCK_DATA_SHARE 0
#define CURL_LOCK_ACCESS_SINGLE 0

struct Curl_easy;
struct Curl_multi;
struct Curl_share;

struct Curl_llist {
    void *head;
    void *tail;
};

struct wildcard {
    void *pattern;
};

struct Curl_easy {
    struct Curl_multi *multi;
    struct Curl_multi *multi_easy;
    unsigned int magic;
    struct {
        struct Curl_llist timeoutlist;
        char *range;
        int rangestringalloc;
        char *first_host;
        char *scratch;
        char *buffer;
        char *headerbuff;
        char *ulbuf;
        void *resolver;
    } state;
    struct {
        char *newurl;
    } req;
    struct {
        char *referer;
        int referer_alloc;
    } change;
    struct {
        char *contenttype;
        char *wouldredirect;
    } info;
    struct Curl_share *share;
    struct wildcard wildcard;
};

struct Curl_multi {
    // multi handle structure members
};

struct Curl_share {
    int dirty;
};

void Curl_expire_clear(struct Curl_easy *data);
void Curl_llist_destroy(struct Curl_llist *list, void *user);
void Curl_free_request_state(struct Curl_easy *data);
void Curl_ssl_close_all(struct Curl_easy *data);
void Curl_safefree(void *ptr);
void Curl_ssl_free_certinfo(struct Curl_easy *data);
void Curl_up_free(struct Curl_easy *data);
void Curl_flush_cookies(struct Curl_easy *data, int flag);
void Curl_digest_cleanup(struct Curl_easy *data);
void Curl_resolver_cleanup(void *resolver);
void Curl_http2_cleanup_dependencies(struct Curl_easy *data);
void Curl_convert_close(struct Curl_easy *data);
void Curl_share_lock(struct Curl_easy *data, int type, int access);
void Curl_share_unlock(struct Curl_easy *data, int type);
void Curl_wildcard_dtor(struct wildcard *wc);
void Curl_freeset(struct Curl_easy *data);
CURLcode curl_multi_remove_handle(struct Curl_multi *multi, struct Curl_easy *data);
CURLcode curl_multi_cleanup(struct Curl_multi *multi);