#include <string.h>
#include <sys/types.h>

#define BUSID_SIZE 32
#define STUB_BUSID_OTHER 0
#define EINVAL 22
#define ENODEV 19

struct device_driver;
struct bus_id_priv {
    int status;
};

extern struct bus_id_priv *get_busid_priv(const char *);
extern int do_rebind(char *, struct bus_id_priv *);
extern void del_match_busid(char *);