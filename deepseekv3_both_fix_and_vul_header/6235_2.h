#include <vector>
#include <string>

namespace tensorflow {
class Status {
public:
    static Status OK();
};
class Tensor {
public:
    int dim_size(int) const;
};
template <typename T>
class ConstFlatSplits {
public:
    size_t size() const;
    T operator()(int) const;
};
Status InvalidArgument(const std::string&);
template <typename... Args>
Status InvalidArgument(Args&&... args);
}  // namespace tensorflow

using SPLITS_TYPE = int;
using ConstFlatSplits = tensorflow::ConstFlatSplits<SPLITS_TYPE>;
using Tensor = tensorflow::Tensor;

using tensorflow::InvalidArgument;