#include <stdbool.h>

struct Variant {
    bool isReferenced() const;
};

struct ArrayData {
    enum Kind {
        kGlobalsKind,
        kProxyKind
    };
    Kind kind() const;
};

struct Array {
    ArrayData* get() const;
};