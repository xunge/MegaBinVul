#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define BUSID_SIZE 32
#define STUB_BUSID_OTHER 0
#define STUB_BUSID_ADDED 1
#define STUB_BUSID_REMOV 2

struct busid_entry {
    char name[BUSID_SIZE];
    int status;
    pthread_spinlock_t busid_lock;
};

struct busid_entry *busid_table;
pthread_spinlock_t busid_table_lock;

int get_busid_idx(char *busid);