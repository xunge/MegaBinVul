#include <assert.h>
#include <string.h>

namespace AnyP {
    enum ProtocolType {
        PROTO_MAX
    };
    extern const char *ProtocolType_str[];
}

const char *AnyP::ProtocolType_str[] = {
    "MAX"
};

enum MatchDomainNameFlags {
    mdnRejectSubsubDomains,
    mdnHonorWildcards
};

int matchDomainName(const char *name1, const char *name2, MatchDomainNameFlags flags = static_cast<MatchDomainNameFlags>(0)) {
    return 0;
}

void debugs(int section, int level, const char *message) {}