#include <stdbool.h>
#include <stddef.h>

typedef void* GWindow;
typedef void* GWidget;

#define CID_Script 0

struct sd_data {
    struct {
        bool script_unsaved;
    } *fv;
    GWindow gw;
};

enum event_type {
    et_close,
    et_controlevent,
    et_char,
    et_map,
    et_resize
};

enum control_subtype {
    et_textchanged,
    et_save
};

enum keysym {
    GK_F1,
    GK_Help
};

typedef struct GEvent {
    enum event_type type;
    union {
        struct {
            enum control_subtype subtype;
        } control;
        struct {
            enum keysym keysym;
        } chr;
    } u;
} GEvent;

struct sd_data* GDrawGetUserData(GWindow gw);
void SD_DoCancel(struct sd_data *sd);
bool GTextFieldIsEmpty(GWidget control);
GWidget GWidgetGetControl(GWindow gw, int cid);
void help(const char *url);
void GDrawRaise(GWindow gw);
void GDrawRequestExpose(GWindow gw, void *rect, bool flag);