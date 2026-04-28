#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <assert.h>

typedef struct JournalFile {
    int open_flags;
    mode_t mode;
} JournalFile;

typedef struct MMapCache MMapCache;
typedef struct Set Set;

typedef unsigned JournalFileFlags;

#define _cleanup_free_ __attribute__((cleanup(free_cleanup)))
static inline void free_cleanup(void *p) { free(*(void**)p); }

void journal_file_offline_close(void *f);
int journal_file_archive(JournalFile *f, char **path);
int journal_file_open(int fd, const char *path, int open_flags, JournalFileFlags file_flags, mode_t mode, uint64_t compress_threshold_bytes, void *metrics, MMapCache *mmap_cache, JournalFile *template, JournalFile **ret);
void journal_file_initiate_close(JournalFile *f, Set *deferred_closes);
void set_clear_with_destructor(Set *s, void (*destructor)(void*));