#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
typedef struct PToken PToken;
typedef struct ScanEnv ScanEnv;
typedef struct CClassNode CClassNode;
typedef struct IApplyCaseFoldArg IApplyCaseFoldArg;
typedef struct BagNode BagNode;
typedef unsigned int OnigCodePoint;
typedef unsigned int OnigOptionType;
typedef unsigned char UChar;

enum TokenSyms {
    TK_ALT,
    TK_EOT,
    TK_SUBEXP_OPEN,
    TK_SUBEXP_CLOSE,
    TK_STRING,
    TK_RAW_BYTE,
    TK_CODE_POINT,
    TK_QUOTE_OPEN,
    TK_CHAR_TYPE,
    TK_CHAR_PROPERTY,
    TK_CC_OPEN,
    TK_ANYCHAR,
    TK_ANYCHAR_ANYTIME,
    TK_BACKREF,
    TK_CALL,
    TK_ANCHOR,
    TK_REPEAT,
    TK_INTERVAL,
    TK_KEEP,
    TK_GENERAL_NEWLINE,
    TK_NO_NEWLINE,
    TK_TRUE_ANYCHAR,
    TK_TEXT_SEGMENT
};

#define INFINITE_REPEAT 0x7fffffff
#define ParseDepthLimit 4096
#define ONIGERR_MEMORY -1
#define ONIGERR_PARSER_BUG -2
#define ONIGERR_UNMATCHED_CLOSE_PARENTHESIS -3
#define ONIGERR_TOO_SHORT_MULTI_BYTE_STRING -4
#define ONIGERR_INVALID_WIDE_CHAR_VALUE -5
#define ONIGERR_TARGET_OF_REPEAT_OPERATOR_NOT_SPECIFIED -6
#define ONIGERR_TARGET_OF_REPEAT_OPERATOR_INVALID -7
#define ONIGERR_PARSE_DEPTH_LIMIT_OVER -8
#define ONIG_OPTION_IGNORECASE 1
#define ONIG_OPTION_ASCII_RANGE 2
#define ONIG_SYN_ALLOW_UNMATCHED_CLOSE_SUBEXP 1
#define ONIG_SYN_CONTEXT_INDEP_REPEAT_OPS 2
#define ONIG_SYN_CONTEXT_INVALID_REPEAT_OPS 4
#define ANCR_WORD_BOUNDARY 1
#define ANCR_NO_WORD_BOUNDARY 2
#define BAG_STOP_BACKTRACK 1
#define ONIGENC_CODE_TO_MBC_MAXLEN 6
#define ONIGENC_CTYPE_WORD 0
#define ONIGENC_CTYPE_SPACE 1
#define ONIGENC_CTYPE_DIGIT 2
#define ONIGENC_CTYPE_XDIGIT 3

struct Node {
    int type;
    union {
        struct {
            UChar* s;
            UChar* end;
            int raw;
        } str;
        struct {
            Node* car;
            Node* cdr;
        } list;
        struct {
            int lower;
            int upper;
            int greedy;
        } quant;
        CClassNode* cclass;
        BagNode* bag;
        Node* body;
    } u;
};

struct BagNode {
    int type;
    struct {
        OnigOptionType options;
    } o;
    Node* body;
};

struct PToken {
    int type;
    union {
        int c;
        int code;
        struct {
            int ctype;
            int not;
        } prop;
        struct {
            int num;
            int* refs;
            int ref1;
            int by_name;
#ifdef USE_BACKREF_WITH_LEVEL
            int exist_level;
            int level;
#endif
        } backref;
        struct {
            UChar* name;
            UChar* name_end;
            int gnum;
            int by_number;
        } call;
        int anchor;
        struct {
            int lower;
            int upper;
            int greedy;
            int possessive;
        } repeat;
    } u;
    UChar* backp;
    int escaped;
};

struct ScanEnv {
    struct {
        unsigned int behavior;
        struct {
            int esc;
        } meta_char_table;
    } syntax;
    OnigOptionType options;
    OnigOptionType case_fold_flag;
    void* enc;
    unsigned int parse_depth;
    int num_call;
    int has_call_zero;
};

struct CClassNode {
    int not;
};

struct IApplyCaseFoldArg {
    ScanEnv* env;
    CClassNode* cc;
    Node* alt_root;
    Node** ptail;
};

#define CHECK_NULL_RETURN_MEMERR(ptr) if ((ptr) == NULL) return ONIGERR_MEMORY
#define IS_NULL(ptr) ((ptr) == NULL)
#define IS_NOT_NULL(ptr) ((ptr) != NULL)
#define NULL_NODE NULL
#define IS_IGNORECASE(options) ((options) & ONIG_OPTION_IGNORECASE)
#define IS_WORD_ASCII(options) ((options) & ONIG_OPTION_ASCII_RANGE)
#define IS_WORD_ANCHOR_TYPE(type) ((type) == ANCR_WORD_BOUNDARY || (type) == ANCR_NO_WORD_BOUNDARY)
#define IS_SYNTAX_BV(syntax, flag) ((syntax).behavior & (flag))
#define MC_ESC(syntax) ((syntax).meta_char_table.esc)
#define STR_(node) (&(node)->u.str)
#define NODE_BODY(node) ((node)->u.body)
#define NODE_STRING_CLEAR_RAW(node) ((node)->u.str.raw = 0)
#define NODE_CAR(node) ((node)->u.list.car)
#define NODE_CDR(node) ((node)->u.list.cdr)
#define QUANT_(node) (&(node)->u.quant)
#define CCLASS_(node) ((node)->u.cclass)
#define BAG_(node) ((node)->u.bag)
#define NCCLASS_SET_NOT(cc) ((cc)->not = 1)

Node* node_new_empty(void);
Node* node_new_group(Node* target);
void onig_node_free(Node* node);
int parse_bag(Node** np, PToken* tok, int term, UChar** src, UChar* end, ScanEnv* env);
int fetch_token(PToken* tok, UChar** src, UChar* end, ScanEnv* env);
int parse_subexp(Node** np, PToken* tok, int term, UChar** src, UChar* end, ScanEnv* env, int group_head);
Node* node_new_str(UChar* s, UChar* end);
int onig_node_str_cat(Node* node, UChar* s, UChar* end);
Node* node_new_str_raw_char(UChar c);
int node_str_cat_char(Node* node, UChar c);
int enclen(void* enc, UChar* p);
Node* node_new_str_raw(UChar* s, UChar* end);
Node* node_new_ctype(int ctype, int not, OnigOptionType options);
Node* node_new_cclass(void);
void add_ctype_to_cc(CClassNode* cc, int ctype, int ascii_range, ScanEnv* env);
int parse_char_property(Node** np, PToken* tok, UChar** src, UChar* end, ScanEnv* env);
int parse_char_class(Node** np, PToken* tok, UChar** src, UChar* end, ScanEnv* env);
int ONIGENC_APPLY_ALL_CASE_FOLD(void* enc, OnigOptionType flag, int (*func)(OnigCodePoint, OnigCodePoint[], int, void*), void* arg);
int i_apply_case_fold(OnigCodePoint code, OnigCodePoint codes[], int num, void* arg);
Node* onig_node_new_alt(Node* left, Node* right);
Node* node_new_anychar(void);
Node* node_new_quantifier(int lower, int upper, int interval);
int set_quantifier(Node* qn, Node* target, int group, ScanEnv* env);
Node* node_new_bag(int type);
Node* node_drop_group(Node* node);
Node* node_new_list(Node* car, Node* cdr);
Node* node_new_backref(int num, int* refs, int by_name, ScanEnv* env);
Node* node_new_call(UChar* name, UChar* name_end, int gnum, int by_number);
Node* onig_node_new_anchor(int type, int ascii_mode);
int node_new_keep(Node** np, ScanEnv* env);
int node_new_general_newline(Node** np, ScanEnv* env);
int node_new_no_newline(Node** np, ScanEnv* env);
int node_new_true_anychar(Node** np, ScanEnv* env);
int make_text_segment(Node** np, ScanEnv* env);
int is_invalid_quantifier_target(Node* node);
UChar* find_str_position(OnigCodePoint* end_op, int n, UChar* start, UChar* end, UChar** nextp, void* enc);
int ONIGENC_MBC_MINLEN(void* enc);
int ONIGENC_IS_VALID_MBC_STRING(void* enc, UChar* p, UChar* end);
int ONIGENC_CODE_TO_MBC(void* enc, OnigCodePoint code, UChar buf[]);