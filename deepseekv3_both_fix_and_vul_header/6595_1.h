#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define WM_SYMBOL

typedef struct midi midi;

extern int WM_Initialized;
extern int WM_ERR_NOT_INIT;
extern int WM_ERR_INVALID_ARG;
extern int WM_ERR_CORUPT;

void _WM_GLOBAL_ERROR(const char *func, int line, int err, const char *arg, int code);
void *_WM_BufferFile(const char *filename, uint32_t *size);
void *_WM_ParseNewHmp(uint8_t *data, uint32_t size);
void *_WM_ParseNewHmi(uint8_t *data, uint32_t size);
void *_WM_ParseNewMus(uint8_t *data, uint32_t size);
void *_WM_ParseNewXmi(uint8_t *data, uint32_t size);
void *_WM_ParseNewMidi(uint8_t *data, uint32_t size);
int add_handle(midi *m);
void WildMidi_Close(midi *m);