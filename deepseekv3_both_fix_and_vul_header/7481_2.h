#include <stdlib.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define PAGECACHE_TAG_DIRTY 0
#define WB_SYNC_NONE 0
#define CONFIG_AFS_FSCACHE 1

typedef unsigned long pgoff_t;

struct address_space {
    // dummy structure
};

struct writeback_control {
    int sync_mode;
    int nr_to_write;
};

struct page {
    // dummy structure
};

struct folio {
    // dummy structure
};

#define _enter(fmt, ...)
#define _debug(fmt, ...)
#define _leave(fmt, ...)
#define BUG() abort()

static int find_get_pages_range_tag(struct address_space *mapping, pgoff_t *index,
                                   pgoff_t end, int tag, int nr_pages, struct page **pages) {
    return 0;
}

static struct folio *page_folio(struct page *page) {
    return (struct folio *)page;
}

static loff_t folio_pos(struct folio *folio) {
    return 0;
}

static unsigned long folio_index(struct folio *folio) {
    return 0;
}

static int folio_lock_killable(struct folio *folio) {
    return 0;
}

static void folio_put(struct folio *folio) {
}

static int folio_trylock(struct folio *folio) {
    return 1;
}

static struct address_space *folio_mapping(struct folio *folio) {
    return NULL;
}

static int folio_test_dirty(struct folio *folio) {
    return 0;
}

static size_t folio_size(struct folio *folio) {
    return PAGE_SIZE;
}

static void folio_unlock(struct folio *folio) {
}

static int folio_test_writeback(struct folio *folio) {
    return 0;
}

static int folio_test_fscache(struct folio *folio) {
    return 0;
}

static void folio_wait_writeback(struct folio *folio) {
}

static void folio_wait_fscache(struct folio *folio) {
}

static int folio_clear_dirty_for_io(struct folio *folio) {
    return 1;
}

static ssize_t afs_write_back_from_locked_folio(struct address_space *mapping,
                                              struct writeback_control *wbc,
                                              struct folio *folio,
                                              loff_t start, loff_t end) {
    return 0;
}

static void cond_resched(void) {
}