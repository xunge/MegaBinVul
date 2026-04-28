#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned long FT_Encoding;
#define FT_ENCODING_NONE 0

typedef struct FT_LibraryRec_ *FT_Library;
typedef struct FT_FaceRec_ {
    int num_glyphs;
    struct FT_GlyphSlotRec_ *glyph;
    struct FT_SizeRec_ *size;
    char* family_name;
    char* style_name;
} *FT_Face;
typedef struct FT_MM_Var_ {
    unsigned int num_axis;
    struct {
        char* name;
        long def;
        long minimum;
        long maximum;
    } *axis;
} *FT_MM_Var;
typedef struct FT_GlyphSlotRec_ *FT_GlyphSlot;
typedef struct FT_SizeRec_ *FT_Size;

typedef struct {
    int type;
} grEvent;

typedef struct grSurface grSurface;
typedef struct grBitmap grBitmap;

extern FT_Library library;
extern FT_Face face;
extern int error;
extern FT_MM_Var multimaster;
extern FT_Encoding encoding;
extern int ptsize;
extern int hinted;
extern int res;
extern int requested_cnt;
extern long* requested_pos;
extern long design_pos[4];
extern int num_glyphs;
extern FT_GlyphSlot glyph;
extern FT_Size size;
extern int render_mode;
extern char Header[256];
extern char* new_header;
extern int fore_color;
extern int Fail;
extern int Num;
extern grSurface* surface;
extern grBitmap bit;

char* ft_basename(char* path);
void parse_design_coords(char* str);
unsigned long make_tag(char* str);
void usage(char* execname);
int FT_Init_FreeType(FT_Library* alibrary);
void PanicZ(const char* msg);
int FT_New_Face(FT_Library library, const char* pathname, int face_index, FT_Face* aface);
int FT_Select_Charmap(FT_Face face, FT_Encoding encoding);
int FT_Get_MM_Var(FT_Face face, FT_MM_Var* amaster);
int FT_Set_Var_Design_Coordinates(FT_Face face, unsigned int num_coords, long* coords);
void FT_Done_Face(FT_Face face);
void FT_Done_FreeType(FT_Library library);
void Reset_Scale(int ptsize);
void Init_Display();
void Clear_Display();
void Render_Text(int num);
void Render_All(int num, int ptsize);
int Process_Event(grEvent* event);
void grSetTitle(grSurface* surface, const char* title);
void grWriteCellString(grBitmap* bitmap, int x, int y, const char* text, int color);
void grRefreshSurface(grSurface* surface);
void grListenSurface(grSurface* surface, int flags, grEvent* event);
void grDoneSurface(grSurface* surface);
void grDoneDevices();