#include <stdio.h>
#include <string.h>

#define WEBUI_LEN_PARM 256
#define DBG 1
#define TYPE_STREAM 1
#define NO_ERRNO 0

struct webui_ctx {
    char url[WEBUI_LEN_PARM];
    char uri_camid[WEBUI_LEN_PARM];
    char uri_cmd1[WEBUI_LEN_PARM];
    char uri_cmd2[WEBUI_LEN_PARM];
    char uri_parm1[WEBUI_LEN_PARM];
    char uri_value1[WEBUI_LEN_PARM];
    char uri_parm2[WEBUI_LEN_PARM];
    char uri_value2[WEBUI_LEN_PARM];
};

int webu_url_decode(char *url, int len);
void webu_parseurl_reset(struct webui_ctx *webui);
void webu_parseurl_parms(struct webui_ctx *webui, char *st_pos);
void MOTION_LOG(int level, int type, int errno, const char *fmt, ...);