#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef void* OGRDataSourceH;
typedef void* OGRLayerH;
typedef void* OGRSFDriverH;
typedef void* OGRFeatureH;

typedef struct {
    char *pszFname;
    char *pszLayerDef;
    int nLayerIndex;
    OGRDataSourceH hDS;
    OGRLayerH hLayer;
    int nTileId;
    void *poCurTile;
    bool rect_is_defined;
    struct {
        double minx;
        double maxx;
        double miny;
        double maxy;
    } rect;
    int last_record_index_read;
    char *dialect;
    char *pszSelect;
    char *pszSpatialFilterTableName;
    char *pszMainTableName;
    char *pszRowId;
    bool bIsOKForSQLCompose;
    bool bPaging;
} msOGRFileInfo;

typedef struct {
    char *name;
    char *data;
    struct {
        char *mappath;
        char *shapepath;
    } *map;
    int debug;
} layerObj;

#define MS_OGRERR 1
#define MS_FALSE 0
#define MS_MAXPATHLEN 1024
#define EQUALN(a,b,n) (strncasecmp(a,b,n)==0)
#define EQUAL(a,b) (strcasecmp(a,b)==0)
#define ACQUIRE_OGR_LOCK
#define RELEASE_OGR_LOCK

extern void msOGRInitialize(void);
extern char *msDecryptStringTokens(void *map, const char *str);
extern void msFree(void *ptr);
extern void msSetError(int code, const char *fmt, const char *func, ...);
extern void msDebug(const char *fmt, ...);
extern char *msStrdup(const char *str);
extern char *msStringConcatenate(char *str, const char *append);
extern void *msConnPoolRequest(layerObj *layer);
extern void msConnPoolRegister(layerObj *layer, void *conn, void (*close_func)(void*));
extern void msConnPoolRelease(layerObj *layer, void *conn);
extern void msOGRCloseConnection(void *conn);
extern char *msTryBuildPath3(char *path, const char *dir1, const char *dir2, const char *file);
extern char *msTryBuildPath(char *path, const char *dir, const char *file);

static inline char *CPLStrdup(const char *str) {
    return str ? strdup(str) : NULL;
}

static inline void CPLFree(void *ptr) {
    free(ptr);
}

static inline char **CSLTokenizeStringComplex(const char *str, const char *delim, int bHonourStrings, int bAllowEmptyTokens) {
    return NULL;
}

static inline int CSLCount(char **papszStrList) {
    return 0;
}

static inline void CSLDestroy(char **papszStrList) {
}

static inline const char *CPLGetLastErrorMsg(void) {
    return "";
}

static inline void CPLErrorReset(void) {
}

static inline void CPLPushErrorHandler(void (*handler)(void)) {
}

static inline void CPLPopErrorHandler(void) {
}

static inline void CPLQuietErrorHandler(void) {
}

static inline OGRDataSourceH OGROpen(const char *pszName, int bUpdate, void *pahDriverList) {
    return NULL;
}

static inline int OGR_DS_GetLayerCount(OGRDataSourceH hDS) {
    return 0;
}

static inline OGRLayerH OGR_DS_GetLayer(OGRDataSourceH hDS, int iLayer) {
    return NULL;
}

static inline OGRLayerH OGR_DS_ExecuteSQL(OGRDataSourceH hDS, const char *pszSQL, void *pSpatialFilter, const char *pszDialect) {
    return NULL;
}

static inline void OGR_DS_ReleaseResultSet(OGRDataSourceH hDS, OGRLayerH hLayer) {
}

static inline OGRSFDriverH OGR_DS_GetDriver(OGRDataSourceH hDS) {
    return NULL;
}

static inline const char *OGR_Dr_GetName(OGRSFDriverH hDriver) {
    return "";
}

static inline const char *OGR_DS_GetName(OGRDataSourceH hDS) {
    return "";
}

static inline void *OGR_L_GetLayerDefn(OGRLayerH hLayer) {
    return NULL;
}

static inline const char *OGR_FD_GetName(void *hDefn) {
    return "";
}

static inline const char *OGR_L_GetName(OGRLayerH hLayer) {
    return "";
}

static inline OGRFeatureH OGR_L_GetNextFeature(OGRLayerH hLayer) {
    return NULL;
}

static inline int OGR_L_GetFeatureCount(OGRLayerH hLayer, int bForce) {
    return 0;
}

static inline void OGR_F_Destroy(OGRFeatureH hFeat) {
}

static inline const char *OGR_F_GetFieldAsString(OGRFeatureH hFeat, int iField) {
    return "";
}

static inline void *CPLCalloc(size_t nCount, size_t nSize) {
    return calloc(nCount, nSize);
}