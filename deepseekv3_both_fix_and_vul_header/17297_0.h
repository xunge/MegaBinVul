#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef unsigned int JshPinFunction;
typedef unsigned int JshPinFunctionToStringFlags;

#define JSH_MASK_INFO 0xFF
#define JSH_MASK_TYPE 0xFF00
#define JSH_SHIFT_TYPE 8
#define JSH_SHIFT_INFO 0

#define JSH_PINFUNCTION_IS_USART(x) 0
#define JSH_PINFUNCTION_IS_SPI(x) 0
#define JSH_PINFUNCTION_IS_I2C(x) 0
#define JSH_PINFUNCTION_IS_DAC(x) 0
#define JSH_PINFUNCTION_IS_TIMER(x) 0

#define JSH_USART1 0
#define JSH_USART_RX 0
#define JSH_USART_TX 0
#define JSH_USART_CK 0

#define JSH_SPI1 0
#define JSH_SPI_MISO 0
#define JSH_SPI_MOSI 0
#define JSH_SPI_SCK 0

#define JSH_I2C1 0
#define JSH_I2C_SCL 0
#define JSH_I2C_SDA 0

#define JSH_DAC 0
#define JSH_DAC_CH1 0
#define JSH_DAC_CH2 0

#define JSH_TIMER1 0
#define JSH_MASK_TIMER_CH 0
#define JSH_TIMER_NEGATED 0

#define JSPFTS_JS_NAMES 0
#define JSPFTS_DEVICE 0
#define JSPFTS_DEVICE_NUMBER 0
#define JSPFTS_SPACE 0
#define JSPFTS_TYPE 0

void jsiConsolePrintf(const char *fmt, ...);
void itostr(int value, char *str, int base);