#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MNEMONIC_SIZE 256

extern bool enforce_wordlist;
extern bool dry_run;
extern char mnemonic[MNEMONIC_SIZE];
extern bool awaiting_character;
extern bool recovery_started;

enum FailureType {
    FailureType_Failure_ActionCancelled
};

enum ButtonRequestType {
    ButtonRequestType_ButtonRequest_Other
};

bool change_pin(void);
void recovery_abort(void);
void fsm_sendFailure(enum FailureType, const char*);
void layoutHome(void);
void storage_setPin(const char*);
void storage_setPassphraseProtected(bool);
void storage_setLanguage(const char*);
void storage_setLabel(const char*);
void storage_setAutoLockDelayMs(uint32_t);
void storage_setU2FCounter(uint32_t);
bool pin_protect(const char*);
bool confirm(enum ButtonRequestType, const char*, const char*);
void storage_reset(void);
void next_character(void);