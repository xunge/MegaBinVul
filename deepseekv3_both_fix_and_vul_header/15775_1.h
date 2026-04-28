#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true

typedef bool gboolean;
typedef char gchar;

extern char *FILENAME_TYPE;
extern int client_uid;

bool str_is_correct_filename(gchar *value);
void error_msg(const char *format, ...);
gboolean allowed_new_user_problem_entry(int uid, gchar *key, gchar *value);