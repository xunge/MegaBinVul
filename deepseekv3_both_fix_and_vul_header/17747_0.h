#include <stdbool.h>

struct vc_data;

static bool npadch_active;
static unsigned int npadch_value;
static int npadch = -1;