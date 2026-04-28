#include <stddef.h>

enum Token {
  EQ_STRICT
};

enum ScopeType {
  BLOCK_SCOPE
};

enum VariableMode {
  LET
};

class RelocInfo {
 public:
  enum Position {
    kNoPosition
  };
};

class Expression {
 public:
  int position() const;
  bool IsVariableProxy() const;
};

class Scope {
 public:
  bool is_function_scope() const;
  bool calls_sloppy_eval() const;
  void RecordEvalCall();
  void set_is_declaration_scope();
  void set_start_position(int pos);
  void set_end_position(int pos);
  Scope* FinalizeBlockScope();
  Scope* parameter(int i);
};

class Block {
 public:
  void set_scope(Scope* scope);
  class StatementList {
   public:
    void Add(Block*, void*);
  };
  StatementList* statements();
};

class Factory {
 public:
  Block* NewBlock(void*, int, bool, RelocInfo::Position);
  Expression* NewVariableProxy(Scope*);
  Expression* NewUndefinedLiteral(RelocInfo::Position);
  Expression* NewCompareOperation(Token, Expression*, Expression*, RelocInfo::Position);
  Expression* NewConditional(Expression*, Expression*, Expression*, RelocInfo::Position);
};

class Parameter {
 public:
  bool is_rest;
  bool is_simple() const;
  Expression* pattern;
  Expression* initializer;
  int position() const;
  int initializer_end_position;
};

class ParserFormalParameters {
 public:
  bool is_simple;
  struct Params {
    Parameter* params;
    int length() const;
    const Parameter& operator[](int i) const { return params[i]; }
  } params;
  Scope* scope;
  Scope* parameter(int i);
};

class DeclarationDescriptor {
 public:
  enum Kind {
    PARAMETER
  };
  Kind declaration_kind;
  class Parser* parser;
  Scope* scope;
  Scope* hoist_scope;
  VariableMode mode;
  int declaration_pos;
  int initialization_pos;
};

class DeclarationParsingResult {
 public:
  struct Declaration {
    Declaration(Expression* p, int pos, Expression* val) 
      : pattern(p), initializer_position(pos), initial_value(val) {}
    Expression* pattern;
    int initializer_position;
    Expression* initial_value;
  };
};

class BlockState {
 public:
  BlockState(Scope**, Scope*);
};

class PatternRewriter {
 public:
  static void DeclareAndInitializeVariables(Block*, DeclarationDescriptor*,
                                         DeclarationParsingResult::Declaration*,
                                         void*, bool*);
};

class Zone {
 public:
  void* Add(void*, void*);
};

class Parser {
 public:
  Block* BuildParameterInitializationBlock(const ParserFormalParameters&, bool*);
  Factory* factory();
  Scope* scope_;
  void RewriteParameterInitializer(Expression*, Scope*);
  void RewriteParameterInitializerScope(int, Expression*, Scope*, Scope*);
  void CheckConflictingVarDeclarations(Scope*, bool*);
  Scope* NewScope(Scope*, ScopeType);
  Zone* zone();
  int stack_limit();
};

#define DCHECK(expr)
#define CHECK_OK ok