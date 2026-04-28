#include <cstddef>

enum Token {
  ASSIGN,
  EQ_STRICT
};

class RelocInfo {
 public:
  enum Position {
    kNoPosition
  };
};

class Expression {};
class VariableProxy : public Expression {};
class UndefinedLiteral : public Expression {};
class CompareOperation : public Expression {};
class Conditional : public Expression {};
class Factory;
class Scope;
class DeclarationDescriptor;
class Parser;

struct PatternContext {};

class Variable {
 public:
  static Variable* CreateTempVar(Expression* current_value);
};

class Factory {
 public:
  CompareOperation* NewCompareOperation(Token op, VariableProxy* left,
                                        Expression* right,
                                        RelocInfo::Position pos);
  VariableProxy* NewVariableProxy(Variable* var);
  UndefinedLiteral* NewUndefinedLiteral(RelocInfo::Position pos);
  Conditional* NewConditional(Expression* condition, Expression* then_expr,
                             Expression* else_expr, RelocInfo::Position pos);
};

class Scope {
 public:
  bool is_arrow_scope() const;
  bool is_block_scope() const;
  Scope* outer_scope() const;
};

class DeclarationDescriptor {
 public:
  enum DeclarationKind {
    PARAMETER
  };
  DeclarationKind declaration_kind;
};

class Parser {
 public:
  int* stack_limit() const;
  
  class PatternRewriter {
   public:
    void VisitAssignment(class Assignment* node);
    Factory* factory();
    bool IsInitializerContext();
    bool IsBindingContext();
    Scope* scope();
    PatternContext SetAssignmentContextIfNeeded(Expression* initializer);
    void RecurseIntoSubpattern(Expression* target, Expression* value);
    void set_context(PatternContext context);
    Variable* CreateTempVar(Expression* current_value);
    
   private:
    Expression* current_value_;
    DeclarationDescriptor* descriptor_;
    Parser* parser_;
  };
};

class Assignment {
 public:
  Token op();
  Expression* value();
  Expression* target();
};

void RewriteParameterInitializerScope(int* stack_limit, Expression* initializer,
                                     Scope* outer_scope, Scope* inner_scope);

#define DCHECK_EQ(a, b)