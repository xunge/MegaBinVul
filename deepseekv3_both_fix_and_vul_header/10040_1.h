#include <stdlib.h>
#include <string.h>

typedef struct VCardAPDU {
    unsigned char *a_data;
    int a_len;
} VCardAPDU;

typedef enum {
    VCARD7816_STATUS_SUCCESS,
    VCARD7816_STATUS_EXC_ERROR_MEMORY_FAILURE,
    VCARD7816_STATUS_ERROR_WRONG_LENGTH
} vcard_7816_status_t;

extern vcard_7816_status_t vcard_apdu_set_class(VCardAPDU *apdu);
extern vcard_7816_status_t vcard_apdu_set_length(VCardAPDU *apdu);

#define g_new(type, count) ((type *)malloc(sizeof(type) * (count)))
#define g_memdup(src, size) memcpy(malloc(size), src, size)
#define g_free(ptr) free(ptr)