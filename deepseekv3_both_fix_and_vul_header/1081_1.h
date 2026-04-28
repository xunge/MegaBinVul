#include <string>
#include <map>

using std::string;

struct Status {
    static Status OK();
    static Status FailedPrecondition(const string& msg1, const string& msg2 = "");
};

struct TensorInfo {
    string name() const;
};

struct SignatureDef {
    const std::map<string, TensorInfo>& outputs() const;
};

struct CollectionDef {
    struct NodeList {
        int value_size() const;
        string value(int index) const;
    };
    const NodeList& node_list() const;
};

struct MetaGraphDef {
    const std::map<string, SignatureDef>& signature_def() const;
    const std::map<string, CollectionDef>& collection_def() const;
};

namespace errors {
    Status FailedPrecondition(const string& msg1, const string& msg2 = "");
}

namespace strings {
    string StrCat(const string& a, const string& b);
}

const string kSavedModelInitOpSignatureKey;
const string kSavedModelMainOpKey;
const string kSavedModelLegacyInitOpKey;