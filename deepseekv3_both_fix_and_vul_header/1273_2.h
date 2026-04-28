#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define ARCHIVE_OK 0
#define ARCHIVE_WARN 1
#define ARCHIVE_FAILED -1
#define ARCHIVE_ERRNO_MISC -1

#define ARCHIVE_ENTRY_ACL_TYPE_ACCESS 0
#define ARCHIVE_ENTRY_ACL_TYPE_DEFAULT 1
#define ARCHIVE_ENTRY_ACL_TYPE_NFS4 2

#define ARCHIVE_ENTRY_ACL_USER 0
#define ARCHIVE_ENTRY_ACL_GROUP 1
#define ARCHIVE_ENTRY_ACL_USER_OBJ 2
#define ARCHIVE_ENTRY_ACL_GROUP_OBJ 3
#define ARCHIVE_ENTRY_ACL_MASK 4
#define ARCHIVE_ENTRY_ACL_OTHER 5
#define ARCHIVE_ENTRY_ACL_EVERYONE 6

#define ARCHIVE_ENTRY_ACL_TYPE_ALLOW 0
#define ARCHIVE_ENTRY_ACL_TYPE_DENY 1
#define ARCHIVE_ENTRY_ACL_TYPE_AUDIT 2
#define ARCHIVE_ENTRY_ACL_TYPE_ALARM 3

#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 1
#define ACL_TYPE_NFS4 2

#define ACL_USER 0
#define ACL_GROUP 1
#define ACL_USER_OBJ 2
#define ACL_GROUP_OBJ 3
#define ACL_MASK 4
#define ACL_OTHER 5
#define ACL_EVERYONE 6

typedef void* acl_t;
typedef void* acl_entry_t;
typedef void* acl_permset_t;
typedef void* acl_flagset_t;

struct archive;
struct archive_acl;

typedef int __LA_MODE_T;

struct acl_perm_map {
    int a_perm;
    int p_perm;
};

typedef struct acl_perm_map acl_perm_map_t;

extern const struct acl_perm_map acl_posix_perm_map[];
extern const int acl_posix_perm_map_size;
extern const struct acl_perm_map acl_nfs4_perm_map[];
extern const int acl_nfs4_perm_map_size;
extern const struct acl_perm_map acl_nfs4_flag_map[];
extern const int acl_nfs4_flag_map_size;

int acl_init(int count);
int acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p);
int acl_set_tag_type(acl_entry_t entry_d, int tag_type);
int acl_set_qualifier(acl_entry_t entry_d, void *qualifier_p);
int acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p);
int acl_clear_perms(acl_permset_t permset_d);
int acl_add_perm(acl_permset_t permset_d, int perm);
void acl_free(acl_t acl);

int archive_acl_reset(struct archive_acl *, int);
int archive_acl_next(struct archive *, struct archive_acl *, int, int *,
    int *, int *, int *, const char **);
uid_t archive_write_disk_uid(struct archive *, const char *, uid_t);
gid_t archive_write_disk_gid(struct archive *, const char *, gid_t);
void archive_set_error(struct archive *, int, const char *, ...);