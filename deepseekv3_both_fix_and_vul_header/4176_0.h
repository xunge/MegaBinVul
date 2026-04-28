#include <assert.h>
#include <stddef.h>

extern void* alarm_timer;
extern void* config;
#define CONFIG_SETTLE_PERIOD_MS 0

void timer_config_save_cb(void*);
void timer_config_save(void*);
void alarm_set(void*, int, void (*)(void*), void*);