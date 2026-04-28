#include <stdint.h>
#include <stddef.h>

typedef uint8_t uint8x8_t;
typedef int16_t int16x4_t;
typedef int32_t int32x4_t;
typedef uint16_t uint16x4_t;
typedef uint8_t uint8x16_t;
typedef int16_t int16x8_t;
typedef uint16_t uint16x8_t;
typedef uint32_t uint32x2_t;

class SkConvolutionFilter1D {
public:
    typedef int16_t ConvolutionFixed;
    static const int kShiftBits = 0;
    int numValues() const;
    const ConvolutionFixed* FilterForValue(int valueOffset, int* filterOffset, int* filterLength) const;
};

uint8x8_t vcreate_u8(uint64_t);
int16x4_t vld1_s16(const int16_t*);
uint16x4_t vld1_u16(const uint16_t*);
int16x4_t vreinterpret_s16_u8(uint8x8_t);
int16x4_t vreinterpret_s16_u16(uint16x4_t);
uint8x8_t vtbl1_u8(uint8x8_t, uint8x8_t);
uint8x8_t vreinterpret_u8_s16(int16x4_t);
int32x4_t vdupq_n_s32(int32_t);
uint8x16_t vld1q_u8(const uint8_t*);
int16x8_t vreinterpretq_s16_u16(uint16x8_t);
uint16x8_t vmovl_u8(uint8x8_t);
uint8x8_t vget_low_u8(uint8x16_t);
uint8x8_t vget_high_u8(uint8x16_t);
int32x4_t vmull_s16(int16x4_t, int16x4_t);
int16x4_t vget_low_s16(int16x8_t);
int16x4_t vget_high_s16(int16x8_t);
int32x4_t vshrq_n_s32(int32x4_t, int);
int16x4_t vqmovn_s32(int32x4_t);
uint8x8_t vqmovun_s16(int16x8_t);
int16x8_t vcombine_s16(int16x4_t, int16x4_t);
void vst1_lane_u32(uint32_t*, uint32x2_t, int);
uint32x2_t vreinterpret_u32_u8(uint8x8_t);