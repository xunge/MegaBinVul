#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define OAMS_TRADITIONAL_GIS_ORDER 0
#define CE_Warning 1
#define CPLE_AppDefined 1

class OGRSpatialReference {
public:
    OGRSpatialReference(const char*);
    void SetWellKnownGeogCS(const char*);
    void SetAxisMappingStrategy(int);
    bool IsSame(OGRSpatialReference*);
    void exportToPrettyWkt(char**, int);
};

class OGRGeomFieldDefn {
public:
    void SetSpatialRef(OGRSpatialReference*);
};

class OGRFeatureDefn {
public:
    OGRFeatureDefn(const char*);
    const char* GetName();
    void Reference();
    void SetGeomType(int);
    int GetGeomFieldCount();
    OGRGeomFieldDefn* GetGeomFieldDefn(int);
    void AddFieldDefn(class OGRFieldDefn*);
};

class OGRFieldDefn {
public:
    OGRFieldDefn(const char*, int);
};

class OGRKMLDataSource {
public:
    bool IsFirstCTError();
    void IssuedFirstCTError();
};

class OGRCoordinateTransformation {};

OGRCoordinateTransformation* OGRCreateCoordinateTransformation(OGRSpatialReference*, OGRSpatialReference*);

char* CPLStrdup(const char*);
void CPLFree(void*);
void CPLError(int, int, const char*, ...);

enum OGRwkbGeometryType {
    wkbUnknown = 0,
    wkbPoint = 1,
    wkbLineString = 2,
    wkbPolygon = 3,
    wkbMultiPoint = 4,
    wkbMultiLineString = 5,
    wkbMultiPolygon = 6,
    wkbGeometryCollection = 7
};

enum OGRFieldType { OFTString };

struct OGRKMLLayer {
    OGRKMLDataSource* poDS_;
    OGRSpatialReference* poSRS_;
    OGRCoordinateTransformation* poCT_;
    OGRFeatureDefn* poFeatureDefn_;
    int iNextKMLId_;
    int nTotalKMLCount_;
    bool bWriter_;
    int nLayerNumber_;
    int nWroteFeatureCount_;
    bool bSchemaWritten_;
    char* pszName_;
    int nLastAsked;
    int nLastCount;
    bool bClosedForWriting;

    OGRKMLLayer(const char*, OGRSpatialReference*, bool, OGRwkbGeometryType, OGRKMLDataSource*);
    void SetDescription(const char*);
};