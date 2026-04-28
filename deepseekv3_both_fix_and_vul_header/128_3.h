#include <vector>
#include <string>

class QString {
public:
    int toInt(bool* ok = nullptr) const;
};

class QStringList {
public:
    QString operator[](int) const;
    int size() const;
};

class AreaData {
public:
    struct Evidence {
        QString name;
        QString description;
        QString image;
    };

    std::vector<Evidence> evidence() const;
    void replaceEvidence(int index, const Evidence& evidence);
};

class AOPacket {};

class AOClient {
public:
    bool checkEvidenceAccess(AreaData* area);
    void sendEvidenceList(AreaData* area);
    void pktEditEvidence(AreaData* area, int argc, QStringList argv, AOPacket packet);
};