#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_ENTRIES 1024
#define MAX_ENTRY_LEN 1024

enum authfile_ret {
    AUTHFILE_OK,
    AUTHFILE_OPENFAIL,
    AUTHFILE_STATFAIL,
    AUTHFILE_MALFORMED
};

typedef struct {
    char *user;
    int ulen;
    char *pass;
    int plen;
} auth_t;

extern auth_t main_auth_entries[MAX_ENTRIES];
extern char *main_auth_data;
extern int entry_cnt;