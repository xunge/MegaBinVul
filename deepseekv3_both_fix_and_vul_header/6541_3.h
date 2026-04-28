#include <string>
#include <vector>
#include <utility>
#include <optional>
#include <cassert>

#define MATCH_POLICY_ACTION 0

using std::string;

enum class TokenID {
    Version,
    Id,
    Sid,
    Effect,
    Principal,
    NotPrincipal,
    Action,
    NotAction,
    Resource,
    NotResource
};

enum class TokenKind {
    version_key,
    effect_key,
    princ_type,
    cond_key
};

enum class Version {};
enum class Effect {};

struct Token {
    TokenID id;
    TokenKind kind;
    int specific;
};

struct Principal {
    static Principal wildcard();
};

struct ARN {
    std::string account;
    static std::optional<ARN> parse(std::pair<const char*, size_t>, bool);
};

struct Condition {
    std::vector<std::string> vals;
};

struct ActionPair {
    std::string name;
    int bit;
};

struct Statement {
    std::optional<std::string> sid;
    Effect effect;
    std::optional<Principal> princ;
    std::optional<Principal> noprinc;
    int action;
    int notaction;
    std::optional<ARN> resource;
    std::optional<ARN> notresource;
    std::vector<Condition> conditions;
};

struct Policy {
    Version version;
    std::string id;
    std::vector<Statement> statements;
};

struct State {
    Token* w;
};

struct Parser {
    Policy policy;
    std::vector<State> s;
    class CephContext* cct;
    struct TokenTable {
        const Token* lookup(const char*, size_t);
    } tokens;
    std::string tenant;
};

struct ParseState {
    Parser* pp;
    Token* w;
    bool arraying;
    std::vector<ActionPair> actpairs;
    bool do_string(CephContext* cct, const char* s, size_t l);
};

class CephContext {
public:
    class Dout {
    public:
        Dout& operator<<(const std::string&);
        Dout& operator<<(const class Dendl&);
    };
    Dout ldout(int);
};

class Dendl {};

#define ceph_assert(expr) assert(expr)
#define ldout(cct, level) (cct)->ldout(level)
#define dendl Dendl()

std::optional<Principal> parse_principal(CephContext*, TokenID, std::string);
bool match_policy(std::pair<const char*, size_t>, const std::string&, int);