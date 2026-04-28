#include <stdbool.h>

typedef void* Dwarf_Debug;
typedef bool Dwarf_Bool;

static void _dwarf_printf(Dwarf_Debug dbg, const char *format, ...);