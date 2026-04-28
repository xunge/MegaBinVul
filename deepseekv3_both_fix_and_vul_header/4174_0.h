#include <pthread.h>
#include <assert.h>

extern void* config;
extern void* alarm_timer;
extern pthread_mutex_t lock;
extern const char* CONFIG_FILE_PATH;

void alarm_cancel(void* alarm);
void config_save(void* config, const char* path);