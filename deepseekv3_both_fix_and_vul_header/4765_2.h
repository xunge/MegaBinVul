#include <stdbool.h>
#include <stdio.h>

struct omx_vdec {
    void* m_out_mem_ptr;
    void* m_inp_mem_ptr;
    unsigned int m_out_bm_count;
    bool release_output_done(void);
};

typedef struct {
    struct {
        unsigned int actualcount;
    } op_buf;
} drv_ctx_t;

extern drv_ctx_t drv_ctx;

#define DEBUG_PRINT_LOW(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define BITMASK_PRESENT(ptr, bit) ((*(ptr)) & (1 << (bit)))