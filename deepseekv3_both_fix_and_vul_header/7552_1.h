#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <arpa/inet.h>

typedef int pj_status_t;
typedef struct pj_pool_t pj_pool_t;
typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pj_dns_parsed_query {
    pj_str_t name;
    uint16_t type;
    uint16_t dnsclass;
} pj_dns_parsed_query;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINSIZE (-1)

typedef uint8_t pj_uint8_t;

static pj_status_t get_name_len(int dummy, const pj_uint8_t *pkt, const pj_uint8_t *start,
                               const pj_uint8_t *max, int *name_part_len, int *name_len);
static pj_status_t get_name(int dummy, const pj_uint8_t *pkt, const pj_uint8_t *start,
                           const pj_uint8_t *max, pj_str_t *name);
static void *pj_pool_alloc(pj_pool_t *pool, size_t size);
static void pj_memcpy(void *dst, const void *src, size_t len);
static uint16_t pj_ntohs(uint16_t val);