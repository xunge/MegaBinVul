#include <stdio.h>
#include <string.h>

typedef unsigned short FT_UShort;
typedef int FT_Error;

struct FT_FaceRec_ {
    char* family_name;
    char* style_name;
};
typedef struct FT_FaceRec_* FT_Face;

typedef struct FTC_ManagerRec_* FTC_Manager;

enum {
    FT_Err_Ok,
    FT_Err_Invalid_Pixel_Size,
    FT_Err_Invalid_PPem
};

#define FT_HAS_GLYPH_NAMES(face) 1

struct {
    const char* header;
    char header_buffer[256];
    double ptsize;
    int Num;
} status;

struct {
    FTC_Manager cache_manager;
    struct {
        int face_id;
    } scaler;
    struct {
        char* filepathname;
    }* current_font;
}* handle;

struct {
    void* bitmap;
    int fore_color;
    void* surface;
}* display;

#define HEADER_HEIGHT 16

FT_Error error;  // 添加这行声明

FT_Error FTC_Manager_LookupFace(FTC_Manager manager, int face_id, FT_Face* aface);
const char* ft_basename(const char* path);
void Fatal(const char* message);
void grWriteCellString(void* bitmap, int x, int y, const char* text, int color);
void grRefreshSurface(void* surface);
int FT_Get_Glyph_Name(FT_Face face, int glyph_index, char* buffer, int buffer_max);