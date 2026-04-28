typedef struct _GSManager GSManager;
typedef struct _GSWindow GSWindow;
typedef struct _GdkMonitor GdkMonitor;
typedef struct _GdkDisplay GdkDisplay;
typedef struct _GtkWidget GtkWidget;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} GdkRectangle;

typedef struct _GSList {
    void *data;
    struct _GSList *next;
} GSList;

struct _GSManagerPrivate {
    int lock_active;
    int user_switch_enabled;
    int logout_enabled;
    int logout_timeout;
    char *logout_command;
    int keyboard_enabled;
    char *keyboard_command;
    char *status_message;
    GSList *windows;
    int active;
    int fading;
};

struct _GSManager {
    struct _GSManagerPrivate *priv;
};