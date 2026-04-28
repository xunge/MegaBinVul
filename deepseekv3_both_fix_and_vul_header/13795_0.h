#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define CONFIDENTIAL
#define MNEMONIC_BUF 256
#define CURRENT_WORD_BUF 64

extern bool recovery_started;
extern bool enforce_wordlist;
extern bool dry_run;
extern bool awaiting_character;
extern char mnemonic[MNEMONIC_BUF];
extern char cipher[MNEMONIC_BUF];

enum FailureType {
    FailureType_Failure_UnexpectedMessage,
    FailureType_Failure_SyntaxError,
    FailureType_Failure_Other
};

enum ButtonRequestType {
    ButtonRequestType_ButtonRequest_Other
};

void recovery_abort(void);
void fsm_sendFailure(enum FailureType, const char*);
void layoutHome(void);
bool attempt_auto_complete(char*);
void storage_reset(void);
void storage_setMnemonic(const char*);
bool storage_isInitialized(void);
bool storage_containsMnemonic(const char*);
void storage_setImported(bool);
void storage_commit(void);
void fsm_sendSuccess(const char*);
void review(enum ButtonRequestType, const char*, const char*);
void session_clear(bool);
bool mnemonic_check(const char*);