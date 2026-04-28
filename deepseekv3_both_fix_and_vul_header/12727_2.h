#include <stdbool.h>

typedef struct IDEState IDEState;
typedef struct IDEBus IDEBus;

struct IDEState {
    IDEBus *bus;
};

void ide_abort_command(IDEState *s);
void ide_set_inactive(IDEState *s, bool inactive);
void ide_set_irq(IDEBus *bus);