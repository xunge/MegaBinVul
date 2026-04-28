#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

typedef enum markup_e {
    MARKUP_NONE,
    MARKUP_H1,
    MARKUP_H2,
    MARKUP_H3,
    MARKUP_H4,
    MARKUP_H5,
    MARKUP_H6,
    MARKUP_H7,
    MARKUP_H8,
    MARKUP_H9,
    MARKUP_H10,
    MARKUP_H11,
    MARKUP_H12,
    MARKUP_H13,
    MARKUP_H14,
    MARKUP_H15,
    MARKUP_A,
    MARKUP_B,
    MARKUP_BR,
    MARKUP_LI,
    MARKUP_UL,
    MARKUP_DD
} markup_t;

typedef struct tree_s {
    markup_t markup;
    struct tree_s *parent;
    struct tree_s *child;
    struct tree_s *next;
    struct tree_s *last_child;
} tree_t;

extern int TocDocCount;
extern int TocLevels;
extern int TocNumbers;
extern int TocLinks;
extern int last_level;
extern int heading_numbers[15];
extern char heading_types[15];
extern tree_t *heading_parents[15];

extern uchar *htmlGetVariable(tree_t *t, uchar *name);
extern void htmlSetVariable(tree_t *t, uchar *name, uchar *value);
extern tree_t *htmlAddTree(tree_t *parent, markup_t markup, uchar *data);
extern tree_t *htmlNewTree(tree_t *parent, markup_t markup, uchar *data);
extern void htmlInsertTree(tree_t *parent, markup_t markup, uchar *data);
extern void add_heading(tree_t *parent, tree_t *child);