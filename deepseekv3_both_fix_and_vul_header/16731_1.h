#include <stdbool.h>
#include <stdint.h>

#define GNRC_RPL_OPT_PAD1 0
#define GNRC_RPL_OPT_DODAG_CONF 1
#define GNRC_RPL_OPT_PREFIX_INFO 2
#define GNRC_RPL_OPT_TARGET 3
#define GNRC_RPL_OPT_TRANSIT 4

#define GNRC_RPL_ICMPV6_CODE_DIO 1
#define GNRC_RPL_ICMPV6_CODE_DAO 2

#define GNRC_RPL_OPT_DODAG_CONF_LEN 16
#define GNRC_RPL_OPT_PREFIX_INFO_LEN 32
#define GNRC_RPL_OPT_TARGET_LEN 16
#define GNRC_RPL_OPT_TRANSIT_INFO_LEN 4

#define GNRC_RPL_MOP_NON_STORING_MODE 0

#define DEBUG(...)

struct gnrc_rpl_opt {
    uint8_t type;
    uint8_t length;
};

struct gnrc_rpl_instance {
    uint8_t mop;
};

struct ipv6_addr {
    uint8_t addr[16];
};

typedef struct gnrc_rpl_instance gnrc_rpl_instance_t;
typedef struct gnrc_rpl_opt gnrc_rpl_opt_t;
typedef struct ipv6_addr ipv6_addr_t;