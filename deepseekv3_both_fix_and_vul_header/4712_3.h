#include <stdint.h>
#include <limits>
#include <cstddef>

struct CFX_GlyphBitmap {
    struct {
        void Create(int width, int height, int format);
        int GetPitch() const;
        uint8_t* GetBuffer();
    } m_Bitmap;
    int m_Left;
    int m_Top;
};

struct CFX_Matrix {
    double GetA() const;
    double GetB() const;
    double GetC() const;
    double GetD() const;
};

struct CFX_SubstFont {
    bool m_bSubstOfCJK;
    bool m_bItlicCJK;
    int m_ItalicAngle;
    int m_Weight;
    int m_WeightCJK;
    int m_Charset;
    int m_SubstFlags;
};

struct CFX_Font {
    const CFX_SubstFont* GetSubstFont() const;
    bool IsVertical() const;
    void AdjustMMParams(uint32_t glyph_index, int dest_width, int weight);
};

struct FXFT_FaceRec_ {
    unsigned long face_flags;
};

typedef FXFT_FaceRec_* FXFT_Face;

struct CFX_FaceCache {
    FXFT_Face m_Face;
    CFX_GlyphBitmap* RenderGlyph(CFX_Font* pFont, uint32_t glyph_index, int bFontStyle, const CFX_Matrix* pMatrix, int dest_width, int anti_alias);
};

class CFX_FontMgr {
public:
    void* GetFTLibrary();
};

struct CFX_GEModule {
    static CFX_GEModule* Get();
    CFX_FontMgr* GetFontMgr();
    const uint8_t* GetTextGammaTable();
};

typedef int FX_BOOL;
#define TRUE 1
#define FALSE 0

#define FXFONT_SHIFTJIS_CHARSET 128
#define FXFONT_SUBST_MM 0x01
#define ANGLESKEW_ARRAY_SIZE 20
#define WEIGHTPOW_ARRAY_SIZE 20

#define FT_FACE_FLAG_SFNT (1 << 0)
#define FXFT_LOAD_NO_BITMAP (1 << 0)
#define FT_LOAD_NO_HINTING (1 << 1)
#define FT_LOAD_NO_SCALE (1 << 2)
#define FT_LCD_FILTER_DEFAULT 0
#define FXFT_RENDER_MODE_MONO 0
#define FXFT_RENDER_MODE_LCD 1
#define FXFT_PIXEL_MODE_MONO 0

#define FXDIB_1bppMask 1
#define FXDIB_8bppMask 8

extern const int g_AngleSkew[ANGLESKEW_ARRAY_SIZE];
extern const int g_WeightPow_SHIFTJIS[WEIGHTPOW_ARRAY_SIZE];
extern const int g_WeightPow_11[WEIGHTPOW_ARRAY_SIZE];

struct FXFT_Matrix {
    signed long xx;
    signed long xy;
    signed long yx;
    signed long yy;
};

class ScopedFontTransform {
public:
    ScopedFontTransform(FXFT_Face face, FXFT_Matrix* matrix);
    ~ScopedFontTransform();
};

int FXFT_Load_Glyph(FXFT_Face face, uint32_t glyph_index, int load_flags);
int FXFT_Render_Glyph(FXFT_Face face, int render_mode);
void FXFT_Outline_Embolden(void* outline, int strength);
void FXFT_Library_SetLcdFilter(void* library, int filter);
void* FXFT_Get_Glyph_Outline(FXFT_Face face);
void* FXFT_Get_Glyph_Bitmap(FXFT_Face face);
int FXFT_Get_Bitmap_Width(void* bitmap);
int FXFT_Get_Bitmap_Rows(void* bitmap);
int FXFT_Get_Bitmap_Pitch(void* bitmap);
uint8_t* FXFT_Get_Bitmap_Buffer(void* bitmap);
int FXFT_Get_Bitmap_PixelMode(void* bitmap);
int FXFT_Get_Glyph_BitmapLeft(FXFT_Face face);
int FXFT_Get_Glyph_BitmapTop(FXFT_Face face);

void FXSYS_memset(void* dest, int value, size_t count);
void FXSYS_memcpy(void* dest, const void* src, size_t count);
int FXSYS_abs(int value);

void _ContrastAdjust(uint8_t* src_buf, uint8_t* dest_buf, int width, int height, int src_pitch, int dest_pitch);
void _GammaAdjust(uint8_t* dest_buf, int width, int height, int dest_pitch, const uint8_t* gamma_table);