#include <stdlib.h>
#include <stdio.h>

typedef struct SWFShape_s {
    int isEnded;
    int isMorph;
    int useVersion;
} *SWFShape;

typedef struct SWFFillStyle_s* SWFFillStyle;
typedef struct SWFCharacter_s* SWFCharacter;

#define NOFILL NULL
#define SWF_SHAPE_FILLSTYLE0FLAG (1 << 0)
#define SWF_SHAPE1 1

typedef struct {
    struct {
        struct {
            int leftFill;
            int flags;
        } *stateChange;
    } record;
} ShapeRecord;

extern ShapeRecord addStyleRecord(SWFShape shape);
extern int getFillIdx(SWFShape shape, SWFFillStyle fill);
extern void SWFFillStyle_addDependency(SWFFillStyle fill, SWFCharacter character);
extern int addFillStyle(SWFShape shape, SWFFillStyle fill);
extern void SWF_error(const char *msg);