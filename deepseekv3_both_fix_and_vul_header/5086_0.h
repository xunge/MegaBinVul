#include <stdio.h>

char buffer[1024];
int used;
struct AST *ast;

void print(struct AST *ast);