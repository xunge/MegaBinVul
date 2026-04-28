#include <limits.h>

extern int curbuf;
extern int State;
extern int VREPLACE_FLAG;
extern int INDENT_SET;
extern int FALSE;
extern int NUL;
extern int SIN_CHANGED;

int get_sw_value_indent(int buf);
long long get_indent();
void change_indent(int type, int amount, int round, int c, int call_changed_bytes);
int set_indent(int count, int flags);