#include <stddef.h>

typedef unsigned int txUnsigned;

typedef struct txTokenDescription {
    int token;
} txTokenDescription;

typedef struct txToken {
    // token fields
} txToken;

typedef struct txNode {
    struct txNode* next;
    txTokenDescription* description;
    int line;
    txUnsigned flags;
} txNode;

typedef struct txNodeList {
    txNode* first;
} txNodeList;

typedef struct txObjectNode {
    txNode base;
    txNodeList* items;
} txObjectNode;

typedef struct txPropertyNode {
    txNode base;
    txNode* value;
} txPropertyNode;

typedef struct txPropertyBindingNode {
    txNode base;
    txNode* binding;
} txPropertyBindingNode;

typedef struct txPropertyAtNode {
    txNode base;
    txNode* value;
} txPropertyAtNode;

typedef struct txPropertyBindingAtNode {
    txNode base;
    txNode* binding;
} txPropertyBindingAtNode;

typedef struct txParser {
    txNode* root;
    txToken* errorSymbol;
    txToken* SyntaxErrorSymbol;
} txParser;

extern txTokenDescription gxTokenDescriptions[];

enum {
    XS_TOKEN_PROPERTY,
    XS_TOKEN_PROPERTY_BINDING,
    XS_TOKEN_PROPERTY_AT,
    XS_TOKEN_PROPERTY_BINDING_AT,
    XS_TOKEN_SPREAD,
    XS_TOKEN_OBJECT_BINDING
};

#define mxSpreadFlag (1 << 0)

txNode* fxBindingFromExpression(txParser* parser, txNode* node, txToken token);
txNode* fxRestBindingFromExpression(txParser* parser, txNode* node, txToken token, int flag);
void fxPushNode(txParser* parser, txNode* node);
void fxPushNodeStruct(txParser* parser, int count, int token, int line);
txNode* fxPopNode(txParser* parser);