#include <string>
#include <memory>

namespace base {
class RefCountedMemory;
class RefCountedString;
}  // namespace base

template<typename T>
class scoped_refptr {
public:
    scoped_refptr();
    scoped_refptr(T* ptr);
};

class Clipboard {
public:
    class aurax11_details_ {
    public:
        void InsertMapping(const char* mime_type,
                          scoped_refptr<base::RefCountedMemory> memory);
    };
    aurax11_details_* aurax11_details_;
    
    void WriteWebSmartPaste();
};

const char kMimeTypeWebkitSmartPaste[] = "";

namespace base {
class RefCountedMemory {
public:
    static scoped_refptr<RefCountedMemory> TakeString(std::string* str);
};
class RefCountedString : public RefCountedMemory {};
}  // namespace base