#include <string.h>
#include <stdio.h>
#include <math.h>

typedef unsigned char xmlChar;

typedef struct _SVGInfo SVGInfo;

struct _SVGInfo {
    FILE *file;
    char *text;
    char *url;
    char *stop_color;
    char *offset;
    char *title;
    char *vertices;
    struct {
        double cx;
        double cy;
        double minor;
        double major;
        double angle;
    } element;
    struct {
        double x1;
        double y1;
        double x2;
        double y2;
    } segment;
    struct {
        double x;
        double y;
        double width;
        double height;
    } bounds;
    struct {
        double x;
        double y;
    } radius;
    struct {
        double x;
        double y;
    } center;
    int svgDepth;
    int n;
};

enum {
    CoderEvent
};

#define MagickTrue 1
#define MagickFalse 0

extern const char *GetMagickModule(void);
extern void LogMagickEvent(int, const char *, const char *, ...);
extern int LocaleCompare(const char *, const char *);
extern int FormatLocaleFile(FILE *, const char *, ...);
extern void SVGStripString(int, char *);
extern char *EscapeString(char *, char);
extern char *DestroyString(char *);
extern char *CloneString(char **, const char *);
extern void SVGProcessStyleElement(void *, const xmlChar *, char *);
extern char **SVGKeyValuePairs(void *, char, char, char *, size_t *);
extern double MagickEpsilon;