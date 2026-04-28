#include <stdint.h>

typedef enum {
    IMHS_CONNECTED,
    IMHS_AUTHENTICATED
} ImapMboxHandleState;

typedef enum {
    IMR_OK
} ImapResponse;

typedef struct ImapMboxHandle ImapMboxHandle;

ImapMboxHandleState imap_mbox_handle_get_state(ImapMboxHandle *h);
void imap_mbox_handle_set_state(ImapMboxHandle *h, ImapMboxHandleState state);