#include <stdatomic.h>
#include <stdio.h>

struct mdev_type;
struct mdev_type_attribute;
struct mbochs_type {
    int mbytes;
};

extern struct mbochs_type mbochs_types[];
extern atomic_int mbochs_avail_mbytes;
extern int max_mbytes;
extern int mbochs_used_mbytes;

int mtype_get_type_group_id(struct mdev_type *mtype);