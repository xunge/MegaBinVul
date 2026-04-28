#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct context_model {
    // 添加必要的成员变量
};
extern int CONTEXT_MODEL_TABLE_LENGTH;
extern int D;

class context_model_table {
public:
    context_model* model;
    int* refcnt;
    void decouple_or_alloc_with_empty_data();
};