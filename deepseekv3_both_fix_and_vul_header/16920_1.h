#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>

struct json_object;
typedef struct json_tokener json_tokener;
enum json_tokener_error {
    json_tokener_continue,
    // 其他可能的错误码...
};

#define JSON_TOKENER_DEFAULT_DEPTH 32
#define JSON_TOKENER_STRICT 1
#define JSON_TOKENER_ALLOW_TRAILING_CHARS 1

// 函数声明
json_tokener* json_tokener_new_ex(int depth);
void json_tokener_set_flags(json_tokener* tok, int flags);
struct json_object* json_tokener_parse_ex(json_tokener* tok, const char* str, int len);
enum json_tokener_error json_tokener_get_error(json_tokener* tok);
int json_tokener_get_parse_end(json_tokener* tok);
const char* json_tokener_error_desc(enum json_tokener_error jerr);
void json_tokener_free(json_tokener* tok);
void json_object_put(struct json_object* obj);