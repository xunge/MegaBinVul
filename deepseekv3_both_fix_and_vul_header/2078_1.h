#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define PATH_MAX 4096
#define BDRV_O_SNAPSHOT 0x0001
#define BDRV_O_RDWR 0x0002
#define BDRV_O_NO_BACKING 0x0004
#define BDRV_SECTOR_MASK 0xFFFFFFFFFFFF0000LL

typedef struct BlockDriver BlockDriver;
typedef struct BlockDriverState BlockDriverState;
typedef struct QEMUOptionParameter QEMUOptionParameter;

struct BlockDriver {
    const char *format_name;
    const char *protocol_name;
    QEMUOptionParameter *create_options;
};

struct BlockDriverState {
    BlockDriver *drv;
    BlockDriverState *backing_hd;
    char backing_file[PATH_MAX];
    char backing_format[PATH_MAX];
    int is_temporary;
    int keep_read_only;
    int io_limits_enabled;
};

extern BlockDriverState *bdrv_new(const char *filename);
extern void bdrv_delete(BlockDriverState *bs);
extern int bdrv_open_common(BlockDriverState *bs, const char *filename, int flags, BlockDriver *drv);
extern int bdrv_getlength(BlockDriverState *bs);
extern int bdrv_create(BlockDriver *drv, const char *filename, QEMUOptionParameter *options);
extern int find_image_format(const char *filename, BlockDriver **drv);
extern BlockDriver *bdrv_find_format(const char *format_name);
extern void bdrv_close(BlockDriverState *bs);
extern int bdrv_key_required(BlockDriverState *bs);
extern void bdrv_dev_change_media_cb(BlockDriverState *bs, bool load);
extern void bdrv_io_limits_enable(BlockDriverState *bs);
extern void bdrv_get_full_backing_filename(BlockDriverState *bs, char *backing_filename, int len);
extern int get_tmp_filename(char *filename, int size);
extern QEMUOptionParameter *parse_option_parameters(const char *param, QEMUOptionParameter *list, QEMUOptionParameter **dest);
extern void set_option_parameter_int(QEMUOptionParameter *options, const char *name, int value);
extern void set_option_parameter(QEMUOptionParameter *options, const char *name, const char *value);
extern void free_option_parameters(QEMUOptionParameter *options);

#define BLOCK_OPT_SIZE "size"
#define BLOCK_OPT_BACKING_FILE "backing_file"
#define BLOCK_OPT_BACKING_FMT "backing_fmt"