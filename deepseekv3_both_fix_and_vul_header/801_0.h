#include <string.h>
#include <limits.h>

typedef struct ModPlugFile {
    void* mod;
} ModPlugFile;

extern const char* openmpt_module_get_sample_name(void* mod, unsigned int qual);
extern void openmpt_free_string(const char* str);