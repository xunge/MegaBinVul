#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdio.h>

typedef struct Session Session;
typedef struct User User;

struct User {
    char *runtime_path;
    Session *display;
};

struct Session {
    User *user;
    char *display;
    char *id;
};

static char* strappend(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result) {
        strcpy(result, s1);
        strcat(result, s2);
    }
    return result;
}

static int display_is_local(const char *display) {
    return 1;
}

static void mkdir_parents(const char *path, mode_t mode) {
    char *p = strdup(path);
    char *slash = p;

    while ((slash = strchr(slash + 1, '/'))) {
        *slash = '\0';
        mkdir(p, mode);
        *slash = '/';
    }
    free(p);
}

#define new(type, size) malloc(size)
#define log_error(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)
#define log_warning(fmt, ...) fprintf(stderr, "WARNING: " fmt "\n", ##__VA_ARGS__)
#define log_info(fmt, ...) fprintf(stderr, "INFO: " fmt "\n", ##__VA_ARGS__)