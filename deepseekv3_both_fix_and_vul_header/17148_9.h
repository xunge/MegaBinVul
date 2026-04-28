#include <stdint.h>
#include <stdlib.h>

typedef unsigned int guint;
typedef uint32_t guint32;
typedef uint64_t guint64;

typedef struct wmem_allocator_t wmem_allocator_t;

guint check_num_oid(const char* str);
guint32* wmem_alloc0_array(wmem_allocator_t* scope, size_t count);

#define D(level, args)

#define wmem_alloc0_array(scope, type, count) ((type*)wmem_alloc0_array(scope, sizeof(type)*(count)))