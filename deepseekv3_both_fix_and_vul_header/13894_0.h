#include <stddef.h>

typedef struct xps_font_s xps_font_t;

struct xps_font_s {
    // Placeholder for actual font structure members
};

int xps_count_font_encodings(xps_font_t *font);
void xps_identify_font_encoding(xps_font_t *font, int i, int *pid, int *eid);
int xps_select_font_encoding(xps_font_t *font, int i);
void gs_warn(const char *msg);