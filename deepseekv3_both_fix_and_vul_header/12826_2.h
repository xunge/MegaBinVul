#include <stddef.h>

typedef int ma_result;
typedef struct ma_vfs ma_vfs;
typedef struct ma_decoder ma_decoder;

struct ma_decoder_config {
    int dummy;
};

struct ma_decoder {
    struct {
        struct {
            void* file;
        } vfs;
    } backend;
};

enum {
    MA_SUCCESS,
    MA_NO_BACKEND
};

enum ma_seek_origin {
    ma_seek_origin_start
};

#define MA_HAS_WAV
#define MA_HAS_FLAC
#define MA_HAS_MP3

#define MA_API

ma_decoder_config ma_decoder_config_init_copy(const ma_decoder_config* pConfig);
ma_result ma_decoder__preinit_vfs(ma_vfs* pVFS, const char* pFilePath, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
ma_result ma_decoder_init_wav__internal(const ma_decoder_config* pConfig, ma_decoder* pDecoder);
ma_result ma_decoder_init_flac__internal(const ma_decoder_config* pConfig, ma_decoder* pDecoder);
ma_result ma_decoder_init_mp3__internal(const ma_decoder_config* pConfig, ma_decoder* pDecoder);
ma_result ma_decoder__on_seek_vfs(void* pDecoder, int offset, enum ma_seek_origin origin);
ma_result ma_decoder__on_read_vfs(void* pUserData, void* pBufferOut, size_t bytesToRead, size_t* pBytesRead);
ma_result ma_decoder_init__internal(ma_result (*on_read)(void*, void*, size_t, size_t*), ma_result (*on_seek)(void*, int, enum ma_seek_origin), void* pUserData, const ma_decoder_config* pConfig, ma_decoder* pDecoder);
ma_result ma_decoder__postinit(const ma_decoder_config* pConfig, ma_decoder* pDecoder);
int ma_path_extension_equal(const char* pFilePath, const char* extension);
void ma_vfs_or_default_close(ma_vfs* pVFS, void* file);