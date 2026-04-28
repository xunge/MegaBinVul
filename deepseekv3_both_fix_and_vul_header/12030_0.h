#include <stdbool.h>
#include <stdint.h>

struct hmap;
struct shash;
struct ds;

struct ovn_datapath {
    struct {
        struct {
            bool enabled;
            bool flood_unregistered;
            bool flood_relay;
            bool flood_static;
        } sw;
    } mcast_info;
    struct {
        struct {
            void *copp;
        } *nbs;
    };
};

struct mcast_switch_info {
    bool enabled;
    bool flood_unregistered;
    bool flood_relay;
    bool flood_static;
};

enum {
    S_SWITCH_IN_L2_LKUP,
    COPP_SVC_MONITOR,
    COPP_IGMP
};

#define MC_FLOOD_L2 "MC_FLOOD_L2"
#define MC_FLOOD "MC_FLOOD"
#define MC_MROUTER_FLOOD "MC_MROUTER_FLOOD"
#define MC_STATIC "MC_STATIC"

void ovn_lflow_metered(struct hmap *lflows, struct ovn_datapath *od, int stage, int priority, const char *match, const char *actions, void *meter);
void ovn_lflow_add(struct hmap *lflows, struct ovn_datapath *od, int stage, int priority, const char *match, const char *actions);
void *copp_meter_get(int copp_type, void *copp, const struct shash *meter_groups);
const char *debug_drop_action(void);
void ds_clear(struct ds *ds);
void ds_put_cstr(struct ds *ds, const char *s);
const char *ds_cstr(const struct ds *ds);