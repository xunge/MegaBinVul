#include <assert.h>
#include <stdint.h>

typedef struct _Bit_Chain
{
  uint8_t *chain;
  uint64_t byte;
  uint64_t bit;
  uint64_t size;
} Bit_Chain;

typedef struct _Dwg_Object
{
  uint64_t bitsize;
  uint64_t size;
  uint64_t bitsize_pos;
  uint64_t stringstream_size;
  uint64_t strpos;
  int has_strings;
  int fixedtype;
} Dwg_Object;

typedef int32_t BITCODE_RL;
typedef int16_t BITCODE_RS;
typedef uint8_t BITCODE_B;

#define FORMAT_RL "%d"
#define DWG_ERR_VALUEOUTOFBOUNDS 1
#define DWG_ERR_NOTYETSUPPORTED 2
#define DWG_TYPE_SCALE 3

void bit_advance_position(Bit_Chain *chain, int offset);
uint64_t bit_position(Bit_Chain *chain);
BITCODE_B bit_read_B(Bit_Chain *chain);
BITCODE_RS bit_read_RS(Bit_Chain *chain);
void bit_reset_chain(Bit_Chain *chain);

#define LOG_ERROR(fmt, ...)
#define LOG_HANDLE(fmt, ...)
#define LOG_TRACE(fmt, ...)
#define LOG_WARN(fmt, ...)