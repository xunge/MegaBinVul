#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct mbfl_encoding;

struct Variant {
    bool isArray() const;
    struct Array toArray() const;
    struct String toString() const;
};

struct String {
    const char* data() const;
    size_t size() const;
};

struct Array {};

bool php_mb_parse_encoding_array(const struct Array& encoding, 
                                struct mbfl_encoding*** return_list, 
                                int* return_size, 
                                int persistent);

bool php_mb_parse_encoding_list(const char* encoding, 
                               size_t size, 
                               struct mbfl_encoding*** return_list, 
                               int* return_size, 
                               int persistent);

namespace req {
    void free(void* ptr);
}