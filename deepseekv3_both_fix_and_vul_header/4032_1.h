#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>

typedef unsigned long CK_ULONG;
typedef CK_ULONG CK_RV;
typedef unsigned long CK_SLOT_ID;

typedef struct CK_VERSION {
    unsigned char major;
    unsigned char minor;
} CK_VERSION;

typedef struct CK_INFO {
    CK_VERSION cryptokiVersion;
    unsigned char manufacturerID[32];
    unsigned char flags;
    unsigned char libraryDescription[32];
    CK_VERSION libraryVersion;
} CK_INFO;

typedef struct CK_TOKEN_INFO {
    unsigned char label[32];
    unsigned char manufacturerID[32];
    unsigned char model[16];
    unsigned char serialNumber[16];
    CK_ULONG flags;
} CK_TOKEN_INFO;

typedef struct CK_FUNCTION_LIST {
    CK_RV (*C_Initialize)(void *);
    CK_RV (*C_GetInfo)(CK_INFO *);
    CK_RV (*C_GetSlotList)(unsigned char, CK_SLOT_ID *, CK_ULONG *);
    CK_RV (*C_GetTokenInfo)(CK_SLOT_ID, CK_TOKEN_INFO *);
    CK_RV (*C_Finalize)(void *);
} CK_FUNCTION_LIST;

struct pkcs11_slotinfo {
    CK_TOKEN_INFO token;
    int logged_in;
};

struct pkcs11_provider {
    char *name;
    void *handle;
    CK_FUNCTION_LIST *function_list;
    CK_ULONG nslots;
    CK_SLOT_ID *slotlist;
    struct pkcs11_slotinfo *slotinfo;
    int valid;
    int refcount;
    CK_INFO info;
    TAILQ_ENTRY(pkcs11_provider) next;
};

struct sshkey;

#define CK_TRUE 1
#define CKR_OK 0
#define CKF_TOKEN_INITIALIZED 0x00000001
#define CKU_USER 1
#define SSH_PKCS11_ERR_NO_SLOTS 1

extern int pkcs11_interactive;
extern struct pkcs11_provider *pkcs11_provider_lookup(char *);
extern void debug_f(const char *, ...);
extern void error(const char *, ...);
extern void fatal(const char *, ...);
extern void *xcalloc(size_t, size_t);
extern char *xstrdup(const char *);
extern void rmspace(char *, size_t);
extern void debug(const char *, ...);
extern void debug2_f(const char *, ...);
extern int pkcs11_open_session(struct pkcs11_provider *, CK_ULONG, char *, CK_ULONG);
extern void pkcs11_fetch_keys(struct pkcs11_provider *, CK_ULONG, struct sshkey ***, char ***, int *);
extern void pkcs11_fetch_certs(struct pkcs11_provider *, CK_ULONG, struct sshkey ***, char ***, int *);
extern int pkcs11_login_slot(struct pkcs11_provider *, struct pkcs11_slotinfo *, CK_ULONG);

TAILQ_HEAD(pkcs11_provider_head, pkcs11_provider);
extern struct pkcs11_provider_head pkcs11_providers;