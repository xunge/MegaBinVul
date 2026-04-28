#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define TL_TPGS_PER_HBA 32
#define KERN_ERR ""
#define KERN_INFO ""
#define ERR_PTR(err) ((void *)(long)(err))
#define ENOMEM 12
#define EINVAL 22
#define TRANSPORT_TPG_TYPE_NORMAL 0

struct config_group {
    char name[64];
    struct config_group *cg_item;
};

struct se_wwn {
    struct {
        struct config_group wwn_group;
    };
};

struct se_portal_group {
    int dummy;
};

struct target_core_fabric_ops {
    int dummy;
};

struct tcm_loop_tpg {
    struct tcm_loop_hba *tl_hba;
    unsigned short tl_tpgt;
    struct se_portal_group tl_se_tpg;
};

struct tcm_loop_hba {
    struct se_wwn tl_hba_wwn;
    struct tcm_loop_tpg tl_hba_tpgs[TL_TPGS_PER_HBA];
};

struct tcm_loop_fabric_configfs {
    struct target_core_fabric_ops tf_ops;
};

extern struct tcm_loop_fabric_configfs *tcm_loop_fabric_configfs;
extern const char *tcm_loop_dump_proto_id(struct tcm_loop_hba *tl_hba);
extern int core_tpg_register(struct target_core_fabric_ops *ops,
                struct se_wwn *wwn,
                struct se_portal_group *se_tpg,
                void *tpg,
                int tpg_type);
extern char *config_item_name(struct config_group *group);
extern unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);
extern int printk(const char *fmt, ...);

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))