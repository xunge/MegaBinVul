#include <stdio.h>
#include <string.h>
#include <strings.h>

extern void gf_cfg_del_section(void *cfg_file, char *section);
extern void gf_cfg_set_key(void *cfg_file, char *section, char *key, char *value);
extern void *cfg_file;