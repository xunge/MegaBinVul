#include <stdio.h>
#include <string.h>
#include <strings.h>

typedef unsigned char uchar;

#define PDF_PAGE_1 0
#define PDF_TOC 1
#define PDF_CHAPTER_1 2
#define OUTPUT_BOOK 0

typedef struct {
    uchar *header[3];
    uchar *footer[3];
} page_t;

extern int PSLevel;
extern int PDFVersion;
extern int PDFPageLayout;
extern int PDFPageMode;
extern int PDFFirstPage;
extern int TitlePage;
extern int TocLevels;
extern int NumberUp;
extern int OutputType;
extern int TocDocCount;
extern int pages_object;
extern int names_object;
extern int outline_object;
extern int root_object;
extern int info_object;
extern int encrypt_object;
extern int chapter_outstarts[];
extern int chapter_starts[];
extern int chapter_ends[];
extern size_t num_objects;
extern int objects[];
extern uchar file_id[16];
extern int Encryption;
extern char *TocHeader[3];
extern char *TocFooter[3];
extern page_t *pages;

extern int pdf_start_object(FILE *out);
extern void pdf_end_object(FILE *out);
extern void write_string(FILE *out, uchar *str, int quote);
extern size_t strlcpy(char *dst, const char *src, size_t siz);