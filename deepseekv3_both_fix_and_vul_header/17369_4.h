#include <memory>
#include <string>
#include <stdexcept>

class RandomNumberGenerator;

class Provider_Not_Found : public std::runtime_error {
public:
    Provider_Not_Found(const std::string& algo, const std::string& provider);
};

namespace PK_Ops {
    class Signature {
    public:
        virtual ~Signature() = default;
    };
}

class DSA_PrivateKey {
public:
    std::string algo_name() const;
    std::unique_ptr<PK_Ops::Signature> create_signature_op(RandomNumberGenerator& rng, const std::string& params, const std::string& provider) const;
};

class DSA_Signature_Operation : public PK_Ops::Signature {
public:
    DSA_Signature_Operation(const DSA_PrivateKey&, const std::string&, RandomNumberGenerator&);
    DSA_Signature_Operation(const DSA_PrivateKey&, const std::string&);
};