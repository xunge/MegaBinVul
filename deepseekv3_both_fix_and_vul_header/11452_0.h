#include <stdint.h>
#include <unistd.h>

typedef struct Dwarf_Die Dwarf_Die;
typedef struct Dwarf_Abbrev Dwarf_Abbrev;

#define unlikely(cond) (cond)
#define DWARF_END_ABBREV ((Dwarf_Abbrev *) -1l)
#define DWARF_E_INVALID_DWARF (-1)
#define DW_FORM_implicit_const (0x21)

Dwarf_Abbrev *__libdw_dieabbrev (Dwarf_Die *, void *);
void __libdw_seterrno (int);

#define get_uleb128_unchecked(var, ptr) \
  (var) = *(ptr)++; if ((var) >= 0x80) { /* Handle multibyte */ }

#define get_sleb128_unchecked(var, ptr) \
  (var) = *(ptr)++; if ((var) >= 0x80) { /* Handle multibyte */ }

struct Dwarf_Abbrev {
  const unsigned char *attrp;
};