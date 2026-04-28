#include <stddef.h>

typedef struct _zval_struct zval;
typedef struct _HashTable {
    // 最小化的HashTable结构定义
    int dummy;
} HashTable;

static HashTable com_dotnet_object_properties;