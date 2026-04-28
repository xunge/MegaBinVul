#include <stdbool.h>
#include <stddef.h>

struct page_info;

int _put_page_type(struct page_info *page, bool preemptible, void *null);