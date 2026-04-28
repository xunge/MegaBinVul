#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define DEBUG_MSG(msg)
#define ETH_ASCII_ADDR_LEN 17
#define IP6_ASCII_ADDR_LEN 39
#define PARAMS_LEN 256

#define FALSE 0
#define TRUE 1
#define GTK_DIALOG_MODAL 1
#define GTK_STOCK_OK 1
#define GTK_RESPONSE_OK 1
#define GTK_STOCK_CANCEL 2
#define GTK_RESPONSE_CANCEL 2
#define GTK_STOCK_DIALOG_QUESTION 3
#define GTK_ICON_SIZE_DIALOG 4
#define GTK_FILL 1

typedef void* GtkWidget;
typedef int gint;

typedef struct {
    void *vbox;
} GtkDialog;

#define GTK_WINDOW(w) ((void*)w)
#define GTK_CONTAINER(w) ((void*)w)
#define GTK_DIALOG(w) ((GtkDialog*)w)
#define GTK_BOX(w) ((void*)w)
#define GTK_MISC(w) ((void*)w)
#define GTK_TABLE(w) ((void*)w)
#define GTK_ENTRY(w) ((void*)w)

extern GtkWidget *window;
extern char params[PARAMS_LEN];
extern void gtkui_start_mitm(void);