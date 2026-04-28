#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>

typedef unsigned char uchar;

struct rpc_t {
    union {
        uchar data[0];
        struct {
            uint32_t id;
            uint32_t rstatus;
            uint32_t verifier;
            uint32_t astatus;
            uint32_t data[0];
        } reply;
    } u;
};

extern int rpc_id;
extern int supported_nfs_versions;
extern uchar filefh[];
extern int filefh3_length;
extern void debug(const char *fmt, ...);

#define NFS_RPC_ERR 1
#define NFS_RPC_DROP 2
#define NFS_RPC_PROG_MISMATCH 1
#define NFS_RPC_PROG_UNAVAIL 2
#define NFS_RPC_PROC_UNAVAIL 3
#define NFS_RPC_GARBAGE_ARGS 4
#define NFS_RPC_SYSTEM_ERR 5

#define NFSV2_FLAG 1
#define NFSV3_FLAG 2

#define NFS_FHSIZE 32
#define NFS3_FHSIZE 64

#define NFS_RPC_SUCCESS 0