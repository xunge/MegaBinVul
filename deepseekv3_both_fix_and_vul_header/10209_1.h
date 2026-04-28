#include <stdint.h>
#include <stddef.h>

typedef enum {
    SDRC_SUCCESS,
    SDRC_ERROR
} smb_sdrc_t;

#define NT_STATUS_INVALID_HANDLE 0xC0000008
#define ERRDOS 0x01
#define ERRbadfid 0x0006
#define RW_READER 1

typedef struct smb_request smb_request_t;
typedef struct smb_ofile smb_ofile_t;
typedef struct smb_llist smb_llist_t;
typedef struct smb_tree smb_tree_t;

struct smb_request {
    uint16_t smb_fid;
    smb_ofile_t *fid_ofile;
    smb_tree_t *tid_tree;
};

struct smb_ofile {
    void *f_mutex;
};

struct smb_llist {
    // implementation details would be needed for full definition
};

struct smb_tree {
    smb_llist_t t_ofile_list;
};

extern int smb_flush_required;
extern int smbsr_encode_empty_result(smb_request_t *);
extern void smbsr_lookup_file(smb_request_t *);
extern void smbsr_error(smb_request_t *, uint32_t, uint16_t, uint16_t);
extern void smb_flush_file(smb_request_t *, smb_ofile_t *);
extern smb_ofile_t *smb_llist_head(smb_llist_t *);
extern smb_ofile_t *smb_llist_next(smb_llist_t *, smb_ofile_t *);
extern void smb_llist_enter(smb_llist_t *, int);
extern void smb_llist_exit(smb_llist_t *);
extern void mutex_enter(void *);
extern void mutex_exit(void *);