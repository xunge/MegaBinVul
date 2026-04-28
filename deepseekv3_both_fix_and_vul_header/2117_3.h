#include <stddef.h>

#define CA_CERTS "/etc/ssl/certs/ca-certificates.crt"
#define SOUP_SESSION_SSL_CA_FILE "ssl-ca-file"
#define SOUP_SESSION_FEATURE(x) ((void*)(x))

typedef enum {
    GDATA_LOG_NONE,
    GDATA_LOG_MESSAGES,
    GDATA_LOG_HEADERS,
    GDATA_LOG_FULL
} GDataLogLevel;

typedef struct _SoupSession SoupSession;
typedef struct _SoupLogger SoupLogger;
typedef enum {
    SOUP_LOGGER_LOG_BODY,
    SOUP_LOGGER_LOG_HEADERS
} SoupLoggerLogLevel;
typedef void (*SoupLoggerPrinter)(SoupLogger *logger, SoupLoggerLogLevel level, char *data, void *user_data);

GDataLogLevel _gdata_service_get_log_level(void);
void soup_log_printer(SoupLogger *logger, SoupLoggerLogLevel level, char *data, void *user_data);
void g_assert_not_reached(void);

SoupSession* soup_session_sync_new_with_options(const char *opt1, const char *opt2, void *opt3);
SoupLogger* soup_logger_new(SoupLoggerLogLevel level, int max_body_size);
void soup_logger_set_printer(SoupLogger *logger, SoupLoggerPrinter printer, void *user_data1, void *user_data2);
void soup_session_add_feature(SoupSession *session, void *feature);
void g_object_unref(void *object);