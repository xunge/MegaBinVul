#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define EX_SYSERR 1

#define CRED_USER 1
#define CRED_PASS 2
#define CRED_DOM 3
#define CRED_UNPARSEABLE 4

struct parsed_mount_info {
    char username[256];
    char domain[256];
    int got_user;
    int verboseflag;
};

int toggle_dac_capability(int a, int b);
void null_terminate_endl(char *str);
int parse_cred_line(char *line, char **value);
int set_password(struct parsed_mount_info *info, char *password);
size_t strlcpy(char *dst, const char *src, size_t size);