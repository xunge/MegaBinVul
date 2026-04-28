#include <string>

#define HHVM_FUNCTION(name, ...) name(__VA_ARGS__)

struct String;
struct Variant;
struct apc_store {
  void setWithoutTTL(const String&, const Variant&);
};
namespace apcExtension {
  extern bool Enable;
}
bool isKeyInvalid(const String&);
void throw_invalid_argument(const std::string&);