#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

extern char* output;
extern char* filename;
extern double percent;

struct assnode {
    char abbrev[16];
    double val;
    struct assnode* next;
};
extern struct assnode* asshead;
extern struct assnode* edges;
extern struct assnode* density;
extern struct assnode* reciprocity;
extern struct assnode* degcent;
extern struct assnode* clustering;
extern struct assnode* diameter;
extern struct assnode* pathlength;
extern struct assnode* betcent;
extern struct assnode* pagecent;

typedef struct {
    void* data;
} igraph_t;

typedef struct {
    void* data;
} igraph_vector_t;

typedef struct {
    void* data;
} igraph_strvector_t;

extern igraph_t g;

#define STR(v, i) ""
#define GAN(g, attr) 0.0

static inline void igraph_vector_init(igraph_vector_t* v, int n) {}
static inline void igraph_strvector_init(igraph_strvector_t* v, int n) {}
static inline void igraph_cattribute_list(igraph_t* g, igraph_strvector_t* gnames, 
                                        igraph_vector_t* gtypes, igraph_strvector_t* vnames,
                                        igraph_vector_t* vtypes, igraph_strvector_t* enames,
                                        igraph_vector_t* etypes) {}
static inline int igraph_strvector_size(igraph_strvector_t* v) { return 0; }
static inline void igraph_vector_destroy(igraph_vector_t* v) {}
static inline void igraph_strvector_destroy(igraph_strvector_t* v) {}