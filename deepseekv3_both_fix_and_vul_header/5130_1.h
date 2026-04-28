#include <ctype.h>

class SExpressionParser {
public:
    char* input;
    int line;
    char* lineStart;
    void parseDebugLocation();
    void skipWhitespace();
};