#include <stdint.h>
#include <errno.h>
#include <string.h>

struct Resource {};
struct String {
  size_t size() const;
};
struct Variant {
  Variant(int64_t) {}
};
struct File {
  int64_t write(const String& data, int64_t length);
};

#define CHECK_HANDLE(handle, f) File* f = nullptr
#define raise_notice(fmt, ...)
#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)