#include <stdbool.h>

typedef struct Variant {
    int type;
    union {
        int int_val;
        bool bool_val;
        double double_val;
        void* ptr_val;
    } data;
    
    Variant() = default;
    
    Variant(int val) {
        type = 0;
        data.int_val = val;
    }
    
    Variant(bool val) {
        type = 1;
        data.bool_val = val;
    }
    
    Variant& operator=(int val) {
        type = 0;
        data.int_val = val;
        return *this;
    }
    
    Variant& operator=(bool val) {
        type = 1;
        data.bool_val = val;
        return *this;
    }
} Variant;

extern int fb_compact_unserialize_from_buffer(Variant& ret, const char* str, int len, int& p, int options);
extern int fb_compact_unserialize_from_buffer(Variant& ret, const char* str, int len, int& p);
extern Variant init_null();