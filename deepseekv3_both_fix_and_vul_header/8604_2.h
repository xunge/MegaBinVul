#include <stdlib.h>

struct seq_file {
    void *private;
};

struct class_dev_iter;

void class_dev_iter_exit(struct class_dev_iter *iter);
void kfree(const void *objp);