#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int digits;
} decNumber;

typedef struct {
    char* literal_data;
} jvp_literal_number;

typedef struct {
    unsigned int flags;
} jv;

#define JVP_HAS_FLAGS(n, f) ((n).flags & (f))
#define JVP_FLAGS_NUMBER_LITERAL 1

static decNumber* jvp_dec_number_ptr(jv n) {
    return NULL;
}

static jvp_literal_number* jvp_literal_number_ptr(jv n) {
    return NULL;
}

static void* jv_mem_alloc(int size) {
    return malloc(size);
}

static int decNumberIsNaN(decNumber* d) {
    return 0;
}

static int decNumberIsInfinite(decNumber* d) {
    return 0;
}

static void decNumberToString(decNumber* d, char* str) {
}