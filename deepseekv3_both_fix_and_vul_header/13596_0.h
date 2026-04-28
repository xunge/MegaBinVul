#include <string.h>

typedef struct _StringInfo {
    char *datum;
    size_t length;
} StringInfo;

size_t GetStringInfoLength(const StringInfo *info);
char* GetStringInfoDatum(StringInfo *info);
void SetStringInfoLength(StringInfo *info, size_t length);