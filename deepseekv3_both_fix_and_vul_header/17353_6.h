#include <string>

#define wxID_ANY 0
#define wxPD_AUTO_HIDE 0
#define wxPD_APP_MODAL 0
#define wxPD_REMAINING_TIME 0
#define wxID_CANCEL 0
#define _T(x) x
#define _(x) x

class wxString {
public:
    wxString();
    wxString(const char*);
    wxString(const wxString&);
    size_t Len() const;
    int Find(char) const;
    wxString SubString(int, int) const;
    const char* c_str() const;
    static wxString Format(const char*, ...);
    wxString operator+(const wxString&) const;
    wxString& operator=(const wxString&);
};

inline wxString operator+(const char* lhs, const wxString& rhs) {
    return wxString(lhs) + rhs;
}

class wxProgressDialog {
public:
    wxProgressDialog(const wxString&, const wxString&, int, void*, int);
};

class wxTextCtrl {
public:
    void SetValue(const wxString&);
};

class wxButton {
public:
    void Enable(bool);
};

class Config {
public:
    static Config* GetConfig();
};

class BZip {
public:
    BZip(const wxString&);
    wxString Extract(wxProgressDialog*);
};

class Tar {
public:
    Tar(const wxString&);
    int ReadHeaders();
    wxString getmDmodDescription();
    wxString getInstalledDmodDirectory();
};

class InstallVerifyFrame_Base {
public:
    InstallVerifyFrame_Base(void*, int, const wxString&);
    void EndModal(int);
    void SetTitle(const wxString&);
};

class InstallVerifyFrame : public InstallVerifyFrame_Base {
public:
    wxString mTarFilePath;
    wxString mDmodName;
    wxTextCtrl* mDmodDescription;
    wxButton* mInstallButton;
    Config* mConfig;

    InstallVerifyFrame(const wxString&);
    void prepareDialog();
};