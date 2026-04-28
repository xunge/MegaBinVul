#include <stddef.h>
#include <string.h>

typedef struct SEQSET_ITERATOR {
  char *substr_cur;
  char *substr_end;
  char *eostr;
  unsigned int range_cur;
  unsigned int range_end;
  int in_range;
  int down;
} SEQSET_ITERATOR;

int mutt_atoui(const char *str, unsigned int *dst);