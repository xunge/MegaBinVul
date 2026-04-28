#include <memory>
#include <string>
#include <atomic>
#include <stdexcept>

namespace zim {
    class Archive;
    
    class EntryNotFound : public std::exception {
    };
    
    class Entry {
    public:
        bool isRedirect() const;
        std::string getPath() const;
        class Item {
        public:
            std::string getMimetype() const;
        };
        Item getItem(bool = false) const;
    };
}

namespace kiwix {
    std::string urlEncode(const std::string&, bool);
    std::string urlDecode(const std::string&);
}

class RequestContext {
public:
    std::string get_url() const;
    std::string get_full_url() const;
};

class Response {
public:
    virtual ~Response() = default;
    static std::unique_ptr<Response> build_404(class InternalServer&, const std::string&, const std::string&, const std::string&, const std::string&);
};

class ItemResponse : public Response {
public:
    static std::unique_ptr<ItemResponse> build(class InternalServer&, const RequestContext&, const zim::Entry::Item&);
};

class ContentResponse : public Response {
public:
    virtual void set_taskbar(const std::string&, const std::string&) = 0;
};

class InternalServer {
private:
    std::atomic<bool> m_verbose;
    std::string m_root;
    class NameMapper* mp_nameMapper;
    class Library* mp_library;

public:
    std::unique_ptr<Response> handle_content(const RequestContext&);
    std::string get_book_name(const RequestContext&) const;
    std::unique_ptr<Response> build_homepage(const RequestContext&) const;
    std::unique_ptr<Response> build_redirect(const std::string&, const zim::Entry::Item&) const;
    zim::Entry getEntryFromPath(const zim::Archive&, const std::string&) const;
    zim::Entry::Item getFinalItem(const zim::Archive&, const zim::Entry&) const;
    std::string getArchiveTitle(const zim::Archive&) const;
    std::string searchSuggestionHTML(const std::string&, const std::string&) const;
};

class NameMapper {
public:
    std::string getIdForName(const std::string&);
};

class Library {
public:
    std::shared_ptr<zim::Archive> getArchiveById(const std::string&);
};