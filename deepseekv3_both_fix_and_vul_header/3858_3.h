#include <utility>
#include <cassert>

namespace hbc {
struct LazyCompilationData {
  bool strictMode;
  void *parentScope;
  struct Name {
    bool isValid() const { return false; }
    bool operator!=(const Name &) const { return false; }
  } originalName, closureAlias;
  bool isGeneratorInnerFunction;
};
}

class Function;
class Variable;

namespace ESTree {
class FunctionLikeNode;
class ArrowFunctionExpressionNode;
}

class ESTreeIRGen {
public:
  struct FunctionContext {
    ESTreeIRGen *irGen;
    Function *function;
    void *scope;
  };
  
  FunctionContext *topLevelContext;
  void *Root;
  void *lexicalScopeChain;
  
  struct {
    void *lookup(const hbc::LazyCompilationData::Name &) { return nullptr; }
    void insert(const hbc::LazyCompilationData::Name &, void*) {}
  } nameTable_;
  
  template<typename T>
  static T *cast(void *) { return nullptr; }
  
  struct BuilderType {
    Function *createTopLevelFunction(bool, void*) { return nullptr; }
  } Builder;
  
  Function *genES5Function(const hbc::LazyCompilationData::Name &, Variable*, void*, bool = false);
  void addLexicalDebugInfo(Function*, Function*, void*);
  void materializeScopesInChain(Function*, void*, int);
  int getDepth(void*);
  
  std::pair<Function *, Function *> doLazyFunction(hbc::LazyCompilationData *lazyData);
};

namespace llvh {
template<typename T>
class SaveAndRestore {
  T &Ref;
  T Saved;
public:
  SaveAndRestore(T &ref, T value) : Ref(ref), Saved(ref) {
    Ref = value;
  }
  ~SaveAndRestore() { Ref = Saved; }
};

template<typename T>
bool isa(void*) { return false; }
}