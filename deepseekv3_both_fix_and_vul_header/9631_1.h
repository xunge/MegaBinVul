#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <assert.h>

enum try_read_result {
    READ_NO_DATA_RECEIVED,
    READ_DATA_RECEIVED,
    READ_MEMORY_ERROR,
    READ_ERROR
};

typedef struct conn {
    char *rbuf;
    char *rcurr;
    int rsize;
    int rbytes;
    int sfd;
    struct {
        struct {
            pthread_mutex_t mutex;
            size_t bytes_read;
        } stats;
    } *thread;
    int write_and_go;
} conn;

struct settings {
    int verbose;
};

extern struct settings settings;

void out_string(conn *c, const char *str);

enum conn_states {
    conn_closing
};