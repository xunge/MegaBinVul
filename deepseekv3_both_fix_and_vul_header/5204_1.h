#include <string>

using namespace std;

struct StartElementEvent {
    enum ContentType {
        empty,
        cdata,
        rcdata,
        mixed,
        element
    };
    ContentType contentType;
    string gi;
    int pos;
};

class OfxContainerBase {
public:
    string type;
};

extern void CharStringtostring(const string&, string&);
extern void message_out(int, const string&);
extern string incoming_data;
extern bool is_data_element;
extern int PARSER;
extern int ERROR;
extern void* libofx_context;
extern OfxContainerBase* curr_container_element;
extern OfxContainerBase* MainContainer;
extern int position;

class OfxMainContainer : public OfxContainerBase {
public:
    OfxMainContainer(void*, OfxContainerBase*, const string&);
};

class OfxStatusContainer : public OfxContainerBase {
public:
    OfxStatusContainer(void*, OfxContainerBase*, const string&);
};

class OfxStatementContainer : public OfxContainerBase {
public:
    OfxStatementContainer(void*, OfxContainerBase*, const string&);
};

class OfxPushUpContainer : public OfxContainerBase {
public:
    OfxPushUpContainer(void*, OfxContainerBase*, const string&);
};

class OfxBankTransactionContainer : public OfxContainerBase {
public:
    OfxBankTransactionContainer(void*, OfxContainerBase*, const string&);
};

class OfxInvestmentTransactionContainer : public OfxContainerBase {
public:
    OfxInvestmentTransactionContainer(void*, OfxContainerBase*, const string&);
};

class OfxAccountContainer : public OfxContainerBase {
public:
    OfxAccountContainer(void*, OfxContainerBase*, const string&);
};

class OfxSecurityContainer : public OfxContainerBase {
public:
    OfxSecurityContainer(void*, OfxContainerBase*, const string&);
};

class OfxBalanceContainer : public OfxContainerBase {
public:
    OfxBalanceContainer(void*, OfxContainerBase*, const string&);
};

class OfxDummyContainer : public OfxContainerBase {
public:
    OfxDummyContainer(void*, OfxContainerBase*, const string&);
};