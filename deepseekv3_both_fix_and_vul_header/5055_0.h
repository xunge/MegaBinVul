#include <stdint.h>

struct OutputFile {
  int64_t readImpl(char* buffer, int64_t length);
};

void raise_warning(const char* message);