#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct Session Session;
typedef struct User User;

struct User {
    Session *display;
    char *runtime_path;
};

struct Session {
    User *user;
};