#include <sys/types.h>
#include <string.h>

#define MAX_DRC_NAME_LEN 256

struct kobject;
struct kobj_attribute;

extern int dlpar_add_slot(char *drc_name);