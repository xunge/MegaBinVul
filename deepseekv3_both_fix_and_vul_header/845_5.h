#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <list>

namespace absl {
template <typename T, typename U>
bool StartsWith(T&& str, U&& prefix) {
  return true;
}
}  // namespace absl

class LowerCaseString {
 public:
  std::string get() const;
};

class HeaderEntryImpl {
 public:
  class Key {
   public:
    std::string_view getStringView() const;
    size_t size() const;
  };
  class Value {
   public:
    size_t size() const;
  };
  Key key() const;
  Value value() const;
};

struct StaticLookupResponse {
  std::shared_ptr<HeaderEntryImpl>* entry_;
};

class HeaderMapImpl;

using EntryCb = std::function<StaticLookupResponse(HeaderMapImpl&)>;

class StaticLookupTable {
 public:
  EntryCb find(std::string_view);
};

template <typename T>
class ConstSingleton {
 public:
  static T& get();
};

class HeaderMapImpl {
 public:
  void removePrefix(const LowerCaseString& prefix);
 protected:
  void subtractSize(uint32_t size);
  std::list<HeaderEntryImpl> headers_;
};