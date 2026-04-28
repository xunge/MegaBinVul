#include <stdint.h>
#include <string.h>

#define FAST_BITS 9

typedef unsigned char stbi_uc;
typedef uint16_t stbi__uint16;
typedef int16_t stbi__int16;

typedef struct
{
   stbi__uint16 fast[1 << FAST_BITS];
   stbi__uint16 firstcode[16];
   int maxcode[17];
   stbi__uint16 firstsymbol[16];
   stbi_uc  size[288];
   stbi__uint16 value[288]; 
} stbi__huffman;

typedef struct
{
   stbi__int16 dc_pred;
   stbi__uint16 *dequant;
} stbi__jpeg_comp;

typedef struct
{
   unsigned int code_buffer;
   int code_bits;
   stbi__jpeg_comp img_comp[4];
} stbi__jpeg;

extern int stbi__err(const char *str, const char *msg);
extern int stbi__grow_buffer_unsafe(stbi__jpeg *j);
extern int stbi__jpeg_huff_decode(stbi__jpeg *j, stbi__huffman *h);
extern int stbi__extend_receive(stbi__jpeg *j, int n);
extern unsigned int stbi__jpeg_dezigzag[64];