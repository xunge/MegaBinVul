#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct git_oid git_oid;
typedef struct git_signature git_signature;
typedef struct git_commit git_commit;
typedef struct git_odb_object git_odb_object;

struct git_oid {
    unsigned char id[20];
};

struct git_signature {
    char *name;
    char *email;
    time_t when;
    int offset;
};

struct git_commit {
    git_oid tree_id;
    git_oid *parent_ids;
    size_t parent_ids_size;
    size_t parent_ids_asize;
    git_signature *author;
    git_signature *committer;
    char *message_encoding;
    char *raw_header;
    char *raw_message;
};

#define GITERR_NOMEMORY 1
#define GITERR_OBJECT 2

#define GITERR_CHECK_ARRAY(arr) do { \
    if (!(arr)) { \
        giterr_set(GITERR_NOMEMORY, "Failed to allocate array"); \
        return -1; \
    } \
} while (0)

#define GITERR_CHECK_ALLOC(ptr) do { \
    if (!(ptr)) { \
        giterr_set(GITERR_NOMEMORY, "Failed to allocate memory"); \
        return -1; \
    } \
} while (0)

#define git_array_init_to_size(arr, n) do { \
    (arr) = git__malloc((n) * sizeof(*(arr))); \
    (arr##_size) = 0; \
    (arr##_asize) = (n); \
} while (0)

static inline git_oid *git_array_alloc(git_commit *commit) {
    if (commit->parent_ids_size == commit->parent_ids_asize) {
        commit->parent_ids_asize *= 2;
        commit->parent_ids = realloc(commit->parent_ids, 
            commit->parent_ids_asize * sizeof(git_oid));
    }
    return &commit->parent_ids[commit->parent_ids_size++];
}

void *git__malloc(size_t len);
void git__free(void *ptr);
char *git__strndup(const char *s, size_t n);
int git__prefixcmp(const char *str, const char *prefix);
void giterr_set(int error_class, const char *message);
const char *git_odb_object_data(git_odb_object *obj);
size_t git_odb_object_size(git_odb_object *obj);
int git_oid__parse(git_oid *oid, const char **buffer, const char *buffer_end, const char *header);
void git_oid_cpy(git_oid *dst, const git_oid *src);
int git_signature__parse(git_signature *sig, const char **buffer, const char *buffer_end, const char *header, char end);