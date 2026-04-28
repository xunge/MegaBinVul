#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Gif_Reader {
    int (*eofer)(struct Gif_Reader*);
    unsigned pos;
} Gif_Reader;

typedef struct Gif_Stream {
    const char* landmark;
    int nimages;
    char* end_comment;
    struct Gif_Extension* end_extension_list;
    int errors;
} Gif_Stream;

typedef struct Gif_Image {
    char* identifier;
    char* comment;
    struct Gif_Extension* extension_list;
} Gif_Image;

typedef struct Gif_Extension {
    struct Gif_Extension* next;
    struct Gif_Image* image;
} Gif_Extension;

typedef struct Gif_Context {
    Gif_Stream* stream;
    int* prefix;
    uint8_t* suffix;
    uint16_t* length;
    void (*handler)(const char*);
    Gif_Image* gfi;
    int errors[2];
} Gif_Context;

typedef int Gif_Code;
typedef void (*Gif_ReadErrorHandler)(const char*);

#define GIF_MAX_CODE 4096
#define GIF_READ_TRAILING_GARBAGE_OK 1

static char* last_name;

static int gifgetc(Gif_Reader* grr) { return 0; }
static int gifeof(Gif_Reader* grr) { return 0; }
static uint8_t gifgetbyte(Gif_Reader* grr) { return 0; }
static Gif_Stream* Gif_NewStream(void) { return NULL; }
static Gif_Image* Gif_NewImage(void) { return NULL; }
static void* Gif_NewArray(size_t element_size, size_t count) { return malloc(element_size * count); }
static int Gif_AddImage(Gif_Stream* gfs, Gif_Image* gfi) { return 0; }
static void Gif_RemoveImage(Gif_Stream* gfs, int index) {}
static void Gif_DeleteImage(Gif_Image* gfi) {}
static void Gif_DeleteArray(void* arr) { free(arr); }
static int read_logical_screen_descriptor(Gif_Stream* gfs, Gif_Reader* grr) { return 0; }
static int read_image(Gif_Reader* grr, Gif_Context* gfc, Gif_Image* gfi, int read_flags) { return 0; }
static void read_graphic_control_extension(Gif_Context* gfc, Gif_Image* gfi, Gif_Reader* grr) {}
static char* suck_data(char* last_name, int unused, Gif_Reader* grr) { return NULL; }
static int read_comment_extension(Gif_Image* gfi, Gif_Reader* grr) { return 0; }
static void read_application_extension(Gif_Context* gfc, Gif_Reader* grr) {}
static void read_unknown_extension(Gif_Context* gfc, Gif_Reader* grr, int block, int unused1, int unused2) {}
static void gif_read_error(Gif_Context* gfc, int level, const char* message) {}
#define GIF_DEBUG(x)

#define Gif_NewArray(type, count) ((type*)Gif_NewArray(sizeof(type), (count)))