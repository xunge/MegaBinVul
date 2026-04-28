#include <stdio.h>
#include <stdlib.h>

typedef struct PK11SlotInfo PK11SlotInfo;
typedef struct PK11SymKey PK11SymKey;
typedef struct SECItem {
    unsigned int type;
    unsigned char *data;
    unsigned int len;
} SECItem;

#define siBuffer 0
#define CKA_SIGN 0
#define PK11_OriginUnwrap 0

struct crypto_instance {
    int crypto_hash_type;
    unsigned char *private_key;
    int private_key_len;
    int log_level_security;
    PK11SymKey *nss_sym_key_sign;
};

extern PK11SymKey *hash_to_nss[];
extern void (*log_printf)(int level, const char *fmt, ...);
extern PK11SlotInfo *PK11_GetBestSlot(PK11SymKey *mechanism, void *wincx);
extern PK11SymKey *PK11_ImportSymKey(PK11SlotInfo *slot, PK11SymKey *type, int origin, int operation, SECItem *key, void *wincx);
extern void PK11_FreeSlot(PK11SlotInfo *slot);
extern int PR_GetError();