#include <vector>
#include <string>

using std::vector;
using std::string;

typedef int INDEX_TYPE;

enum class RowPartitionType {
  VALUE_ROWIDS,
  ROW_SPLITS
};

class OpKernelContext {};
class RowPartitionTensor {
 public:
  size_t size() const { return 0; }
};

namespace tensorflow {
class Status {
 public:
  static Status OK() { return Status(); }
};
}  // namespace tensorflow

using Status = tensorflow::Status;

class errors {
 public:
  static Status InvalidArgument(const string& message) { return Status(); }
  static Status InvalidArgument(const string& message, size_t a, const string& b, size_t c) { return Status(); }
  static Status InvalidArgument(const string& message, const string& type) { return Status(); }
};

Status CalculateOutputIndexValueRowID(
    const RowPartitionTensor& row_partition_tensor,
    const vector<INDEX_TYPE>& parent_output_index,
    INDEX_TYPE output_index_multiplier,
    INDEX_TYPE output_size,
    vector<INDEX_TYPE>* result) {
  return Status::OK();
}

Status CalculateOutputIndexRowSplit(
    const RowPartitionTensor& row_partition_tensor,
    const vector<INDEX_TYPE>& parent_output_index,
    INDEX_TYPE output_index_multiplier,
    INDEX_TYPE output_size,
    vector<INDEX_TYPE>* result) {
  return Status::OK();
}

Status CalculateOutputIndexValueRowID(
    OpKernelContext* context,
    const RowPartitionTensor& row_partition_tensor,
    const vector<INDEX_TYPE>& parent_output_index,
    INDEX_TYPE output_index_multiplier,
    INDEX_TYPE output_size,
    vector<INDEX_TYPE>* result) {
  return Status::OK();
}

Status CalculateOutputIndexRowSplit(
    OpKernelContext* context,
    const RowPartitionTensor& row_partition_tensor,
    const vector<INDEX_TYPE>& parent_output_index,
    INDEX_TYPE output_index_multiplier,
    INDEX_TYPE output_size,
    vector<INDEX_TYPE>* result) {
  return Status::OK();
}

RowPartitionTensor GetRowPartitionTensor(OpKernelContext* context, int dimension) {
  return RowPartitionTensor();
}

RowPartitionType GetRowPartitionTypeByDimension(int dimension) {
  return RowPartitionType::VALUE_ROWIDS;
}

string RowPartitionTypeToString(RowPartitionType partition_type) {
  return "";
}