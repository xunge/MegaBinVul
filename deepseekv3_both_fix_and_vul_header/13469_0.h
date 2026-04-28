#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned int u32;
typedef int Bool;
typedef int GF_Err;

#define GF_TRUE 1
#define GF_FALSE 0

typedef struct {
    char *value;
    u32 namelen;
} XML_Entity;

typedef struct {
    u32 line;
    u32 line_size;
    Bool in_entity;
    char *buffer;
    void *entities;
} GF_SAXParser;

GF_Err xml_sax_append_string(GF_SAXParser *parser, char *current);
GF_Err xml_sax_parse(GF_SAXParser *parser, Bool flag);
XML_Entity *gf_xml_locate_entity(GF_SAXParser *parser, char *name, Bool *needs_text);
u32 gf_list_count(void *list);
void *gf_malloc(size_t size);
void gf_free(void *ptr);