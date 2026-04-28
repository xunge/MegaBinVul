#include <stdlib.h>

#define INTERNAL static

typedef struct VTerm VTerm;

struct VTermAllocator {
  void (*free)(void *ptr, void *allocdata);
};

struct VTerm {
  struct VTermAllocator *allocator;
  void *allocdata;
};