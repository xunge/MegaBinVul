#include <stdint.h>
#include <string.h>

typedef struct midi midi;

extern int WM_Initialized;
extern uint32_t WM_MAXFILESIZE;

#define WM_SYMBOL

enum {
    WM_ERR_NOT_INIT,
    WM_ERR_INVALID_ARG,
    WM_ERR_LONGFIL,
    WM_ERR_CORUPT
};

void _WM_GLOBAL_ERROR(const char *func, int line, int err, const char *msg, int val);
midi* _WM_ParseNewHmp(uint8_t *midibuffer, uint32_t size);
midi* _WM_ParseNewHmi(uint8_t *midibuffer, uint32_t size);
midi* _WM_ParseNewMus(uint8_t *midibuffer, uint32_t size);
midi* _WM_ParseNewXmi(uint8_t *midibuffer, uint32_t size);
midi* _WM_ParseNewMidi(uint8_t *midibuffer, uint32_t size);
int add_handle(midi *ret);
void WildMidi_Close(midi *ret);