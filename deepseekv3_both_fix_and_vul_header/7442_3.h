#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using ViewType = uint64_t;

#define INFO 0
#define PBFT_LOG(level) std::cout
#define LOG_DESC(desc) desc
#define LOG_KV(key, value) key << "=" << value

class Config;

class ConsensusNode {
public:
    uint64_t weight();
};

class Config {
public:
    ViewType toView();
    void setToView(ViewType);
    ConsensusNode* getConsensusNodeByIndex(uint64_t);
    uint64_t maxFaultyQuorum();
    std::string printCurrentState();
};

class PBFTCacheProcessor {
public:
    ViewType tryToTriggerFastViewChange();
    std::map<ViewType, std::map<uint64_t, bool>> m_viewChangeCache;
    Config* m_config;
};