#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Display Display;
typedef char* String;

int ProtocolVersion(Display*);
int ProtocolRevision(Display*);
char* ServerVendor(Display*);
int VendorRelease(Display*);
int ScreenCount(Display*);
char** XListExtensions(Display*, int*);
void XFreeExtensionList(char**);
char* XDisplayName(char*);
void XmuGetHostname(char*, int);

void AddDef(String*, const char*, const char*);
void AddDefTok(String*, const char*, const char*);
void AddNum(String*, const char*, int);
void AddDefQ(String*, const char*, const char*);

#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN 255
#endif