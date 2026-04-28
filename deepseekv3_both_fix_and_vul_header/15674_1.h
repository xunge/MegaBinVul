#include <stdbool.h>

#define FR_COMMAND_CAN_ARCHIVE_MANY_FILES (1 << 0)
#define FR_COMMAND_CAN_READ (1 << 1)

typedef unsigned int FrCommandCaps;
typedef bool gboolean;

typedef struct {
    // dummy structure for FrCommand
} FrCommand;

#define CPIO_PATH "/bin/cpio"

bool is_program_available(const char *path, bool check_command);