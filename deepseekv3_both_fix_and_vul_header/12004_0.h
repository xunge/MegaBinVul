#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t u8[16];
} uip_ipaddr_t;

typedef struct {
    uint8_t addr[8];
} uip_lladdr_t;

extern uint8_t *iphc_ptr;
extern uint8_t *packetbuf_ptr;
extern uint8_t packetbuf_datalen(void);
extern void uip_ds6_set_addr_iid(uip_ipaddr_t *ipaddr, uip_lladdr_t *lladdr);
extern void LOG_DBG(const char *fmt, ...);
extern void LOG_WARN(const char *fmt, ...);
extern void LOG_DBG_6ADDR(uip_ipaddr_t *ipaddr);
extern void LOG_DBG_(const char *fmt, ...);