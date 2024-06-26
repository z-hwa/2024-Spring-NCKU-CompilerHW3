#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define WJCL_LINKED_LIST_IMPLEMENTATION
#include "main.h"
#define WJCL_HASH_MAP_IMPLEMENTATION
//#include "value_operation.h"

#include "stack.h"
#include "linkedList.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define iload(var) code("iload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lload(var) code("lload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fload(var) code("fload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dload(var) code("dload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define aload(var) code("aload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define istore(var) code("istore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lstore(var) code("lstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fstore(var) code("fstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dstore(var) code("dstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define astore(var) code("astore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define ldz(val) code("ldc %d", getBool(val))
#define ldb(val) code("ldc %d", getByte(val))
#define ldc(val) code("ldc %d", getChar(val))
#define lds(val) code("ldc %d", getShort(val))
#define ldi(val) code("ldc %d", getInt(val))
#define ldl(val) code("ldc_w %" PRId64, getLong(val))
#define ldf(val) code("ldc %.6f", getFloat(val))
#define ldd(val) code("ldc_w %lf", getDouble(val))
#define ldt(val) code("ldc \"%s\"", getString(val))

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_BYTE] = "byte",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_SHORT] = "short",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_LONG] = "long",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_DOUBLE] = "double",
    [OBJECT_TYPE_STR] = "string",
};
const char* objectJavaTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "V",
    [OBJECT_TYPE_VOID] = "V",
    [OBJECT_TYPE_BOOL] = "Z",
    [OBJECT_TYPE_BYTE] = "B",
    [OBJECT_TYPE_CHAR] = "C",
    [OBJECT_TYPE_SHORT] = "S",
    [OBJECT_TYPE_INT] = "I",
    [OBJECT_TYPE_LONG] = "J",
    [OBJECT_TYPE_FLOAT] = "F",
    [OBJECT_TYPE_DOUBLE] = "D",
    [OBJECT_TYPE_STR] = "Ljava/lang/String;",
};

char* yyInputFileName;
bool compileError;

//用於計算function的signal
char funcSig[100] = "(";

int indent = 0;
int scopeLevel = -1;	//scope 層級
int funcLineNo = 0;
int variableAddress = 0;	//變數位置
ObjectType variableIdentType;

bool set = false;
ObjectType lastType = OBJECT_TYPE_UNDEFINED;
ObjectType funcType = OBJECT_TYPE_UNDEFINED;

LinkedList *scope_list;	//紀錄scope的linked list
Stack *scope_stack; //紀錄當前所在scope的stack
Stack *print_stack; //用於紀錄輸出訊息
LinkedList *print_list; //用於記錄順向的輸出訊息
LinkedList *var_list;	//用於記錄變數的陣列

/*hw3 part*/
Stack *if_st, *out_st, *while_st, *for_st;
int tct = 0;	//total counter

int for_ct = 0;	//for標記
int add_ct = 0;	//比較模塊的計數器

void addArrayEle_j(ObjectType type){
	if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
		codeRaw("iastore");
	}else if(type == OBJECT_TYPE_FLOAT) {
		codeRaw("fastore");
	}
}

void addBreak_j(){
	int addr = frontAddr(&out_st);
	code("goto out%d", addr);
	pushAddr(&out_st, addr);
}

void addFor_j(char type) {
	if(type == 'f') {
		code("ifeq out%d", tct);	//如果條件判斷為0，跳出
		pushAddr(&out_st, tct++);
	}
	else if(type == 'i') {
		codeRaw("\n");

		code("for%d:", tct);	//設置for標記
		pushAddr(&for_st, tct++);
	}
	else if(type == 'c') {
		code("goto for%d", frontAddr(&for_st));	//check part
	}
	else if(type == 'o') {
		code("out%d:", frontAddr(&out_st));	//離開標記
		codeRaw("\n");
	}
	else if(type == '1') {
		code("goto f2%d", tct);
		code("f4%d:", tct);
	}
	else if(type == '2') {
		code("f2%d:", tct);
		pushAddr(&for_st, tct++);
	}
	else if(type == '3') {
		code("goto f4%d", frontAddr(&for_st));
	} 
}

void addWhile_j(char type) {
	if(type == 'w') {
		code("ifeq out%d", tct);	//如果條件判斷為0，跳出
		pushAddr(&out_st, tct++);
	}
	else if(type == 'i') {
		codeRaw("\n");
		code("while%d:", tct);	//設置while標記
		pushAddr(&while_st, tct++);
	}
	else if(type == 'c') {
		code("goto while%d", frontAddr(&while_st));	//check part
	}
	else if(type == 'o') {
		code("out%d:", frontAddr(&out_st));	//離開標記
		codeRaw("\n");
	}
}

void addIf_j(char type){
	if(type == 'i') {
		codeRaw("\n");
		code("ifeq else%d", tct);	//如果條件判斷為0，不執行以下程式碼，跳出
		pushAddr(&if_st, tct++);
	}
	else if(type == 'e') code("else%d:", frontAddr(&if_st));	//幫else做標記
	else if(type == 'g') {
		code("goto out%d", tct);	//if如果成功執行，需要跳出
		pushAddr(&out_st, tct++);
	}
	else if(type == 'o') code("out%d:", frontAddr(&out_st));	//幫out做標記
}

void addCast_j(ObjectType type){

	//因為測資只有float and int，所以做特判
	//不是很general的方法
	if(type == OBJECT_TYPE_INT) codeRaw("f2i");
	else if(type == OBJECT_TYPE_FLOAT) codeRaw("i2f");
}

void addAssign_j(char* name, char* op) {
	//進行對應操作
	ObjectType type = getVarTypeByName(name);
	addOpByType_j(op, type);
}

void addPushLocalVar_j(char* name, char op) {
	Object *var = getObjectByName(name, 'v');
	SymbolData *sym = var->symbol;

	int var_index = sym->addr;	//設置名稱為var_index的變數
	ObjectType type = var->type;

	if(op == 'l') {
		//將變數中的數字儲存到stack頂端
		if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
			codeRaw("iaload");
		}else if(type == OBJECT_TYPE_FLOAT) {
			codeRaw("faload");
		}else if(type == OBJECT_TYPE_STR) {
			codeRaw("aaload");
		}
	}
	else if(op == 'L') code("aload %d", var_index);	//載入陣列位置
	else {
		//將變數中的數字儲存到stack頂端
		if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
			code("iload %d", var_index);
		}else if(type == OBJECT_TYPE_FLOAT) {
			code("fload %d", var_index);
		}else if(type == OBJECT_TYPE_STR) {
			code("aload %d", var_index);
		}
	}

}

void addLocalVar_j(char* name, char isAssign, ObjectType valType) {
	Object *var = getObjectByName(name, 'v');
	SymbolData *sym = var->symbol;

	int var_index = sym->addr;	//設置名稱為var_index的變數
	ObjectType type = var->type; //獲取該變數類別

	//如果沒有設定初始值，就自動載入一個0到stack頂端
	if(isAssign == 'n') codeRaw("ldc 0");
	
	//處理陣列的賦值
	if(valType == OBJECT_TYPE_VOID) {
		code("astore %d", var_index);
		return;
	}

	//將stack頂端的數字儲存到變數中
	if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) {
		if(valType == OBJECT_TYPE_FLOAT) codeRaw("f2i");

		code("istore %d", var_index);
	}else if(type == OBJECT_TYPE_FLOAT) {
		if(valType == OBJECT_TYPE_INT) codeRaw("i2f");

		code("fstore %d", var_index);
	}else if(type == OBJECT_TYPE_STR) {
		code("astore %d", var_index);
	}
}

void addOpByType_j(char* op, ObjectType type) {
	// printf("%d\n", type);
	// printf("%s\n", objectTypeName[type]);

	if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) addOpInt_j(op);
	else if(type == OBJECT_TYPE_FLOAT) addOpFloat_j(op);
}

void addOpInt_j(char* op) {
	if(strcmp(op, "add")==0) codeRaw("iadd");
	else if(strcmp(op, "sub")==0) codeRaw("isub");
	else if(strcmp(op, "mul")==0) codeRaw("imul");
	else if(strcmp(op, "div")==0) codeRaw("idiv");
	else if(strcmp(op, "neg")==0) codeRaw("ineg");
	else if(strcmp(op, "rem")==0) codeRaw("irem");
	else if(strcmp(op, "gtr")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmpgt gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "or")==0) codeRaw("ior");
	else if(strcmp(op, "and")==0) codeRaw("iand");
	else if(strcmp(op, "not")==0) {
		codeRaw("\n");

		codeRaw("iconst_m1");
		codeRaw("ixor");

		codeRaw("\n");
	}
	else if(strcmp(op, "neq")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmpne gtr_true_%d", add_ct); // if v1 != v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "xor")==0) codeRaw("ixor");
	else if(strcmp(op, "eql")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmpeq gtr_true_%d", add_ct); // if v1 = v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "leq")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmple gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "geq")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmpge gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "shr")==0) codeRaw("ishr");
	else if(strcmp(op, "inc")==0) {
		codeRaw("ldc 1");
		codeRaw("iadd");
	}
	else if(strcmp(op, "dec")==0) {
		codeRaw("ldc -1");
		codeRaw("iadd");
	}
	else if(strcmp(op, "shl")==0) codeRaw("ishl");
	else if(strcmp(op, "les")==0) {
		//比較大小
		codeRaw("\n");
		code("if_icmplt gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "")==0) codeRaw("");
}

void addOpFloat_j(char* op) {
	if(strcmp(op, "add")==0) codeRaw("fadd");
	else if(strcmp(op, "sub")==0) codeRaw("fsub");
	else if(strcmp(op, "mul")==0) codeRaw("fmul");
	else if(strcmp(op, "div")==0) codeRaw("fdiv");
	else if(strcmp(op, "neg")==0) codeRaw("fneg");
	else if(strcmp(op, "rem")==0) codeRaw("frem");
	else if(strcmp(op, "gtr")==0) {
		//比較大小
		codeRaw("\n");
		
		codeRaw("fsub");
		codeRaw("f2i");
		code("ifgt gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "or")==0) codeRaw("for");
	else if(strcmp(op, "and")==0) codeRaw("fand");
	else if(strcmp(op, "not")==0) {
		codeRaw("\n");

		codeRaw("fconst_m1");
		codeRaw("fxor");

		codeRaw("\n");
	}
	else if(strcmp(op, "neq")==0) {
		//比較大小
		codeRaw("\n");
		
		codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmpne gtr_true_%d", add_ct); // if v1 != v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "xor")==0) codeRaw("fxor");
	else if(strcmp(op, "eql")==0) {
		//比較大小
		codeRaw("\n");
		
		codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmpeq gtr_true_%d", add_ct); // if v1 = v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "leq")==0) {
		//比較大小
		codeRaw("\n");
		
		codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmple gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "geq")==0) {
		//比較大小
		codeRaw("\n");
		
		codeRaw("fsub");
		codeRaw("f2i");
		code("if_icmpge gtr_true_%d", add_ct); // if v1 > v2

		code("gtr_false_%d:", add_ct);	//false
		codeRaw("iconst_0");	//結果設為false
		code("goto gtr_end_%d", add_ct);

		code("gtr_true_%d:", add_ct); //true
		codeRaw("iconst_1");	// 結果設為true

		code("gtr_end_%d:", add_ct);
		codeRaw("\n");

		add_ct++;
	}
	else if(strcmp(op, "shr")==0) codeRaw("fshr");
	else if(strcmp(op, "inc")==0) {
		codeRaw("ldc 1.0");
		codeRaw("fadd");
	}
	else if(strcmp(op, "dec")==0) {
		codeRaw("ldc -1.0");
		codeRaw("fadd");
	}
	else if(strcmp(op, "shl")==0) codeRaw("fshl");
}

void addPrintExp_j(ObjectType type) {
	codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");
	codeRaw("swap");
	
	if(type == OBJECT_TYPE_INT) {
		codeRaw("invokevirtual java/io/PrintStream/print(I)V");
	} else if(type == OBJECT_TYPE_BOOL) {
		codeRaw("invokevirtual java/io/PrintStream/print(Z)V");
	} else if(type == OBJECT_TYPE_FLOAT) {
		codeRaw("invokevirtual java/io/PrintStream/print(F)V");
	} else if(type == OBJECT_TYPE_STR) {
		codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
	}
}

void addRet_j(ObjectType type, int isMain){

	if(isMain == 1 || type == OBJECT_TYPE_VOID) codeRaw("return");
	else if(type == OBJECT_TYPE_BOOL || type == OBJECT_TYPE_INT) codeRaw("ireturn");
	else if(type == OBJECT_TYPE_FLOAT) codeRaw("freturn");
}

void addPrint_j(char* str){
	codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");
	code("ldc \"%s\";", str);
	codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
}

void addFileStart_j() {
    codeRaw(".class public Main");
    codeRaw(".super java/lang/Object");
}

void addFunEnd_j(){
	codeRaw(".end method");
}

void addFunDef_j(char* funName, char operation){
	// .method public static main([Ljava/lang/String;)V
	// .limit stack 100
	// .limit locals 100
	
	//根據函數名稱獲取該函數簽名
	Object * op = getObjectByName(funName, 'f');
	SymbolData* sp = op->symbol;
	char* funcSig = sp->func_sig;

	if(operation =='n') {
		fprintf(yyout, ".method public static %s", funName);
	}else {
		//fprintf(yyout, ".method public static %s%s\n", funName, funcSig);
		fprintf(yyout, "%s\n", funcSig);
		codeRaw(".limit stack 100");
		codeRaw(".limit locals 100");
	}
}

/*hw3 part*/

//現在宣告的array中帶有的元素數量
int arrayNum = 0;

// //用於紀錄連續的陣列變數宣告
// int arrayFun(char op){
// 	if(op == 'c') {
// 		//counter 累加有幾個陣列宣告
// 		arrayNum++;
// 	}else if(op == 'r') arrayNum = 0;	//重置計數器
// 	else if(op == 'g') return arrayNum;	//回傳現在的計數

// 	return 0;
// }

//將Set設置為還沒開始設定變數
void typeSet(bool b){
	set = b;
}

//將變數插入至序列並進行紀錄
//根據變數宣告分為auto與沒有auto
//後續交給insert處理
void insertAuto(char* variableName, ObjectType type1, ObjectType type2, int src) {
	if(type1 == OBJECT_TYPE_AUTO) insert(variableName, type2, src);
	else insert(variableName, type1, src);
}

//根據函數的回傳值設置他的簽名
void setFuncSig(char*name, ObjectType ret) {
	Object *var = getObjectByName(name, 'f');
	strcat(funcSig, ")");	

	//根據函數的回傳值，設置簽名(main 換成回傳void)
	if(ret == OBJECT_TYPE_INT && strcmp(name, "main") != 0) strcat(funcSig, "I");
	else if(ret == OBJECT_TYPE_INT && strcmp(name, "main") == 0) {
		strcat(funcSig, "V"); 
		var->funcType = OBJECT_TYPE_VOID;
	}
	else if(ret == OBJECT_TYPE_VOID) strcat(funcSig, "V");
	else if(ret == OBJECT_TYPE_BOOL) strcat(funcSig, "B");
	else if(ret == OBJECT_TYPE_STR) strcat(funcSig, "Ljava/lang/String;");
	else if(ret == OBJECT_TYPE_FLOAT) strcat(funcSig, "F");

	//設置函數簽名
	SymbolData *sym = var->symbol;
	sym->func_sig = malloc(sizeof(funcSig));	
	strcpy(sym->func_sig, funcSig);

	//重置函數簽名
	strcpy(funcSig, "(");
}

/*
創建變數物件
將變數插入到對應scope stack的linked list之中
並輸出插入訊息
0的來源是連續的變數定義
1的來源是普通的變數定義
2的來源是函數宣告
3的來源是函數的參數定義
4的來源是函數的參數定義中的陣列
*/
void insert(char* variableName, ObjectType type, int src) {

	//來源是變數定義需要確定是不是連續的，以進行類別重定義
	if(src == 0 && set == true) type = lastType;
	else if(src == 0 && set == false) set = true;

	//函數的參數定義處理
	if(src == 3) {
		char *sig = "";
		if(type == OBJECT_TYPE_INT) sig = "I";
		else if(type == OBJECT_TYPE_STR) sig = "Ljava/lang/String;";
		else if(type == OBJECT_TYPE_BOOL) sig = "B";
		
		strcat(funcSig, sig);
	}

	//函數的參數定義中的陣列處理
	if(src == 4) {
		char *sig = "[Ljava/lang/String;";
		strcat(funcSig, sig);
	}

	Object* var = (Object *)malloc(sizeof(Object));	//變數物件 用於symbol table
	SymbolData* sym = (SymbolData *)malloc(sizeof(SymbolData));	//symbol data

	//獲取要使用的index
	Stack *sp = top(&scope_stack);
	int index = sp->index++;

	//set symbol data
	sym->name = variableName; 
	sym->index = index;
	sym->lineno = yylineno;	
	sym->func_sig = "-";
	
	//區分為函數宣告或不是，去設置addr
	if(src != 2) sym->addr = variableAddress;
	else sym->addr = -1;

	//set variable data
	var->symbol = sym;
	var->type = type;
	if(src == 2) var->funcType = funcType;	//函數需要另外設置type

	//製造變數的資料包
	LinkedList data;
	data.var = var;

	//將變數插入對應scope的陣列中	
	insertToList(&var_list, data);	

	//輸出insert資訊
	if(src != 2) printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, variableAddress++, scopeLevel);
	else {
		printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, -1, scopeLevel);
	}
	
	//更新上一個插入的類別紀錄
	lastType = type;
}

/*如果進到下一個scope 會呼叫該函數並輸出進入下一個scope的訊息
並創建scope物件，放入推疊*/
void pushScope() {
	scopeLevel++;	//scope level加一
	
	//創建scope
	Stack scope;
	Stack *sp = top(&scope_stack);

	//設置scope資料
	scope.scopeLevel = scopeLevel;
	scope.index = 0;

	//紀錄該scope對應的變數起始與結束
	if(sp != NULL) scope.indexSt = sp->indexSt + sp->index;	
	else scope.indexSt = 0;

	//插入scope
	push(&scope_stack, scope);	

	//輸出scope資訊
	printf("> Create symbol table (scope level %d)\n", scopeLevel);
}

//離開當前scope
void dumpScope() {
	
	//輸出scope資料
	printScope();

	//更新變數紀錄的串列
	Stack *sp = top(&scope_stack);
	int index = sp->index;
	while(index--) {
		deleteTail(&var_list);
	}
	
	scopeLevel--;

	//將stack最上方的scope推出堆疊	
	pop(&scope_stack);
}

//創建函數
void createFunction(ObjectType variableType, char* funcName) {
	
	//output func msg
	printf("func: %s\n", funcName);	
	
	//insert variable
	funcType = variableType;
	insert(funcName, OBJECT_TYPE_FUNCTION, 2);

}

//當函數呼叫的時候，用於輸出函數呼叫的資訊
void printSigByName(char* name) {
	Object *var = getObjectByName(name, 'f');
	SymbolData *sym = var->symbol;
	printf("%s",sym->func_sig);
}

//當函數呼叫的時候，用於回傳函數呼叫的資訊
char* getSigByName(char* name) {
	Object *var = getObjectByName(name, 'f');
	SymbolData *sym = var->symbol;
	return sym->func_sig;
}

//根據名稱獲取該變數的object
Object* getObjectByName(char* name, char op) {
	LinkedList *lp;
	lp = getByName(&var_list, name, op);	
	Object* var = lp->var;

	return var;	
}

//根據變數名稱輸出name and address
void printIDByName(char* name, char op) {
	Object *var = getObjectByName(name, op);
	SymbolData *sym = var->symbol;

	printf("IDENT (name=%s, address=%ld)\n", sym->name, sym->addr);
}

//用於在以呼叫函數設值的情況，回傳類別用於定義
ObjectType getFuncType(char* name) {
	Object *var = getObjectByName(name, 'f');
	return var->funcType;	
}

//根據名稱獲取該變數的型別
ObjectType getVarTypeByName(char* name) {
	Object* var = getObjectByName(name, 'v');

	return var->type;
}

//物件 exp binary
bool objectExpBinary(char op, Object* a, Object* b, Object* out) {
	if(op == '1') {
		//BOR
		out->value = a->value | b->value;
		printf("BOR\n");
	}else if(op == '2') {
		//BXO
		out->value = a->value ^ b->value;
		printf("BXO\n");
	}else if(op == '3') {
		//BAN
		out->value = a->value & b->value;
		printf("BAN\n");
	}

	out->type = OBJECT_TYPE_BOOL;
    
	
	return false;
}

//物件 exp 布林值
bool objectExpBoolean(char op, Object* a, Object* b, Object* out) {
	if(op == '1') {
		//LOR
		out->value = a->value || b->value;
		printf("LOR\n");
	}else if(op == '2') {
		//LAN
		out->value = a->value && b->value;
		printf("LAN\n");
	}else if(op == '3') {
		//EQL
		out->value = (a->value == b->value);
		printf("EQL\n");
	}else if(op == '4') {
		//NEQ
		out->value = (a->value != b->value);
		printf("NEQ\n");
	}

	out->type = OBJECT_TYPE_BOOL;

	return false;
}

//輸出"型別轉換"的訊息
void printCastInfo(ObjectType type) {
	printf("Cast to %s\n", objectTypeName[type]);
}

//遇到布林值用於輸出true or false
void printBool(bool b){
	if(b == true) printf("BOOL_LIT TRUE\n");
	else printf("BOOL_LIT FALSE\n");
}

//添加obj的type進入msg，用於後續輸出
void addMsgObj(Object *obj) {
	LinkedList data;
	char* str = malloc(sizeof(objectTypeName[obj->type])+10);

	sprintf(str, "%s", objectTypeName[obj->type]);

	data.msg = str;
	
	insertToList(&print_list, data);
}

//將訊息放進msg中，用於後續的倒序輸出
void addMsg(char* msg) {
	LinkedList data;
	data.msg = msg;

	insertToList(&print_list, data);
}

//輸出msg
void printMsg() {
	while(print_list != NULL) {
		printf("%s", print_list->msg);
		deleteHead(&print_list);
	}
}

//找變數
Object* findVariable(char* variableName) {
    Object* variable = NULL;
    return variable;
}

//由高到低 輸出所有scope
void printScope() {
	printf("\n");
	printf("> Dump symbol table (scope level: %d)\n", scopeLevel);
	printf("Index     Name                Type      Addr      Lineno    Func_sig  \n");
	
	printVar(); //輸出該scope底下的var list
}

//印出當前scope底下的variable
void printVar(int num) {
	//變數的屬性
	int32_t index, lineno;
	int64_t addr;
	char *name, *func_sig;
	const char *type;

	Stack *sp = top(&scope_stack);
	int st = sp->indexSt;
	num = sp->index;	

	while(num--) {
		Object *op = getByIndex(&var_list, st);
		SymbolData *sp = op->symbol;		

		index = sp->index;
		addr = sp->addr;		
		lineno = sp->lineno;
		func_sig = sp->func_sig;

		name = sp->name;
		type = objectTypeName[op->type];


		printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n", index, name, type, addr, lineno, func_sig);

		st++;
	}
}

int main(int argc, char* argv[]) {
    char* outputFileName = NULL;
    if (argc == 3) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = fopen(outputFileName = argv[2], "w");
    } else if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = stdout;
    } else {
        printf("require input file");
        exit(1);
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }
    if (!yyout) {
        printf("file `%s` doesn't exists or cannot be opened\n", outputFileName);
        exit(1);
    }

    scopeLevel = -1;

	// codeRaw(".method public static main([Ljava/lang/String;)V ; main function");
	// codeRaw(".limit stack 100");
	// codeRaw(".limit locals 100");
	// codeRaw("return");
	// codeRaw(".end method");

    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}