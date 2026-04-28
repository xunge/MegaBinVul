#include <stdbool.h>
#include <stddef.h>

typedef struct FontView FontView;
typedef struct SplineFont SplineFont;
typedef struct FontViewBase FontViewBase;

struct FontView {
    struct {
        SplineFont *cidmaster;
        SplineFont *sf;
        FontViewBase *nextsame;
    } b;
    bool script_unsaved;
    void *gw;
};

struct SplineFont {
    char *filename;
    char *origname;
    FontViewBase *fv;
};

extern bool warn_script_unsaved;
extern int AskScriptChanged(void);
extern int AskChanged(SplineFont *sf);
extern bool _FVMenuSave(FontView *fv);
extern void _FVCloseWindows(FontView *fv);
extern void RecentFilesRemember(char *filename);
extern void GDrawDestroyWindow(void *gw);
extern bool SFCloseAllInstrs(SplineFont *sf);
extern bool SFAnyChanged(SplineFont *sf);
extern void SFClearAutoSave(SplineFont *sf);