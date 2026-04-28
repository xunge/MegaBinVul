#include <string>

#define wxPD_AUTO_HIDE 1
#define wxPD_APP_MODAL 2
#define wxPD_REMAINING_TIME 4
#define wxOK 8
#define wxICON_INFORMATION 16
#define wxYES_NO 32
#define wxICON_WARNING 64
#define wxNO 128
#define wxID_OK 256
#define wxID_CANCEL 512
#define _T(x) x
#define _(x) x

class wxString : public std::string {
public:
    wxString(const char* s = "") : std::string(s) {}
    wxString(const std::string& s) : std::string(s) {}
    int Len() const { return length(); }
    wxString RemoveLast() { pop_back(); return *this; }
    char Last() const { return back(); }
    wxString& operator+=(const wxString& s) { append(s); return *this; }
    void Printf(const char* fmt, const wxString& arg) {}
};

class wxFileName {
public:
    static wxString GetPathSeparator() { return "/"; }
};

class wxProgressDialog {
public:
    wxProgressDialog(const wxString&, const wxString&, int, void*, int) {}
};

class wxCommandEvent {};

class wxChoice {
public:
    int GetSelection() const { return 0; }
};

class Config {
public:
    wxString GetDinkrefDir() const { return ""; }
    wxString mDModDir;
    wxString mSelectedDmod;
};

class Tar {
public:
    Tar(const wxString& path) : mTarFilePath(path) {}
    int ReadHeaders() { return 0; }
    int Extract(const wxString& dest, wxProgressDialog* progress) { return 0; }
    wxString getInstalledDmodDirectory() { return ""; }
private:
    wxString mTarFilePath;
};

class InstallVerifyFrame {
public:
    void onInstall(wxCommandEvent& Event);
    wxString mDmodName;
    Config* mConfig;
    wxChoice* mDestdirBox;
    wxString mTarFilePath;
    void EndModal(int) {}
};

int wxMessageBox(const wxString&, const wxString&, int, void*) { return 0; }
void wxLogError(const wxString&) {}
bool wxDirExists(const wxString&) { return false; }