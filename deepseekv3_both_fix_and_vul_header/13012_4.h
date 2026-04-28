#include <stdexcept>
#include <vector>
#include <string>

class ZerocoinException : public std::runtime_error {
public:
    explicit ZerocoinException(const std::string& what) : std::runtime_error(what) {}
};

struct CommitmentGroup {
};

struct AccumulatorParams {
    CommitmentGroup accumulatorPoKCommitmentGroup;
};

class Params {
public:
    CommitmentGroup serialNumberSoKCommitmentGroup;
    AccumulatorParams accumulatorParams;
};

class PrivateCoin;
class Accumulator;
class AccumulatorWitness;
class SpendMetaData;
class Commitment;
class CommitmentProofOfKnowledge;
class AccumulatorProofOfKnowledge;
class SerialNumberSignatureOfKnowledge;

struct PublicCoin {
    int getDenomination() const;
    std::vector<unsigned char> getValue() const;
};

class PrivateCoin {
public:
    PublicCoin getPublicCoin() const;
    std::vector<unsigned char> getSerialNumber() const;
};

class Accumulator {
public:
    bool VerifyWitness(const AccumulatorWitness& witness, const PublicCoin& coin) const;
};

class AccumulatorWitness {
public:
    bool VerifyWitness(const Accumulator& a, const PublicCoin& coin) const;
};

class Commitment {
public:
    Commitment(const CommitmentGroup*, const std::vector<unsigned char>&);
    std::vector<unsigned char> getCommitmentValue() const;
};

class CommitmentProofOfKnowledge {
public:
    CommitmentProofOfKnowledge(const CommitmentGroup*, const CommitmentGroup*);
    CommitmentProofOfKnowledge(const CommitmentGroup*, const CommitmentGroup*, const Commitment&, const Commitment&);
};

class AccumulatorProofOfKnowledge {
public:
    AccumulatorProofOfKnowledge(const AccumulatorParams*);
    AccumulatorProofOfKnowledge(const AccumulatorParams*, const Commitment&, const AccumulatorWitness&, const Accumulator&);
};

class SerialNumberSignatureOfKnowledge {
public:
    SerialNumberSignatureOfKnowledge(const Params*);
    SerialNumberSignatureOfKnowledge(const Params*, const PrivateCoin&, const Commitment&, const std::vector<unsigned char>&);
};

class CoinSpend {
public:
    CoinSpend(const Params* p, const PrivateCoin& coin, Accumulator& a, const AccumulatorWitness& witness, const SpendMetaData& m);
    bool HasValidSerial() const;
private:
    const Params* params;
    int denomination;
    std::vector<unsigned char> coinSerialNumber;
    AccumulatorProofOfKnowledge accumulatorPoK;
    SerialNumberSignatureOfKnowledge serialNumberSoK;
    CommitmentProofOfKnowledge commitmentPoK;
    std::vector<unsigned char> serialCommitmentToCoinValue;
    std::vector<unsigned char> accCommitmentToCoinValue;
};

std::vector<unsigned char> signatureHash(const SpendMetaData&);