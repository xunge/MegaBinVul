#include <stdint.h>

#define FLASH_BOOTSTRAP_SECTOR 0
#define FLASH_BOOT_SECTOR_FIRST 1
#define FLASH_BOOT_SECTOR_LAST 2
#define FLASH_CR_PROGRAM_X32 0
#define FLASH_CR_PG 0
#define FLASH_CR_LOCK 0

extern uint32_t _param_1;
extern uint32_t _param_2;
extern uint32_t _param_3;
extern uint32_t FLASH_CR;

void flash_clear_status_flags(void);
void flash_unlock(void);
void flash_erase_sector(uint32_t sector, uint32_t program_size);
int flash_chk_status(void);
void flash_wait_for_last_operation(void);