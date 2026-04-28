#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct Document Document;

struct Node {
    int tipo;
    Node *padre;
};

struct Document {
    Node *inicio;
    char encoding[0];
};

extern Document *document;
extern Node *actual_element;
extern int state;

#define ST_PARSING 0
#define ST_END 1
#define Node_element 0

#define EPRINTF(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(msg) { fprintf(stderr, "%s\n", msg); exit(EXIT_FAILURE); }

void elm_close(Node *node);
#ifdef SELLAR
void sellar_documento();
#endif