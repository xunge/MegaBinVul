#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
    GF_OK = 0,
    GF_EOS,
    GF_NOT_SUPPORTED,
    GF_OUT_OF_MEM,
    GF_CORRUPTED_DATA
} GF_Err;

typedef enum {
    GF_LOG_ERROR = 0,
    GF_LOG_WARNING,
    GF_LOG_INFO,
    GF_LOG_DEBUG
} GF_LogLevel;

typedef enum {
    GF_LOG_CORE = 0,
    GF_LOG_PARSER,
    GF_LOG_CODEC
} GF_LogModule;

typedef enum {
    SAX_STATE_TEXT_CONTENT,
    SAX_STATE_ELEMENT,
    SAX_STATE_ATT_NAME,
    SAX_STATE_ATT_VALUE,
    SAX_STATE_COMMENT,
    SAX_STATE_ENTITY,
    SAX_STATE_SKIP_DOCTYPE,
    SAX_STATE_XML_PROC,
    SAX_STATE_CDATA,
    SAX_STATE_SYNTAX_ERROR,
    SAX_STATE_ALLOC_ERROR,
    SAX_STATE_DONE
} SAX_State;

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1
#define XML_INPUT_SIZE 4096

static void GF_LOG(GF_LogLevel level, GF_LogModule module, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

typedef struct {
    u32 current_pos;
    u32 line_size;
    u32 line;
    u32 file_pos;
    u32 elt_name_start;
    u32 elt_name_end;
    u32 elt_start_pos;
    u32 elt_end_pos;
    u32 text_check_escapes;
    u32 init_state;
    u32 ent_rec_level;
    Bool suspended;
    SAX_State sax_state;
    char *buffer;
    void *entities;
} GF_SAXParser;

static void xml_sax_store_text(GF_SAXParser *parser, u32 len) {}
static void xml_sax_flush_text(GF_SAXParser *parser) {}
static void xml_sax_node_start(GF_SAXParser *parser) {}
static void xml_sax_node_end(GF_SAXParser *parser, Bool flag) {}
static void xml_sax_swap(GF_SAXParser *parser) {}
static Bool xml_sax_parse_comments(GF_SAXParser *parser) { return GF_TRUE; }
static Bool xml_sax_parse_attribute(GF_SAXParser *parser) { return GF_FALSE; }
static void xml_sax_parse_entity(GF_SAXParser *parser) {}
static void xml_sax_skip_doctype(GF_SAXParser *parser) {}
static void xml_sax_skip_xml_proc(GF_SAXParser *parser) {}
static void xml_sax_cdata(GF_SAXParser *parser) {}
static GF_Err gf_xml_sax_parse_intern(GF_SAXParser *parser, char *buf) { return GF_OK; }

static char *gf_strdup(const char *str) { return NULL; }
static void gf_free(void *ptr) {}
static u32 gf_list_count(void *list) { return 0; }