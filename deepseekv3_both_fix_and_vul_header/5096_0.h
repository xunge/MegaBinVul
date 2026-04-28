#include <stdint.h>
#include <stdlib.h>

#define FILEXFER_ALLOWED_OR_CLOSE_AND_RETURN(msg, cl, ret) 

typedef struct rfbClientRec* rfbClientPtr;
struct rfbClientRec;

void rfbLog(const char* format, ...);
void rfbLogPerror(const char* msg);
int rfbReadExact(rfbClientPtr cl, char* buf, int len);
void rfbCloseClient(rfbClientPtr cl);