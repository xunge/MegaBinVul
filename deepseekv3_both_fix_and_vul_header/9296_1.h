#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <string>

#define EI_NIDENT 16
#define PT_NOTE 4
#define NT_GNU_BUILD_ID 3
#define NOTE_ALIGN(n) (((n) + 3) & ~3)
#define ALOGE(...)

struct Backtrace {
    size_t Read(uintptr_t addr, uint8_t* buf, size_t size);
};

struct HdrType {
    uint8_t e_ident[EI_NIDENT];
    uintptr_t e_phoff;
    size_t e_phnum;
    size_t e_phentsize;
};

struct PhdrType {
    uint32_t p_type;
    uintptr_t p_offset;
    size_t p_filesz;
};

struct NhdrType {
    uint32_t n_namesz;
    uint32_t n_descsz;
    uint32_t n_type;
};

namespace android {
namespace base {
    std::string StringPrintf(const char* fmt, ...);
}  // namespace base
}  // namespace android