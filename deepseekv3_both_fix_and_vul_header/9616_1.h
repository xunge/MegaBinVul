#include <stdint.h>

#define TIPC_NODE_MODE 0
#define TIPC_NET_MODE 1
#define ENOPROTOOPT 92

typedef uint32_t u32;
typedef void (*Handler)(void);

extern int tipc_mode;
extern u32 tipc_own_addr;
extern u32 tipc_net_id;

void tipc_subscr_stop(void);
void tipc_cfg_stop(void);
void tipc_named_reinit(void);
void tipc_port_reinit(void);
int tipc_bearer_init(void);
int net_init(void);
int tipc_cltr_init(void);
int tipc_bclink_init(void);
void tipc_k_signal(Handler handler, int arg);
void tipc_subscr_start(void);
void tipc_cfg_init(void);
char *addr_string_fill(char *buf, u32 addr);
void info(const char *fmt, ...);