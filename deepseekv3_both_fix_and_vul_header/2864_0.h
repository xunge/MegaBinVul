#include <stdbool.h>

struct jsonparse_state {
    const char *json;
    int pos;
    int depth;
    char vtype;
    int error;
};

enum {
    JSON_TYPE_ERROR = -1,
    JSON_TYPE_PAIR_NAME = -2,
    JSON_TYPE_NUMBER = -3,
    JSON_TYPE_NULL = -4,
    JSON_TYPE_TRUE = -5,
    JSON_TYPE_FALSE = -6
};

enum {
    JSON_ERROR_UNEXPECTED_OBJECT = 1,
    JSON_ERROR_UNEXPECTED_END_OF_OBJECT,
    JSON_ERROR_UNEXPECTED_END_OF_ARRAY,
    JSON_ERROR_SYNTAX,
    JSON_ERROR_UNEXPECTED_STRING,
    JSON_ERROR_UNEXPECTED_ARRAY
};

char jsonparse_get_type(struct jsonparse_state *state);
void skip_ws(struct jsonparse_state *state);
bool push(struct jsonparse_state *state, char c);
bool pop(struct jsonparse_state *state);
bool modify(struct jsonparse_state *state, char c);
int atomic(struct jsonparse_state *state, int type);