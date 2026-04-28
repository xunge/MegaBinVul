#include <stdlib.h>
#include <string.h>

class IStorage {
public:
    enum { TYPE_ALL };
};

class IGraphics {
public:
    enum { TEXLOAD_MULTI_DIMENSION };
    bool LoadPNG(void *pImg, const char *pFilename, int StorageType);
    void *LoadTextureRaw(int Width, int Height, int Format, void *pData, int StoreFormat, int Flags);
};

class CDataFileReader {
public:
    bool Open(IStorage *pStorage, const char *pFilename, int StorageType);
    void *FindItem(int Type, int ID);
    void GetType(int Type, int *pStart, int *pNum);
    void *GetItem(int Index, int *pType, int *pID);
    void *GetData(int Index);
    void UnloadData(int Index);
    void *GetDataSwapped(int Index);
};

struct CTile {
    int m_Index;
};

struct CQuad {
};

struct CEnvPoint {
    int m_Time;
    int m_Curvetype;
    int m_aValues[4];
};

struct CEnvPoint_v1 {
    int m_Time;
    int m_Curvetype;
    int m_aValues[4];
};

template<class T>
class CArray {
public:
    void add(T item) {}
    int size() { return 0; }
    void set_size(int size) {}
    T& operator[](int index) { static T t; return t; }
    T* base_ptr() { return nullptr; }
};

class CEditorImage {
public:
    void *m_pEditor;
    int m_External;
    int m_Width;
    int m_Height;
    int m_Format;
    void *m_pData;
    void *m_Texture;
    char m_aName[128];
    CEditorImage(void *pEditor) : m_pEditor(pEditor) {}
    void LoadAutoMapper() {}
};

class CLayer {
public:
    int m_Flags;
};

class CLayerTiles : public CLayer {
public:
    void *m_pEditor;
    int m_Width;
    int m_Height;
    int m_Color;
    int m_ColorEnv;
    int m_ColorEnvOffset;
    int m_Image;
    int m_Game;
    char m_aName[128];
    CTile *m_pTiles;
    CLayerTiles(int Width, int Height) : m_Width(Width), m_Height(Height) {}
    void ExtractTiles(CTile *pData) {}
};

class CLayerGame : public CLayerTiles {
public:
    CLayerGame(int Width, int Height) : CLayerTiles(Width, Height) {}
};

class CLayerQuads : public CLayer {
public:
    void *m_pEditor;
    int m_Image;
    char m_aName[128];
    CArray<CQuad> m_lQuads;
};

class CLayerGroup {
public:
    int m_ParallaxX;
    int m_ParallaxY;
    int m_OffsetX;
    int m_OffsetY;
    int m_UseClipping;
    int m_ClipX;
    int m_ClipY;
    int m_ClipW;
    int m_ClipH;
    char m_aName[128];
    void AddLayer(CLayer *pLayer) {}
};

class CEnvelope {
public:
    int m_Synchronized;
    char m_aName[128];
    CArray<CEnvPoint> m_lPoints;
    CEnvelope(int Channels) {}
};

class CEditor {
public:
    IGraphics *Graphics() { return nullptr; }
};

class CEditorMap {
public:
    struct MapInfo {
        char m_aAuthor[128];
        char m_aVersion[128];
        char m_aCredits[128];
        char m_aLicense[128];
    } m_MapInfo;
    
    CEditor *m_pEditor;
    CArray<CEditorImage*> m_lImages;
    CArray<CEnvelope*> m_lEnvelopes;
    
    void Clean() {}
    CLayerGroup *NewGroup() { return new CLayerGroup(); }
    void MakeGameLayer(CLayerTiles *pTiles) {}
    void MakeGameGroup(CLayerGroup *pGroup) {}
    int Load(IStorage *pStorage, const char *pFileName, int StorageType);
};

struct CMapItemVersion {
    enum { CURRENT_VERSION = 1 };
    int m_Version;
};

struct CMapItemInfo {
    int m_Version;
    int m_Author;
    int m_MapVersion;
    int m_Credits;
    int m_License;
};

struct CMapItemImage {
    int m_Version;
    int m_Width;
    int m_Height;
    int m_External;
    int m_ImageName;
    int m_ImageData;
    int m_Format;
};

struct CMapItemGroup {
    enum { CURRENT_VERSION = 3 };
    int m_Version;
    int m_ParallaxX;
    int m_ParallaxY;
    int m_OffsetX;
    int m_OffsetY;
    int m_UseClipping;
    int m_ClipX;
    int m_ClipY;
    int m_ClipW;
    int m_ClipH;
    int m_StartLayer;
    int m_NumLayers;
    int m_aName[3];
};

struct CMapItemLayer {
    int m_Type;
    int m_Flags;
};

struct CMapItemLayerTilemap {
    int m_Version;
    int m_Width;
    int m_Height;
    int m_Flags;
    int m_Color;
    int m_ColorEnv;
    int m_ColorEnvOffset;
    int m_Image;
    int m_Data;
    int m_aName[3];
};

struct CMapItemLayerQuads {
    int m_Version;
    int m_NumQuads;
    int m_Data;
    int m_Image;
    int m_aName[3];
};

struct CMapItemEnvelope {
    int m_Version;
    int m_Channels;
    int m_StartPoint;
    int m_NumPoints;
    int m_aName[8];
    int m_Synchronized;
};

struct CImageInfo {
    enum { FORMAT_RGB = 0, FORMAT_RGBA = 1, FORMAT_AUTO = 2 };
};

#define MAPITEMTYPE_VERSION 0
#define MAPITEMTYPE_INFO 1
#define MAPITEMTYPE_IMAGE 2
#define MAPITEMTYPE_LAYER 3
#define MAPITEMTYPE_GROUP 4
#define MAPITEMTYPE_ENVPOINTS 5
#define MAPITEMTYPE_ENVELOPE 6

#define LAYERTYPE_TILES 0
#define LAYERTYPE_QUADS 1

#define TILESLAYERFLAG_GAME 1

#define IO_MAX_PATH_LENGTH 512
#define ENTITY_OFFSET 1

static inline int MakeVersion(int a, int b) { return (a<<16)+b; }
static inline int MakeVersion(int a, const CMapItemLayerTilemap& item) { return (a<<16)+item.m_Version; }
static inline int minimum(int a, int b) { return a < b ? a : b; }
static inline void str_copy(char *dst, const char *src, int size) { strncpy(dst, src, size); }
static inline void str_format(char *buffer, int buffer_size, const char *format, ...) {}
static inline void *mem_alloc(int size) { return malloc(size); }
static inline void mem_copy(void *dst, const void *src, int size) { memcpy(dst, src, size); }
static inline void mem_zero(void *dst, int size) { memset(dst, 0, size); }
static inline void IntsToStr(const int *pInts, int Num, char *pStr) {}