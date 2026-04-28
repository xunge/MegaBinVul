#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum ldns_status ldns_status;
typedef struct ldns_rr ldns_rr;
typedef struct ldns_rdf ldns_rdf;
typedef struct ldns_buffer {
    uint8_t* _data;
    size_t position;
    size_t limit;
} ldns_buffer;
typedef struct ldns_rr_descriptor ldns_rr_descriptor;
typedef uint16_t ldns_rr_type;
typedef uint16_t ldns_rr_class;

#define LDNS_XMALLOC(type, size) malloc((size) * sizeof(type))
#define LDNS_MALLOC(type) malloc(sizeof(type))
#define LDNS_FREE(ptr) free(ptr)

#define LDNS_MAX_DOMAINLEN 255
#define LDNS_TTL_DATALEN 20
#define LDNS_SYNTAX_DATALEN 20
#define LDNS_MAX_PACKETLEN 65535
#define LDNS_MAX_RDFLEN 1024

#define LDNS_DEFAULT_TTL 3600
#define LDNS_RR_CLASS_IN 1
#define LDNS_RR_TYPE_SOA 6
#define LDNS_RDF_TYPE_B64 0
#define LDNS_RDF_TYPE_HEX 1
#define LDNS_RDF_TYPE_LOC 2
#define LDNS_RDF_TYPE_WKS 3
#define LDNS_RDF_TYPE_IPSECKEY 4
#define LDNS_RDF_TYPE_AMTRELAY 5
#define LDNS_RDF_TYPE_NSEC 6
#define LDNS_RDF_TYPE_LONG_STR 7
#define LDNS_RDF_TYPE_DNAME 8
#define LDNS_RDF_TYPE_HIP 9
#define LDNS_RDF_TYPE_UNKNOWN 10

enum ldns_status {
    LDNS_STATUS_OK,
    LDNS_STATUS_SYNTAX_ERR,
    LDNS_STATUS_SYNTAX_TTL_ERR,
    LDNS_STATUS_SYNTAX_CLASS_ERR,
    LDNS_STATUS_SYNTAX_TYPE_ERR,
    LDNS_STATUS_SYNTAX_RDATA_ERR,
    LDNS_STATUS_SYNTAX_SUPERFLUOUS_TEXT_ERR,
    LDNS_STATUS_SYNTAX_MISSING_VALUE_ERR,
    LDNS_STATUS_MEM_ERR
};

static ldns_rr* ldns_rr_new(void) { return NULL; }
static void ldns_rr_free(ldns_rr* rr) {}
static void ldns_rr_set_owner(ldns_rr* rr, ldns_rdf* rdf) {}
static ldns_rdf* ldns_rr_owner(ldns_rr* rr) { return NULL; }
static void ldns_rr_set_question(ldns_rr* rr, bool question) {}
static void ldns_rr_set_ttl(ldns_rr* rr, uint32_t ttl) {}
static void ldns_rr_set_class(ldns_rr* rr, ldns_rr_class clas) {}
static void ldns_rr_set_type(ldns_rr* rr, ldns_rr_type type) {}
static bool ldns_rr_push_rdf(ldns_rr* rr, ldns_rdf* rdf) { return false; }
static uint16_t ldns_rr_rd_count(ldns_rr* rr) { return 0; }

static ldns_rdf* ldns_rdf_clone(const ldns_rdf* rdf) { return NULL; }
static void ldns_rdf_deep_free(ldns_rdf* rdf) {}
static void ldns_rdf_set_type(ldns_rdf* rdf, uint16_t type) {}
static uint8_t* ldns_rdf_data(ldns_rdf* rdf) { return NULL; }
static size_t ldns_rdf_size(ldns_rdf* rdf) { return 0; }

static ldns_rdf* ldns_dname_new_frm_str(const char* str) { return NULL; }
static bool ldns_dname_str_absolute(const char* str) { return false; }
static ldns_status ldns_dname_cat(ldns_rdf* rdf1, const ldns_rdf* rdf2) { return LDNS_STATUS_OK; }

static ldns_rdf* ldns_rdf_new_frm_str(uint16_t type, const char* str) { return NULL; }

static ldns_buffer* ldns_buffer_new_frm_data(ldns_buffer* buffer, const char* data, size_t size) { return NULL; }
static void ldns_buffer_free(ldns_buffer* buffer) {}
static ssize_t ldns_bget_token(ldns_buffer* buffer, char* token, const char* delimiters, size_t limit) { return 0; }
static char* ldns_buffer_current(ldns_buffer* buffer) { return NULL; }
static void ldns_buffer_skip(ldns_buffer* buffer, size_t count) {}
static size_t ldns_buffer_position(ldns_buffer* buffer) { return 0; }
static size_t ldns_buffer_limit(ldns_buffer* buffer) { return 0; }
static size_t ldns_buffer_remaining(ldns_buffer* buffer) { return 0; }
static bool ldns_buffer_available(ldns_buffer* buffer, size_t count) { return false; }
static void ldns_buffer_set_position(ldns_buffer* buffer, size_t pos) {}

static const ldns_rr_descriptor* ldns_rr_descript(uint16_t type) { return NULL; }
static uint16_t ldns_rr_descriptor_maximum(const ldns_rr_descriptor* desc) { return 0; }
static uint16_t ldns_rr_descriptor_minimum(const ldns_rr_descriptor* desc) { return 0; }
static uint16_t ldns_rr_descriptor_field_type(const ldns_rr_descriptor* desc, uint16_t index) { return 0; }
static bool ldns_rdf_type_maybe_quoted(uint16_t type) { return false; }

static ldns_rr_type ldns_get_rr_type_by_name(const char* name) { return 0; }
static ldns_rr_class ldns_get_rr_class_by_name(const char* name) { return 0; }

static uint32_t ldns_str2period(const char* str, const char** endptr) { return 0; }
static ldns_status ldns_wire2rdf(ldns_rr* rr, uint8_t* data, size_t len, size_t* pos) { return LDNS_STATUS_OK; }
static void ldns_write_uint16(uint8_t* data, uint16_t value) {}
static void ldns_hexstring_to_data(uint8_t* data, const char* str) {}

static size_t strlcpy(char* dst, const char* src, size_t size) { return 0; }

#define sldns_buffer_remaining ldns_buffer_remaining
#define strbuf rd_buf