#include <stddef.h>
#include <string.h>
#include <sys/types.h>

struct node {
    struct node* parent;
    char* graft_path;
    size_t graft_pathlen;
    char* actual_name;
    char* name;
    size_t namelen;
};