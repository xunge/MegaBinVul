#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>

typedef struct Image Image;
typedef struct GraphicsManager GraphicsManager;
typedef struct GraphicsCommand GraphicsCommand;
typedef struct LoadData LoadData;
typedef struct GlobalState GlobalState;

struct LoadData {
    uint8_t *buf;
    size_t buf_used;
    size_t buf_capacity;
    size_t data_sz;
    uint8_t *mapped_file;
    size_t mapped_file_sz;
    bool is_4byte_aligned;
    bool is_opaque;
    uint8_t *data;
};

struct Image {
    uint32_t internal_id;
    uint32_t client_id;
    uint32_t width;
    uint32_t height;
    uint32_t texture_id;
    size_t used_storage;
    time_t atime;
    bool data_loaded;
    LoadData load_data;
};

struct GraphicsCommand {
    uint32_t id;
    uint32_t data_width;
    uint32_t data_height;
    size_t data_sz;
    size_t data_offset;
    size_t payload_sz;
    unsigned char transmission_type;
    unsigned char compressed;
    uint32_t format;
    bool more;
};

struct GraphicsManager {
    uint32_t loading_image;
    GraphicsCommand last_init_graphics_command;
    bool layers_dirty;
    size_t used_storage;
};

struct GlobalState {
    bool boss;
};

static GlobalState global_state;
static uint32_t internal_id_counter = 1;
static bool has_add_respose = false;
static bool send_to_gpu = true;

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define REPEAT_CLAMP 0

void set_add_response(const char *code, const char *fmt, ...);
void free_load_data(LoadData *ld);
void free_refs_data(Image *img);
void remove_images(GraphicsManager *self, bool (*pred)(Image*, void*), void *data);
Image* find_or_create_image(GraphicsManager *self, uint32_t iid, bool *existing);
Image* img_by_internal_id(GraphicsManager *self, uint32_t internal_id);
bool mmap_img_file(GraphicsManager *self, Image *img, int fd, size_t data_sz, size_t data_offset);
void safe_close(int fd, const char *file, int line);
void call_boss(void (*func)(const char*, ...), const char *fmt, const char *arg);
void safe_delete_temp_file(const char *fname);
bool inflate_zlib(GraphicsManager *self, Image *img, uint8_t *buf, size_t bufsz);
bool inflate_png(GraphicsManager *self, Image *img, uint8_t *buf, size_t bufsz);
void send_image_to_gpu(uint32_t *texture_id, uint8_t *data, uint32_t width, uint32_t height, bool is_opaque, bool is_4byte_aligned, bool flip, int repeat);
time_t monotonic(void);
bool add_trim_predicate(Image *img, void *data);