#include <stdio.h>
#include <vector>

#define DEBUG_AUDIONODE_REFERENCES 1
#define ASSERT(expr) ((void)0)

struct AudioContext {
    bool m_isInitialized;
    std::vector<void*> m_referencedNodes;
    std::vector<void*> m_finishedNodes;
    std::vector<void*> m_automaticPullNodes;
    bool m_automaticPullNodesNeedUpdating;
    std::vector<void*> m_renderingAutomaticPullNodes;
    std::vector<void*> m_suspendResolvers;
    std::vector<void*> m_resumeResolvers;
    
    ~AudioContext();
};