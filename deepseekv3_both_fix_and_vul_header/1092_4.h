#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <initializer_list>
#include <sstream>

using std::string;
using std::vector;
using std::map;
using std::initializer_list;
using std::ostringstream;

struct Status {
    static Status OK();
    static Status Internal(const string&);
};

namespace errors {
    Status Internal(const string&);
}

#define TF_RETURN_IF_ERROR(expr) (expr)
#define CHECK_GE(a, b)
#define DCHECK_EQ(a, b)

namespace strings {
    template <typename... Args>
    string StrCat(const Args&... args) {
        ostringstream ss;
        (ss << ... << args);
        return ss.str();
    }

    template <typename... Args>
    void StrAppend(string* s, const Args&... args) {
        ostringstream ss;
        ss << *s;
        (ss << ... << args);
        *s = ss.str();
    }
}

struct AttrSlice {};
struct OpDef {
    struct ArgDef {
        string name() const;
        bool is_ref() const;
    };
};
struct FunctionDef {
    struct ArgAttrs {
        map<string, int> attr_;
        const map<string, int>& attr() const { return attr_; }
    };
};
struct NodeDef {
    void set_op(const string&);
    map<string, int>* mutable_attr();
};
struct DataTypeVector : vector<int> {};
struct DataType {
    static const int DT_INT32;
    DataType(int);
    DataType(const DataType&);
};

struct FunctionLibraryDefinition {
    static const string kDeviceArgOp;
    static const string kArgOp;
};

struct ArgItem {
    bool b;
    int i1, i2;
    bool is_type_list;
    DataTypeVector dtypes;
    ArgItem(bool, int, int, bool, DataTypeVector);
    ArgItem(bool, int, int, bool, initializer_list<int>);
};

struct Result {
    vector<NodeDef> nodes;
    vector<int> arg_types;
} result_;

Status ArgNumType(const AttrSlice&, const OpDef::ArgDef&, bool*, DataTypeVector*);
Status AddItem(const string&, const ArgItem&);
NodeDef* AddNode(const string&);
void AddAttr(const string&, const DataType&, NodeDef*);
void AddAttr(const string&, int, NodeDef*);
void AddAttr(const string&, const int&, map<string, int>*);
DataType MakeRefType(int);