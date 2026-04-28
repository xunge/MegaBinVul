#include <vector>
#include <system_error>
#include <cstdint>

namespace boost {
namespace system {
enum errc {
    not_enough_memory
};
} // namespace system
} // namespace boost

namespace bdecode_errors {
enum error_code_enum {
    no_error,
    depth_exceeded,
    unexpected_eof,
    expected_string,
    overflow,
    limit_exceeded,
    expected_value
};
} // namespace bdecode_errors

class lazy_entry {
public:
    enum type_t { dict_t, list_t };
    type_t type() const;
    void clear();
    void set_end(const char*);
    lazy_entry* dict_append(const char*);
    lazy_entry* list_append();
    void construct_dict(const char*);
    void construct_list(const char*);
    void construct_int(const char*, int);
    void construct_string(const char*, int);
};

struct error_code {};

#define TORRENT_FAIL_BDECODE(e) do {} while(0)
#define TORRENT_ASSERT(expr) do {} while(0)

bool numeric(char c);
const char* parse_int(const char*, const char*, char, int64_t&, bdecode_errors::error_code_enum&);
const char* find_char(const char*, const char*, char);

namespace boost {
    using int64_t = int64_t;
}