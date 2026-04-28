#include <map>

struct Expression;
struct Location {
    // empty definition to make it complete type
};
struct Function {
    std::map<Expression*, Location> debugLocations;
};
struct Element {
    Location* startLoc;
};
struct SExpressionWasmBuilder {
    Function* currFunction;
    Expression* parseExpression(Element& s);
};

Expression* makeExpression(Element& s);
Location getDebugLocation(Location loc);