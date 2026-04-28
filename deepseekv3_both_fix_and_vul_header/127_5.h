class AreaData {
public:
    class EvidenceList {
    public:
        int size();
    };
    EvidenceList& evidence();
    void deleteEvidence(int idx);
};

class AOPacket {};

class QStringList {
public:
    QStringList();
    class StringRef {
    public:
        int toInt(bool* ok) const;
    };
    StringRef operator[](int) const;
};

class AOClient {
public:
    bool checkEvidenceAccess(AreaData* area);
    void sendEvidenceList(AreaData* area);
    void pktRemoveEvidence(AreaData* area, int argc, QStringList argv, AOPacket packet);
};