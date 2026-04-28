#include <stdio.h>
#include <stdlib.h>

typedef void* SQLHDBC;
typedef void* SQLHSTMT;
typedef void* SQLHENV;
typedef short SQLSMALLINT;
typedef long SQLINTEGER;
typedef long long SQLLEN;
typedef unsigned short SQLTCHAR;

#define SQL_SUCCESS 0
#define SQL_SUCCESS_WITH_INFO 1
#define SQL_NO_DATA 100
#define SQL_NTS (-3)
#define SQL_DROP 0

extern int bVerbose;
extern int buseED;
extern SQLHENV hEnv;

extern void DumpODBCLog(SQLHENV hEnv, SQLHDBC hDbc, SQLHSTMT hStmt);
extern void ansi_to_unicode(char *src, SQLTCHAR *dest);
extern void WriteHeaderHTMLTable(SQLHSTMT hStmt);
extern void UWriteHeaderNormal(SQLHSTMT hStmt, SQLTCHAR *szSepLine);
extern void WriteHeaderDelimited(SQLHSTMT hStmt, char cDelimiter);
extern void WriteBodyHTMLTable(SQLHSTMT hStmt);
extern SQLLEN WriteBodyNormal(SQLHSTMT hStmt);
extern void WriteBodyDelimited(SQLHSTMT hStmt, char cDelimiter);
extern void WriteFooterHTMLTable(SQLHSTMT hStmt);
extern void UWriteFooterNormal(SQLHSTMT hStmt, SQLTCHAR *szSepLine, SQLLEN nRows);

int SQLAllocStmt(SQLHDBC hDbc, SQLHSTMT* phStmt);
int SQLExecDirect(SQLHSTMT hStmt, SQLTCHAR* szSQL, int length);
int SQLPrepare(SQLHSTMT hStmt, SQLTCHAR* szSQL, int length);
int SQLExecute(SQLHSTMT hStmt);
int SQLNumResultCols(SQLHSTMT hStmt, SQLSMALLINT* pcols);
int SQLMoreResults(SQLHSTMT hStmt);
int SQLFreeStmt(SQLHSTMT hStmt, int option);