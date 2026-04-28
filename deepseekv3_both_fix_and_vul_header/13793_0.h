#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef enum {
    FailureType_Failure_UnexpectedMessage
} FailureType;

typedef enum {
    NORMAL_MSG
} MsgType;

typedef enum {
    IN_MSG
} MsgDirection;

typedef struct {
    // Define structure members as needed
} MessagesMap_t;

extern int msg_tiny_flag;
extern void (*msg_failure)(FailureType, const char*);
extern const MessagesMap_t* message_map_entry(MsgType, uint16_t, MsgDirection);
extern void tiny_dispatch(const MessagesMap_t*, const void*, uint32_t);
extern void usb_rx_helper(const void*, size_t, MsgType);