#include <stdint.h>
#include <string.h>

#define BLE_GAP_PASSKEY_LEN 6

typedef struct JsVar JsVar;

void jsvGetString(JsVar *var, char *str, size_t len);
uint32_t jsble_central_send_passkey(const char *passkey);
void jsble_check_error(uint32_t err_code);