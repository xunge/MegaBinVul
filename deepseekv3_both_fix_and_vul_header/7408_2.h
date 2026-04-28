#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Bool;

typedef enum {
    GF_OK,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef struct JSContext JSContext;
typedef struct JSValue {
    int dummy;  // Placeholder for incomplete type
} JSValue;
typedef JSValue JSValueConst;

#define GF_JS_EXCEPTION(ctx) ((JSValue){0})

static inline void *gf_malloc(size_t size) { return malloc(size); }
static inline void gf_free(void *ptr) { free(ptr); }
static inline u32 gf_base16_decode(const u8 *in, u32 in_size, u8 *out, u32 out_size) { return 0; }
static inline u32 gf_base64_decode(const u8 *in, u32 in_size, u8 *out, u32 out_size) { return 0; }
static inline u32 gf_base16_encode(const u8 *in, u32 in_size, u8 *out, u32 out_size) { return 0; }
static inline u32 gf_base64_encode(const u8 *in, u32 in_size, u8 *out, u32 out_size) { return 0; }
static inline void js_gpac_free(void *opaque, void *ptr) { gf_free(ptr); }

static inline const char *JS_ToCString(JSContext *ctx, JSValueConst val) { return NULL; }
static inline void JS_FreeCString(JSContext *ctx, const char *ptr) {}
static inline const void *JS_GetArrayBuffer(JSContext *ctx, size_t *psize, JSValueConst array_buffer) { return NULL; }
static inline JSValue JS_NewArrayBuffer(JSContext *ctx, void *buf, size_t len, void (*free_func)(void *opaque, void *ptr), void *opaque, int is_shared) { return (JSValue){0}; }
static inline JSValue JS_NewString(JSContext *ctx, const char *str) { return (JSValue){0}; }
static inline JSValue js_throw_err(JSContext *ctx, GF_Err e) { return (JSValue){0}; }