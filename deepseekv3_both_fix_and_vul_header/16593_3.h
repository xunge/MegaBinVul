#include <stdio.h>
#include <unistd.h>

typedef long ssize_t;
typedef unsigned long long uint64_t;

struct device;
struct device_attribute;

struct iscsi_internal {
    void *iscsi_transport;
};

#define CAP_SYS_ADMIN 0
#define EACCES 13

int capable(int cap);
uint64_t iscsi_handle(void *transport);
struct iscsi_internal *dev_to_iscsi_internal(struct device *dev);