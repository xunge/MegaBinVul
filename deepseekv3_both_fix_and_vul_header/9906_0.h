#include <string.h>

typedef struct String String;
void AddDef(String *buff, char *title, char *value);
void addstring(String *buff, const char *str);

extern int need_real_defines;