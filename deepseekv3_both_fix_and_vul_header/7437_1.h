#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define OUTPUT_BOOK 0

typedef struct {
    int nup;
    int pages[];
} outpage_t;

typedef struct {
    int nup;
    int width;
    int length;
    int outpage;
} page_t;

extern outpage_t *outpages;
extern int num_pages;
extern int num_outpages;
extern int TitlePage;
extern page_t *pages;
extern int chapter_starts[];
extern int chapter_outstarts[];
extern int chapter_ends[];
extern int chapter_outends[];
extern int OutputType;
extern int TocLevels;
extern int TocDocCount;
extern int num_headings;
extern int heading_pages[];
extern int num_links;

typedef struct {
    char *name;
    int page;
} link_t;

extern link_t *links;

void pspdf_transform_page(int outpage_num, int pos, int page_num);