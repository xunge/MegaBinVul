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
class RowPartitionTensor {};

namespace tensorflow {
class Status {
 public:
  static Status OK();
};
}

using Status = tensorflow::Status;

namespace errors {
Status InvalidArgument(const string& message, const string& details);
}

RowPartitionTensor GetRowPartitionTensor(OpKernelContext* context, int dimension);
RowPartitionType GetRowPartitionTypeByDimension(int dimension);
string RowPartitionTypeToString(RowPartitionType partition_type);
void CalculateOutputIndexValueRowID(OpKernelContext* context, const RowPartitionTensor& row_partition_tensor, const vector<INDEX_TYPE>& parent_output_index, INDEX_TYPE output_index_multiplier, INDEX_TYPE output_size, vector<INDEX_TYPE>* result);
void CalculateOutputIndexRowSplit(OpKernelContext* context, const RowPartitionTensor& row_partition_tensor, const vector<INDEX_TYPE>& parent_output_index, INDEX_TYPE output_index_multiplier, INDEX_TYPE output_size, vector<INDEX_TYPE>* result);
void CalculateOutputIndexValueRowID(const RowPartitionTensor& row_partition_tensor, const vector<INDEX_TYPE>& parent_output_index, INDEX_TYPE output_index_multiplier, INDEX_TYPE output_size, vector<INDEX_TYPE>* result);
void CalculateOutputIndexRowSplit(const RowPartitionTensor& row_partition_tensor, const vector<INDEX_TYPE>& parent_output_index, INDEX_TYPE output_index_multiplier, INDEX_TYPE output_size, vector<INDEX_TYPE>* result);