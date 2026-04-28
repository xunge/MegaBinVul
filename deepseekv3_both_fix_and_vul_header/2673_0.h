#include <time.h>
#include <string.h>
#include <stdlib.h>

struct t_gui_buffer;
struct tm;

extern const char *weechat_info_get(const char *info_name, const char *arguments);
extern char *weechat_string_replace(const char *string, const char *search, const char *replace);
extern char *weechat_buffer_string_replace_local_var(struct t_gui_buffer *buffer, const char *string);
extern const char *weechat_config_string(const void *config_option);
extern int weechat_config_boolean(const void *config_option);
extern void weechat_string_tolower(char *string);
extern void weechat_printf_date_tags(struct t_gui_buffer *buffer, time_t date, const char *tags, const char *message, ...);
extern const char *weechat_buffer_get_string(struct t_gui_buffer *buffer, const char *property);

extern void *logger_config_file_replacement_char;
extern void *logger_config_file_name_lower_case;
extern const char *LOGGER_PLUGIN_NAME;

struct weechat_logger_plugin_t {
    int debug;
};
extern struct weechat_logger_plugin_t *weechat_logger_plugin;