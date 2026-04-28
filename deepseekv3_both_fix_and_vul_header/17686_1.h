#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

#define SSL_REQUIRED_BY_SERVER 1
#define SSL_NOT_ALLOWED_BY_SERVER 2
#define SSL_CERT_NOT_ON_SERVER 3
#define INCONSISTENT_FLAGS 4
#define HYBRID_REQUIRED_BY_SERVER 5

#define NEGO_STATE_FAIL 6

typedef struct rdpNego {
    int state;
    BOOL sendNegoData;
} rdpNego;

typedef struct wStream {
    uint8_t* buffer;
    size_t position;
    size_t length;
} wStream;

#define TAG "NEGO"

#define WLog_DBG(tag, fmt, ...) 
#define WLog_WARN(tag, fmt, ...) 
#define WLog_ERR(tag, fmt, ...) 

#define Stream_GetRemainingLength(s) ((s)->length - (s)->position)
#define Stream_Read_UINT8(s, val) do { (val) = *((s)->buffer + (s)->position); (s)->position += 1; } while(0)
#define Stream_Read_UINT16(s, val) do { (val) = *((uint16_t*)((s)->buffer + (s)->position)); (s)->position += 2; } while(0)
#define Stream_Read_UINT32(s, val) do { (val) = *((uint32_t*)((s)->buffer + (s)->position)); (s)->position += 4; } while(0)