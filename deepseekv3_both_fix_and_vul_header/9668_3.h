#include <stdio.h>
#include <string.h>

typedef unsigned short FT_UShort;
typedef int FT_Error;

typedef struct FT_FaceRec {
    char* family_name;
    char* style_name;
    char* filepathname;
} *FT_Face;

typedef struct FTC_ScalerRec {
    void* face_id;
} FTC_ScalerRec;

typedef struct FTC_ManagerRec *FTC_Manager;
typedef struct FT_Bitmap FT_Bitmap;
typedef struct FT_Surface FT_Surface;

#define FT_Err_Ok 0
#define FT_Err_Invalid_Pixel_Size 1
#define FT_Err_Invalid_PPem 2
#define CELLSTRING_HEIGHT 16

typedef struct {
    const char* header;
    char header_buffer[256];
    double ptsize;
    int angle;
} Status;

typedef struct {
    FTC_Manager cache_manager;
    FTC_ScalerRec scaler;
    FT_Face current_font;
} Handle;

typedef struct {
    FT_Bitmap* bitmap;
    int fore_color;
    FT_Surface* surface;
} Display;

extern FT_Error FTC_Manager_LookupFace(FTC_Manager manager, void* face_id, FT_Face* face);
extern const char* ft_basename(const char* path);
extern void grWriteCellString(FT_Bitmap* bitmap, int x, int y, const char* str, int color);
extern void grRefreshSurface(FT_Surface* surface);
extern void PanicZ(const char* msg);

static Status status;
static Handle* handle;
static Display* display;
static FT_Error error;