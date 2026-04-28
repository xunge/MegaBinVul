#include <stddef.h>

typedef void* OGRFeatureH;
typedef void* OGRLayerH;
typedef void* OGRGeometryH;

typedef struct {
    OGRLayerH hLayer;
    OGRFeatureH hLastFeature;
    int last_record_index_read;
    int nTileId;
} msOGRFileInfo;

typedef struct {
    int type;
    int numvalues;
    char **values;
    int index;
    int resultindex;
    int tileindex;
} shapeObj;

typedef struct {
    int debug;
    int numitems;
    int type;
} layerObj;

#define MS_DEBUGLEVEL_VV 2
#define MS_DEBUGLEVEL_VVV 3
#define MS_FAILURE 1
#define MS_SUCCESS 0
#define MS_DONE 2
#define MS_MISCERR 1
#define MS_OGRERR 2
#define MS_SHAPE_NULL 0
#define CE_Failure 1

#define ACQUIRE_OGR_LOCK
#define RELEASE_OGR_LOCK
#define CPL_FRMT_GIB "lld"
#define GIntBig long long
#define wkbUnknown 0
#define wkbFlatten(x) (x)

extern void msSetError(int, const char *, const char *, ...);
extern void msDebug(const char *, ...);
extern void msFreeShape(shapeObj *);
extern char **msOGRGetValues(layerObj *, OGRFeatureH);
extern int ogrConvertGeometry(OGRGeometryH, shapeObj *, int);
extern OGRGeometryH ogrGetLinearGeometry(OGRFeatureH);
extern int CPLGetLastErrorType();
extern const char* CPLGetLastErrorMsg();
extern void OGR_F_Destroy(OGRFeatureH);
extern OGRFeatureH OGR_L_GetNextFeature(OGRLayerH);
extern long OGR_F_GetFID(OGRFeatureH);
extern OGRGeometryH OGR_F_GetGeometryRef(OGRFeatureH);
extern int OGR_G_GetGeometryType(OGRGeometryH);