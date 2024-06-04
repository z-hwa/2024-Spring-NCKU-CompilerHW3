#ifndef MAIN_H
#define MAIN_H
#include "compiler_common.h"
#include "linkedList.h"

#define code(format, ...) \
    fprintf(yyout, "%*s" format "\n", scopeLevel << 2, "", __VA_ARGS__)
#define codeRaw(code) \
    fprintf(yyout, "%*s" code "\n", scopeLevel << 2, "")

extern FILE* yyout;
extern FILE* yyin;
extern bool compileError;
extern int scopeLevel;
int yyparse();
int yylex();
int yylex_destroy();

void pushScope();
void dumpScope();

/*hw3 part*/

//根據現在運算的型別，導入到不同的運算
void addOpByType_j(char* op, ObjectType type);

//整數與布林型別的運算
void addOpInt_j(char *op);

//浮點數型別的運算
void addOpFloat_j(char *op);

//添加 輸出指令(整數或浮點數)
void addPrintExp_j(ObjectType type);

//添加return
void addRet_j();

//println指令
void addPrint_j();

//添加檔案開頭
void addFileStart_j();

//根據函數名稱，在main.j中添加函數開頭
void addFunDef_j(char* funName, char op);

//在main.j中添加函數結尾
void addFunEnd_j();

/*hw3 part*/

/*hw2 code start*/

//插入可能帶有auto的變數宣告
void insertAuto(char* variableName, ObjectType objectType1, ObjectType objectType2, int src);

//插入指定型態的變數宣告
void insert(char* variableName, ObjectType objectType, int src);

//輸出當前scope
void printScope();

//印出當前scope底下的variable
void printVar();

//輸出指定函數名稱的簽名
void printSigByName(char *name);

//輸出變數
void printBool(bool b);

//輸出型別轉換資訊
void printCastInfo(ObjectType type);

//用於紀錄連續的陣列變數宣告
int arrayFun(char op);

void setFuncSig(char *name, ObjectType type);   //根據函數的回傳值設置他的簽名
Object* getObjectByName(char* name, char op);   //根據名稱獲取object
ObjectType getFuncType(char* name);     //根據函數名稱獲取該函數的回傳類別

void addMsgObj(Object* obj);    //將object中的"類別"訊息添加到輸出列表中
void addMsg(char* msg); //將訊息添加到輸出列表中
void printMsg();    //打印輸出列表
void printIDByName(char* name, char op);    //根據名稱以及類別輸出相關資訊

//將Set設置成還沒開始變數宣告
void typeSet(bool b);   

//根據名稱獲取變數型態
ObjectType getVarTypeByName(char* name);    

/*如果進到下一個scope 會呼叫該函數並輸出進入下一個scope的訊息
並創建scope物件，放入推疊*/
void pushFunParm(ObjectType variableType, char* variableName, int parmFlag);
void createFunction(ObjectType variableType, char* funcName);   //創建函數的宣告

/*hw2 code end*/

Object* findVariable(char* variableName);
bool initVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
Object* createVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName, Object* value);

void functionLocalsBegin();
void functionParmPush(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
void functionBegin(ObjectType returnType, LinkedList* arraySubscripts, char* funcName);
bool functionEnd(ObjectType returnType);

bool returnObject(Object* obj);
bool breakLoop();

void functionArgsBegin();
void functionArgPush(Object* obj);
void functionCall(char* funcName, Object* out);

bool stdoutPrint(Object* obj);

// Expressions
bool objectExpression(char op, Object* a, Object* b, Object* out);
bool objectExpBinary(char op, Object* a, Object* b, Object* out);
bool objectExpBoolean(char op, Object* a, Object* b, Object* out);
bool objectNotBinaryExpression(Object* a, Object* out);
bool objectNotBooleanExpression(Object* a, Object* out);
bool objectNegExpression(Object* a, Object* out);
bool objectIncAssign(Object* a, Object* out);
bool objectDecAssign(Object* a, Object* out);
bool objectCast(ObjectType variableType, Object* a, Object* out);
bool objectExpAssign(char op, Object* dest, Object* val, Object* out);
bool objectValueAssign(Object* dest, Object* val, Object* out);

bool ifBegin(Object* a);
bool ifEnd();
bool ifOnlyEnd();
bool elseBegin();
bool elseEnd();

bool whileBegin();
bool whileBodyBegin();
bool whileEnd();

bool forBegin();
bool forInitEnd();
bool forConditionEnd(Object* result);
bool forHeaderEnd();
bool foreachHeaderEnd(Object* obj);
bool forEnd();

bool arrayCreate(Object* out);
bool objectArrayGet(Object* arr, LinkedList* arraySubscripts, Object* out);
LinkedList* arraySubscriptBegin(Object* index);
bool arraySubscriptPush(LinkedList* arraySubscripts, Object* index);
bool arraySubscriptEnd(LinkedList* arraySubscripts);

#endif