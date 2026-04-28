#include <string_view>
#include <map>
#include <string>
#include <cstddef>

struct Topic {
    std::map<size_t, std::pair<std::string_view, std::string_view>> messages;
    Topic* terminatingWildcardChild;
    Topic* wildcardChild;
    bool triggered;
    std::map<std::string_view, Topic*> children;
};

extern Topic* triggeredTopics[64];
extern size_t numTriggeredTopics;
extern size_t messageId;

void drain();