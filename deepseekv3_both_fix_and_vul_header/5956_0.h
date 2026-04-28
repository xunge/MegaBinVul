#include <stddef.h>
#include <string.h>

typedef struct gnutls_session_int *gnutls_session_t;
typedef struct {
    void *data;
    size_t size;
} gnutls_datum_t;

#define RESUME_FALSE 0
#define GNUTLS_E_INVALID_SESSION -1
#define GNUTLS_E_SHORT_MEMORY_BUFFER -2

int _gnutls_session_pack(gnutls_session_t session, gnutls_datum_t *psession);
void _gnutls_free_datum(gnutls_datum_t *datum);

struct gnutls_session_int {
    struct {
        int resumable;
    } internals;
};