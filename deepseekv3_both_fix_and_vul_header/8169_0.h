#include <stddef.h>

struct page;
#define PageHuge(page) (0)
#define PageTransHuge(page) (0)
#define PageError(page) (0)
#define PageReferenced(page) (0)
#define PageUptodate(page) (0)
#define PageUnevictable(page) (0)
#define PageChecked(page) (0)
#define PageMappedToDisk(page) (0)
#define PageDirty(page) (0)
#define PageSwapBacked(page) (0)
#define PageSwapCache(page) (0)
#define PagePrivate(page) (0)
#define PageWriteback(page) (0)
#define PageActive(page) (0)
#define VM_BUG_ON_PAGE(cond, page) do { } while (0)

void copy_huge_page(struct page *newpage, struct page *page);
void copy_highpage(struct page *newpage, struct page *page);
void SetPageError(struct page *page);
void SetPageReferenced(struct page *page);
void SetPageUptodate(struct page *page);
void SetPageActive(struct page *page);
void SetPageUnevictable(struct page *page);
void SetPageChecked(struct page *page);
void SetPageMappedToDisk(struct page *page);
void SetPageDirty(struct page *page);
void __set_page_dirty_nobuffers(struct page *page);
int TestClearPageActive(struct page *page);
int TestClearPageUnevictable(struct page *page);
void clear_page_dirty_for_io(struct page *page);
int page_is_young(struct page *page);
void set_page_young(struct page *page);
int page_is_idle(struct page *page);
void set_page_idle(struct page *page);
int page_cpupid_xchg_last(struct page *page, int cpupid);
void ksm_migrate_page(struct page *newpage, struct page *page);
void ClearPageSwapCache(struct page *page);
void ClearPagePrivate(struct page *page);
void set_page_private(struct page *page, unsigned long private);
void end_page_writeback(struct page *page);