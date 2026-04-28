#include <time.h>

struct LeakyBucket {
    int tokensPerSec;
    int maxTokens;
    int currentTokens;
    time_t lastUpdate;
    LeakyBucket();
    time_t now();
};