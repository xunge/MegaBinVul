#include <stddef.h>

typedef long txInteger;
typedef char* txString;
typedef size_t txSize;

typedef enum {
    XS_KEY_KIND,
    XS_KEY_X_KIND,
    XS_STRING_KIND,
    XS_STRING_X_KIND
} txKind;

typedef struct txSlot {
    union {
        struct {
            char* string;
        } key;
        char* string;
    } value;
    txKind kind;
} txSlot;

typedef struct txMachine {
    txSlot** keyArrayHost;
    txSlot** keyArray;
    txInteger keyOffset;
    txInteger keyCount;
    void* dtoa;
} txMachine;

extern char* c_strcpy(char* dest, const char* src);
extern char* c_strcat(char* dest, const char* src);
extern txKind mxGetKeySlotKind(txSlot* key);
extern void fxIntegerToString(void* dtoa, txInteger id, txString theBuffer, txSize theSize);