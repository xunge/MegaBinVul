#include <stddef.h>
#include <stdbool.h>

#define EINTR 4
#define ERESTART 512

struct page {
    // 定义必要的成员
};

struct arch_vcpu {
    struct page *old_guest_table;
    struct page *old_guest_ptpg;
};

struct vcpu {
    struct arch_vcpu arch;
};

int _put_page_type(struct page *page, bool flag, struct page *ptpg);
void put_page(struct page *page);