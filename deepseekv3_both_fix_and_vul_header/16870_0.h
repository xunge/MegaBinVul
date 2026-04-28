#include <stdlib.h>

typedef struct Sdb Sdb;
void r_cons_println(const char *str);
void R_LOG_ERROR(const char *msg);
char *sdb_querys(Sdb *db, void *null, int zero, const char *input);