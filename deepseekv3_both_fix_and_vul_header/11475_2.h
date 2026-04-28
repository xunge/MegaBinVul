#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_text fz_text;
typedef struct pdf_device pdf_device;
typedef struct fz_text_span fz_text_span;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

struct fz_text {
    fz_text_span *head;
};

struct fz_text_span {
    fz_text_span *next;
    fz_matrix trm;
    void *font;
};

void pdf_dev_begin_text(fz_context *ctx, pdf_device *pdev, fz_matrix trm, int flag);
void pdf_dev_ctm(fz_context *ctx, pdf_device *pdev, fz_matrix ctm);
void pdf_dev_font(fz_context *ctx, pdf_device *pdev, void *font);
void pdf_dev_text_span(fz_context *ctx, pdf_device *pdev, fz_text_span *span);