#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct _FlatpakDir FlatpakDir;
typedef struct _FlatpakDecomposed FlatpakDecomposed;

#define FLATPAK_ANSI_BOLD_ON "\033[1m"
#define FLATPAK_ANSI_BOLD_OFF "\033[22m"
#define FLATPAK_ESCAPE_ALLOW_NEWLINES (1 << 0)
#define FLATPAK_ESCAPE_DO_NOT_QUOTE (1 << 1)

#define gboolean bool
#define g_print printf
#define g_assert assert
#define _(x) x
#define g_autofree
#define g_autoptr(type) type*

bool flatpak_dir_ref_is_pinned(FlatpakDir *dir, const char *ref);
char *flatpak_decomposed_dup_branch(FlatpakDecomposed *ref);
const char *flatpak_decomposed_get_ref(FlatpakDecomposed *ref);
bool flatpak_fancy_output(void);
FlatpakDecomposed *flatpak_decomposed_new_from_ref(const char *ref, void *error);
bool flatpak_decomposed_is_runtime(FlatpakDecomposed *ref);
char *flatpak_decomposed_dup_id(FlatpakDecomposed *ref);
const char *flatpak_decomposed_get_branch(FlatpakDecomposed *ref);
int flatpak_decomposed_get_kind(FlatpakDecomposed *ref);
char *flatpak_escape_string(const char *str, int flags);