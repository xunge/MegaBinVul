#include <stdio.h>
#include <stdlib.h>

typedef struct SWF_ACTIONRECORD {
    int Offset;
    int ActionCode;
} SWF_ACTIONRECORD;

typedef struct SWF_ACTION {
    SWF_ACTIONRECORD SWF_ACTIONRECORD;
} SWF_ACTION;

#define SWFACTION_END 0
#define SWFACTION_CONSTANTPOOL 1
#define SWFACTION_GOTOLABEL 2
#define SWFACTION_GOTOFRAME 3
#define SWFACTION_GOTOFRAME2 4
#define SWFACTION_WAITFORFRAME 5
#define SWFACTION_GETURL2 6
#define SWFACTION_GETURL 7
#define SWFACTION_PUSH 8
#define SWFACTION_PUSHDUP 9
#define SWFACTION_STACKSWAP 10
#define SWFACTION_SETPROPERTY 11
#define SWFACTION_GETPROPERTY 12
#define SWFACTION_GETTIME 13
#define SWFACTION_TRACE 14
#define SWFACTION_CALLFRAME 15
#define SWFACTION_EXTENDS 16
#define SWFACTION_INITOBJECT 17
#define SWFACTION_NEWOBJECT 18
#define SWFACTION_NEWMETHOD 19
#define SWFACTION_GETMEMBER 20
#define SWFACTION_SETMEMBER 21
#define SWFACTION_GETVARIABLE 22
#define SWFACTION_SETVARIABLE 23
#define SWFACTION_DEFINELOCAL 24
#define SWFACTION_DEFINELOCAL2 25
#define SWFACTION_DECREMENT 26
#define SWFACTION_INCREMENT 27
#define SWFACTION_STOREREGISTER 28
#define SWFACTION_JUMP 29
#define SWFACTION_RETURN 30
#define SWFACTION_LOGICALNOT 31
#define SWFACTION_IF 32
#define SWFACTION_WITH 33
#define SWFACTION_ENUMERATE 34
#define SWFACTION_ENUMERATE2 35
#define SWFACTION_INITARRAY 36
#define SWFACTION_DEFINEFUNCTION 37
#define SWFACTION_DEFINEFUNCTION2 38
#define SWFACTION_CALLFUNCTION 39
#define SWFACTION_CALLMETHOD 40
#define SWFACTION_INSTANCEOF 41
#define SWFACTION_SHIFTLEFT 42
#define SWFACTION_SHIFTRIGHT 43
#define SWFACTION_SHIFTRIGHT2 44
#define SWFACTION_ADD 45
#define SWFACTION_ADD2 46
#define SWFACTION_SUBTRACT 47
#define SWFACTION_MULTIPLY 48
#define SWFACTION_DIVIDE 49
#define SWFACTION_MODULO 50
#define SWFACTION_BITWISEAND 51
#define SWFACTION_BITWISEOR 52
#define SWFACTION_BITWISEXOR 53
#define SWFACTION_EQUAL 54
#define SWFACTION_EQUALS2 55
#define SWFACTION_LESS2 56
#define SWFACTION_LOGICALAND 57
#define SWFACTION_LOGICALOR 58
#define SWFACTION_GREATER 59
#define SWFACTION_LESSTHAN 60
#define SWFACTION_STRINGEQ 61
#define SWFACTION_STRINGCOMPARE 62
#define SWFACTION_STRICTEQUALS 63
#define SWFACTION_POP 64
#define SWFACTION_STARTDRAG 65
#define SWFACTION_DELETE 66
#define SWFACTION_DELETE2 67
#define SWFACTION_TARGETPATH 68
#define SWFACTION_TYPEOF 69
#define SWFACTION_ORD 70
#define SWFACTION_CHR 71
#define SWFACTION_INT 72
#define SWFACTION_TOSTRING 73
#define SWFACTION_TONUMBER 74
#define SWFACTION_RANDOMNUMBER 75
#define SWFACTION_STRINGLENGTH 76
#define SWFACTION_PLAY 77
#define SWFACTION_STOP 78
#define SWFACTION_NEXTFRAME 79
#define SWFACTION_PREVFRAME 80
#define SWFACTION_ENDDRAG 81
#define SWFACTION_STOPSOUNDS 82
#define SWFACTION_TOGGLEQUALITY 83
#define SWFACTION_MBSUBSTRING 84
#define SWFACTION_SUBSTRING 85
#define SWFACTION_STRINGCONCAT 86
#define SWFACTION_REMOVECLIP 87
#define SWFACTION_DUPLICATECLIP 88
#define SWFACTION_SETTARGET 89
#define SWFACTION_SETTARGET2 90
#define SWFACTION_IMPLEMENTSOP 91
#define SWFACTION_CASTOP 92
#define SWFACTION_THROW 93
#define SWFACTION_TRY 94

void SWF_error(const char *msg);
const char *actionName(int actionCode);
void decompileCONSTANTPOOL(SWF_ACTION *action);
int decompileGOTOFRAME(int n, SWF_ACTION *actions, int maxn, int flag);
int decompileGOTOFRAME2(int n, SWF_ACTION *actions, int maxn);
void decompileWAITFORFRAME(SWF_ACTION *action);
void decompileGETURL2(SWF_ACTION *action);
void decompileGETURL(SWF_ACTION *action);
void decompilePUSH(SWF_ACTION *action);
void decompilePUSHDUP(SWF_ACTION *action);
void decompileSTACKSWAP(SWF_ACTION *action);
void decompileSETPROPERTY(int n, SWF_ACTION *actions, int maxn);
void decompileGETPROPERTY(int n, SWF_ACTION *actions, int maxn);
int decompileGETTIME(int n, SWF_ACTION *actions, int maxn);
void decompileTRACE(int n, SWF_ACTION *actions, int maxn);
void decompileCALLFRAME(int n, SWF_ACTION *actions, int maxn);
void decompileEXTENDS(int n, SWF_ACTION *actions, int maxn);
void decompileINITOBJECT(int n, SWF_ACTION *actions, int maxn);
void decompileNEWOBJECT(int n, SWF_ACTION *actions, int maxn);
void decompileNEWMETHOD(int n, SWF_ACTION *actions, int maxn);
void decompileGETMEMBER(int n, SWF_ACTION *actions, int maxn);
void decompileSETMEMBER(int n, SWF_ACTION *actions, int maxn);
void decompileGETVARIABLE(int n, SWF_ACTION *actions, int maxn);
void decompileSETVARIABLE(int n, SWF_ACTION *actions, int maxn, int flag);
void decompileDEFINELOCAL2(int n, SWF_ACTION *actions, int maxn);
int decompileINCR_DECR(int n, SWF_ACTION *actions, int maxn, int flag);
void decompileSTOREREGISTER(int n, SWF_ACTION *actions, int maxn);
int decompileJUMP(int n, SWF_ACTION *actions, int maxn);
void decompileRETURN(int n, SWF_ACTION *actions, int maxn);
int decompileLogicalNot(int n, SWF_ACTION *actions, int maxn);
int decompileIF(int n, SWF_ACTION *actions, int maxn);
void decompileWITH(int n, SWF_ACTION *actions, int maxn);
int decompileENUMERATE(int n, SWF_ACTION *actions, int maxn, int flag);
int decompileINITARRAY(int n, SWF_ACTION *actions, int maxn);
int decompileDEFINEFUNCTION(int n, SWF_ACTION *actions, int maxn, int flag);
int decompileCALLFUNCTION(int n, SWF_ACTION *actions, int maxn);
int decompileCALLMETHOD(int n, SWF_ACTION *actions, int maxn);
int decompileArithmeticOp(int n, SWF_ACTION *actions, int maxn);
void pop();
int decompileSTARTDRAG(int n, SWF_ACTION *actions, int maxn);
int decompileDELETE(int n, SWF_ACTION *actions, int maxn, int flag);
int decompileSingleArgBuiltInFunctionCall(int n, SWF_ACTION *actions, int maxn, const char *name);
int decompile_Null_ArgBuiltInFunctionCall(int n, SWF_ACTION *actions, int maxn, const char *name);
int decompileSUBSTRING(int n, SWF_ACTION *actions, int maxn);
int decompileSTRINGCONCAT(int n, SWF_ACTION *actions, int maxn);
int decompileREMOVECLIP(int n, SWF_ACTION *actions, int maxn);
int decompileDUPLICATECLIP(int n, SWF_ACTION *actions, int maxn);
int decompileSETTARGET(int n, SWF_ACTION *actions, int maxn, int flag);
int decompileIMPLEMENTS(int n, SWF_ACTION *actions, int maxn);
int decompileCAST(int n, SWF_ACTION *actions, int maxn);
int decompileTHROW(int n, SWF_ACTION *actions, int maxn);
int decompileTRY(int n, SWF_ACTION *actions, int maxn);
void outputSWF_ACTION(int n, SWF_ACTION *action);