typedef unsigned long DWORD;
typedef long HRESULT;
#define STDMETHODIMP HRESULT

class IInternetProtocol;
typedef HRESULT (*InternetProtocol_Terminate_Fn)(IInternetProtocol*, DWORD);

class ProtData;
template <typename T> class scoped_refptr;

class ExceptionBarrierReportOnlyModule {
};

class ProtData {
public:
    static scoped_refptr<ProtData> DataFromProtocol(IInternetProtocol* protocol);
    bool is_attach_external_tab_request() const;
    void Invalidate();
    int renderer_type() const;
};

template <typename T>
class scoped_refptr {
public:
    scoped_refptr(T* ptr) : ptr_(ptr) {}
    T* get() const { return ptr_; }
    T* operator->() const { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }
private:
    T* ptr_;
};

bool IsChrome(int renderer_type);