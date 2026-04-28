#include <stdint.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_qflag;
    int ndo_vflag;
} netdissect_options;

struct sunrpc_msg {
    uint32_t rm_xid;
    uint32_t rm_direction;
    uint32_t rm_call;
    uint32_t rm_vers;
    uint32_t rm_proc;
};

#define NFS_VER3 3
#define NFS_NPROCS 22

enum {
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
    NFSPROC_COMMIT
};

extern const char *nfsproc_str[];
extern const uint32_t nfsv3_procid[];
extern const char *nfsv3_writemodes[];
extern const char *tstr;
extern int nfserr;

#define ND_TCHECK(p)
#define ND_PRINT(args)
#define EXTRACT_32BITS(p) (*(const uint32_t *)(p))

const uint32_t *parserep(netdissect_options *, const struct sunrpc_msg *, int);
int parseattrstat(netdissect_options *, const uint32_t *, int, int);
int parsewccres(netdissect_options *, const uint32_t *, int);
const uint32_t *parsestatus(netdissect_options *, const uint32_t *, int *);
const uint32_t *parse_post_op_attr(netdissect_options *, const uint32_t *, int);
const uint32_t *parsefh(netdissect_options *, const uint32_t *, int);
int parsediropres(netdissect_options *, const uint32_t *);
int parselinkres(netdissect_options *, const uint32_t *, int);
const uint32_t *parse_wcc_data(netdissect_options *, const uint32_t *, int);
const uint32_t *parsecreateopres(netdissect_options *, const uint32_t *, int);
int parsev3rddirres(netdissect_options *, const uint32_t *, int);
int parserddires(netdissect_options *, const uint32_t *);
int parsestatfs(netdissect_options *, const uint32_t *, int);
int parsefsinfo(netdissect_options *, const uint32_t *);
int parsepathconf(netdissect_options *, const uint32_t *);
const char *tok2str(const char *, const char *, unsigned int);