typedef struct _VteTerminal VteTerminal;
typedef struct _GValueArray GValueArray;

typedef void (*VteSequenceHandler)(VteTerminal *terminal, GValueArray *params);

void vte_sequence_handler_multiple(VteTerminal *terminal, GValueArray *params, VteSequenceHandler handler);
void vte_sequence_handler_ic(VteTerminal *terminal, GValueArray *params);