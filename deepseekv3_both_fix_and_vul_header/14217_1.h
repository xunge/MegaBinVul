#include <cstdint>

namespace application_features {
class ApplicationServer;
}

class GeneralRequest;
class GeneralResponse;

class RestVocbaseBaseHandler {
public:
    RestVocbaseBaseHandler(application_features::ApplicationServer&, GeneralRequest*, GeneralResponse*);
};

class RestAuthHandler : public RestVocbaseBaseHandler {
public:
    RestAuthHandler(application_features::ApplicationServer&, GeneralRequest*, GeneralResponse*);
    RestAuthHandler(application_features::ApplicationServer&, GeneralRequest*, GeneralResponse*, std::int64_t);
private:
    std::int64_t _validFor;
};