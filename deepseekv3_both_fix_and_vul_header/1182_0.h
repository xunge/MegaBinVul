#include <string.h>

typedef char XML_Char;

typedef struct {
  void *(*malloc_fcn)(size_t);
} XML_Memory_Handling_Suite;