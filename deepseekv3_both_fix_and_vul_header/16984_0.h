#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef enum {
    GF_OK = 0,
    GF_OTHER_ERROR
} GF_Err;
#define GF_TRUE 1
#define GF_FALSE 0

typedef struct {
    char *value;
    u32 namelen;
} XML_Entity;

typedef struct {
    u32 line;
    u32 line_size;
    char *buffer;
    Bool in_entity;
    void *entities;
} GF_SAXParser;

static GF_Err xml_sax_append_string(GF_SAXParser *parser, char *str);
static GF_Err xml_sax_parse(GF_SAXParser *parser, Bool flag);
static XML_Entity *gf_xml_locate_entity(GF_SAXParser *parser, char *name, Bool *needs_text);
static u32 gf_list_count(void *list);
static void *gf_malloc(size_t size);
static void gf_free(void *ptr);