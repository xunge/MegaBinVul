#include <stdint.h>

extern uint32_t _param_1;
extern uint32_t _param_2;
extern uint32_t _param_3;

#define BSTRP_FLASH_SECT_START 0
#define BSTRP_FLASH_SECT_LEN 0
#define BLDR_FLASH_SECT_START 0 
#define BLDR_FLASH_SECT_LEN 0

#define FLASH_CR_PG 0
#define FLASH_CR_LOCK 0
extern uint32_t FLASH_CR;

void flash_clear_status_flags(void);
void flash_unlock(void);
void flash_program(uint32_t addr, uint8_t *data, uint32_t len);
uint32_t flash_chk_status(void);
void flash_wait_for_last_operation(void);