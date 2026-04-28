#include <stdint.h>
#include <climits>
#include <limits>
#include <cstddef>

typedef struct FXFT_FaceRec_ {
    unsigned long face_flags;
} FXFT_FaceRec;
typedef FXFT_FaceRec* FXFT_Face;

typedef struct FXFT_Matrix_ {
    int xx, xy;
    int yx, yy;
} FXFT_Matrix;

typedef struct FXFT_Vector_ {
    int x, y;
} FXFT_Vector;

typedef struct FXFT_Outline_Funcs_ {
    int (*move_to)(const FXFT_Vector* to, void* user);
    int (*line_to)(const FXFT_Vector* to, void* user);
    int (*conic_to)(const FXFT_Vector* control, const FXFT_Vector* to, void* user);
    int (*cubic_to)(const FXFT_Vector* control1, const FXFT_Vector* control2, const FXFT_Vector* to, void* user);
    int shift;
    int delta;
} FXFT_Outline_Funcs;

struct CFX_PathData {
    void SetPointCount(int count);
    void TrimPoints(int count);
    struct PathPoint* GetPoints();
};

struct PathPoint {
    int m_Flag;
};

struct OUTLINE_PARAMS {
    int m_bCount;
    int m_PointCount;
    PathPoint* m_pPoints;
    int m_CurX;
    int m_CurY;
    double m_CoordUnit;
};

struct SubstFont {
    int m_ItalicAngle;
    int m_SubstFlags;
    int m_Weight;
    int m_Charset;
};

class ScopedFontTransform {
public:
    ScopedFontTransform(FXFT_Face face, FXFT_Matrix* matrix);
    ~ScopedFontTransform();
};

#define FXFONT_SUBST_MM (1 << 0)
#define FXFONT_SHIFTJIS_CHARSET 1
#define TRUE 1
#define FALSE 0
#define FXPT_CLOSEFIGURE (1 << 0)
#define ANGLESKEW_ARRAY_SIZE 16
#define WEIGHTPOW_ARRAY_SIZE 16
#define FT_FACE_FLAG_SFNT (1 << 0)
#define FXFT_LOAD_NO_BITMAP (1 << 1)
#define FT_LOAD_NO_HINTING (1 << 0)
#define FT_IS_TRICKY(face) 0

extern int g_AngleSkew[];
extern int g_WeightPow[];
extern int g_WeightPow_SHIFTJIS[];

int _Outline_MoveTo(const FXFT_Vector* to, void* user);
int _Outline_LineTo(const FXFT_Vector* to, void* user);
int _Outline_ConicTo(const FXFT_Vector* control, const FXFT_Vector* to, void* user);
int _Outline_CubicTo(const FXFT_Vector* control1, const FXFT_Vector* control2, const FXFT_Vector* to, void* user);
void _Outline_CheckEmptyContour(OUTLINE_PARAMS* params);

void FXFT_Set_Pixel_Sizes(FXFT_Face face, int pixel_width, int pixel_height);
int FXFT_Load_Glyph(FXFT_Face face, uint32_t glyph_index, int load_flags);
void FXFT_Outline_Embolden(void* outline, int strength);
void FXFT_Outline_Decompose(void* outline, FXFT_Outline_Funcs* funcs, void* user);
void* FXFT_Get_Glyph_Outline(FXFT_Face face);
void AdjustMMParams(uint32_t glyph_index, int dest_width, int weight);

class CFX_Font {
public:
    FXFT_Face m_Face;
    SubstFont* m_pSubstFont;
    bool m_bVertical;
    CFX_PathData* LoadGlyphPath(uint32_t glyph_index, int dest_width);
};