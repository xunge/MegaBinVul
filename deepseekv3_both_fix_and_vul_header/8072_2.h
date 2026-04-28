#include <stdbool.h>

struct Challenger {
    bool operator==(const Challenger& that) const;
    bool Equals(const Challenger& that) const;
};

struct AuthChallengeInfo {
    bool is_proxy;
    Challenger challenger;
    int scheme;
    int realm;
    bool Equals(const AuthChallengeInfo& that) const;
};