#include <string.h>
#include <errno.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct nvmet_ctrl {
    struct nvmet_subsys *subsys;
    const char *hostnqn;
    int shash_id;
    struct nvme_auth_key *host_key;
    struct nvme_auth_key *ctrl_key;
};

struct nvmet_subsys {
    bool allow_any_host;
    struct list_head hosts;
};

struct nvmet_host_link {
    struct nvmet_host *host;
    struct list_head entry;
};

struct nvmet_host {
    const char *dhchap_secret;
    const char *dhchap_ctrl_secret;
    int dhchap_hash_id;
    int dhchap_key_hash;
    int dhchap_ctrl_key_hash;
    int dhchap_dhgroup_id;
};

struct nvme_auth_key {
    int hash;
    size_t len;
    unsigned char *key;
};

struct rw_semaphore {
    // minimal stub for compilation
};

extern struct rw_semaphore nvmet_config_sem;
extern void down_read(struct rw_semaphore *sem);
extern void up_read(struct rw_semaphore *sem);
extern bool nvmet_is_disc_subsys(struct nvmet_subsys *subsys);
extern const char *nvmet_host_name(struct nvmet_host *host);
extern const char *nvme_auth_hmac_name(int hash_id);
extern void nvme_auth_free_key(struct nvme_auth_key *key);
extern struct nvme_auth_key *nvme_auth_extract_key(const char *secret, int hash_id);
extern int nvmet_setup_dhgroup(struct nvmet_ctrl *ctrl, int dhgroup_id);
extern void pr_debug(const char *fmt, ...);
extern void pr_warn(const char *fmt, ...);

#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))
#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((head)->next); \
         &pos->member != (head); \
         pos = (typeof(pos))(pos->member.next))