#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

typedef struct {
    int server;
    char *control_socket_path;
} Fep;

enum {
    FEP_LOG_LEVEL_WARNING
};

void fep_log(int level, const char *format, ...);
char *create_socket_name(const char *template);
void remove_control_socket(const char *path);