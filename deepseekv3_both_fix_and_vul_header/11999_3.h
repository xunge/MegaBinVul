#include <stdlib.h>

typedef struct bfd bfd;

struct module {
    unsigned int file_table_count;
    struct fileinfo *file_table;
};

struct fileinfo {
    // 添加必要的成员变量
    int dummy;  // 示例成员
};

void *bfd_zalloc(bfd *abfd, size_t size);
void *bfd_malloc(size_t size);