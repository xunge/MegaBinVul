#include <stdbool.h>

struct page;
bool PageCompound(struct page *page);
bool is_zone_device_page(struct page *page);
void *page_mapping(struct page *page);
int page_has_private(struct page *page);
int page_count(struct page *page);
int page_mapcount(struct page *page);