#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct mmd_s mmd_t;
typedef struct mxml_node_s mxml_node_t;

#define OUTPUT_HTML 0
#define MXML_DESCEND_FIRST 0

static void markdown_write_block(FILE *out, mmd_t *body, int mode);
static void write_file(FILE *out, const char *bodyfile, int mode);
static mxml_node_t *find_public(mxml_node_t *start, mxml_node_t *top, const char *element, const char *name, int mode);
static void write_scu(FILE *out, int mode, mxml_node_t *doc, mxml_node_t *scut);
static void write_function(FILE *out, int mode, mxml_node_t *doc, mxml_node_t *function, int indent);
static const char *get_comment_info(mxml_node_t *description);
static void write_description(FILE *out, int mode, mxml_node_t *description, const char *element, int indent);
static void write_string(FILE *out, const char *string, int output_type, int indent);
static void write_element(FILE *out, mxml_node_t *doc, mxml_node_t *element, int output_type);