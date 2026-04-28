#include <stdlib.h>
#include <string.h>

typedef int grub_err_t;
typedef void *grub_fshelp_node_t;

enum grub_fshelp_filetype {
    GRUB_FSHELP_DIR,
    GRUB_FSHELP_SYMLINK
};

enum {
    GRUB_ERR_NONE = 0,
    GRUB_ERR_BAD_FILE_TYPE,
    GRUB_ERR_SYMLINK_LOOP,
    GRUB_ERR_FILE_NOT_FOUND
};

extern grub_err_t grub_errno;

struct grub_fshelp_find_file_closure {
    grub_fshelp_node_t currroot;
    grub_fshelp_node_t rootnode;
    int symlinknest;
    enum grub_fshelp_filetype foundtype;
    int (*iterate_dir)(grub_fshelp_node_t, void *, void *);
    char *(*read_symlink)(grub_fshelp_node_t);
};

struct find_file_closure {
    char *name;
    enum grub_fshelp_filetype *type;
    grub_fshelp_node_t *oldnode;
    grub_fshelp_node_t *currnode;
};

void *grub_malloc(size_t size);
void grub_free(void *ptr);
char *grub_strchr(const char *s, int c);
size_t grub_strlen(const char *s);
char *grub_strncpy(char *dest, const char *src, size_t n);
grub_err_t grub_error(int errnum, const char *fmt, ...);
void free_node(grub_fshelp_node_t node, struct grub_fshelp_find_file_closure *c);
int iterate(void *arg, void *data);