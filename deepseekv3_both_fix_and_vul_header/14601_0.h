#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct ldns_rr ldns_rr;
typedef struct ldns_rdf ldns_rdf;

#define LDNS_XMALLOC(type, size) ((type *) malloc((size) * sizeof(type)))

ldns_rdf* ldns_nsec3_salt(const ldns_rr*);
size_t ldns_rdf_size(const ldns_rdf*);
uint8_t* ldns_rdf_data(const ldns_rdf*);