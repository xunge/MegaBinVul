#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define FIXED_SHIFT 16

typedef struct _cairo_surface cairo_surface_t;

extern "C" {
void *gmallocn(int n, int size);
void *gmallocn3(int n, int m, int size);
unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);
int cairo_image_surface_get_stride(cairo_surface_t *surface);
}

class CairoRescaleBox {
private:
    virtual void getRow(int row, uint32_t *buffer) = 0;
    int compute_coverage(int *coverage, int src_size, int dest_size);
    void downsample_row_box_filter(int start, int width, uint32_t *src, uint32_t *src_end, uint32_t *dest, int *x_coverage, int coverage);
    void downsample_row_box_filter(int start, int width, uint32_t *src, uint32_t *dest, int *x_coverage, int coverage);
    void downsample_columns_box_filter(int width, int start_coverage, int coverage, uint32_t *src, uint32_t *dest);
public:
    bool downScaleImage(unsigned orig_width, unsigned orig_height,
                       signed scaled_width, signed scaled_height,
                       unsigned short int start_column, unsigned short int start_row,
                       unsigned short int width, unsigned short int height,
                       cairo_surface_t *dest_surface);
};