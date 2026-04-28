#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
    int (*back)(void);
    void (*pop_back)(void);
    bool (*empty)(void);
} IntVector;

int lastFieldId_;
IntVector nestedStructFieldIds_;

static int IntVector_back(void) {
    return nestedStructFieldIds_.data[nestedStructFieldIds_.size-1];
}

static void IntVector_pop_back(void) {
    if(nestedStructFieldIds_.size > 0) nestedStructFieldIds_.size--;
}

static bool IntVector_empty(void) {
    return nestedStructFieldIds_.size == 0;
}

void initIntVector() {
    nestedStructFieldIds_.back = IntVector_back;
    nestedStructFieldIds_.pop_back = IntVector_pop_back;
    nestedStructFieldIds_.empty = IntVector_empty;
}