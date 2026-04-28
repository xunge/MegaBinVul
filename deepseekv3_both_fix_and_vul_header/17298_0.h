#include <string.h>
#include <stdlib.h>

typedef int Pin;
#define PIN_NAMES_DIRECT
#define JSH_PORT_MASK 0xFF
#define JSH_PORTA 0
#define JSH_PIN0 0

#define JSH_PORTA_OFFSET -1
#define JSH_PORTA_COUNT 0
#define JSH_PORTB_OFFSET -1 
#define JSH_PORTB_COUNT 0
#define JSH_PORTC_OFFSET -1
#define JSH_PORTC_COUNT 0
#define JSH_PORTD_OFFSET -1
#define JSH_PORTD_COUNT 0
#define JSH_PORTE_OFFSET -1
#define JSH_PORTE_COUNT 0
#define JSH_PORTF_OFFSET -1
#define JSH_PORTF_COUNT 0
#define JSH_PORTG_OFFSET -1
#define JSH_PORTG_COUNT 0
#define JSH_PORTH_OFFSET -1
#define JSH_PORTH_COUNT 0
#define JSH_PORTI_OFFSET -1
#define JSH_PORTI_COUNT 0
#define JSH_PORTV_OFFSET -1
#define JSH_PORTV_COUNT 0

struct PinInfo {
    int port;
    int pin;
};
extern struct PinInfo pinInfo[];

int jshIsPinValid(Pin pin);
void itostr(int value, char* str, int base);