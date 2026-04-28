#include <vector>
#include <string>
#include <unordered_map>

using string = std::string;
using Labels = std::vector<int>;
using OperandLabels = std::vector<Labels>;
using LabelCounts = std::vector<int>;
using OperandLabelCounts = std::vector<LabelCounts>;

enum DimensionType {
  kBatch,
  kContracting,
  kFree,
  kReduction
};

constexpr int kEllipsisLabel = -1;

struct Status {
  static Status OK();
  bool ok() const;
};

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)

template <typename T, size_t N>
class InlinedVector {
 public:
  void resize(size_t size);
  T& at(size_t index);
  T& operator[](size_t index);
  size_t size() const;
};

namespace gtl {
template <typename T, size_t N>
using InlinedVector = ::InlinedVector<T, N>;
}  // namespace gtl

namespace absl {
template <typename K, typename V>
class flat_hash_map {
 public:
  size_t size() const;
};
}  // namespace absl

Status ParseEinsumEquation(const string& equation,
                          gtl::InlinedVector<string, 2>* input_str,
                          string* output_str);
void MapToLabels(const string& str, Labels* labels,
                 absl::flat_hash_map<char, int>* label_mapping);
DimensionType GetDimensionType(bool removed, bool unique);