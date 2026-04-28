#include <stdbool.h>
#include <stddef.h>

typedef struct git_object git_object;
typedef struct git_reference git_reference;
typedef struct git_repository git_repository;
typedef struct git_str git_str;

#define GIT_STR_INIT {0}
#define GIT_ASSERT_ARG(expr) 
#define GIT_ERROR_INVALID 0
#define GIT_ERROR 0
#define GIT_EINVALIDSPEC 0

struct git_str {
    char *ptr;
    size_t size;
    size_t asize;
};

const char *git_str_cstr(const git_str *buf);
void git_str_dispose(git_str *buf);
void git_object_free(git_object *object);
void git_reference_free(git_reference *reference);
void git_error_set(int error_class, const char *message, ...);

int ensure_base_rev_loaded(git_object **base_rev, git_reference **reference, const char *spec, size_t identifier_len, git_repository *repo, bool allow_empty_identifier);
int extract_curly_braces_content(git_str *buf, const char *spec, size_t *pos);
int handle_caret_curly_syntax(git_object **temp_object, git_object *base_rev, const char *content);
int extract_how_many(int *n, const char *spec, size_t *pos);
int handle_caret_parent_syntax(git_object **temp_object, git_object *base_rev, int n);
int handle_linear_syntax(git_object **temp_object, git_object *base_rev, int n);
int extract_path(git_str *buf, const char *spec, size_t *pos);
bool any_left_hand_identifier(git_object *base_rev, git_reference *reference, size_t identifier_len);
int handle_colon_syntax(git_object **temp_object, git_object *base_rev, const char *path);
int handle_grep_syntax(git_object **temp_object, git_repository *repo, git_object *base_rev, const char *path);
int ensure_base_rev_is_not_known_yet(git_object *base_rev);
int handle_at_syntax(git_object **temp_object, git_reference **reference, const char *spec, size_t identifier_len, git_repository *repo, const char *content);
int ensure_left_hand_identifier_is_not_known_yet(git_object *base_rev, git_reference *reference);