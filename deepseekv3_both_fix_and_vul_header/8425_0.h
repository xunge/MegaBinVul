#include <stddef.h>
#include <string.h>

#define ZEND_DEBUG 0
#define UNEXPECTED(condition) (condition)
#define EXPECTED(condition) (condition)
#define ZEND_MM_ALIGNED_OFFSET(ptr, alignment) ((size_t)(ptr) & (alignment - 1))
#define ZEND_MM_ALIGNED_BASE(ptr, alignment) ((void *)((size_t)(ptr) & ~(size_t)(alignment - 1)))
#define ZEND_MM_ALIGNED_SIZE(size) (((size) + (sizeof(void*) - 1)) & ~(sizeof(void*) - 1))
#define ZEND_MM_ALIGNED_SIZE_EX(size, alignment) (((size) + (alignment - 1)) & ~(alignment - 1))
#define ZEND_MM_MAX_LARGE_SIZE (2 * 1024 * 1024)
#define ZEND_MM_MAX_SMALL_SIZE (3072)
#define ZEND_MM_CHUNK_SIZE (2 * 1024 * 1024)
#define ZEND_MM_PAGE_SIZE (4096)
#define ZEND_MM_PAGES (ZEND_MM_CHUNK_SIZE / ZEND_MM_PAGE_SIZE)
#define REAL_PAGE_SIZE (4096)
#define ZEND_WIN32 0
#define ZEND_MM_STAT 0
#define ZEND_MM_LIMIT 0
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct _zend_mm_heap zend_mm_heap;
typedef struct _zend_mm_chunk zend_mm_chunk;
typedef struct _zend_mm_debug_info zend_mm_debug_info;
typedef size_t zend_mm_page_info;

struct _zend_mm_heap {
    size_t real_size;
    size_t size;
    size_t peak;
    size_t real_peak;
    size_t limit;
    int overflow;
};

struct _zend_mm_chunk {
    zend_mm_heap *heap;
    zend_mm_page_info map[ZEND_MM_PAGES];
    int free_pages;
    unsigned int free_map[ZEND_MM_PAGES / (8 * sizeof(unsigned int))];
};

struct _zend_mm_debug_info {
    size_t size;
    const char *filename;
    const char *orig_filename;
    int lineno;
    int orig_lineno;
};

#define ZEND_MM_IS_SRUN (1 << 0)
#define ZEND_MM_IS_LARGE_RUN (1 << 1)
#define ZEND_MM_SRUN_BIN_NUM(info) ((info) >> 2)
#define ZEND_MM_LRUN_PAGES(info) ((info) >> 2)
#define ZEND_MM_LRUN(pages) ((pages) << 2 | ZEND_MM_IS_LARGE_RUN)
#define ZEND_MM_SMALL_SIZE_TO_BIN(size) (0)
#define ZEND_MM_CHECK(condition, message)

static size_t bin_data_size[] = {0};

static void *zend_mm_alloc_heap(zend_mm_heap *heap, size_t size);
static void zend_mm_free_heap(zend_mm_heap *heap, void *ptr);
static size_t zend_mm_get_huge_block_size(zend_mm_heap *heap, void *ptr);
static void zend_mm_change_huge_block_size(zend_mm_heap *heap, void *ptr, size_t size);
static int zend_mm_chunk_truncate(zend_mm_heap *heap, void *ptr, size_t old_size, size_t new_size);
static int zend_mm_chunk_extend(zend_mm_heap *heap, void *ptr, size_t old_size, size_t new_size);
static zend_mm_debug_info *zend_mm_get_debug_info(zend_mm_heap *heap, void *ptr);
static void zend_mm_safe_error(zend_mm_heap *heap, const char *format, ...);
static int zend_mm_gc(zend_mm_heap *heap);
static void zend_mm_bitset_reset_range(unsigned int *bitset, int start, int count);
static int zend_mm_bitset_is_free_range(unsigned int *bitset, int start, int count);
static void zend_mm_bitset_set_range(unsigned int *bitset, int start, int count);

#define ZEND_FILE_LINE_DC
#define ZEND_FILE_LINE_ORIG_DC
#define ZEND_FILE_LINE_RELAY_CC
#define ZEND_FILE_LINE_ORIG_RELAY_CC