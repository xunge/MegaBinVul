#include <stddef.h>
#include <assert.h>

#define MAX_OVERLOADED_FUNCTIONS 10
#define ERROR_SUCCESS 0
#define FAIL_ON_ERROR(x) if ((x) != ERROR_SUCCESS) return (x)
#define FAIL_ON_ERROR_WITH_CLEANUP(x, y) if ((x) != ERROR_SUCCESS) { y; return (x); }
#define FALSE 0
#define UNDEFINED 0

typedef enum {
    OBJECT_TYPE_INTEGER,
    OBJECT_TYPE_STRING,
    OBJECT_TYPE_FLOAT,
    OBJECT_TYPE_FUNCTION,
    OBJECT_TYPE_STRUCTURE,
    OBJECT_TYPE_ARRAY,
    OBJECT_TYPE_DICTIONARY
} YR_OBJECT_TYPE;

typedef struct _YR_OBJECT YR_OBJECT;
typedef struct _YR_STRUCTURE_MEMBER YR_STRUCTURE_MEMBER;
typedef struct _YR_OBJECT_FUNCTION YR_OBJECT_FUNCTION;
typedef struct _YR_OBJECT_INTEGER YR_OBJECT_INTEGER;
typedef struct _YR_OBJECT_STRING YR_OBJECT_STRING;
typedef struct _YR_OBJECT_DOUBLE YR_OBJECT_DOUBLE;
typedef struct _YR_OBJECT_ARRAY YR_OBJECT_ARRAY;
typedef struct _YR_OBJECT_DICTIONARY YR_OBJECT_DICTIONARY;
typedef struct _YR_OBJECT_STRUCTURE YR_OBJECT_STRUCTURE;

struct _YR_STRUCTURE_MEMBER {
    YR_OBJECT* object;
    YR_STRUCTURE_MEMBER* next;
};

struct _YR_OBJECT_FUNCTION {
    YR_OBJECT* return_obj;
    void* prototypes[MAX_OVERLOADED_FUNCTIONS];
};

struct _YR_OBJECT_INTEGER {
    int value;
};

struct _YR_OBJECT_STRING {
    char* value;
};

struct _YR_OBJECT_DOUBLE {
    double value;
};

struct _YR_OBJECT_ARRAY {
    YR_OBJECT* prototype_item;
};

struct _YR_OBJECT_DICTIONARY {
    YR_OBJECT* prototype_item;
};

struct _YR_OBJECT_STRUCTURE {
    YR_STRUCTURE_MEMBER* members;
};

struct _YR_OBJECT {
    YR_OBJECT_TYPE type;
    char* identifier;
    union {
        YR_OBJECT_INTEGER integer;
        YR_OBJECT_STRING string;
        YR_OBJECT_DOUBLE floating;
        YR_OBJECT_FUNCTION function;
        YR_OBJECT_STRUCTURE structure;
        YR_OBJECT_ARRAY array;
        YR_OBJECT_DICTIONARY dictionary;
    } value;
};

int yr_object_create(YR_OBJECT_TYPE type, char* identifier, void* null, YR_OBJECT** object);
int yr_object_structure_set_member(YR_OBJECT* object, YR_OBJECT* member);
void yr_object_destroy(YR_OBJECT* object);
void yr_free(void* ptr);
char* sized_string_dup(char* str);