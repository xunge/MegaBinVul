#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct igraph_t {
    int n;
    int directed;
    void *from;
    void *to;
    void *oi;
    void *ii;
    void *os;
    void *is;
    void *attr;
} igraph_t;

typedef void (*igraph_error_handler_t)(const char* reason, const char* file, int line);
typedef void (*igraph_warning_handler_t)(const char* reason, const char* file, int line);

typedef struct igraph_attribute_table_t {
    void (*init)(igraph_t*);
    void (*destroy)(igraph_t*);
    void (*copy)(igraph_t*, const igraph_t*);
    void (*add_vertices)(igraph_t*, int);
    void (*add_edges)(igraph_t*, const void*);
} igraph_attribute_table_t;

extern igraph_attribute_table_t igraph_cattribute_table;

extern igraph_error_handler_t igraph_error_handler_ignore;
extern igraph_error_handler_t igraph_error_handler_abort;
extern igraph_warning_handler_t igraph_warning_handler_ignore;

void igraph_i_set_attribute_table(igraph_attribute_table_t* table);
igraph_error_handler_t* igraph_set_error_handler(igraph_error_handler_t* handler);
igraph_warning_handler_t* igraph_set_warning_handler(igraph_warning_handler_t* handler);
int igraph_read_graph_graphml(igraph_t* graph, FILE* instream, int index);
int igraph_write_graph_graphml(const igraph_t* graph, FILE* outstream, int prefixattr);
void igraph_destroy(igraph_t* graph);
void dump_graph(const char* msg, const igraph_t* g);
void dump_vertex_attribute_bool(const char* attr, const igraph_t* g);
void dump_vertex_attribute_string(const char* attr, const igraph_t* g);
void dump_vertex_attribute_numeric(const char* attr, const igraph_t* g);
void custom_warning_handler(const char* reason, const char* file, int line);

#define IGRAPH_UNIMPLEMENTED 1
#define IGRAPH_PARSEERROR 2