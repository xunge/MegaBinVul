#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double minx, miny, maxx, maxy;
} rectObj;

typedef struct {
    int nProperties;
} sortByObj;

typedef struct {
    char *native_string;
    char *string;
} filterObj;

typedef struct {
    char **items;
    int numitems;
    sortByObj sortBy;
    int debug;
    int maxfeatures;
    int startindex;
    filterObj filter;
    char *name;
    char *(*GetProcessingKey)(void *layer, const char *key);
} layerObj;

typedef struct {
    void *hLayer;
    void *hDS;
    char *pszSelect;
    char *pszLayerDef;
    bool bIsOKForSQLCompose;
    int nLayerIndex;
    char *dialect;
    bool rect_is_defined;
    rectObj rect;
    bool bPaging;
    char *pszMainTableName;
    char *pszRowId;
    char *pszSpatialFilterTableName;
    int last_record_index_read;
} msOGRFileInfo;

#define MS_MISCERR 1
#define MS_OGRERR 2
#define MS_FAILURE 0
#define MS_SUCCESS 1
#define MS_DEBUGLEVEL_VVV 5
#define EQUAL(a,b) (strcasecmp(a,b)==0)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define ACQUIRE_OGR_LOCK
#define RELEASE_OGR_LOCK

int msSetError(int code, const char *message, const char *function, ...);
char *msStrdup(const char *string);
char *msStringConcatenate(char *dest, const char *src);
void msFree(void *ptr);
void *msSmallMalloc(size_t size);
char *msLayerBuildSQLOrderBy(layerObj *layer);
void msOGRLayerInitItemInfo(layerObj *layer);
void msDebug(const char *format, ...);
char *msLayerGetProcessingKey(layerObj *layer, const char *key);
char *strcasestr(const char *haystack, const char *needle);

typedef void* OGRGeometryH;
typedef void* OGRLayerH;
typedef void* OGRDataSourceH;
#define wkbNone 0
#define wkbPoint 1
#define wkbLineString 2
#define wkbPolygon 3
#define wkbLinearRing 4
#define OGRERR_NONE 0

const char *OGR_L_GetGeometryColumn(OGRLayerH hLayer);
const char *OGR_L_GetFIDColumn(OGRLayerH hLayer);
const char *OGR_FD_GetName(void *hLayerDefn);
void *OGR_L_GetLayerDefn(OGRLayerH hLayer);
int OGR_L_GetGeomType(OGRLayerH hLayer);
void OGR_DS_ReleaseResultSet(OGRDataSourceH hDS, OGRLayerH hLayer);
OGRLayerH OGR_DS_ExecuteSQL(OGRDataSourceH hDS, const char *pszSQL, 
                           OGRGeometryH hSpatialFilter, const char *pszDialect);
void OGR_L_SetSpatialFilter(OGRLayerH hLayer, OGRGeometryH hGeom);
int OGR_L_SetAttributeFilter(OGRLayerH hLayer, const char *pszQuery);
void OGR_L_ResetReading(OGRLayerH hLayer);
OGRGeometryH OGR_G_CreateGeometry(int eGeometryType);
void OGR_G_SetPoint_2D(OGRGeometryH hGeom, int i, double x, double y);
void OGR_G_AddPoint_2D(OGRGeometryH hGeom, double x, double y);
void OGR_G_AddGeometryDirectly(OGRGeometryH hGeom, OGRGeometryH hNewSubGeom);
void OGR_G_DestroyGeometry(OGRGeometryH hGeom);
const char *CPLGetLastErrorMsg(void);
void CPLErrorReset(void);