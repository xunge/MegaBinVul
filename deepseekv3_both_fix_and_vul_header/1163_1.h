#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct rad_dict_vendor_t {
    uint32_t id;
    int tag;
    int len;
};

struct rad_dict_attr_t {
    const char *name;
    int type;
    int size;
    int array;
};

struct rad_attr_t {
    struct rad_dict_vendor_t *vendor;
    struct rad_dict_attr_t *attr;
    int len;
    uint8_t *raw;
    int alloc;
    union {
        char *string;
        uint8_t *octets;
        uint32_t integer;
        struct {
            uint8_t len;
            uint8_t prefix[16];
        } ipv6prefix;
    } val;
    struct list_head entry;
};

struct rad_packet_t {
    uint8_t code;
    uint8_t id;
    uint16_t len;
    uint8_t *buf;
    struct timespec tv;
    struct list_head attrs;
};

#define REQ_LENGTH_MAX 4096
#define MAP_FAILED ((void *)-1)
#define ATTR_TYPE_STRING 1
#define ATTR_TYPE_OCTETS 2
#define ATTR_TYPE_ETHER 3
#define ATTR_TYPE_TLV 4
#define ATTR_TYPE_INTEGER 5
#define ATTR_TYPE_DATE 6
#define ATTR_TYPE_IPADDR 7
#define ATTR_TYPE_IFID 8
#define ATTR_TYPE_IPV6ADDR 9
#define ATTR_TYPE_IPV6PREFIX 10

extern struct rad_packet_t *rad_packet_alloc(int);
extern void rad_packet_free(struct rad_packet_t *);
extern struct rad_dict_vendor_t *rad_dict_find_vendor_id(uint32_t);
extern struct rad_dict_attr_t *rad_dict_find_attr_id(struct rad_dict_vendor_t *, int);
extern void *mempool_alloc(void *);
extern void *_malloc(size_t);
extern void list_add_tail(struct list_head *, struct list_head *);
extern void *buf_pool;
extern void *attr_pool;
extern void log_emerg(const char *, ...);
extern void log_ppp_error(const char *, ...);
extern void log_ppp_warn(const char *, ...);