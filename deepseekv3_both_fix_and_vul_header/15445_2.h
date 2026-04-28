#include <string.h>
#include <stdio.h>

#define INVALID_SOCKET (-1)
#define KEX_FLAG_REKEYING 0x01
#define PROPOSAL_KEX_ALGS 0
#define KEX_DH_NONE 0
#define _TRUNCATE ((size_t)-1)

typedef struct {
    int socket;
    unsigned int kex_status;
    struct {
        char* KexOrder;
    } settings;
} *PTInstVar;

extern char* myproposal[];
extern const char* get_kex_algorithm_name(int index);

int strncat_s(char *dest, size_t destsz, const char *src, size_t count);