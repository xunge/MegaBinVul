#include <stddef.h>
#include <stdint.h>

typedef struct {
    void *res;
    int accept_ssl_errors;
} CheckData;

typedef struct {
    unsigned int status_code;
} SoupMessage;

typedef enum {
    SOUP_STATUS_OK = 200,
    SOUP_STATUS_CANCELLED = -1
} SoupStatusCode;

typedef enum {
    GOA_ERROR_FAILED = 1
} GoaErrorCode;

#define GOA_ERROR 0
#define FALSE 0
#define TRUE 1

typedef unsigned int GTlsCertificateFlags;
typedef int gboolean;
typedef void* gpointer;
typedef void* SoupSession;
typedef void* GError;

int soup_message_get_https_status(SoupMessage *msg, void *unused, GTlsCertificateFlags *flags);
void goa_utils_set_error_ssl(GError **error, GTlsCertificateFlags flags);
void http_client_check_data_free(gpointer data);
void g_simple_async_result_set_op_res_gboolean(void *res, gboolean op_res);
void g_simple_async_result_take_error(void *res, GError *error);
void g_simple_async_result_complete_in_idle(void *res);
int g_idle_add(void (*func)(gpointer), gpointer data);
void g_set_error(GError **err, int domain, int code, const char *format, ...);
const char *_(const char *str);