#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filter_op {
   int opcode;
};

struct unfold_elm {
   int label;
   struct filter_op fop;
   struct unfold_elm *next;
};

extern struct unfold_elm *tree_root;
extern struct unfold_elm unfolded_tree;

#define BUG_IF(expr) if (expr) abort()
#define SAFE_REALLOC(ptr, size) \
   do { \
      void *tmp = realloc(ptr, size); \
      if (!tmp) abort(); \
      ptr = tmp; \
   } while (0)

#define TAILQ_FOREACH(var, head, field) \
   for ((var) = (head); (var) != NULL; (var) = (var)->field)

#define FOP_EXIT 0

void unfold_blk(struct unfold_elm **root);
void labels_to_offsets(void);