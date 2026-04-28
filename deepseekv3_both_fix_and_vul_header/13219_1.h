#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>

#define MODE_ENCODE 0
#define MODE_DECODE 1
#define MODE_TEST 2

#define KiB(x) ((x) * 1024)
#define MiB(x) ((x) * 1024 * 1024)

#define BZ3_OK 0

typedef uint8_t u8;
typedef int32_t s32;

struct bz3_state;

extern struct bz3_state *bz3_new(int block_size);
extern void bz3_free(struct bz3_state *state);
extern int bz3_last_error(struct bz3_state *state);
extern const char *bz3_strerror(struct bz3_state *state);
extern s32 bz3_encode_block(struct bz3_state *state, u8 *buffer, s32 size);
extern s32 bz3_decode_block(struct bz3_state *state, u8 *buffer, s32 new_size, s32 old_size);
extern void bz3_encode_blocks(struct bz3_state **states, u8 **buffers, s32 *sizes, s32 count);
extern void bz3_decode_blocks(struct bz3_state **states, u8 **buffers, s32 *sizes, s32 *old_sizes, s32 count);

extern size_t xread(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern size_t xwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
extern size_t xread_noeof(void *ptr, size_t size, size_t nmemb, FILE *stream);
extern int xread_eofcheck(void *ptr, size_t size, size_t nmemb, FILE *stream);

extern void write_neutral_s32(u8 buf[4], s32 value);
extern s32 read_neutral_s32(const u8 buf[4]);