#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;
typedef unsigned char ut8;

struct RPrint {
    bool cur_enabled;
    ut64 cur;
};

struct RConfig;
struct RAnal;

typedef struct RCore {
    ut64 offset;
    struct RPrint *print;
    struct RAnal *anal;
    struct RConfig *config;
} RCore;

char* __holdMouseState(RCore* core);
char* r_meta_get_string(struct RAnal* anal, int type, ut64 addr);
char* r_str_between(const char* str, const char* start, const char* end);
char* getcommapath(RCore* core);
char* r_cons_input(const char* prompt);
char* r_str_newf(const char* fmt, ...);
void r_meta_set_string(struct RAnal* anal, int type, ut64 addr, const char* str);
char* r_file_slurp(const char* file, int* sz);
char* r_core_editor(RCore* core, const char* file, const char* data);
int r_file_dump(const char* file, const ut8* data, int len, int append);
void eprintf(const char* fmt, ...);
void r_cons_enable_mouse(bool enable);
int r_config_get_i(struct RConfig* config, const char* key);

#define R_SYS_DIR "/"
#define R_META_TYPE_COMMENT 0