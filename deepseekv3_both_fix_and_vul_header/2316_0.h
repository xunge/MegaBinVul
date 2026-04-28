#include <stddef.h>

#define EPERM 1
#define ENOMEM 2
#define EINVAL 3

#define USER_CLIENT 0
#define KERNEL_CLIENT 1

#define SNDRV_SEQ_PORT_FLG_GIVEN_PORT (1<<0)

struct snd_seq_addr {
    int client;
    int port;
};

struct snd_seq_port_callback {
    void *owner;
    void *private_data;
    void (*private_free)(void *);
    int (*event_input)(struct snd_seq_event *ev, int direct, void *private_data, int atomic, int hop);
    int (*subscribe)(void *private_data, struct snd_seq_port_subscribe *info);
    int (*unsubscribe)(void *private_data, struct snd_seq_port_subscribe *info);
    int (*use)(void *private_data, struct snd_seq_port_subscribe *info);
    int (*unuse)(void *private_data, struct snd_seq_port_subscribe *info);
};

struct snd_seq_port_info {
    struct snd_seq_addr addr;
    unsigned int flags;
    void *kernel;
};

struct snd_seq_client_port {
    struct snd_seq_addr addr;
    void *owner;
    void *private_data;
    void (*private_free)(void *);
    int (*event_input)(struct snd_seq_event *ev, int direct, void *private_data, int atomic, int hop);
    struct {
        int (*open)(void *private_data, struct snd_seq_port_subscribe *info);
        int (*close)(void *private_data, struct snd_seq_port_subscribe *info);
    } c_src, c_dest;
};

struct snd_seq_client {
    int number;
    int type;
};

struct snd_seq_event;
struct snd_seq_port_subscribe;

static struct snd_seq_client_port *snd_seq_create_port(struct snd_seq_client *client, int port);
static void snd_seq_delete_port(struct snd_seq_client *client, int port);
static void snd_seq_set_port_info(struct snd_seq_client_port *port, struct snd_seq_port_info *info);
static void snd_seq_system_client_ev_port_start(int client, int port);