#include <stdio.h>
#include <stddef.h>

struct kobject;
struct bin_attribute;
typedef long long loff_t;
typedef unsigned long size_t;
typedef long ssize_t;

struct rbu_data_type {
    int lock;
    unsigned long packetsize;
};

static struct rbu_data_type rbu_data;

#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0