#include <stdint.h>
#include <string.h>

typedef enum {
    FailureType_Failure_UnexpectedMessage
} FailureType;

typedef enum {
    DEBUG_MSG
} MessageType;

typedef enum {
    IN_MSG
} MessageDirection;

typedef struct {
    // Define the structure members as needed
} MessagesMap_t;

extern int msg_tiny_flag;
extern void (*msg_failure)(FailureType, const char*);
extern const MessagesMap_t* message_map_entry(MessageType, uint16_t, MessageDirection);
extern void tiny_dispatch(const MessagesMap_t*, const void*, uint32_t);
extern void usb_rx_helper(const void*, size_t, MessageType);