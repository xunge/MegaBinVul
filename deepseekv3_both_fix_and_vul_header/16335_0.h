#include <stdbool.h>

struct files_struct;
struct io_wq_work {
    struct files_struct *files;
};