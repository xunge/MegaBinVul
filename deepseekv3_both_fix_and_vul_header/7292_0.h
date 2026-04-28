#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct session;
extern struct session *cryptobox_session_find(void *g_cryptobox, const char *userid, const char *clientid, const char *lclientid);
extern int cryptobox_session_add_send(void *g_cryptobox, const char *userid, const char *clientid, const char *lclientid, const uint8_t *key, size_t key_len);
extern int client_id_load(char *lclientid, size_t size);
extern void output(const char *format, ...);
extern void debug(const char *format, ...);
extern void info(const char *format, ...);
extern void warning(const char *format, ...);
extern void *g_cryptobox;