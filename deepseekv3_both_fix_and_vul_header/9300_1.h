#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

typedef void* wifi_handle;
typedef void (*wifi_cleaned_up_handler)(wifi_handle);

typedef struct cb_info {
    void* cb_arg;
} cb_info;

typedef struct cmd_info {
    void* cmd;
} cmd_info;

typedef struct hal_info {
    wifi_cleaned_up_handler cleaned_up_handler;
    int cleanup_socks[2];
    bool clean_up;
    pthread_mutex_t cb_lock;
    int num_event_cb;
    cb_info *event_cb;
    int num_cmd;
    cmd_info *cmd;
} hal_info;

typedef struct WifiCommand {
    const char* (*getType)(void);
    void (*cancel)(void);
    void (*releaseRef)(void);
} WifiCommand;

hal_info* getHalInfo(wifi_handle handle);
void ALOGE(const char* fmt, ...);
void ALOGD(const char* fmt, ...);
void ALOGI(const char* fmt, ...);
void internal_cleaned_up_handler(wifi_handle handle);