#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned long bfSize;
    unsigned short zzHotX;
    unsigned short zzHotY;
    unsigned long bfOffs;
    unsigned long biSize;
} BitmapFileHead;

typedef struct {
    unsigned long biWidth;
    unsigned long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCnt;
    unsigned long biCompr;
    unsigned long biSizeIm;
    unsigned long biXPels;
    unsigned long biYPels;
    unsigned long biClrUsed;
    unsigned long biClrImp;
} BitmapHead;

typedef struct {
    void *data;
    unsigned short width;
    unsigned short height;
    unsigned short nplanes;
} at_bitmap;

typedef void* gpointer;
typedef char gchar;
typedef void (*at_msg_func)(void* msg_data, const char* message);

typedef struct {
    int dummy;
} at_input_opts_type;

typedef struct {
    at_msg_func msg_func;
    gpointer msg_data;
} at_exception_type;

#define LOG printf

extern BitmapFileHead Bitmap_File_Head;
extern BitmapHead Bitmap_Head;
extern at_bitmap at_bitmap_init(void *data, unsigned short width, unsigned short height, unsigned short nplanes);
extern at_exception_type at_exception_new(at_msg_func msg_func, gpointer msg_data);
extern void at_exception_fatal(at_exception_type *exp, const char *message);
extern int at_exception_got_fatal(at_exception_type *exp);
extern int ReadOK(FILE *fd, unsigned char *buffer, int count);
extern unsigned long ToL(unsigned char *buffer);
extern unsigned short ToS(unsigned char *buffer);
extern void ReadColorMap(FILE *fd, unsigned char ColorMap[256][3], int ColormapSize, int Maps, int *Grey, at_exception_type *exp);
extern unsigned char *ReadImage(FILE *fd, unsigned long width, unsigned long height, unsigned char ColorMap[256][3], unsigned short biBitCnt, unsigned long biCompr, int rowbytes, int Grey);

BitmapFileHead Bitmap_File_Head;
BitmapHead Bitmap_Head;