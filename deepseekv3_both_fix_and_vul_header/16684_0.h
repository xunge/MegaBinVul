#include <string.h>
#include <sys/types.h>

#define MAX_DRC_NAME_LEN 64

struct kobject;
struct kobj_attribute;

extern int dlpar_remove_slot(char *drc_name);