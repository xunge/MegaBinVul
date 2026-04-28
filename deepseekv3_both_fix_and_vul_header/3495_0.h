#include <stdlib.h>

extern int *bool_pending_values;
extern int bool_num;
extern int bool_maxstr;

int xfree(void *ptr);
int security_get_bools(int *num, void *unused, int **values, ...);