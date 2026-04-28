#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <limits.h>
#include <err.h>
#include <stdint.h>
#include <locale.h>

struct sem_perm {
    int id;
};

struct sem_elem {
    int semval;
    int ncount;
    int zcount;
    pid_t pid;
};

struct sem_data {
    struct sem_perm sem_perm;
    size_t sem_nsems;
    struct sem_elem *elements;
};

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

extern void *xcalloc(size_t nmemb, size_t size);
extern char *_(const char *msgid);