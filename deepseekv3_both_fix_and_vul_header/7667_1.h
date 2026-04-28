#include <stdint.h>

#define BSTRP_FLASH_SECT_START 0
#define BSTRP_FLASH_SECT_LEN 0
#define BLDR_FLASH_SECT_START 0 
#define BLDR_FLASH_SECT_LEN 0

extern volatile uint32_t FLASH_CR;
#define FLASH_CR_PG (1 << 0)
#define FLASH_CR_LOCK (1 << 7)

extern uint32_t _param_1;
extern uint32_t _param_2; 
extern uint32_t _param_3;

void flash_clear_status_flags(void);
void flash_unlock(void);
void flash_program_word(uint32_t dst, uint32_t src);
int flash_chk_status(void);
void flash_wait_for_last_operation(void);