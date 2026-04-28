#include <stdio.h>
#include <string.h>

typedef unsigned short FT_UShort;
typedef int FT_Error;
typedef int FT_Encoding;

#define FT_ENCODING_NONE 0
#define FT_Err_Ok 0
#define FT_Err_Invalid_Pixel_Size 1
#define FT_Err_Invalid_PPem 2
#define HEADER_HEIGHT 16

typedef struct FT_FaceRec_* FT_Face;
typedef struct FTC_ManagerRec_* FTC_Manager;

struct FTC_ScalerRec_ {
    void* face_id;
};

struct FT_FaceRec_ {
    char* family_name;
    char* style_name;
};

struct Display {
    void* bitmap;
    int fore_color;
    void* surface;
};

struct Status {
    char* header;
    char header_buffer[256];
    FT_Encoding encoding;
    int ptsize;
    int Num;
    int use_custom_lcd_filter;
    int fw_index;
    unsigned char filter_weights[5];
};

struct Handle {
    FTC_Manager cache_manager;
    struct FTC_ScalerRec_ scaler;
    struct Font* current_font;
};

struct Font {
    char* filepathname;
};

extern FT_Error error;
extern struct Handle* handle;
extern struct Status status;
extern struct Display* display;

extern FT_Error FTC_Manager_LookupFace(FTC_Manager, void*, FT_Face*);
extern const char* ft_basename(const char*);
extern void Fatal(const char*);
extern void grWriteCellString(void*, int, int, const char*, int);
extern void grRefreshSurface(void*);
extern int FTDemo_Get_Index(struct Handle*, int);
extern int FT_Get_Glyph_Name(FT_Face, int, char*, int);
extern int FT_HAS_GLYPH_NAMES(FT_Face);