#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

typedef struct future_t future_t;
typedef struct config_t config_t;
typedef struct alarm_t alarm_t;

static pthread_mutex_t lock;
static config_t *config = NULL;
static alarm_t *alarm_timer = NULL;

#define CONFIG_FILE_PATH NULL
#define LEGACY_CONFIG_FILE_PATH NULL

#define FUTURE_SUCCESS 0
#define FUTURE_FAIL 1

future_t *future_new_immediate(int value);
config_t *config_new(const char *filename);
config_t *btif_config_transcode(const char *filename);
config_t *config_new_empty(void);
int config_save(config_t *config, const char *filename);
void btif_config_remove_unpaired(config_t *config);
alarm_t *alarm_new(void);
void alarm_free(alarm_t *alarm);
void config_free(config_t *config);

#define LOG_WARN(...)
#define LOG_ERROR(...)