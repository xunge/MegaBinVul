#include <cstddef>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <ostream>
#include <iostream>

#define BYN_TRACE(x) std::cout << x

enum class ExternalKind {
  Function,
  Table,
  Memory,
  Global,
  Tag
};

class Name {
public:
  Name(const std::string& str) : str(str) {}
  operator std::string() const { return str; }
  std::string str;
};

class Type {
public:
  bool isSignature() const { return false; }
  std::string toString() const { return ""; }
  static const Type i64;
  bool operator==(const Type& other) const { return false; }
};

class Function;
class Table;
class Global;
class Tag;

class Memory {
public:
  static const size_t kUnlimitedSize;
};

class Builder {
public:
  enum Mutability {
    Mutable,
    Immutable
  };
  Builder(class Wasm& wasm) {}
  std::unique_ptr<Function> makeFunction(Name name, Type type, std::vector<Type> params);
  std::unique_ptr<Table> makeTable(Name name);
  std::unique_ptr<Global> makeGlobal(Name name, Type type, void* init, Mutability mut);
  std::unique_ptr<Tag> makeTag(Name name, Type signature);
};

class Wasm {
public:
  void addFunction(std::unique_ptr<Function> func) {}
  void addTable(std::unique_ptr<Table> table) {}
  void addGlobal(std::unique_ptr<Global> global) {}
  void addTag(std::unique_ptr<Tag> tag) {}
  struct {
    std::string module;
    std::string base;
    Name name;
    bool exists;
    size_t initial;
    size_t max;
    bool shared;
    Type indexType;
  } memory;
};

class Function {
public:
  std::string module;
  std::string base;
};

class Table {
public:
  static const size_t kUnlimitedSize;
  std::string module;
  std::string base;
  Type type;
  size_t initial;
  size_t max;
};

class Global {
public:
  std::string module;
  std::string base;
};

class Tag {
public:
  std::string module;
  std::string base;
};

class WasmBinaryBuilder {
public:
  void readImports();
  size_t getU32LEB() { return 0; }
  Name getInlineString() { return Name(""); }
  Type getType() { return Type(); }
  Type getConcreteType() { return Type(); }
  Type getTypeByIndex(size_t index) { return Type(); }
  Type getSignatureByTypeIndex(size_t index) { return Type(); }
  void getResizableLimits(size_t& initial, size_t& max, bool& shared, Type& indexType, size_t maxSize) {}
  void throwError(const std::string& msg) {}
  int8_t getInt8() { return 0; }
  std::vector<Type> functionTypes;
  std::vector<Function*> functionImports;
  std::vector<Table*> tableImports;
  std::vector<Global*> globalImports;
  Wasm wasm;
};