#define MAX_BUSID 256
#define STUB_BUSID_OTHER 2

struct bus_id_priv {
    char name[32];
    int shutdown_busid;
    int status;
};

extern struct bus_id_priv busid_table[MAX_BUSID];
extern int busid_table_lock;
extern void do_rebind(char *name, struct bus_id_priv *busid_priv);

#define spin_lock(lock) (void)(*(lock) = 1)
#define spin_unlock(lock) (void)(*(lock) = 0)
#define IS_MODULE(x) 1
#define CONFIG_USBIP_HOST 1