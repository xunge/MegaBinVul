#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define JOURNAL_HEADER_SEALED(header) ((header)->flags & 1)
#define FSPRG_GetEpoch(state) (0)
#define FSPRG_Evolve(state) 
#define ESTALE (-1)

typedef struct JournalFile JournalFile;
typedef struct {
    int flags;
} JournalHeader;

struct JournalFile {
    JournalHeader *header;
    void *fsprg_state;
};

int journal_file_get_epoch(JournalFile *f, uint64_t realtime, uint64_t *goal);
void log_debug(const char *format, ...);