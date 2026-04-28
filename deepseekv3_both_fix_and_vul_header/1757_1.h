#include <stddef.h>

enum migrate_mode {
    MIGRATE_SYNC_NO_COPY
};

struct address_space;
struct folio;

#define BUG_ON(condition) ((void)0)
#define MIGRATEPAGE_SUCCESS 0

static inline int folio_test_writeback(struct folio *folio) { return 0; }
static inline int folio_migrate_mapping(struct address_space *mapping, struct folio *dst, struct folio *src, int flags) { return 0; }
static inline void folio_migrate_copy(struct folio *dst, struct folio *src) {}
static inline void folio_migrate_flags(struct folio *dst, struct folio *src) {}