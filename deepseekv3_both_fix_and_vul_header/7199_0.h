#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DLT_CTRL_ECUID_LEN 128

extern char local_ecuid[DLT_CTRL_ECUID_LEN];
extern int dlt_parse_config_param(const char *key, char **value);
extern void pr_error(const char *msg);