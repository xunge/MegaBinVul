#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_text fz_text;
typedef struct fz_stroke_state fz_stroke_state;
typedef struct pdf_device pdf_device;
typedef struct fz_text_span fz_text_span;

struct fz_matrix {
    float a, b, c, d, e, f;
};

typedef struct fz_matrix fz_matrix;

struct fz_rect {
    float x0, y0, x1, y1;
};

typedef struct fz_rect fz_rect;

struct fz_text_span {
    struct fz_text_span *next;
    void *font;
    fz_matrix trm;
};

struct fz_text {
    struct fz_text_span *head;
};

void pdf_dev_begin_text(fz_context *ctx, pdf_device *pdev, fz_matrix trm, int flag);
void pdf_dev_font(fz_context *ctx, pdf_device *pdev, void *font);
void pdf_dev_ctm(fz_context *ctx, pdf_device *pdev, fz_matrix ctm);
void pdf_dev_text_span(fz_context *ctx, pdf_device *pdev, fz_text_span *span);