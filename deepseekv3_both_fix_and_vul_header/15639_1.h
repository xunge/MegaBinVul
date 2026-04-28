#include <stdlib.h>
#include <string.h>

#define gs_error_VMerror (-1)

typedef struct gx_device_txtwrite_s gx_device_txtwrite_t;
typedef struct textw_text_enum_s textw_text_enum_t;
typedef struct text_list_entry_s text_list_entry_t;

struct text_list_entry_s {
    struct text_list_entry_s *next;
    struct text_list_entry_s *previous;
    unsigned short *Unicode_Text;
    float *Widths;
    char *FontName;
    int Unicode_Text_Size;
    struct {
        float x;
        float y;
    } start;
    struct {
        float x;
        float y;
    } end;
};

struct textw_text_enum_s {
    struct {
        float x;
        float y;
    } origin;
    struct {
        struct {
            float x;
            float y;
        } total_width;
    } returned;
    text_list_entry_t *text_state;
    unsigned short *TextBuffer;
    float *Widths;
    size_t TextBufferIndex;
    struct {
        size_t size;
    } text;
};

struct gx_device_txtwrite_s {
    struct {
        text_list_entry_t *unsorted_text_list;
    } PageData;
    struct {
        void *stable_memory;
    } *memory;
};

extern void *gs_malloc(void *mem, size_t num_elements, size_t element_size, const char *cname);
extern int gs_note_error(int error);
extern float fixed2float(int fixed);
extern int txt_add_sorted_fragment(gx_device_txtwrite_t *tdev, textw_text_enum_t *penum);