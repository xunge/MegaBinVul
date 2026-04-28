#include <stdlib.h>

typedef struct json_t json_t;
typedef struct json_object_t json_object_t;
typedef struct hashtable_t {
    void *dummy; 
} hashtable_t;

struct json_t {
    int type;
};

struct json_object_t {
    json_t json;
    hashtable_t hashtable;
    int serial;
    int visited;
};

#define JSON_OBJECT 1

extern int hashtable_seed;
extern void json_object_seed(unsigned int seed);
extern void *jsonp_malloc(size_t size);
extern void jsonp_free(void *ptr);
extern int hashtable_init(hashtable_t *hashtable);
extern void json_init(json_t *json, int type);