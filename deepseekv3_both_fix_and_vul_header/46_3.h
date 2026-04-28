#include <memory>

struct VariableDeclaration {
    virtual ~VariableDeclaration() = default;
};

struct ContractDefinition : public VariableDeclaration {
};

struct Expression {
    virtual ~Expression() = default;
};

struct Annotation {
    VariableDeclaration const* referencedDeclaration;
};

struct Identifier : public Expression {
    Annotation const& annotation() const;
};

struct MemberAccess : public Expression {
    Expression const& expression() const;
    Annotation const& annotation() const;
};

struct SMTEncoder {
    struct Context {
        bool knownVariable(VariableDeclaration const&) const;
    };
    Context m_context;
    VariableDeclaration const* identifierToVariable(Expression const& _expr) const;
    VariableDeclaration const* expressionToDeclaration(Expression const& _expr) const;
    Expression const* cleanExpression(Expression const& _expr) const;
};

void solAssert(bool condition, char const* message);