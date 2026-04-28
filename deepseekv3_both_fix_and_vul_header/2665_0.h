#include <string.h>

typedef struct fz_xml fz_xml;
typedef struct fz_css_selector fz_css_selector;
typedef struct fz_css_condition fz_css_condition;

struct fz_css_selector {
    char combine;
    fz_css_selector *left;
    fz_css_selector *right;
    char *name;
    fz_css_condition *cond;
};

static int match_condition(fz_css_condition *cond, fz_xml *node);

fz_xml *fz_xml_up(fz_xml *node);
fz_xml *fz_xml_prev(fz_xml *node);
char *fz_xml_tag(fz_xml *node);