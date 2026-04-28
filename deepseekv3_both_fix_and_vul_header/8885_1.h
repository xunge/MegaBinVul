#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    time_t realtime;
    time_t monotonic;
} dual_timestamp;

typedef struct {
    char *stamp_path;
    dual_timestamp last_trigger;
} Timer;

typedef struct {
    void *manager;
} Unit;

typedef struct {
    char *name;
    char *message;
} sd_bus_error;

#define SD_BUS_ERROR_NULL {0}
#define UID_INVALID ((uid_t) -1)
#define GID_INVALID ((gid_t) -1)
#define MODE_INVALID ((mode_t) -1)
#define _cleanup_bus_error_free_

enum {
    JOB_START,
    JOB_REPLACE
};

enum {
    TIMER_RUNNING,
    TIMER_FAILURE_RESOURCES
};

bool unit_stop_pending(Unit *u);
int manager_add_job(void *manager, int job_type, void *trigger, int job_replace, bool flag, sd_bus_error *error, void *null);
void dual_timestamp_get(dual_timestamp *ts);
void touch_file(const char *path, bool create, time_t mtime, uid_t uid, gid_t gid, mode_t mode);
void timer_set_state(Timer *t, int state);
void log_unit_warning(Unit *u, const char *format, ...);
void timer_enter_dead(Timer *t, int reason);
const char *bus_error_message(const sd_bus_error *e, int r);

#define UNIT(t) ((Unit*) (t))
#define UNIT_TRIGGER(u) (NULL)