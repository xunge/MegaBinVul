#include <stdbool.h>

typedef struct TypedValue {
    // minimal definition needed for pointer operations
    struct TypedValue* next;
} TypedValue;

typedef struct Variant {
    static Variant attach(TypedValue value);
} Variant;

enum JSONContainerType {
    // placeholder enum values
    JSON_ARRAY,
    JSON_OBJECT
};

class SimpleParser {
public:
    SimpleParser(const char* inp, int length, TypedValue* buf, JSONContainerType container_type, bool is_tsimplejson);
    bool parseValue();
    void skipSpace();
    const char* p;
    TypedValue* top;
};

void tvDecRefRange(TypedValue* buf, TypedValue* top);