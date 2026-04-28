#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define DBG(fmt, ...)
#define btd_error(id, fmt, ...)
#define MGMT_OP_SET_DISCOVERABLE (1 << 0)
#define ENOMEM 12
#define EINPROGRESS 115

typedef struct GSList {
    void *data;
    struct GSList *next;
} GSList;

struct btd_adapter {
    uint32_t dev_id;
    uint32_t current_settings;
    GSList *discovery_list;
    struct mgmt_cp_start_service_discovery *current_discovery_filter;
    int discovering;
};

struct mgmt_cp_start_service_discovery {
    bool discoverable;
};

struct discovery_client {
    struct mgmt_cp_start_service_discovery *discovery_filter;
};

int discovery_filter_to_mgmt_cp(struct btd_adapter *adapter, struct mgmt_cp_start_service_discovery **sd_cp);
bool filters_equal(struct mgmt_cp_start_service_discovery *a, struct mgmt_cp_start_service_discovery *b);
void set_discovery_discoverable(struct btd_adapter *adapter, bool discoverable);
void trigger_start_discovery(struct btd_adapter *adapter, int flags);
void g_free(void *ptr);
GSList* g_slist_next(GSList *l);