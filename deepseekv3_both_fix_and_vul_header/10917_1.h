#include <stdint.h>
#include <stdlib.h>

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

typedef enum {
    YCbCrColorspace
} ColorspaceType;

typedef struct {
    int ping;
    const char *options;
} ImageInfo;

typedef struct {
    size_t columns;
    size_t rows;
    int depth;
    ColorspaceType colorspace;
    void *properties;
} Image;

typedef struct {
    int code;
    const char *message;
} ExceptionInfo;

typedef int heif_item_id;

enum heif_channel {
    heif_channel_Y,
    heif_channel_Cb,
    heif_channel_Cr
};

enum heif_colorspace {
    heif_colorspace_YCbCr
};

enum heif_chroma {
    heif_chroma_420
};

struct heif_context;
struct heif_image;
struct heif_image_handle;
struct heif_decoding_options {
    int ignore_transformations;
};

struct heif_error {
    int code;
    const char *message;
};

typedef unsigned long Quantum;

extern struct heif_error heif_context_get_image_handle(struct heif_context*, heif_item_id, struct heif_image_handle**);
extern struct heif_error heif_decode_image(struct heif_image_handle*, struct heif_image**, enum heif_colorspace, enum heif_chroma, struct heif_decoding_options*);
extern const uint8_t* heif_image_get_plane_readonly(struct heif_image*, enum heif_channel, int*);
extern int heif_image_handle_get_width(struct heif_image_handle*);
extern int heif_image_handle_get_height(struct heif_image_handle*);
extern int heif_image_get_width(struct heif_image*, enum heif_channel);
extern int heif_image_get_height(struct heif_image*, enum heif_channel);
extern void heif_image_handle_release(struct heif_image_handle*);
extern void heif_image_release(struct heif_image*);
extern struct heif_decoding_options* heif_decoding_options_alloc(void);
extern void heif_decoding_options_free(struct heif_decoding_options*);

extern MagickBooleanType IsHeifSuccess(const struct heif_error*, Image*, ExceptionInfo*);
extern MagickBooleanType ReadHEICColorProfile(Image*, struct heif_image_handle*, ExceptionInfo*);
extern MagickBooleanType ReadHEICExifProfile(Image*, struct heif_image_handle*, ExceptionInfo*);
extern MagickBooleanType HEICSkipImage(const ImageInfo*, Image*);
extern MagickBooleanType SetImageExtent(Image*, size_t, size_t, ExceptionInfo*);
extern void SetImageColorspace(Image*, ColorspaceType, ExceptionInfo*);
extern const char* GetImageOption(const ImageInfo*, const char*);
extern MagickBooleanType IsStringTrue(const char*);
extern void SetImageProperty(Image*, const char*, const char*, ExceptionInfo*);
extern Quantum* QueueAuthenticPixels(Image*, ssize_t, ssize_t, size_t, size_t, ExceptionInfo*);
extern MagickBooleanType SyncAuthenticPixels(Image*, ExceptionInfo*);
extern unsigned char ScaleCharToQuantum(unsigned char);
extern void SetPixelRed(Image*, Quantum, Quantum*);
extern void SetPixelGreen(Image*, Quantum, Quantum*);
extern void SetPixelBlue(Image*, Quantum, Quantum*);
extern size_t GetPixelChannels(Image*);