#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct tcpr_cidrmap_t tcpr_cidrmap_t;

char *safe_strdup(const char *s);
void safe_free(void *ptr);
int parse_cidr_map(tcpr_cidrmap_t **cidrmap, const char *map);
size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);