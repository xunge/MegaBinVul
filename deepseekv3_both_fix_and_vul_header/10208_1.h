#include <stdint.h>
#include <stddef.h>

typedef struct smb_request smb_request_t;
typedef struct smb_ofile smb_ofile_t;
typedef struct smb_node smb_node_t;
typedef struct smb_credential smb_credential_t;

typedef struct {
    uint64_t persistent;
    uint64_t temporal;
} smb2fid_t;

typedef enum {
    SDRC_SUCCESS,
    SDRC_ERROR
} smb_sdrc_t;

#define NODE_FLAGS_WRITE_THROUGH 0x00000001

struct smb_request {
    struct {
        uint8_t *data;
    } smb_data;
    uint8_t *reply;
    smb_ofile_t *fid_ofile;
};

struct smb_ofile {
    smb_node_t *f_node;
    smb_credential_t *f_cr;
};

struct smb_node {
    uint32_t flags;
};

int smb_mbc_decodef(void *, const char *, ...);
int smb_mbc_encodef(void *, const char *, ...);
uint32_t smb2sr_lookup_fid(smb_request_t *, smb2fid_t *);
void smb2sr_put_error(smb_request_t *, uint32_t);
int smb_fsop_commit(smb_request_t *, smb_credential_t *, smb_node_t *);