#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cassert>
#include <sstream>

enum ErrorCode {
  INVALID_ARGUMENT,
  UNIMPLEMENTED
};

class Status {
 public:
  Status(ErrorCode code, const std::string& message);
  bool ok() const;
  std::string error_message() const;
};

template <typename T>
class StatusOr {
 public:
  StatusOr(const T& value);
  StatusOr(const Status& status);
  bool ok() const;
  const T& value() const;
  const Status& status() const;
};

enum FullTypeId {
  TFT_PRODUCT,
  TFT_VAR
};

class FullTypeDef {
 public:
  void set_type_id(FullTypeId type_id);
  FullTypeId type_id() const;
  FullTypeDef* add_args();
  int args_size() const;
  FullTypeDef* mutable_args(int index);
  void clear_s();
  void set_s(const std::string& s);
  const std::string& s() const;
};

class AttrSlice {
 public:
  const class AttrValue* Find(const std::string& key) const;
  std::string DebugString() const;
};

class OpDef {
 public:
  class ArgDef {
   public:
    const FullTypeDef& experimental_full_type() const;
  };
  int output_arg_size() const;
  const ArgDef& output_arg(int index) const;
};

class AttrValue {
 public:
  enum ValueCase {
    kList,
    kType,
    VALUE_NOT_SET
  };
  ValueCase value_case() const;
  const class ListValue& list() const;
  int type() const;
};

class ListValue {
 public:
  int type_size() const;
  int type(int index) const;
};

void map_dtype_to_tensor(int dtype, FullTypeDef* ft);

#define DCHECK(expr) assert(expr)

namespace error {
constexpr ErrorCode INVALID_ARGUMENT = ::INVALID_ARGUMENT;
constexpr ErrorCode UNIMPLEMENTED = ::UNIMPLEMENTED;
}

namespace absl {
inline std::string StrCat(const std::string& a, const std::string& b) {
  std::ostringstream ss;
  ss << a << b;
  return ss.str();
}

inline std::string StrCat(const std::string& a, const std::string& b, const std::string& c) {
  std::ostringstream ss;
  ss << a << b << c;
  return ss.str();
}

inline std::string StrCat(const std::string& a, const std::string& b, const std::string& c, const std::string& d) {
  std::ostringstream ss;
  ss << a << b << c << d;
  return ss.str();
}
}