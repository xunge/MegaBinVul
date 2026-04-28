#include <stddef.h>
#include <stdint.h>

#define PJ_DEF(x) x
#define PJ_UNUSED_ARG(x) (void)(x)
#define PJ_ASSERT_RETURN(expr, retval) do { if (!(expr)) return (retval); } while(0)
#define PJ_EINVAL (-1)
#define PJ_EBUG (-2)
#define PJ_SUCCESS 0
#define PJNATH_EINSTUNMSGLEN (-3)
#define PJNATH_ESTUNINATTRLEN (-4)
#define PJNATH_ESTUNTOOMANYATTR (-5)
#define PJNATH_ESTUNDUPATTR (-6)
#define PJNATH_ESTUNFINGERPOS (-7)
#define PJ_STUN_CHECK_PACKET 0x01
#define PJ_STUN_IS_DATAGRAM 0x02
#define PJ_STUN_MAX_ATTR 128
#define PJ_STUN_ATTR_MESSAGE_INTEGRITY 0x0008
#define PJ_STUN_ATTR_FINGERPRINT 0x8028
#define PJ_STUN_SC_BAD_REQUEST 400
#define PJ_STUN_SC_UNKNOWN_ATTRIBUTE 420
#define PJ_STUN_SC_SERVER_ERROR 500
#define PJ_ERR_MSG_SIZE 80
#define THIS_FILE __FILE__
#define ATTR_HDR_LEN 4

typedef int pj_status_t;
typedef unsigned int pj_size_t;
typedef uint8_t pj_uint8_t;
typedef uint16_t pj_uint16_t;
typedef uint32_t pj_uint32_t;
typedef int pj_bool_t;
#define PJ_FALSE 0
#define PJ_TRUE 1

typedef struct pj_pool_t pj_pool_t;
typedef struct pj_stun_msg pj_stun_msg;
typedef struct pj_stun_msg_hdr pj_stun_msg_hdr;
typedef struct pj_stun_attr_hdr pj_stun_attr_hdr;
typedef struct pj_stun_binary_attr pj_stun_binary_attr;
typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

struct pj_stun_msg_hdr {
    pj_uint16_t type;
    pj_uint16_t length;
    pj_uint32_t magic;
};

struct pj_stun_attr_hdr {
    pj_uint16_t type;
    pj_uint16_t length;
};

struct pj_stun_binary_attr {
    pj_stun_attr_hdr hdr;
    pj_uint8_t data[1];
};

struct pj_stun_msg {
    pj_stun_msg_hdr hdr;
    pj_stun_attr_hdr *attr[PJ_STUN_MAX_ATTR];
    unsigned attr_count;
};

struct attr_desc {
    pj_status_t (*decode_attr)(pj_pool_t*, const pj_uint8_t*, const pj_stun_msg_hdr*, void**);
};

#define GETVAL16H(buf,offset) (((pj_uint16_t)((buf)[offset]) << 8) | \
                              ((pj_uint16_t)((buf)[offset+1])))
#define PJ_STUN_IS_REQUEST(type) (((type) & 0x0110) == 0x0000)

static pj_uint16_t pj_ntohs(pj_uint16_t val) { return val; }
static pj_uint32_t pj_ntohl(pj_uint32_t val) { return val; }
static int pj_ansi_snprintf(char *buf, size_t size, const char *format, ...) { return 0; }
static void pj_memcpy(void *dst, const void *src, size_t len) {}
static void PJ_LOG(int level, const char *format, ...) {}
static pj_status_t pj_stun_msg_check(const pj_uint8_t *pdu, pj_size_t pdu_len, unsigned options) { return PJ_SUCCESS; }
static pj_status_t pj_stun_msg_create_response(pj_pool_t *pool, pj_stun_msg *msg, unsigned err_code, pj_str_t *err_msg, pj_stun_msg **p_response) { return PJ_SUCCESS; }
static pj_status_t pj_stun_msg_add_unknown_attr(pj_pool_t *pool, pj_stun_msg *msg, int count, pj_uint16_t *attrs) { return PJ_SUCCESS; }
static pj_status_t pj_stun_binary_attr_create(pj_pool_t *pool, unsigned attr_type, const pj_uint8_t *data, pj_uint16_t length, pj_stun_binary_attr **p_attr) { return PJ_SUCCESS; }
static const char *pj_stun_get_attr_name(unsigned attr_type) { return ""; }
static void pj_strerror(pj_status_t status, char *buf, size_t size) {}
static const struct attr_desc *find_attr_desc(unsigned attr_type) { return NULL; }
#define PJ_POOL_ZALLOC_T(pool, type) ((type*)calloc(1, sizeof(type)))
#define PJ_STATUS_FROM_STUN_CODE(code) (-(code))