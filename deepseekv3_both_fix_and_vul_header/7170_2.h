#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct AttVal AttVal;
typedef struct Stack Stack;
typedef struct TidyDocImpl TidyDocImpl;

struct Node {
    Node *content;
    Node *next;
    Node *parent;
    AttVal *attributes;
};

struct AttVal {
    char *value;
    AttVal *next;
};

#define TY_(x) TY_##x

Stack *TY_newStack(TidyDocImpl *doc, int size);
void TY_freeStack(Stack *stack);
void TY_push(Stack *stack, Node *node);
Node *TY_pop(Stack *stack);
bool TY_nodeIsElement(Node *node);
void TY_DiscardElement(TidyDocImpl *doc, Node *node);
void DiscardContainer(TidyDocImpl *doc, Node *node, Node **next);
AttVal *TY_GetAttrByName(Node *node, const char *name);
void TY_RepairAttrValue(TidyDocImpl *doc, Node *parent, const char *attr, char *value);
void TY_DropAttrByName(TidyDocImpl *doc, Node *node, const char *attr);

bool nodeIsSTYLE(Node *node);
bool nodeIsP(Node *node);
bool nodeIsSPAN(Node *node);
bool nodeIsA(Node *node);