#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t type;
    uint8_t flags;
    uint8_t aggr;
    uint8_t prec;
    uint8_t length;
    union {
        uint16_t etx;
        struct {
            uint8_t flags;
            uint8_t energy_est;
        } energy;
    } obj;
} rpl_metric_container_t;

typedef struct {
    uint8_t length;
    uint8_t flags;
    uint32_t lifetime;
    uint8_t prefix[16];
} rpl_prefix_info_t;

typedef struct {
    uint8_t instance_id;
    uint8_t version;
    uint16_t rank;
    uint8_t grounded;
    uint8_t mop;
    uint8_t preference;
    uint8_t dtsn;
    uint8_t dag_id[16];
    uint8_t dag_intdoubl;
    uint8_t dag_intmin;
    uint8_t dag_redund;
    uint16_t dag_min_hoprankinc;
    uint16_t dag_max_rankinc;
    uint16_t ocp;
    uint8_t default_lifetime;
    uint16_t lifetime_unit;
    rpl_metric_container_t mc;
    rpl_prefix_info_t destination_prefix;
    rpl_prefix_info_t prefix_info;
} rpl_dio_t;

typedef uint8_t uip_ipaddr_t[16];

typedef struct {
    uip_ipaddr_t srcipaddr;
} uip_ip_buf_t;

extern uip_ip_buf_t* UIP_IP_BUF;
extern unsigned char* UIP_ICMP_PAYLOAD;
extern uint16_t uip_len;
extern uint16_t uip_l3_icmp_hdr_len;

#define RPL_DIO_INTERVAL_DOUBLINGS 0
#define RPL_DIO_INTERVAL_MIN 0
#define RPL_DIO_REDUNDANCY 0
#define RPL_MIN_HOPRANKINC 0
#define RPL_MAX_RANKINC 0
#define RPL_OF_OCP 0
#define RPL_DEFAULT_LIFETIME 0
#define RPL_DEFAULT_LIFETIME_UNIT 0
#define RPL_DIO_GROUNDED 0
#define RPL_DIO_MOP_MASK 0
#define RPL_DIO_MOP_SHIFT 0
#define RPL_DIO_PREFERENCE_MASK 0
#define RPL_OPTION_PAD1 0
#define RPL_OPTION_DAG_METRIC_CONTAINER 1
#define RPL_OPTION_ROUTE_INFO 2
#define RPL_OPTION_DAG_CONF 3
#define RPL_OPTION_PREFIX_INFO 4
#define RPL_DAG_MC_NONE 0
#define RPL_DAG_MC_ETX 1
#define RPL_DAG_MC_ENERGY 2

static inline uint16_t get16(const uint8_t* buffer, int index) {
    return (buffer[index] << 8) | buffer[index + 1];
}

static inline uint32_t get32(const uint8_t* buffer, int index) {
    return (buffer[index] << 24) | (buffer[index + 1] << 16) | 
           (buffer[index + 2] << 8) | buffer[index + 3];
}

#define LOG_INFO(...)
#define LOG_INFO_6ADDR(...)
#define LOG_INFO_(...)
#define LOG_DBG(...)
#define LOG_DBG_6ADDR(...)
#define LOG_DBG_(...)
#define LOG_WARN(...)
#define RPL_STAT(...)
#define RPL_DEBUG_DIO_INPUT(...)

struct rpl_stats {
    int malformed_msgs;
};
extern struct rpl_stats rpl_stats;

extern void rpl_process_dio(uip_ipaddr_t*, rpl_dio_t*);
extern void uip_ipaddr_copy(uip_ipaddr_t*, uip_ipaddr_t*);
extern void uipbuf_clear(void);