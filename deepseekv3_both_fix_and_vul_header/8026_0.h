#include <stdbool.h>
#include <stdint.h>

#define LOG_TAG ""
#define LOG_INFO(tag, fmt, ...)

static bool restricted_mode;
static bool interface_ready(void);
static int BT_STATUS_NOT_READY;
static int BT_STATUS_SUCCESS;

typedef struct {
    void (*start_up_stack_async)(void);
} stack_manager_t;

static stack_manager_t* stack_manager_get_interface(void);