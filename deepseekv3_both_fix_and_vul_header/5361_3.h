#include <limits>
#include <cassert>

enum IrOpcode {
  kLoadBuffer
};

enum MachineType {
  kMachNone
};

enum Representation {
  kRepTagged,
  kRepFloat64,
  kRepFloat32
};

enum BranchHint {
  kTrue
};

#define DCHECK_EQ(a, b) assert((a) == (b))
#define DCHECK_NE(a, b) assert((int)(a) != (int)(b))

class Node;

struct BufferAccess {
  MachineType machine_type() const { return kMachNone; }
};

BufferAccess BufferAccessOf(const BufferAccess& op) { return op; }
Representation RepresentationOf(MachineType type) { return kRepTagged; }

class MachineOperatorBuilder {
public:
  bool Is64() const { return false; }
  Node* ChangeUint32ToUint64() { return nullptr; }
  Node* Uint32LessThan() { return nullptr; }
  Node* Load(MachineType type) { return nullptr; }
  Node* CheckedLoad(MachineType type) { return nullptr; }
};

class CommonOperatorBuilder {
public:
  Node* Branch(BranchHint hint) { return nullptr; }
  Node* IfTrue() { return nullptr; }
  Node* IfFalse() { return nullptr; }
  Node* Merge(int count) { return nullptr; }
  Node* EffectPhi(int count) { return nullptr; }
  Node* Phi(MachineType type, int count) { return nullptr; }
};

class Graph {
public:
  Node* NewNode(Node* op, Node* n1) { return nullptr; }
  Node* NewNode(Node* op, Node* n1, Node* n2) { return nullptr; }
  Node* NewNode(Node* op, Node* n1, Node* n2, Node* n3) { return nullptr; }
  Node* NewNode(Node* op, Node* n1, Node* n2, Node* n3, Node* n4) { return nullptr; }
};

class JSGraph {
public:
  Node* UndefinedConstant() { return nullptr; }
  Node* Float64Constant(double value) { return nullptr; }
  Node* Float32Constant(float value) { return nullptr; }
  Node* Int32Constant(int value) { return nullptr; }
};

class RepresentationChanger {
public:
  Node* GetRepresentationFor(Node* etrue, MachineType type, MachineType output_type) { return nullptr; }
};

class Node {
public:
  IrOpcode opcode() { return kLoadBuffer; }
  Node* InputAt(int) { return nullptr; }
  void set_op(void*) {}
  void ReplaceInput(int, Node*) {}
  void TrimInputCount(int) {}
  BufferAccess op() { return BufferAccess(); }
};

class NodeProperties {
public:
  static void ReplaceWithValue(Node*, Node*, Node*) {}
};

class SimplifiedLowering {
public:
  void DoLoadBuffer(Node* node, MachineType output_type, RepresentationChanger* changer);
  MachineOperatorBuilder* machine() { return nullptr; }
  CommonOperatorBuilder* common() { return nullptr; }
  Graph* graph() { return nullptr; }
  JSGraph* jsgraph() { return nullptr; }
};

template <typename T>
class NumericLimits {
public:
  static T quiet_NaN() { return T(); }
};