#include <stdlib.h>

typedef struct ST ST;
typedef struct sql_comp_t sql_comp_t;

ST *sqlc_union_dt_wrap_v1(sql_comp_t *sc, ST *tree);
ST *sqlc_union_dt_wrap_v2(ST *tree);
void sql_stmt_comp(sql_comp_t *sc, ST **ptree);
void sqlc_union_stmt(sql_comp_t *sc, ST **ptree);