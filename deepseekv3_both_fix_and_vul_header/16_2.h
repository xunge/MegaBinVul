#include <stdlib.h>
#include <string.h>

typedef struct igraph_vector_bool_t {
    int* stor_begin;
    int* stor_end;
    int* end;
} igraph_vector_bool_t;

typedef struct igraph_vector_t {
    double* stor_begin;
    double* stor_end;
    double* end;
} igraph_vector_t;

typedef struct igraph_strvector_t {
    char** stor_begin;
    char** stor_end;
    char** end;
} igraph_strvector_t;

typedef struct igraph_vector_ptr_t {
    void** stor_begin;
    void** stor_end;
    void** end;
} igraph_vector_ptr_t;

typedef struct igraph_trie_t {
    void* root;
} igraph_trie_t;

typedef enum {
    IGRAPH_ATTRIBUTE_GRAPH,
    IGRAPH_ATTRIBUTE_VERTEX,
    IGRAPH_ATTRIBUTE_EDGE,
    IGRAPH_ATTRIBUTE_BOOLEAN,
    IGRAPH_ATTRIBUTE_NUMERIC,
    IGRAPH_ATTRIBUTE_STRING
} igraph_attribute_elemtype_t;

typedef union {
    int as_boolean;
    double as_numeric;
    const char* as_string;
} igraph_attribute_value_t;

typedef struct igraph_attribute_record_t {
    igraph_attribute_elemtype_t type;
    void* value;
} igraph_attribute_record_t;

typedef struct igraph_i_graphml_attribute_record_t {
    igraph_attribute_record_t record;
    igraph_attribute_value_t default_value;
} igraph_i_graphml_attribute_record_t;

typedef struct igraph_i_graphml_parser_state {
    const char* data_key;
    igraph_attribute_elemtype_t data_type;
    char* data_char;
    igraph_trie_t g_names;
    igraph_trie_t v_names;
    igraph_trie_t e_names;
    igraph_vector_ptr_t g_attrs;
    igraph_vector_ptr_t v_attrs;
    igraph_vector_ptr_t e_attrs;
    long act_node;
    igraph_vector_t edgelist;
} igraph_i_graphml_parser_state;

#define VECTOR(v) ((v).stor_begin)
#define igraph_warningf(...)
#define igraph_Free free
#define RETURN_GRAPHML_PARSE_ERROR_WITH_CODE(state, msg, code) return

static const char* fromXmlChar(const char* str) { return str; }
static int igraph_trie_check(igraph_trie_t* trie, const char* key, long* id) { return 0; }
static long igraph_vector_size(const igraph_vector_t* v) { return v->end - v->stor_begin; }
static long igraph_vector_bool_size(const igraph_vector_bool_t* v) { return v->end - v->stor_begin; }
static long igraph_strvector_size(const igraph_strvector_t* v) { return v->end - v->stor_begin; }
static int igraph_vector_bool_resize(igraph_vector_bool_t* v, long size) { return 0; }
static int igraph_vector_resize(igraph_vector_t* v, long size) { return 0; }
static int igraph_strvector_resize(igraph_strvector_t* v, long size) { return 0; }
static int igraph_strvector_set(igraph_strvector_t* v, long idx, const char* value) { return 0; }
static int igraph_i_graphml_parse_boolean(const char* str, int default_val) { return 0; }
static double igraph_i_graphml_parse_numeric(const char* str, double default_val) { return 0.0; }