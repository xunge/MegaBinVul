#include <stdbool.h>

struct SkChunkAlloc;

struct SkOpGlobalState {
    enum Phase {
        kIntersecting,
        kWalking
    };
    void setPhase(Phase);
    bool angleCoincidence();
};

struct SkOpContourHead {
    struct SkOpGlobalState* globalState();
};

struct SkOpCoincidence {
    bool fixAligned();
    bool addMissing(struct SkChunkAlloc*);
    bool expand();
    bool addExpanded(struct SkChunkAlloc*);
    bool mark();
    bool apply();
    void findOverlaps(struct SkOpCoincidence*, struct SkChunkAlloc*);
    bool isEmpty();
    void debugShowCoincidence();
};

bool moveMultiples(struct SkOpContourHead*);
void findCollapsed(struct SkOpContourHead*);
void moveNearby(struct SkOpContourHead*);
void align(struct SkOpContourHead*);
void addAlignIntersections(struct SkOpContourHead*, struct SkChunkAlloc*);
bool missingCoincidence(struct SkOpContourHead*, struct SkOpCoincidence*, struct SkChunkAlloc*);
void calcAngles(struct SkOpContourHead*, struct SkChunkAlloc*);
void sortAngles(struct SkOpContourHead*);
void DebugShowActiveSpans(struct SkOpContourHead*);

#define DEBUG_COINCIDENCE_HEALTH(contourList, str)
#define DEBUG_VALIDATE 0
#define PATH_OPS_DEBUG_VALIDATE_PARAMS(globalState)
#define DEBUG_ACTIVE_SPANS 0