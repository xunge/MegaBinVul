#include <stddef.h>

typedef void SoupSession;
typedef void SoupLogger;
typedef int gboolean;
#define TRUE 1
#define NULL ((void*)0)

typedef enum {
    SOUP_LOGGER_LOG_HEADERS,
    SOUP_LOGGER_LOG_BODY
} SoupLoggerLogLevel;

typedef void (*SoupLoggerPrinter)(SoupLogger *logger, SoupLoggerLogLevel level, char *data, size_t len, void *user_data);

typedef enum {
    GDATA_LOG_NONE,
    GDATA_LOG_MESSAGES,
    GDATA_LOG_HEADERS,
    GDATA_LOG_FULL,
    GDATA_LOG_FULL_UNREDACTED
} GDataLogLevel;

#define SOUP_SESSION_SSL_USE_SYSTEM_CA_FILE 0
#define SOUP_TYPE_GNOME_FEATURES_2_26 0
#define SOUP_SESSION_FEATURE(x) (x)

extern SoupSession* soup_session_sync_new_with_options(int option, gboolean value, void* null);
extern void soup_session_add_feature_by_type(SoupSession* session, int type);
extern void soup_session_add_feature(SoupSession* session, void* feature);
extern SoupLogger* soup_logger_new(SoupLoggerLogLevel level, int max_size);
extern void soup_logger_set_printer(SoupLogger* logger, SoupLoggerPrinter printer, void* null1, void* null2);
extern void soup_log_printer(SoupLogger *logger, SoupLoggerLogLevel level, char *data, size_t len, void *user_data);
extern void g_object_unref(void* object);
extern void g_assert_not_reached(void);
extern GDataLogLevel _gdata_service_get_log_level(void);