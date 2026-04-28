#include <string.h>
#include <stdio.h>

#define MG_BUF_LEN 8192

struct mg_connection;
struct mg_file;

int mg_fgetc(struct mg_file *fp, int offset);
void mg_cry_internal(struct mg_connection *conn, const char *fmt, ...);
size_t mg_write(struct mg_connection *conn, const void *buf, size_t len);
void do_ssi_include(struct mg_connection *conn, const char *path, const char *include, int level);
void do_ssi_exec(struct mg_connection *conn, const char *command);