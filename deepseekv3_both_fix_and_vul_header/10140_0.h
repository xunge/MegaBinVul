#include <stdint.h>

#define JPC_QCX_GETEXPN(q) ((q) >> 11)
#define JPC_QCX_GETMANT(q) ((q) & 0x7ff)
#define JPC_QCX_EXPN(e) ((e) << 11)
#define JPC_QCX_MANT(m) ((m) & 0x7ff)