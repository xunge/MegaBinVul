#include <stdint.h>
#include <stddef.h>

typedef int PARTITION_CONTEXT;
typedef int ENTROPY_CONTEXT;

typedef struct {
  int mi_stride;
  int mi_rows;
  int mi_cols;
  int mi_alloc_size;
  int seg_map_alloc_size;
  int above_context_alloc_cols;
  void (*free_mi)(void *);
  int (*alloc_mi)(void *, int);
  void *above_context;
  void *above_seg_context;
} VP9_COMMON;

#define MAX_MB_PLANE 3

int calc_mi_size(int mi_rows);
int mi_cols_aligned_to_sb(int mi_cols);
void vp9_set_mb_mi(VP9_COMMON *cm, int width, int height);
void vp9_free_context_buffers(VP9_COMMON *cm);
void free_seg_map(VP9_COMMON *cm);
int alloc_seg_map(VP9_COMMON *cm, int size);
void *vpx_calloc(size_t num, size_t size);
void vpx_free(void *ptr);