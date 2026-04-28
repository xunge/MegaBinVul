#include <stdlib.h>

typedef struct rdpBitmap rdpBitmap;

struct BITMAP_V2_CELL {
    unsigned int number;
    rdpBitmap** entries;
};

struct rdpUpdate {
    void* context;
};

struct freerdp {
    struct rdpUpdate* update;
};

struct rdpSettings {
    struct freerdp* instance;
    unsigned int BitmapCacheV2NumCells;
    struct {
        unsigned int numEntries;
    } BitmapCacheV2CellInfo[];
};

struct rdpBitmapCache {
    struct rdpSettings* settings;
    struct rdpUpdate* update;
    void* context;
    unsigned int maxCells;
    struct BITMAP_V2_CELL* cells;
};

typedef struct rdpBitmapCache rdpBitmapCache;
typedef struct rdpSettings rdpSettings;
typedef struct freerdp freerdp;
typedef struct BITMAP_V2_CELL BITMAP_V2_CELL;