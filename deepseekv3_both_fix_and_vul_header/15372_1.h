#include <stddef.h>

typedef struct gx_device_s gx_device;
typedef void (*dev_proc)(void);

#define output_page "output_page"
#define open_device "open_device" 
#define close_device "close_device"
#define map_color_rgb "map_color_rgb"
#define get_params "get_params"
#define put_params "put_params"
#define get_color_mapping_procs "get_color_mapping_procs"
#define get_color_comp_index "get_color_comp_index"
#define encode_color "encode_color"
#define decode_color "decode_color"
#define update_spot_equivalent_colors "update_spot_equivalent_colors"
#define ret_devn_params "ret_devn_params"
#define dev_spec_op "dev_spec_op"

void gdev_prn_initialize_device_procs(gx_device *dev);
void set_dev_proc(gx_device *dev, const char *proc_name, dev_proc proc);

dev_proc gdev_prn_output_page_seekable;
dev_proc tiffsep_prn_open;
dev_proc tiffsep_prn_close;
dev_proc tiffsep_decode_color;
dev_proc tiffsep_get_params;
dev_proc tiffsep_put_params;
dev_proc tiffsep_get_color_mapping_procs;
dev_proc tiffsep_get_color_comp_index;
dev_proc tiffsep_encode_color;
dev_proc tiffsep_update_spot_equivalent_colors;
dev_proc tiffsep_ret_devn_params;
dev_proc tiffsep_spec_op;