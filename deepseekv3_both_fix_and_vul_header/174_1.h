#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

struct upnphttp {
    char *req_buf;
    int req_contentoff;
    int req_contentlen;
};

struct NameValueParserData {
    void *l_head;
};

#define GETFLAG(x) 0
#define IPV6FCFWDISABLEDMASK 0

void ParseNameValue(const char *buffer, int bufsize, struct NameValueParserData *data);
char *GetValueFromNameValueList(struct NameValueParserData *pdata, const char *Name);
void ClearNameValueList(struct NameValueParserData *pdata);
void SoapError(struct upnphttp *h, int errCode, const char *errDesc);
void BuildSendAndCloseSoapResp(struct upnphttp *h, const char *body, int bodylen);

char *ext_port = NULL;