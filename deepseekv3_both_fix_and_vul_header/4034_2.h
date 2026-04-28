#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef unsigned long CK_ULONG;
typedef unsigned long CK_RV;
typedef unsigned long CK_FLAGS;
typedef CK_FLAGS *CK_FLAGS_PTR;
typedef CK_ULONG *CK_ULONG_PTR;

typedef struct CK_VERSION {
    unsigned char major;
    unsigned char minor;
} CK_VERSION;

typedef struct CK_INFO {
    CK_VERSION cryptokiVersion;
    unsigned char manufacturerID[32];
    CK_FLAGS flags;
    unsigned char libraryDescription[32];
    CK_VERSION libraryVersion;
} CK_INFO;

typedef struct CK_TOKEN_INFO {
    unsigned char label[32];
    unsigned char manufacturerID[32];
    unsigned char model[16];
    unsigned char serialNumber[16];
    CK_FLAGS flags;
    CK_ULONG ulMaxSessionCount;
    CK_ULONG ulSessionCount;
    CK_ULONG ulMaxRwSessionCount;
    CK_ULONG ulRwSessionCount;
    CK_ULONG ulMaxPinLen;
    CK_ULONG ulMinPinLen;
    CK_ULONG ulTotalPublicMemory;
    CK_ULONG ulFreePublicMemory;
    CK_ULONG ulTotalPrivateMemory;
    CK_ULONG ulFreePrivateMemory;
    CK_VERSION hardwareVersion;
    CK_VERSION firmwareVersion;
    unsigned char utcTime[16];
} CK_TOKEN_INFO;

typedef CK_ULONG CK_SLOT_ID;
typedef CK_SLOT_ID *CK_SLOT_ID_PTR;

typedef struct CK_FUNCTION_LIST {
    CK_RV (*C_Initialize)(void *);
    CK_RV (*C_Finalize)(void *);
    CK_RV (*C_GetInfo)(CK_INFO *);
    CK_RV (*C_GetSlotList)(unsigned char, CK_SLOT_ID *, CK_ULONG *);
    CK_RV (*C_GetTokenInfo)(CK_SLOT_ID, CK_TOKEN_INFO *);
} CK_FUNCTION_LIST;

struct sshkey;

struct pkcs11_slotinfo {
    CK_TOKEN_INFO token;
    int logged_in;
};

struct pkcs11_provider {
    char *name;
    void *handle;
    CK_FUNCTION_LIST *function_list;
    CK_INFO info;
    CK_ULONG nslots;
    CK_SLOT_ID *slotlist;
    struct pkcs11_slotinfo *slotinfo;
    int valid;
    int refcount;
    struct pkcs11_provider *next;
};

struct pkcs11_provider_head {
    struct pkcs11_provider *tqh_first;
    struct pkcs11_provider **tqh_last;
};

extern struct pkcs11_provider_head pkcs11_providers;
extern int pkcs11_interactive;
#define SSH_PKCS11_ERR_NO_SLOTS 1
#define CKR_OK 0
#define CK_TRUE 1
#define CKF_TOKEN_INITIALIZED 0x00000002
#define CKU_USER 1

static void rmspace(char *s, size_t n);
static void *xcalloc(size_t nmemb, size_t size);
static char *xstrdup(const char *s);
static void debug(const char *fmt, ...);
static void debug2_f(const char *fmt, ...);
static void debug_f(const char *fmt, ...);
static void error(const char *fmt, ...);
static struct pkcs11_provider *pkcs11_provider_lookup(char *provider_id);
static int pkcs11_open_session(struct pkcs11_provider *p, CK_ULONG i, char *pin, CK_ULONG user);
static void pkcs11_fetch_keys(struct pkcs11_provider *p, CK_ULONG i, struct sshkey ***keyp, char ***labelsp, int *nkeys);
static void pkcs11_fetch_certs(struct pkcs11_provider *p, CK_ULONG i, struct sshkey ***keyp, char ***labelsp, int *nkeys);
static int pkcs11_login_slot(struct pkcs11_provider *p, struct pkcs11_slotinfo *si, CK_ULONG user_type);

#define TAILQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->field = NULL; \
    (head)->tqh_last = &(elm)->field; \
    *(head)->tqh_last = (elm); \
} while (0)