#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define HIDE_ERRORED_LINE_CONTENT 0

typedef struct dictionary dictionary;
typedef struct nio_t nio_t;
typedef struct bridge_t {
    nio_t *source_nio;
    nio_t *destination_nio;
    char *name;
} bridge_t;

bridge_t *add_bridge(bridge_t **bridges);
void free_nio(nio_t *nio);
void parse_capture(dictionary *config, const char *section, bridge_t *bridge);
void parse_filter(dictionary *config, const char *section, bridge_t *bridge);
int getstr(dictionary *ini, const char *section, const char *key, const char **value);