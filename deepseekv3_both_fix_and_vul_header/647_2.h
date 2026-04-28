#include <stdlib.h>
#include <string.h>

#define GENL_START_ALLOC 0
#define GENL_MAX_ID 1023
#define GENL_ID_CTRL 0
#define GENL_ID_PMCRAID 1
#define GENL_ID_VFS_DQUOT 2

#define EEXIST -17
#define ENOMEM -12
#define GFP_KERNEL 0

#define CTRL_CMD_NEWFAMILY 0
#define CTRL_CMD_NEWMCAST_GRP 1

struct nlattr {
    // dummy definition
};

struct genl_family {
    const char *name;
    unsigned int maxattr;
    unsigned int parallel_ops;
    struct nlattr **attrbuf;
    int id;
    int n_mcgrps;
    void *mcgrps;
    int mcgrp_offset;
    // other members omitted
};

struct genl_ctrl {
    // dummy definition
};

extern struct genl_family genl_ctrl;
extern void *genl_fam_idr;

int genl_validate_ops(struct genl_family *family);
int genl_validate_assign_mc_groups(struct genl_family *family);
struct genl_family *genl_family_find_byname(const char *name);
void genl_lock_all(void);
void genl_unlock_all(void);
void genl_ctrl_event(int cmd, struct genl_family *family, void *data, int grp_id);

void *kmalloc_array(size_t n, size_t size, int flags);
void kfree(void *ptr);
int idr_alloc(void *idr, void *ptr, int start, int end, int flags);
void idr_remove(void *idr, int id);