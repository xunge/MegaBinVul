#include <string>
#include <sstream>

enum DataType {
  DT_INVALID = 0,
  DT_FLOAT = 1,
  DT_DOUBLE = 2,
  DT_INT32 = 3,
  DT_UINT8 = 4,
  DT_INT16 = 5,
  DT_INT8 = 6,
  DT_STRING = 7,
  DT_COMPLEX64 = 8,
  DT_INT64 = 9,
  DT_BOOL = 10,
  DT_QINT8 = 11,
  DT_QUINT8 = 12,
  DT_QINT32 = 13,
  DT_BFLOAT16 = 14,
  DT_QINT16 = 15,
  DT_QUINT16 = 16,
  DT_UINT16 = 17,
  DT_COMPLEX128 = 18,
  DT_HALF = 19,
  DT_RESOURCE = 20,
  DT_VARIANT = 21,
  DT_UINT32 = 22,
  DT_UINT64 = 23
};

class Status {
public:
    static Status OK();
};

class Node {
public:
    int num_outputs() const;
    int num_inputs() const;
    const std::string& name() const;
    DataType output_type(int index) const;
    DataType input_type(int index) const;
};

class Graph {
public:
    void AddEdge(Node* src, int output_index, Node* dst, int input_index);
};

class GraphConstructor {
public:
    Status MakeEdge(Node* src, int output_index, Node* dst, int input_index);
private:
    Graph* g_;
};

class errors {
public:
    template<typename... Args>
    static Status InvalidArgument(Args&&... args);
};

std::string DataTypeString(DataType dtype);
bool TypesCompatible(DataType dst_in, DataType src_out);