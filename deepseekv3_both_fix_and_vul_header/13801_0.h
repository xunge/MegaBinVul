#include <stdbool.h>
#include <string.h>

extern bool recovery_started;
extern char mnemonic[];
extern void recovery_abort(void);
extern void fsm_sendFailure(int, const char*);
extern void layoutHome(void);
extern void next_character(void);

enum FailureType {
    FailureType_Failure_UnexpectedMessage
};