#include <stddef.h>
#include <stdint.h>

typedef struct AR_ExpNode AR_ExpNode;
typedef struct cypher_astnode_t cypher_astnode_t;
typedef struct AST AST;
typedef struct AnnotationCtx AnnotationCtx;

typedef struct {
    int type;
    union {
        int64_t intval;
        double doubleval;
        char *stringval;
        void *ptrval;
    } v;
} SIValue;

extern AST *QueryCtx_GetAST(void);
extern void ErrorCtx_SetError(const char *error);
extern AR_ExpNode *AR_EXP_NewConstOperandNode(SIValue val);
extern SIValue SI_NullVal(void);
extern AnnotationCtx *AST_AnnotationCtxCollection_GetNamedPathsCtx(void *collection);
extern const cypher_astnode_t *cypher_astnode_get_annotation(AnnotationCtx *ctx, const cypher_astnode_t *node);
extern AR_ExpNode *_AR_EXP_FromASTNode(const cypher_astnode_t *node);
extern AR_ExpNode *_AR_EXP_FromIdentifierExpression(const cypher_astnode_t *expr);

struct AST {
    void *anot_ctx_collection;
};