#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>

typedef struct problem_data_t problem_data_t;
typedef struct GVariant GVariant;
typedef struct GVariantIter GVariantIter;
typedef char gchar;
typedef bool gboolean;

extern problem_data_t *problem_data_new(void);
extern void problem_data_add_text_editable(problem_data_t *pd, const char *key, const char *value);
extern const char *problem_data_get_content_or_NULL(problem_data_t *pd, const char *key);
extern void problem_data_add_text_noteditable(problem_data_t *pd, const char *key, const char *value);
extern void problem_data_add_basics(problem_data_t *pd);
extern char *problem_data_save(problem_data_t *pd);
extern void problem_data_free(problem_data_t *pd);
extern void notify_new_path(const char *problem_id);
extern char *xasprintf(const char *format, ...);
extern void g_variant_get(GVariant *value, const char *format_string, ...);
extern gboolean g_variant_iter_loop(GVariantIter *iter, const char *format_string, ...);
extern void log_info(const char *format, ...);

#define FILENAME_UID "uid"