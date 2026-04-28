#include <stdlib.h>

typedef struct
{
  int __used;
  struct __spawn_action *__actions;
} posix_spawn_file_actions_t;

struct __spawn_action
{
  int tag;
  union
  {
    struct
    {
      char *path;
    } open_action;
  } action;
};

enum
{
  spawn_do_open,
  spawn_do_close,
  spawn_do_dup2
};