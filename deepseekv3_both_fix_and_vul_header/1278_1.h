#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

typedef int __LA_MODE_T;

struct archive;
struct archive_acl;

#define ARCHIVE_OK 0
#define ARCHIVE_FAILED 1
#define ARCHIVE_WARN 2
#define ARCHIVE_ERRNO_MISC (-1)
#define ARCHIVE_ENTRY_ACL_TYPE_NFS4 0x1000
#define ARCHIVE_ENTRY_ACL_USER 1
#define ARCHIVE_ENTRY_ACL_GROUP 2
#define ARCHIVE_ENTRY_ACL_USER_OBJ 3
#define ARCHIVE_ENTRY_ACL_GROUP_OBJ 4
#define ARCHIVE_ENTRY_ACL_EVERYONE 5
#define ARCHIVE_ENTRY_ACL_TYPE_ALLOW 6
#define ARCHIVE_ENTRY_ACL_TYPE_DENY 7
#define ARCHIVE_ENTRY_ACL_TYPE_AUDIT 8
#define ARCHIVE_ENTRY_ACL_TYPE_ALARM 9

struct richacl {
    struct richace *a_entries;
};

struct richace {
    unsigned short e_type;
    unsigned short e_flags;
    unsigned int e_mask;
    unsigned int e_id;
};

#define RICHACE_ACCESS_ALLOWED_ACE_TYPE 0
#define RICHACE_ACCESS_DENIED_ACE_TYPE 1
#define RICHACE_IDENTIFIER_GROUP 0x0040
#define RICHACE_SPECIAL_WHO 0x4000
#define RICHACE_OWNER_SPECIAL_ID 0
#define RICHACE_GROUP_SPECIAL_ID 1
#define RICHACE_EVERYONE_SPECIAL_ID 2

extern int archive_acl_reset(struct archive_acl *, int);
extern int archive_acl_next(struct archive *, struct archive_acl *, int, int *,
    int *, int *, int *, const char **);
extern void archive_set_error(struct archive *, int, const char *, ...);
extern uid_t archive_write_disk_uid(struct archive *, const char *, uid_t);
extern gid_t archive_write_disk_gid(struct archive *, const char *, gid_t);
extern int richacl_set_fd(int, struct richacl *);
extern int richacl_set_file(const char *, struct richacl *);
extern struct richacl *richacl_alloc(int);
extern void richacl_free(struct richacl *);
extern void _richacl_mode_to_masks(struct richacl *, __LA_MODE_T);

extern int acl_nfs4_perm_map_size;
extern int acl_nfs4_flag_map_size;
extern struct {
    int a_perm;
    int p_perm;
} acl_nfs4_perm_map[];
extern struct {
    int a_perm;
    int p_perm;
} acl_nfs4_flag_map[];