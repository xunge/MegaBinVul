#include <stdlib.h>

typedef struct {
    int (*bad)();
} OFCondition;

#define EC_Normal (OFCondition){0}

typedef struct {
    void* DULassociation;
    void* params;
    void* sendPDVBuffer;
} T_ASC_Association;

OFCondition ASC_dropAssociation(T_ASC_Association* association);
OFCondition ASC_destroyAssociationParameters(void** params);