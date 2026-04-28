#include <stddef.h>
#include <stdbool.h>

typedef void* GtkNotebook;
typedef void* GtkWidget;
typedef void* gpointer;
typedef void* GtkTextView;
typedef void* GtkTextBuffer;
typedef void* GtkToggleButton;
typedef void* GtkExpander;
typedef bool gboolean;

#define TRUE true
#define FALSE false
#define FILENAME_COMMENT "comment"
#define PAGENO_SUMMARY 0
#define PAGENO_EDIT_ELEMENTS 1
#define PAGENO_REVIEW_DATA 2
#define PAGENO_EDIT_COMMENT 3
#define PAGENO_EVENT_PROGRESS 4
#define PAGENO_EVENT_SELECTOR 5

extern GtkWidget *g_assistant;
extern GtkWidget *g_btn_detail;
extern GtkWidget *g_btn_onfail;
extern GtkWidget *g_btn_repeat;
extern GtkWidget *g_btn_next;
extern GtkWidget *g_exp_search;
extern GtkWidget *g_rb_custom_search;
extern GtkWidget *g_tb_approve_bt;
extern GtkTextView *g_tv_comment;
extern gboolean g_expert_mode;
extern gboolean g_auto_event_list;
extern char *g_event_selected;

struct PageInfo {
    GtkWidget *page_widget;
    int page_no;
};

extern struct PageInfo pages[];

void gtk_widget_hide(GtkWidget *widget);
void gtk_widget_show(GtkWidget *widget);
void gtk_widget_set_sensitive(GtkWidget *widget, gboolean sensitive);
void gtk_notebook_set_current_page(GtkNotebook *notebook, int page_num);
void gtk_expander_set_expanded(GtkExpander *expander, gboolean expanded);
void gtk_toggle_button_set_active(GtkToggleButton *toggle_button, gboolean active);
gboolean gtk_toggle_button_get_active(GtkToggleButton *toggle_button);
GtkTextBuffer* gtk_text_view_get_buffer(GtkTextView *text_view);
GtkToggleButton* GTK_TOGGLE_BUTTON(GtkWidget *widget);

void log_ready_state(void);
int is_processing_finished(void);
void show_next_step_button(void);
void clear_warnings(void);
void save_items_from_notepad(void);
void save_text_from_text_view(GtkTextView *text_view, const char *filename);
int select_next_page_no(int current_page_no, void *data);
void log_info(const char *format, ...);
gboolean highlight_forbidden(void);
void add_sensitive_data_warning(void);
void show_warnings(void);
void update_ls_details_checkboxes(const char *event);
void on_comment_changed(GtkTextBuffer *buffer, gpointer user_data);
void hide_next_step_button(void);
void start_event_run(const char *event);