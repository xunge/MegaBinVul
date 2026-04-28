#include <memory>
#include <string>
#include <stdexcept>

class RandomNumberGenerator;
class Lookup_Error;

namespace PK_Ops {
    class Signature {
    public:
        virtual ~Signature() = default;
    };
}

class Provider_Not_Found : public std::runtime_error {
public:
    Provider_Not_Found(const std::string& algo, const std::string& provider);
};

class ECDSA_PrivateKey {
public:
    std::string algo_name() const;
    std::unique_ptr<PK_Ops::Signature> create_signature_op(RandomNumberGenerator& rng,
                                                          const std::string& params,
                                                          const std::string& provider) const;
};

class ECDSA_Signature_Operation : public PK_Ops::Signature {
public:
    ECDSA_Signature_Operation(const ECDSA_PrivateKey&, const std::string&, RandomNumberGenerator&);
    ECDSA_Signature_Operation(const ECDSA_PrivateKey&, const std::string&);
};

std::unique_ptr<PK_Ops::Signature> make_bearssl_ecdsa_sig_op(const ECDSA_PrivateKey&, const std::string&);
std::unique_ptr<PK_Ops::Signature> make_openssl_ecdsa_sig_op(const ECDSA_PrivateKey&, const std::string&);