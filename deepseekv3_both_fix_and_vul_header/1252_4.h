#include <stdlib.h>

#define R_API
#define R_FREE(x) free(x)

typedef struct RCore RCore;
typedef struct RList RList;
typedef struct REvent REvent;
typedef struct RNum RNum;
typedef struct RCmd RCmd;
typedef struct RAnal RAnal;
typedef struct RAsm RAsm;
typedef struct RPrint RPrint;
typedef struct RBin RBin;
typedef struct RLang RLang;
typedef struct RDebug RDebug;
typedef struct RIo RIo;
typedef struct RConfig RConfig;
typedef struct RCons {
    char *pager;
    void *teefile;
} RCons;
typedef struct RSearch RSearch;
typedef struct RFlag RFlag;
typedef struct RFs RFs;
typedef struct REgg REgg;
typedef struct RLib RLib;
typedef struct RBuf RBuf;
typedef struct RAGraph RAGraph;
typedef struct Sdb Sdb;
typedef struct RParse RParse;

struct RCore {
    void *tasks;
    RList *ropchain;
    REvent *ev;
    char *cmdlog;
    char *lastsearch;
    RCons *cons;
    char *cmdqueue;
    char *lastcmd;
    char *stkcmd;
    struct {
        RList *tabs;
    } visual;
    void *block;
    void *autocomplete;
    RList *gadgets;
    RList *undos;
    RNum *num;
    char *table_query;
    RList *files;
    RList *watchers;
    RList *scriptstack;
    RCmd *rcmd;
    RList *cmd_descriptors;
    RAnal *anal;
    RAsm *assembler;
    RPrint *print;
    RBin *bin;
    RLang *lang;
    RDebug *dbg;
    RIo *io;
    RConfig *config;
    RSearch *search;
    RFlag *flags;
    RFs *fs;
    REgg *egg;
    RLib *lib;
    RBuf *yank_buf;
    RAGraph *graph;
    char *asmqjmps;
    Sdb *sdb;
    void *log;
    RParse *parser;
    void *times;
};

// 函数声明
void r_core_task_break_all(void *tasks);
void r_core_task_join(void *tasks, void *arg, int timeout);
void r_core_wait(RCore *c);
void r_list_free(RList *list);
void r_event_free(REvent *ev);
void r_core_autocomplete_free(void *autocomplete);
void r_num_free(RNum *num);
void r_core_task_scheduler_fini(void *tasks);
RCmd *r_cmd_free(RCmd *rcmd);
RAnal *r_anal_free(RAnal *anal);
void r_asm_free(RAsm *a);
RPrint *r_print_free(RPrint *print);
RBin *r_bin_free(RBin *bin);
RLang *r_lang_free(RLang *lang);
RDebug *r_debug_free(RDebug *dbg);
void r_io_free(RIo *io);
void r_config_free(RConfig *config);
void r_cons_free(void);
RCons *r_cons_singleton(void);
void r_search_free(RSearch *search);
void r_flag_free(RFlag *flags);
void r_fs_free(RFs *fs);
void r_egg_free(REgg *egg);
void r_lib_free(RLib *lib);
void r_buf_free(RBuf *buf);
void r_agraph_free(RAGraph *graph);
void sdb_free(Sdb *sdb);
void r_core_log_free(void *log);
void r_parse_free(RParse *parser);