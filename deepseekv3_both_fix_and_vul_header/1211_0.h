#include <stdint.h>
#include <string.h>

#define UIP_ND6_OPT_TYPE_OFFSET 0
#define UIP_ND6_OPT_LEN_OFFSET 1
#define UIP_ND6_OPT_DATA_OFFSET 2
#define UIP_ND6_OPT_LLAO_LEN 8
#define UIP_LLADDR_LEN 6

extern uint8_t uip_lladdr[UIP_LLADDR_LEN];