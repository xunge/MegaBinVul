#include <stdint.h>
#include <string.h>
#include <assert.h>

struct lyext_plugin;

extern struct {
    const char *name;
    const char *module;
    const char *revision;
    struct lyext_plugin *plugin;
} ext_plugins[];

extern uint16_t ext_plugins_count;