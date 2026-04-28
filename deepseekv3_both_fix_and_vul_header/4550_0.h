#include <stdlib.h>

typedef struct _spl_ptr_heap spl_ptr_heap;
typedef void *spl_ptr_heap_element;

struct _spl_ptr_heap {
    void **elements;
    int count;
    int max_size;
    int flags;
    void (*ctor)(spl_ptr_heap_element TSRMLS_DC);
    int (*cmp)(spl_ptr_heap_element, spl_ptr_heap_element, void * TSRMLS_DC);
};

#define TSRMLS_DC
#define TSRMLS_CC
#define EG(exception) (0)
#define SPL_HEAP_CORRUPTED (1 << 0)

void *safe_erealloc(void *ptr, size_t size, size_t count, size_t new_size);