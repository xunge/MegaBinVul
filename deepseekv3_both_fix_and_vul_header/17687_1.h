#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define TAG "nego"
#define WLog_DBG(tag, ...)
#define WLog_ERR(tag, ...)

typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint8_t UINT8;
typedef bool BOOL;
#define TRUE true
#define FALSE false

typedef enum
{
    NEGO_STATE_FAIL,
    NEGO_STATE_FINAL
} NEGO_STATE;

typedef struct
{
    UINT8 flags;
    UINT32 SelectedProtocol;
    NEGO_STATE state;
} rdpNego;

typedef struct wStream wStream;

size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT8(wStream* s, UINT8* val);
void Stream_Read_UINT16(wStream* s, UINT16* val);
void Stream_Read_UINT32(wStream* s, UINT32* val);