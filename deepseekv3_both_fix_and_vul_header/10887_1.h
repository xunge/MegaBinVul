#include <stdint.h>
#include <stddef.h>

#define PJ_DEF(x) x
#define PJ_CHECK_STACK()
#define PJ_LOG(level, args)
#define THIS_FILE ""
#define PJLIB_UTIL_ESTUNINMSGTYPE (-1)
#define PJLIB_UTIL_ESTUNINMSGLEN (-2)
#define PJLIB_UTIL_ESTUNINATTRLEN (-3)
#define PJ_SUCCESS 0

typedef int pj_status_t;
typedef uint16_t pj_uint16_t;
typedef uint32_t pj_uint32_t;
typedef size_t pj_size_t;

typedef enum {
    PJSTUN_BINDING_REQUEST,
    PJSTUN_BINDING_RESPONSE,
    PJSTUN_BINDING_ERROR_RESPONSE,
    PJSTUN_SHARED_SECRET_REQUEST,
    PJSTUN_SHARED_SECRET_RESPONSE,
    PJSTUN_SHARED_SECRET_ERROR_RESPONSE
} pjstun_msg_type;

typedef enum {
    PJSTUN_ATTR_MAPPED_ADDR,
    PJSTUN_ATTR_RESPONSE_ADDR,
    PJSTUN_ATTR_CHANGE_REQUEST,
    PJSTUN_ATTR_SOURCE_ADDR,
    PJSTUN_ATTR_CHANGED_ADDR,
    PJSTUN_ATTR_USERNAME,
    PJSTUN_ATTR_PASSWORD,
    PJSTUN_ATTR_MESSAGE_INTEGRITY,
    PJSTUN_ATTR_ERROR_CODE,
    PJSTUN_ATTR_UNKNOWN_ATTRIBUTES,
    PJSTUN_ATTR_REFLECTED_FROM,
    PJSTUN_ATTR_XOR_MAPPED_ADDR
} pjstun_attr_type;

typedef struct pjstun_msg_hdr {
    pj_uint16_t type;
    pj_uint16_t length;
    pj_uint32_t tsx[4];
    pj_uint32_t magic;
} pjstun_msg_hdr;

typedef struct pjstun_attr_hdr {
    pj_uint16_t type;
    pj_uint16_t length;
} pjstun_attr_hdr;

typedef struct pjstun_msg {
    pjstun_msg_hdr *hdr;
    pjstun_attr_hdr *attr[32];
    unsigned attr_count;
} pjstun_msg;

static inline pj_uint16_t pj_ntohs(pj_uint16_t val) {
    return ((val << 8) & 0xff00) | ((val >> 8) & 0x00ff);
}