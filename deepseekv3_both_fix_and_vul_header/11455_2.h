#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef bool gboolean;
#define FALSE false
#define TRUE true

#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)
#define g_assert(expr) do { if (!(expr)) abort(); } while (0)
#define g_assert_not_reached() abort()

typedef struct _GString GString;
typedef struct _GSList GSList;
typedef struct _GError GError;

typedef enum {
  STATE_START,
  STATE_AFTER_OPEN_ANGLE,
  STATE_AFTER_CLOSE_ANGLE,
  STATE_AFTER_ELISION_SLASH,
  STATE_INSIDE_OPEN_TAG_NAME,
  STATE_INSIDE_ATTRIBUTE_NAME,
  STATE_AFTER_ATTRIBUTE_NAME,
  STATE_BETWEEN_ATTRIBUTES,
  STATE_AFTER_ATTRIBUTE_EQUALS_SIGN,
  STATE_INSIDE_ATTRIBUTE_VALUE_SQ,
  STATE_INSIDE_ATTRIBUTE_VALUE_DQ,
  STATE_INSIDE_TEXT,
  STATE_AFTER_CLOSE_TAG_SLASH,
  STATE_INSIDE_CLOSE_TAG_NAME,
  STATE_AFTER_CLOSE_TAG_NAME,
  STATE_INSIDE_PASSTHROUGH,
  STATE_ERROR
} ParseState;

typedef struct _GMarkupParseContext {
  gboolean parsing;
  ParseState state;
  GString *partial_chunk;
  gboolean document_empty;
  GSList *tag_stack;
} GMarkupParseContext;

#define G_MARKUP_ERROR_EMPTY 0
#define G_MARKUP_ERROR_PARSE 1

#define _(x) x

void g_string_free(GString *string, gboolean free_segment);
const char *current_element(GMarkupParseContext *context);
void set_error(GMarkupParseContext *context, GError **error, int code, const char *message, ...);
void set_error_literal(GMarkupParseContext *context, GError **error, int code, const char *message);