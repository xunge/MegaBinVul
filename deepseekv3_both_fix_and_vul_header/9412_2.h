#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef struct QEMUFile QEMUFile;

extern void qemu_get_sbe32s(QEMUFile *f, int32_t *v);