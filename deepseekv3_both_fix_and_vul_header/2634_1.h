#include <stddef.h>
#include <stdint.h>
#include <time.h>

typedef struct circuit_t {
    int purpose;
    unsigned int n_circ_id;
} circuit_t;

typedef struct origin_circuit_t {
    circuit_t base_;
    struct rend_data_t *rend_data;
} origin_circuit_t;

typedef struct rend_service_t {
    time_t desc_is_dirty;
} rend_service_t;

typedef struct rend_intro_point_t {
    int circuit_established;
} rend_intro_point_t;

#define REND_SERVICE_ID_LEN_BASE32 32
#define REND_SERVICE_ID_LEN 16

#define CIRCUIT_PURPOSE_S_ESTABLISH_INTRO 0
#define CIRCUIT_PURPOSE_S_INTRO 0
#define END_CIRC_REASON_TORPROTOCOL 0
#define LD_PROTOCOL 0
#define LD_REND 0

#define tor_assert(expr) (void)(expr)
#define log_warn(ld, msg, ...) (void)(ld)
#define log_info(ld, msg, ...) (void)(ld)
#define safe_str_client(str) (str)
#define TO_CIRCUIT(circ) ((circuit_t*)(circ))

const void *rend_data_get_pk_digest(struct rend_data_t *rend_data, void *arg);
rend_service_t *rend_service_get_by_pk_digest(const char *digest);
rend_intro_point_t *find_intro_point(origin_circuit_t *circuit);
void circuit_change_purpose(circuit_t *circuit, int purpose);
void pathbias_mark_use_success(origin_circuit_t *circuit);
void circuit_mark_for_close(circuit_t *circuit, int reason);
void base32_encode(char *dest, size_t destlen, const char *src, size_t srclen);