#include <cstdint>
#include <string>
#include <unordered_map>

struct HeaderEntryImpl {
  struct Entry {
    std::string key() const;
    std::string value() const;
  };
  Entry* entry_;
};

class HeaderMapImpl {
public:
  void removeInline(HeaderEntryImpl** ptr_to_entry);
private:
  std::unordered_map<HeaderEntryImpl::Entry*, HeaderEntryImpl*> headers_;
  void subtractSize(uint64_t size);
};