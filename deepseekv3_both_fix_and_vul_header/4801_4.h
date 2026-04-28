#include <stdbool.h>

typedef struct module_t module_t;
typedef struct me_t {
    int conf_table;
} me_t;

typedef struct service_t {
    me_t *me;
} service_t;

extern service_t *chansvs;
extern bool anope_flags_compat;
extern void *cs_flags;

void service_named_bind_command(const char *, void *);
void add_bool_conf_item(const char *, int *, int, bool *, bool);
void hook_add_event(const char *);
void hook_add_nick_can_register(void (*)(void));
void hook_add_user_can_register(void (*)(void));
void check_registration_keywords(void);

// 修正指针访问方式
#define chansvs (*(chansvs))