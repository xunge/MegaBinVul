#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct wStream wStream;
typedef uint16_t UINT16;
typedef bool BOOL;

#define TRUE true
#define FALSE false

size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT16(wStream* s, UINT16 value);
BOOL rdp_read_flow_control_pdu(wStream* s, UINT16* type);