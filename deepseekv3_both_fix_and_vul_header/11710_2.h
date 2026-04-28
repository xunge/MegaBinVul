#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

typedef struct script_t {
    int uid;
    int gid;
} script_t;

typedef struct ifp_t {
    char *ifname;
} ifp_t;

typedef struct vrrp_t {
    char *iname;
} vrrp_t;

typedef struct data_t {
    char *network_namespace;
    char *instance_name;
    char *router_id;
    struct sockaddr_storage smtp_server;
    char *smtp_helo_name;
    unsigned long smtp_connection_to;
    char *email_from;
    void *email;
    int smtp_alert;
    int smtp_alert_vrrp;
    int smtp_alert_checker;
    int dynamic_interfaces;
    int allow_if_changes;
    int no_email_faults;
    int lvs_tcp_timeout;
    int lvs_tcpfin_timeout;
    int lvs_udp_timeout;
    struct {
        vrrp_t *vrrp;
        char *ifname;
        unsigned syncid;
        unsigned sync_maxlen;
        struct sockaddr_storage mcast_group;
        int mcast_port;
        unsigned mcast_ttl;
    } lvs_syncd;
    int lvs_flush;
    struct {
        char *name;
        script_t *script;
    } notify_fifo, vrrp_notify_fifo, lvs_notify_fifo;
    struct sockaddr_in vrrp_mcast_group4;
    struct sockaddr_in6 vrrp_mcast_group6;
    unsigned vrrp_garp_delay;
    unsigned vrrp_garp_rep;
    struct timeval vrrp_garp_refresh;
    int vrrp_garp_refresh_rep;
    int vrrp_garp_lower_prio_delay;
    int vrrp_garp_lower_prio_rep;
    int vrrp_lower_prio_no_advert;
    int vrrp_higher_prio_send_advert;
    int vrrp_garp_interval;
    int vrrp_gna_interval;
    int vrrp_version;
    char vrrp_iptables_inchain[64];
    char vrrp_iptables_outchain[64];
    int using_ipsets;
    char vrrp_ipset_address[64];
    char vrrp_ipset_address6[64];
    char vrrp_ipset_address_iface6[64];
    int vrrp_check_unicast_src;
    int vrrp_skip_check_adv_addr;
    int vrrp_strict;
    int vrrp_process_priority;
    int vrrp_no_swap;
    unsigned vrrp_realtime_priority;
    unsigned long vrrp_rlimit_rt;
    int checker_process_priority;
    int checker_no_swap;
    unsigned checker_realtime_priority;
    unsigned long checker_rlimit_rt;
    int bfd_process_priority;
    int bfd_no_swap;
    unsigned bfd_realtime_priority;
    unsigned long bfd_rlimit_rt;
    int enable_snmp_vrrp;
    int enable_snmp_checker;
    int enable_snmp_rfcv2;
    int enable_snmp_rfcv3;
    int enable_traps;
    char *snmp_socket;
    int enable_dbus;
    char *dbus_service_name;
    ifp_t *default_ifp;
    struct {
        unsigned vrrp_netlink_cmd_rcv_bufs;
        unsigned vrrp_netlink_cmd_rcv_bufs_force;
        unsigned vrrp_netlink_monitor_rcv_bufs;
        unsigned vrrp_netlink_monitor_rcv_bufs_force;
        unsigned lvs_netlink_cmd_rcv_bufs;
        unsigned lvs_netlink_cmd_rcv_bufs_force;
        unsigned lvs_netlink_monitor_rcv_bufs;
        unsigned lvs_netlink_monitor_rcv_bufs_force;
        unsigned rs_init_notifies;
        unsigned no_checker_emails;
        unsigned vrrp_rx_bufs_policy;
        unsigned long vrrp_rx_bufs_size;
        unsigned vrrp_rx_bufs_multiples;
    } *global_data;
} data_t;

#define TIMER_HZ 1
#define PARAMETER_UNSET -1
#define DFLT_INT "eth0"
#define PROG_TYPE_VRRP 1
#define RX_BUFS_POLICY_MTU 1
#define RX_BUFS_POLICY_ADVERT 2
#define RX_BUFS_SIZE 3

extern int script_security;
extern int default_script_uid;
extern int default_script_gid;
extern data_t *global_data;
extern int prog_type;

void conf_write(FILE *fp, const char *fmt, ...);
char *inet_sockaddrtos(struct sockaddr_storage *addr);
in_port_t inet_sockaddrport(struct sockaddr_storage *addr);
void dump_list(FILE *fp, void *list);
char *cmd_str(script_t *cmd);