#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct HINSTANCE__;

typedef struct {
    unsigned int dwSize;
    unsigned int dwICC;
} INITCOMMONCONTROLSEX;

#define ICC_WIN95_CLASSES 0x000000FF
#define FALSE 0

extern int __argc;
extern char **__argv;

extern void ws_init_dll_search_path(void);
extern void ws_load_library(const char *libname);
extern void set_has_console(int has_console);
extern void set_console_wait(int console_wait);
extern int main(int argc, char **argv);

int InitCommonControlsEx(void *lpInitCtrls);

#define _stdcall __attribute__((stdcall))