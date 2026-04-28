#include <vector>
#include <string>
#include <cassert>

#define DCHECK_EQ(a, b) assert((a) == (b))

struct IndexedDBBlobInfo {};
struct IndexedDBMsg_BlobOrFileInfo {
  std::string uuid;
};

class IndexedDBDispatcherHost {
 public:
  bool* blob_storage_context();
  class Context {
   public:
    void* TaskRunner();
  };
  Context* Context();
};

template <typename T>
class scoped_refptr {
 public:
  T* operator->();
};

std::string CreateBlobData(const IndexedDBBlobInfo&,
                          scoped_refptr<IndexedDBDispatcherHost>,
                          void*);
std::string CreateBlobData(const IndexedDBBlobInfo&,
                          scoped_refptr<IndexedDBDispatcherHost>,
                          bool*,
                          void*);