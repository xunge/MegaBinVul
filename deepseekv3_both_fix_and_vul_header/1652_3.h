#include <stdbool.h>
#include <stddef.h>

#define OGS_OK 0
#define OGS_ERROR 1

typedef struct ogs_sbi_response_s ogs_sbi_response_t;

typedef struct connection_s {
    char *method;
    char *location;
    void *memory;
    size_t size;
    bool memory_overflow;
    char *error;
    void (*client_cb)(int, ogs_sbi_response_t *, void *);
    void *data;
} connection_t;

typedef struct ogs_sbi_response_s {
    struct {
        char *method;
        char *uri;
    } h;
    struct {
        void *headers;
        void *content;
        size_t content_length;
    } http;
    long status;
} ogs_sbi_response_t;

typedef struct ogs_sbi_client_s {
    void *multi;
} ogs_sbi_client_t;

typedef enum ogs_log_level_e {
    OGS_LOG_DEBUG,
    OGS_LOG_ERROR
} ogs_log_level_e;

typedef void CURL;
typedef void CURLM;
typedef struct CURLMsg {
    int msg;
    CURL *easy_handle;
    union {
        int result;
    } data;
} CURLMsg;
typedef int CURLcode;

#define CURLE_OK 0
#define CURLMSG_DONE 1
#define CURLINFO_PRIVATE 0
#define CURLINFO_EFFECTIVE_URL 0
#define CURLINFO_RESPONSE_CODE 0
#define CURLINFO_CONTENT_TYPE 0

#define OGS_SBI_CONTENT_TYPE "Content-Type"
#define OGS_SBI_LOCATION "Location"

void ogs_assert(int cond);
void ogs_warn(const char *fmt, ...);
void ogs_error(const char *fmt, ...);
void ogs_debug(const char *fmt, ...);
void ogs_log_message(ogs_log_level_e level, int dummy, const char *fmt, ...);
char *ogs_strdup(const char *str);
void *ogs_memdup(const void *src, size_t size);
ogs_sbi_response_t *ogs_sbi_response_new();
void ogs_sbi_response_free(ogs_sbi_response_t *response);
void ogs_sbi_header_set(void *headers, const char *key, const char *value);
void connection_remove(connection_t *conn);