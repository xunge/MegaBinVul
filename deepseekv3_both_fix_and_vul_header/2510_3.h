#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct sunrpc_msg {
    struct {
        uint32_t cb_vers;
        uint32_t cb_proc;
    } rm_call;
};

struct nfsv3_sattr {
    uint32_t sa_mode;
    uint32_t sa_uid;
    uint32_t sa_gid;
    uint64_t sa_size;
    uint64_t sa_atime;
    uint64_t sa_mtime;
};

typedef enum {
    NFSPROC_GETATTR,
    NFSPROC_SETATTR,
    NFSPROC_LOOKUP,
    NFSPROC_ACCESS,
    NFSPROC_READLINK,
    NFSPROC_READ,
    NFSPROC_WRITE,
    NFSPROC_CREATE,
    NFSPROC_MKDIR,
    NFSPROC_SYMLINK,
    NFSPROC_MKNOD,
    NFSPROC_REMOVE,
    NFSPROC_RMDIR,
    NFSPROC_RENAME,
    NFSPROC_LINK,
    NFSPROC_READDIR,
    NFSPROC_READDIRPLUS,
    NFSPROC_FSSTAT,
    NFSPROC_FSINFO,
    NFSPROC_PATHCONF,
    NFSPROC_COMMIT,
    NFS_NPROCS
} nfs_proc;

typedef enum {
    NFCHR,
    NFBLK
} nfs_type;

#define NFS_VER3 3
#define NFSV3ACCESS_READ 0x0001
#define NFSV3ACCESS_LOOKUP 0x0002
#define NFSV3ACCESS_MODIFY 0x0004
#define NFSV3ACCESS_EXTEND 0x0008
#define NFSV3ACCESS_DELETE 0x0010
#define NFSV3ACCESS_EXECUTE 0x0020
#define NFSV3ACCESS_FULL 0x003F

#define ND_PRINT(args) printf args
#define ND_TCHECK(p) 
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))
#define EXTRACT_64BITS(p) (*(const uint64_t *)(p))

extern const char *tstr;
extern int nfserr;
extern const uint32_t nfsv3_procid[];
extern const char *nfsproc_str[];
extern const char *type2str[];
extern const char *nfsv3_writemodes[];
extern const char *tok2str(const char * const *, const char *, int);

int xid_map_enter(netdissect_options *, const struct sunrpc_msg *, const u_char *);
const uint32_t *parsereq(netdissect_options *, const struct sunrpc_msg *, u_int);
const uint32_t *parsefh(netdissect_options *, const uint32_t *, int);
const uint32_t *parsefhn(netdissect_options *, const uint32_t *, int);
const uint32_t *parsefn(netdissect_options *, const uint32_t *);
const uint32_t *parse_sattr3(netdissect_options *, const uint32_t *, struct nfsv3_sattr *);
void print_sattr3(netdissect_options *, const struct nfsv3_sattr *, int);