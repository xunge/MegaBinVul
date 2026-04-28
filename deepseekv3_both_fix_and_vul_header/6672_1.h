#include <stdint.h>

#define SBRDEC_OK 0
#define SBRDEC_UNSUPPORTED_CONFIG 1
#define MAX_NUM_PATCHES 5
#define MAX_NUM_NOISE_VALUES 5
#define SHIFT_START_SB 0
#define NUM_WHFACTOR_TABLE_ENTRIES 5

typedef uint8_t UCHAR;
typedef uint32_t UINT;
typedef int SBR_ERROR;

typedef struct {
    int off;
    int transitionLevel;
    int lowLevel;
    int midLevel;
    int highLevel;
} WH_FACTORS;

typedef struct {
    int guardStartBand;
    int targetStartBand;
    int sourceStartBand;
    int targetBandOffs;
    int numBandsInPatch;
    int sourceStopBand;
} PATCH_PARAM;

typedef struct {
    PATCH_PARAM *patchParam;
    int noOfPatches;
    int lbStartPatching;
    int lbStopPatching;
    UCHAR bwBorders[MAX_NUM_NOISE_VALUES];
    WH_FACTORS whFactors;
} TRANSPOSER_SETTINGS;

typedef struct {
    TRANSPOSER_SETTINGS *pSettings;
} *HANDLE_SBR_LPP_TRANS;

extern int FDK_sbrDecoder_sbr_whFactorsIndex[NUM_WHFACTOR_TABLE_ENTRIES];
extern int FDK_sbrDecoder_sbr_whFactorsTable[NUM_WHFACTOR_TABLE_ENTRIES][5];

int fixMin(int a, int b);
int fixMax(int a, int b);
int findClosestEntry(int desiredBorder, UCHAR *v_k_master, UCHAR numMaster, int flag);