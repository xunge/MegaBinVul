#include <stddef.h>
#include <stdint.h>

enum class ErrorType {
    TypedArrayInvalidByteOffset,
    TypedArrayInvalidBufferLength,
    TypedArrayOutOfRangeByteOffset,
    InvalidLength,
    TypedArrayOutOfRangeByteOffsetOrLength
};

class RangeError {};

struct VM {
    bool exception();
    template<typename T>
    void throw_exception(struct GlobalObject&, ErrorType, ...);
};

struct Value {
    bool is_undefined() const;
    size_t to_index(struct GlobalObject&);
};

struct GlobalObject {
    VM& vm();
};

struct ArrayBuffer {
    size_t byte_length() const;
};

struct TypedArrayBase {
    size_t element_size() const;
    const char* class_name() const;
    void set_viewed_array_buffer(ArrayBuffer*);
    void set_byte_length(size_t);
    void set_byte_offset(size_t);
    void set_array_length(size_t);
};

template<typename T>
struct Checked {
    Checked() = default;
    Checked(T);
    bool has_overflow() const;
    T value() const;
    Checked& operator-=(T);
    Checked& operator+=(T);
    Checked& operator*=(T);
};