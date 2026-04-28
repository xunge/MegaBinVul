#include <string.h>

typedef struct git_odb_object git_odb_object;
typedef struct git_tree git_tree;
typedef struct git_tree_entry git_tree_entry;
typedef struct git_oid git_oid;

#define DEFAULT_TREE_SIZE 16
#define GIT_OID_RAWSZ 20

struct git_array {
    size_t size;
    void *ptr;
};

struct git_tree {
    git_odb_object *odb_obj;
    struct git_array *entries;  // Changed to pointer type
};

struct git_tree_entry {
    unsigned int attr;
    size_t filename_len;
    const char *filename;
    git_oid *oid;
};

#define GITERR_CHECK_ARRAY(arr) 
#define GITERR_CHECK_ALLOC(ptr) 

int git_odb_object_dup(git_odb_object **dest, git_odb_object *src);
const char *git_odb_object_data(git_odb_object *obj);
size_t git_odb_object_size(git_odb_object *obj);
void git_array_init_to_size(struct git_array *array, size_t size);
git_tree_entry *git_array_alloc(struct git_array *array);
int parse_mode(unsigned int *mode, const char *buffer, const char **endptr);
int tree_error(const char *msg, const char *arg);

// Added memory allocation function for git_array
struct git_array *git_array_new(size_t size);