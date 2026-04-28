#include <stdio.h>
#include <string.h>

#define DEBUG_printf(x)
#define OUTPUT_BOOK 1

extern int num_pages;
extern int chapter;
extern int OutputType;
extern int title_page;
extern int *chapter_starts;
extern double PagePrintWidth;
extern double PagePrintLength;
extern double HeadFootSize;

struct {
    int landscape;
    double width;
    double length;
    double right;
    double left;
    double top;
    double bottom;
    char *header[3];
    char *header1[3];
    char *footer[3];
    char page_text[64];
} *pages;

char *format_number(int num, char type);
void pspdf_prepare_heading(int page, int print_page, char **heading, int top, char *page_text, size_t size);
size_t strlcpy(char *dst, const char *src, size_t size);