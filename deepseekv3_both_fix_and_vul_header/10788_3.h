#include <stdint.h>
#include <stdbool.h>

typedef struct Var Var;
typedef uint32_t uint32;
typedef int32_t int32;

struct JavascriptArray {
    uint32_t length;
    void GetArrayTypeAndConvert(bool* isIntArray, bool* isFloatArray);
    template<typename T> bool IsMissingItemAt(uint32_t index);
    bool IsMissingItem(uint32_t index);
};