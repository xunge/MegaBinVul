#include <stdlib.h>
#include <string.h>

typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pj_list {
    struct pj_list *prev;
    struct pj_list *next;
} pj_list;

typedef struct pj_pool_t {
    void *dummy;
} pj_pool_t;

typedef struct pj_scanner {
    char *curptr;
} pj_scanner;

typedef struct pj_xml_node {
    pj_str_t name;
    pj_str_t content;
    pj_list attr_head;
    pj_list node_head;
} pj_xml_node;

typedef struct pj_xml_attr {
    pj_str_t name;
    pj_str_t value;
    pj_list list;
} pj_xml_attr;

#define PJ_FALSE 0
#define PJ_TRUE 1
#define PJ_CHECK_STACK()

static void on_syntax_error(pj_scanner *scanner);
static pj_xml_node *alloc_node(pj_pool_t *pool);
static pj_xml_attr *alloc_attr(pj_pool_t *pool);
static int pj_scan_strcmp(pj_scanner *scanner, const char *s, int len);
static void pj_scan_advance_n(pj_scanner *scanner, int n, int skip_ws);
static void pj_scan_get_until_ch(pj_scanner *scanner, char ch, pj_str_t *out);
static void pj_scan_get_until_chr(pj_scanner *scanner, const char *delim, pj_str_t *out);
static char pj_scan_get_char(pj_scanner *scanner);
static void pj_scan_get_quotes(pj_scanner *scanner, const char *start_quote, const char *end_quote, int len, pj_str_t *out);
static int pj_scan_is_eof(pj_scanner *scanner);
static int pj_stricmp(const pj_str_t *s1, const pj_str_t *s2);
static void pj_list_push_back(pj_list *list, void *item);