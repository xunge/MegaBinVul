#include <stddef.h>

typedef int ma_result;
typedef struct ma_decoder ma_decoder;
typedef struct ma_vfs ma_vfs;

#define MA_API
#define MA_INVALID_ARGS 0
#define MA_SUCCESS 0

typedef struct {
    int dummy;
} ma_data_converter;

typedef struct {
    int dummy;
} ma_data_source;

struct ma_decoder {
    void (*onUninit)(ma_decoder*);
    ma_result (*onRead)(void);
    union {
        struct {
            ma_vfs* pVFS;
            void* file;
        } vfs;
    } backend;
    ma_data_converter converter;
    ma_data_source ds;
};

ma_result ma_decoder__on_read_vfs(void);
ma_result ma_vfs_or_default_close(ma_vfs* pVFS, void* file);
void ma_data_converter_uninit(ma_data_converter* converter);
void ma_data_source_uninit(ma_data_source* ds);