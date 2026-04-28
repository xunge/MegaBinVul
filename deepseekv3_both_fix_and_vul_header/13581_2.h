#include <stdbool.h>
#include <stddef.h>

typedef struct sd_event_source sd_event_source;

typedef struct JournalFile {
    struct {
        int sealed;
    } header;
    sd_event_source *post_change_timer;
} JournalFile;

#define HAVE_GCRYPT 1
#define JOURNAL_HEADER_SEALED(header) ((header).sealed)
#define log_error_errno(r, ...)

int sd_event_source_get_enabled(sd_event_source *src, void *userdata);
void sd_event_source_disable_unref(sd_event_source *src);

bool journal_file_writable(JournalFile *f);
int journal_file_append_tag(JournalFile *f);
void journal_file_post_change(JournalFile *f);
void journal_file_set_offline(JournalFile *f, bool offline);
JournalFile* journal_file_close(JournalFile *f);