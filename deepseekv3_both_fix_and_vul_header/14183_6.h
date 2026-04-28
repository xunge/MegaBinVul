#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <cstdint>
#include <iostream>

using std::string;

struct NodeDef;
struct Tensor;
struct AttrValue;

enum DataType {
  DT_RESOURCE
};

enum DeviceType {
  DEVICE_CPU
};

extern const char* kScopedAllocatorAttrName;

struct PartialTensorShape {
  bool IsFullyDefined() const;
  int64_t num_elements() const;
};

bool MaybeReplaceShapeOp(
    const class Node*,
    const std::unordered_map<string, std::vector<PartialTensorShape>>*,
    std::unordered_map<const class Node*, std::vector<Tensor>>*);

class Node {
public:
  bool IsConstant() const;
  DataType output_type(int) const;
  const class OpDef& op_def() const;
  string name() const;
  bool IsControlFlow() const;
  bool IsSend() const;
  bool IsRecv() const;
  bool IsGetSessionHandle() const;
  bool IsGetSessionTensor() const;
  bool IsDeleteSessionTensor() const;
  bool IsSource() const;
  bool IsSink() const;
  bool IsFakeParam() const;
  const AttrValue* Find(const string& attr_name) const;
  string DebugString() const;
  const NodeDef& def() const;
  class AttrsSlice {
  public:
    const AttrValue* Find(const string& attr_name) const;
  };
  AttrsSlice attrs() const;
};

class OpDef {
public:
  bool is_stateful() const;
};

size_t DataTypeSize(DataType dt);
bool KernelDefAvailable(DeviceType device_type, const NodeDef& node_def);
#define VLOG(x) std::cout