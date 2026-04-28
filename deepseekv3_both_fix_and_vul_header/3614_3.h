#include <limits.h>
#include <stddef.h>

typedef struct _VteTerminal VteTerminal;
typedef struct _GValue GValue;
typedef struct _GValueArray {
    unsigned int n_values;
    struct _GValue *values;
} GValueArray;
typedef void (*VteTerminalSequenceHandler)(VteTerminal *terminal, GValueArray *params);

#define G_MAXLONG LONG_MAX
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define G_VALUE_HOLDS_LONG(value) 1

struct _GValue* g_value_array_get_nth(GValueArray *array, unsigned int index);
long g_value_get_long(const struct _GValue *value);