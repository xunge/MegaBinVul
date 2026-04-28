#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>

#define DEFAULT_THP_HASH "SHA-256"
#define PATH_MAX 4096

typedef void* json_auto_t;

void cleanup_str(char **str);
json_auto_t* jwk_generate(const char *alg);
char* jwk_thumbprint(json_auto_t *jwk, const char *hash);
int json_dump_file(json_auto_t *jwk, const char *path, int flags);