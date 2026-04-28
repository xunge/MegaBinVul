#include <cassert>
#include <iostream>

typedef struct _GtkTargetList GtkTargetList;
typedef unsigned int GdkAtom;

void gtk_target_list_add_text_targets(GtkTargetList* list, int info);
void gtk_target_list_add_uri_targets(GtkTargetList* list, int info);
void gtk_target_list_add(GtkTargetList* list, GdkAtom target, int flags, int info);

namespace ui {
enum {
  TEXT_PLAIN,
  TEXT_URI_LIST,
  TEXT_HTML,
  NETSCAPE_URL,
  CHROME_TAB,
  CHROME_BOOKMARK_ITEM,
  CHROME_NAMED_URL,
  DIRECT_SAVE_FILE,
  CUSTOM_DATA,
  RENDERER_TAINT
};

GdkAtom GetAtomForTarget(int target_code);
}  // namespace ui

#define GTK_TARGET_SAME_APP 0
#define NOTREACHED() std::cerr