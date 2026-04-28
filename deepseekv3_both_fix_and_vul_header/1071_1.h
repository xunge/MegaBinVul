#include <string>
#include <vector>

struct ResourceHandleProto {
  std::string device;
  std::string container;
  std::string name;
  std::vector<std::string> dtypes_and_shapes;
};

class Status {
public:
  bool ok() const { return true; }
  static Status OK() { return Status(); }
};

class ResourceHandle {
public:
  explicit ResourceHandle(const ResourceHandleProto& proto);
  Status FromProto(const ResourceHandleProto& proto) { return Status::OK(); }
};

#define TF_CHECK_OK(val) \
  while (!(val).ok()) {}