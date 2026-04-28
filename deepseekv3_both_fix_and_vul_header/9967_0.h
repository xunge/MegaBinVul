#include <stdint.h>

struct NativeWebKeyboardEvent {
    uint32_t type;
    uint32_t modifiers;
    uint32_t windows_key_code;
    uint32_t native_key_code;
    uint32_t is_system_key;
    char16_t character;
    char16_t unmodified_character;
    uint32_t focus_on_editable_field;
};

#define OVERRIDE