#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>

typedef void* plist_t;

typedef struct {
    char* in_file;
    char* out_file;
} options_t;

options_t* parse_arguments(int argc, char *argv[]);
void print_usage(int argc, char *argv[]);
void plist_from_bin(const char *plist_bin, uint32_t length, plist_t *plist);
void plist_from_xml(const char *plist_xml, uint32_t length, plist_t *plist);
void plist_to_xml(plist_t plist, char **plist_xml, uint32_t *length);
void plist_to_bin(plist_t plist, char **plist_bin, uint32_t *length);
void plist_free(plist_t plist);