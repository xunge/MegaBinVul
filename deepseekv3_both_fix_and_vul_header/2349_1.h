#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

struct page_info;

int _put_page_type(struct page_info *page, bool flag, void *arg);