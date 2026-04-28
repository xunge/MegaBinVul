#include <pthread.h>
#include <unistd.h>

typedef struct config_t config_t;
typedef struct alarm_t alarm_t;
typedef struct future_t future_t;

typedef enum {
    FUTURE_SUCCESS,
    FUTURE_FAIL
} future_status_t;

static pthread_mutex_t lock;
static config_t *config = NULL;
static alarm_t *alarm_timer = NULL;

#define CONFIG_FILE_PATH "/etc/config"
#define LEGACY_CONFIG_FILE_PATH "/etc/legacy_config"
#define LOG_TAG "BT"
#define LOG_WARN(tag, fmt, ...)
#define LOG_ERROR(tag, fmt, ...)