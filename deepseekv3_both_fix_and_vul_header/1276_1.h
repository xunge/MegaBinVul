#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

struct archive;
struct archive_acl;
struct acl_posix_perm {
    int a_perm;
    int p_perm;
};
extern struct acl_posix_perm acl_posix_perm_map[];
extern int acl_posix_perm_map_size;

typedef void *acl_t;
typedef void *acl_entry_t;
typedef void *acl_permset_t;

#define __LA_MODE_T mode_t
#define ARCHIVE_OK 0
#define ARCHIVE_FAILED 1
#define ARCHIVE_WARN 2
#define ARCHIVE_ENTRY_ACL_TYPE_ACCESS 1
#define ARCHIVE_ENTRY_ACL_TYPE_DEFAULT 2
#define ARCHIVE_ERRNO_MISC -1
#define ACL_TYPE_ACCESS 0
#define ACL_TYPE_DEFAULT 1
#define ACL_USER 0
#define ACL_GROUP 1
#define ACL_USER_OBJ 2
#define ACL_GROUP_OBJ 3
#define ACL_MASK 4
#define ACL_OTHER 5

int archive_acl_reset(struct archive_acl *, int);
int archive_acl_next(struct archive *, struct archive_acl *, int, int *,
    int *, int *, int *, const char **);
uid_t archive_write_disk_uid(struct archive *, const char *, int);
gid_t archive_write_disk_gid(struct archive *, const char *, int);
void archive_set_error(struct archive *, int, const char *, ...);

#define ARCHIVE_ENTRY_ACL_USER 1
#define ARCHIVE_ENTRY_ACL_GROUP 2
#define ARCHIVE_ENTRY_ACL_USER_OBJ 3
#define ARCHIVE_ENTRY_ACL_GROUP_OBJ 4
#define ARCHIVE_ENTRY_ACL_MASK 5
#define ARCHIVE_ENTRY_ACL_OTHER 6

acl_t acl_init(int);
int acl_create_entry(acl_t *, acl_entry_t *);
int acl_set_tag_type(acl_entry_t, int);
int acl_set_qualifier(acl_entry_t, const void *);
int acl_get_permset(acl_entry_t, acl_permset_t *);
int acl_clear_perms(acl_permset_t);
int acl_add_perm(acl_permset_t, int);
int acl_set_fd(int, acl_t);
int acl_set_file(const char *, int, acl_t);
int acl_free(acl_t);