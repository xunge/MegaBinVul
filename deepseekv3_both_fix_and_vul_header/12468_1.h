#include <stdbool.h>

enum lcShadingMode
{
    Wireframe,
    Flat
};

#define LC_MESH_LINES 1
#define LC_MESH_CONDITIONAL_LINES 2
#define LC_MESH_TRIANGLES 4
#define LC_MESH_TEXTURED_TRIANGLES 8

struct lcPreferences
{
    bool mDrawEdgeLines;
    bool mDrawConditionalLines;
    float mLineWidth;
};

struct lcContext
{
    void SetViewMatrix(const float* matrix);
};

class lcPiecesLibrary
{
public:
    void UpdateBuffers(lcContext* Context);
    void UploadTextures(lcContext* Context);
};

class lcScene
{
public:
    void Draw(lcContext* Context) const;
    void DrawOpaqueMeshes(lcContext* Context, bool b1, int types, bool b2, bool b3) const;
    void DrawTranslucentMeshes(lcContext* Context, bool b1, bool b2, bool b3, bool b4) const;
    
    float mViewMatrix[16];
    lcShadingMode mShadingMode;
    bool mTranslucentFade;
    bool mHasFadedParts;
    void (*mPreTranslucentCallback)();
    bool mAllowWireframe;
};

lcPreferences lcGetPreferences();
lcPiecesLibrary* lcGetPiecesLibrary();