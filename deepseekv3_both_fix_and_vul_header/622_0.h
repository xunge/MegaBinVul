#include <stdio.h>
#include <stdlib.h>

typedef unsigned short unichar_t;

typedef struct GTextField {
    unichar_t *text;
} GTextField;

extern int _ggadget_use_gettext;
extern char *GWidgetOpenFile8(const char *title, const char *default_name, const char *filter, const char *ext, const char *dir);
extern unichar_t *GWidgetSaveAsFile(const char *title, const char *default_name, const char *filter, const char *ext, const char *dir);
extern unichar_t *utf82u_copy(const char *utf8);
extern char *u2def_copy(const unichar_t *u);
extern void GWidgetError8(const char *title, const char *format, const char *arg);
extern void GWidgetError(const char *title, const char *format, const char *arg);
extern const char *_STR_Save;
extern const char *errort;
extern const char *error;
extern const char *txt;