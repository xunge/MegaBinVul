#include <string.h>
#include <stdlib.h>

struct dump_dir;
struct problem_data;

typedef struct HashTable GHashTable;

static GHashTable *g_loaded_texts;
static struct problem_data *g_cd;
static const char *g_dump_dir_name;

void *g_hash_table_lookup(GHashTable *hash_table, const void *key);
void dd_save_text(struct dump_dir *dd, const char *name, const char *value);
void dd_close(struct dump_dir *dd);
struct dump_dir *wizard_open_directory_for_writing(const char *name);
const char *problem_data_get_content_or_NULL(struct problem_data *pd, const char *name);
void problem_data_reload_from_dump_dir(void);
void update_gui_state_from_problem_data(int flag);