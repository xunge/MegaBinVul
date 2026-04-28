#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <limits.h>

#define C_PATH_MAX PATH_MAX
#define mxSeparator '/'

typedef struct txMachine txMachine;
typedef struct txScript txScript;
typedef char* txString;
typedef unsigned int txUnsigned;
typedef int (*txGetter)(FILE*);

typedef struct txParserJump {
    jmp_buf jmp_buf;
} txParserJump;

typedef struct txParser {
    txString path;
    unsigned int errorCount;
    size_t total;
    txParserJump* firstJump;
    void* parserBuffer;
    size_t parserBufferSize;
    void* parserTable;
    size_t parserTableModulo;
} txParser;

struct txMachine {
    size_t parserBufferSize;
    size_t parserTableModulo;
    size_t peakParserSize;
    txParser* parser;
};

#define c_setjmp _setjmp
#define c_strrchr strrchr
#define c_strcat strcat
#define c_realpath realpath

void fxInitializeParser(txParser* parser, txMachine* the, size_t bufferSize, size_t tableModulo);
void fxTerminateParser(txParser* parser);
txString fxNewParserSymbol(txParser* parser, txString path);
void fxParserTree(txParser* parser, FILE* file, txGetter getter, txUnsigned flags, txString* name);
void fxParserSourceMap(txParser* parser, FILE* file, txGetter getter, txUnsigned flags, txString* name);
void fxParserHoist(txParser* parser);
void fxParserBind(txParser* parser);
txScript* fxParserCode(txParser* parser);
void mxParserThrowElse(void* condition);