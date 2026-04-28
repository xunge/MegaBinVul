#include <stdlib.h>
#include <string.h>
#include <fnmatch.h>

#define PV_VAL_INT 0x01
#define PV_TYPE_INT 0x02
#define AVP_VAL_STR 0x04
#define EQ_T 1

typedef struct str {
    char* s;
    int len;
} str;

typedef struct ip_addr {
    unsigned int af;
    unsigned int len;
    union {
        unsigned int ip;
        unsigned short ip6[8];
    } u;
} ip_addr;

typedef struct pv_value_t {
    int flags;
    int ri;
    str rs;
} pv_value_t;

typedef struct ds_dest_t {
    ip_addr* ips;
    int* ports;
    int ips_cnt;
    str attrs;
    str script_attrs;
} ds_dest_t;

typedef struct ds_set_t {
    int id;
    int nr;
    ds_dest_t* dlist;
    struct ds_set_t* next;
    struct ds_set_t* sets;
} ds_set_t, *ds_set_p;

typedef struct ds_partition_t {
    void* lock;
    ds_set_t** data;
    int attrs_avp_name;
    int attrs_avp_type;
    int script_attrs_avp_name;
    int script_attrs_avp_type;
} ds_partition_t;

typedef struct int_str {
    str s;
} int_str;

extern str ds_setid_pvname;
extern pv_value_t ds_setid_pv;

struct sip_msg;

ip_addr* str2ip(str* s);
ip_addr* str2ip6(str* s);
int ip_addr_cmp(ip_addr* ip1, ip_addr* ip2);
int dst_is_active(ds_dest_t dest);
int pv_set_value(struct sip_msg* msg, pv_value_t* pv, int op, pv_value_t* val);
int add_avp(int flags, int name, int_str val);
void* pkg_malloc(size_t size);
void pkg_free(void* p);
void lock_start_read(void* lock);
void lock_stop_read(void* lock);
void LM_ERR(const char* fmt, ...);