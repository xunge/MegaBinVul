#include <assert.h>
#include <cstddef>

class CPDFSDK_Annot;
class CPDFDoc_Environment;
class CPDFSDK_AnnotHandlerMgr;

template <typename T>
class CFX_ArrayTemplate {
public:
    int GetSize();
    T* GetAt(int index);
    void RemoveAll();
};

class CPDFSDK_PageView {
public:
    ~CPDFSDK_PageView();
    void KillFocusAnnot();

    CPDFDoc_Environment* m_pSDKDoc;
    CFX_ArrayTemplate<CPDFSDK_Annot> m_fxAnnotArray;
    void* m_pAnnotList;
};

class CPDFSDK_Annot {};

class CPDFDoc_Environment {
public:
    CPDFSDK_Annot* GetFocusAnnot();
    CPDFSDK_AnnotHandlerMgr* GetAnnotHandlerMgr();
    CPDFDoc_Environment* GetEnv();
};

class CPDFSDK_AnnotHandlerMgr {
public:
    void ReleaseAnnot(CPDFSDK_Annot* pAnnot);
};

#define ASSERT assert