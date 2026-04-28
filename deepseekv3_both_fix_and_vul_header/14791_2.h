#include <stddef.h>
#include <assert.h>

enum PDFOBJ_TYPE {
    PDFOBJ_DICTIONARY
};

class FX_BSTRC {
public:
    FX_BSTRC(const char*) {}
};

class CPDF_Object {
public:
    virtual ~CPDF_Object() {}
    virtual PDFOBJ_TYPE GetType() const = 0;
    virtual unsigned long GetObjNum() const = 0;
};

class CPDF_Dictionary : public CPDF_Object {
public:
    PDFOBJ_TYPE GetType() const override { return PDFOBJ_DICTIONARY; }
    unsigned long GetObjNum() const override { return 0; }
    CPDF_Dictionary* GetDict(const FX_BSTRC&) const { return nullptr; }
};

#define ASSERT assert

class CPDF_Document {
public:
    CPDF_Dictionary* GetPage(int iPage);
    CPDF_Object* GetIndirectObject(int objnum);
    CPDF_Dictionary* GetRoot();
    CPDF_Dictionary* _FindPDFPage(CPDF_Dictionary* pPages, int iPage, int iPage2, int iPage3);

    class {
    public:
        int GetSize() const { return 0; }
        int GetAt(int index) const { return 0; }
        void SetAt(int index, int value) {}
    } m_PageList;

    bool m_bLinearized;
    unsigned long m_dwFirstPageNo;
    unsigned long m_dwFirstPageObjNum;
};