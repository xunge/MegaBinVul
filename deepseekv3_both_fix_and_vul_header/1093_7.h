#include <string>
#include <vector>
#include <cstdint>
#include <initializer_list>
#include <utility>
#include <map>
#include <sstream>

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::ostringstream;

enum DataType {
  DT_INT32
};

class Status {
 public:
  bool ok() const { return true; }
  static Status OK() { return Status(); }
};

class OpDef {
 public:
  class ArgDef {
   public:
    const string& name() const { static string s; return s; }
    bool is_ref() const { return false; }
  };
};

class AttrSlice {};
class FunctionDef {
 public:
  class ArgAttrs {
   public:
    using AttrMap = map<string, string>;
    const AttrMap& attr() const { static AttrMap m; return m; }
  };
};

class NodeDef {
 public:
  void set_op(const string& op) {}
  map<string, string>* mutable_attr() { return &attrs_; }
 private:
  map<string, string> attrs_;
};

class FunctionLibraryDefinition {
 public:
  static const char* kDeviceArgOp;
  static const char* kArgOp;
};

class DataTypeVector : public vector<DataType> {
 public:
  DataTypeVector() = default;
  DataTypeVector(std::initializer_list<DataType> init) : vector<DataType>(init) {}
  DataTypeVector(const DataTypeVector&) = default;
};

struct ItemArgs {
  bool b1;
  int index;
  int zero;
  bool is_type_list;
  DataTypeVector dtypes;
  ItemArgs(bool b, int i, int z, bool itl, const DataTypeVector& dt) 
    : b1(b), index(i), zero(z), is_type_list(itl), dtypes(dt) {}
  ItemArgs(bool b, int i, int z, bool itl, std::initializer_list<DataType> dt)
    : b1(b), index(i), zero(z), is_type_list(itl), dtypes(dt) {}
};

class Result {
 public:
  vector<NodeDef> nodes;
  vector<DataType> arg_types;
};

Result result_;

Status ArgNumType(const AttrSlice&, const OpDef::ArgDef&, bool*, DataTypeVector*) {
  return Status::OK();
}

Status AddItem(const string&, const ItemArgs&) {
  return Status::OK();
}

NodeDef* AddNode(const string&) {
  return nullptr;
}

void AddAttr(const string&, DataType, NodeDef*) {}
void AddAttr(const string&, int64_t, NodeDef*) {}
void AddAttr(const string&, const string&, map<string, string>*) {}

DataType MakeRefType(DataType dtype) { return dtype; }

namespace strings {
string StrCat(const string& a, const string& b) {
  return a + b;
}
string StrCat(const string& a, const string& b, size_t c) {
  ostringstream oss;
  oss << a << b << c;
  return oss.str();
}
void StrAppend(string* s, const string& a) {
  *s += a;
}
void StrAppend(string* s, const string& a, size_t b) {
  ostringstream oss;
  oss << *s << a << b;
  *s = oss.str();
}
}

namespace errors {
Status Internal(const string& msg) {
  return Status();
}
Status Internal(const string& msg1, const string& msg2, int arg1, const string& msg3, size_t arg2) {
  return Status();
}
}

#define TF_RETURN_IF_ERROR(expr) \
  do {                           \
    const Status& _status = (expr); \
    if (!_status.ok())           \
      return _status;           \
  } while (0)

#define DCHECK_EQ(a, b) ((void)0)