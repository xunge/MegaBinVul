#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _subscription subscription;
typedef subscription *subscriptionPtr;
typedef struct _UpdateRequest UpdateRequest;
typedef struct _node node;

enum {
    DEBUG_UPDATE
};

typedef unsigned int guint;
typedef uint64_t guint64;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

struct subscriptionType {
    gboolean (*prepare_update_request)(subscriptionPtr, UpdateRequest*);
};

#define SUBSCRIPTION_TYPE(sub) ((struct subscriptionType*)sub->type)

void debug1(int level, const char *format, ...);
gboolean subscription_can_be_updated(subscriptionPtr subscription);
void subscription_reset_update_counter(subscriptionPtr subscription, guint64 *now);
char *subscription_get_source(subscriptionPtr subscription);
char *subscription_get_filter(subscriptionPtr subscription);
UpdateRequest *update_request_new(char *source, void *updateState, void *updateOptions);
void update_request_allow_commands(UpdateRequest *request, gboolean allow);
void *update_execute_request(subscriptionPtr subscription, UpdateRequest *request, 
                            void (*callback)(subscriptionPtr, void*), 
                            subscriptionPtr sub, guint flags);
void update_jobs_get_count(guint *count, guint *maxcount);
void liferea_shell_set_status_bar(const char *format, ...);
char *node_get_title(node *n);
const char *_(const char *str);
void g_object_unref(void *object);
char *g_strdup(const char *str);
guint64 g_get_real_time(void);

void subscription_process_update_result(subscriptionPtr subscription, void *result);

struct _subscription {
    void *updateJob;
    node *node;
    void *updateState;
    void *updateOptions;
    struct subscriptionType *type;
};

struct _UpdateRequest {
    char *filtercmd;
};