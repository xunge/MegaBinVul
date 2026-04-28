#include <stdbool.h>
#include <string.h>

#define MNEMONIC_SIZE 256
#define CIPHER_SIZE 256

extern bool dry_run;
extern bool recovery_started;
extern bool awaiting_character;
extern char mnemonic[MNEMONIC_SIZE];
extern char cipher[CIPHER_SIZE];

void storage_reset(void);
void memzero(void *dest, size_t n);