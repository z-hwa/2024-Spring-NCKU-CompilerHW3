/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;

	char* assign_var;	//用於為變數設值的時候，紀錄當前設定的變數名稱
	ObjectType nowDealType;	//用於變數設值的時候，紀錄值的類型，用於判斷變數與值類型是否相同

	int array_ct = 0;	//用於紀錄連續的陣列變數宣告
	int para_ct	=0;	//紀錄參數數量的變數
	Object* para[100];	//紀錄參數的型態

	int isMain = 0;	//確認現在是不是在main中
%}


/* Variable or self-defined structure */
%union {
    ObjectType var_type;
    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BXO MUL DIV REM GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE
%token ')' ';' '{' '}'
%token ENDL

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_val> IDENT

//有value的token 需要特別讓他帶著屬性
%token <b_var> BOOL_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT
%token <s_var> STR_LIT

%token <object_val> '(' SUB NOT BNT ADD

/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression Printable PrintableList
%type <object_val> Or And BitwiseOr BitwiseXor BitwiseAnd Equality Relational Shift Additive Multiplicative Unary Primary TypeCast Post AssignBody Assignable
%type <object_val> FunctionCall ArgumentList ArgumentListNonEmpty, List, AssignList

//%type <object_val> Term
//%type <object_val> Factor

%left ADD SUB
%left MUL DIV REM

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { 
		pushScope();
		addFileStart_j();
	 } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
	| CoutStmt
    | ReturnStmt
	| AssignStmt
	| SelectionStmt {addIf_j('o');}
	| IterationStmt
	| JumpStmt
	| FunctionCallStmt
	//| /* Empty Stmt */ 
;

FunctionCallStmt
	: FunctionCall ';'

;

JumpStmt
	: BREAK ';' {
		printf("BREAK\n");
		addBreak_j();
	}
;

/*while and for*/
IterationStmt
	: WHILE {
		printf("WHILE\n");
		addWhile_j('i');	//設置循環標記
	} '(' Expression ')' {
		addWhile_j('w');	//check condition
		pushScope();
	} CompoundStmt {
		addWhile_j('c');	//go to 循環標記
		dumpScope();
		addWhile_j('o');	//離開標記
	}
	| FOR {
		printf("FOR\n");
		pushScope();
	} '(' ForCondition ')' {
		addFor_j('2');	//get jump, f2
	} CompoundStmt {
		addFor_j('3');	//f3
		dumpScope();
		addFor_j('o');	//離開標記
	}
;

ForCondition
	: ExpressionStmt {
		addFor_j('i');	//設置循環標記;
	} ExpressionStmt {
		addFor_j('f');	//check condition

		addFor_j('1');	//f1
		addFor_j('4');	//f4
	} ExpressionStmt {
		addFor_j('c');
	}
	| VARIABLE_T IDENT ':' IDENT {
		//auto i:a	類型的for迴圈
		insert($<s_var>2, getVarTypeByName($<s_var>4), 1);
		printIDByName($<s_var>4, 'v'); 
	}
;

ExpressionStmt
	: Expression ';'
	| DefineVariableStmt
	| AssignBody
	| Expression
	| ';'
;

/*複合敘述*/
CompoundStmt
	: '{' GlobalStmtList '}'
	| GlobalStmtList
;


/*if else*/
SelectionStmt
	: IF '(' Expression ')'{ 
		printf("IF\n");
		addIf_j('i');	//判斷條件是否為真，錯的話跳出
	} Selection {
		addIf_j('g');
		addIf_j('e');
	}
	| SelectionStmt ELSE {
		printf("ELSE\n");
	} Selection
;

Selection
	: GlobalStmt
	| '{' {pushScope();} GlobalStmtList {dumpScope();} '}';
;

/*define and 設值敘述*/

AssignStmt
	: AssignBody ';'
;

AssignBody
	: IDENT { 
		printIDByName($<s_var>1, 'v');	//輸出該變數資訊

		assign_var = $<s_var>1;
		addPushLocalVar_j($<s_var>1, ' ');	//將當前設值的變數放進stack
	} Assign {
		$<object_val>0.type = OBJECT_TYPE_BOOL;	//設值成功，回傳bool

		//將變數設值
		addLocalVar_j($<s_var>1, 'y', nowDealType);
	}
	| IDENT '[' {
		addPushLocalVar_j($<s_var>1, 'L');
		assign_var = $<s_var>1;
	} AssignList {$<object_val>0.type = $<object_val>3.type;}
;

/*如果存在語意致導方案，資料流就不會自動向上傳，而是會被擋住
如果不存在，則會在grammar中自動向上傳遞一格
*/
AssignList
	: Expression ']' {
		printIDByName(assign_var, 'v');
	} Assign {
		$<object_val>0.type = OBJECT_TYPE_BOOL;
		addArrayEle_j(nowDealType);
	}
	| Expression ']' '[' Expression ']' {
		printIDByName(assign_var, 'v');

		codeRaw("swap");
		codeRaw("ldc 3");
		codeRaw("imul");
		codeRaw("iadd");//count index
	} Assign {
		$<object_val>0.type = OBJECT_TYPE_BOOL;
		addArrayEle_j(nowDealType);
	}
;

Assign
	: Assignable
	| VAL_ASSIGN Assign{
		printf("EQL_ASSIGN\n");
	}
	| ADD_ASSIGN Assign{
		printf("ADD_ASSIGN\n");
		addAssign_j(assign_var, "add");
	}
	| SUB_ASSIGN Assign{
		printf("SUB_ASSIGN\n");
		addAssign_j(assign_var, "sub");}
	| MUL_ASSIGN Assign{
		printf("MUL_ASSIGN\n");
		addAssign_j(assign_var, "mul");}
	| DIV_ASSIGN Assign{
		printf("DIV_ASSIGN\n");
		addAssign_j(assign_var, "div");}
	| REM_ASSIGN Assign{
		printf("REM_ASSIGN\n");
		addAssign_j(assign_var, "rem");}
	| BAN_ASSIGN Assign{
		printf("BAN_ASSIGN\n");
		addAssign_j(assign_var, "and");}
	| BOR_ASSIGN Assign{
		printf("BOR_ASSIGN\n");
		addAssign_j(assign_var, "or");}
	| BXO_ASSIGN Assign{
		printf("BXO_ASSIGN\n");
		addAssign_j(assign_var, "xor");}
	| SHR_ASSIGN Assign{
		printf("SHR_ASSIGN\n");
		addAssign_j(assign_var, "shr");}
	| SHL_ASSIGN Assign{
		printf("SHL_ASSIGN\n");
		addAssign_j(assign_var, "shl");}
;

Assignable	
	: STR_LIT  {
		$<object_val>0.type = OBJECT_TYPE_STR;
		nowDealType = OBJECT_TYPE_STR;
		printf("STR_LIT \"%s\"\n", $<s_var>1);

		code("ldc \"%s\"", $<s_var>1);
	}
	| Expression { nowDealType = $<object_val>0.type; }
;

/* define variable */
DefineVariableStmt
	: VARIABLE_T DeclaratorList ';' {typeSet(false);}
;

DeclaratorList
	: Declarator
	| DeclaratorList ',' Declarator
;

Declarator
	: IDENT {
		//普通的變數宣告
		insert($<s_var>1, $<var_type>0, 0);

		//創建並添加該變數
		addLocalVar_j($<s_var>1, 'n', OBJECT_TYPE_INT);
	}	
	| IDENT VAL_ASSIGN Assignable {
		//普通的變數宣告與賦值
		insertAuto($<s_var>1, $<var_type>0, $<var_type>2, 0);

		//創建並添加該變數
		addLocalVar_j($<s_var>1, 'y', $<object_val>2.type);
	}
	| IDENT '[' Expression ']' {
		//陣列的變數宣告
		printf("create array: %d\n", 0);
		insert($<s_var>1, $<var_type>0, 0);

		codeRaw("newarray int");	//宣告陣列

		addLocalVar_j($<s_var>1, 'y', OBJECT_TYPE_VOID);
	}
	| IDENT '[' Expression ']' '[' Expression ']' {
		//二維陣列的變數宣告
		insert($<s_var>1, $<var_type>0, 0);

		/*這裡的實現應該是取yacc計算出來的expression
		用於紀錄這個list的一維、二維大小，之後直接傳給java做計算
		就可以適配各種長寬的二維陣列
		
		可惜我沒有算yacc的結果，所以之後有空再弄
		不過這個list在浮點數上能不能用也是未知數*/

		codeRaw("imul");

		//創建陣列
		codeRaw("newarray int");	//宣告陣列
		addLocalVar_j($<s_var>1, 'y', OBJECT_TYPE_VOID);
	}
	| IDENT '[' Expression ']' {
		codeRaw("newarray int");	//宣告陣列
	} VAL_ASSIGN '{' ArrayEles '}' {
		//一維陣列的變數宣告與賦值
		printf("create array: %d\n", array_ct);
		array_ct = 0;
		insert($<s_var>1, $<var_type>0, 0);

		//創建陣列
		addLocalVar_j($<s_var>1, 'y', OBJECT_TYPE_VOID);
	}  
;

ArrayEles
	: {
		codeRaw("dup");
		code("ldc %d", array_ct);
	}Assignable {
		addArrayEle_j($<object_val>1.type);
		array_ct++;
	}
	| ArrayEles ',' {
		codeRaw("dup");
		code("ldc %d", array_ct);
	}Assignable {
		addArrayEle_j($<object_val>3.type);
		array_ct++;
	}
	| 
;

/* Return */
ReturnStmt
    : RETURN Expression ';' {
		printf("RETURN\n");
		addRet_j($<object_val>1.type, isMain);	//添加函數回傳
	}
    | RETURN ';' {
		printf("RETURN\n");
		addRet_j(OBJECT_TYPE_VOID, 0);	//添加函數回傳
	}
	| {
		printf("RETURN\n");
		addRet_j(OBJECT_TYPE_VOID, 0);	//添加函數回傳
	}
;

/*cin cout*/
CoutStmt
	: COUT {
		addMsg("cout");
	} SHL PrintableList ';' {
		addMsg("\n");
		printMsg();
	}
;

//可印出的列表
PrintableList
    : Printable 
    | PrintableList SHL Printable
;

//可印出的token
Printable
    : STR_LIT { 
		addMsg(" string");
		printf("STR_LIT \"%s\"\n", $<s_var>1);
		
		addPrint_j($<s_var>1);}
    | ENDL { 
		addMsg(" string");
		printf("IDENT (name=endl, address=-1)\n"); 

		addPrint_j("\n");
	}
	| Expression {
		addMsg(" ");
		addMsgObj(&$<object_val>0);

		addPrintExp_j($<object_val>0.type);
	}
;


/* expression */

Expression
	: Or
	//| AssignBody {$<object_val>0.type = OBJECT_TYPE_BOOL;}
	| STR_LIT {
		printf("STR_LIT \"%s\"\n", $<s_var>1);
		code("ldc \"%s\"", $<s_var>1);
	}
;

Or
	: And
	| Or LOR And{
		// here is correct
		objectExpBoolean('1', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		
		addOpByType_j("or", $<object_val>0.type);
	}
;

And
	: BitwiseOr //{setType(&$<object_val>1, &$<object_val>0);}
	| And LAN BitwiseOr{
		objectExpBoolean('2', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		
		addOpByType_j("and", $<object_val>0.type);
	} 
;

BitwiseOr
	: BitwiseXor
	| BitwiseOr BOR BitwiseXor{
		objectExpBinary('1', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		
		addOpByType_j("or", $<object_val>0.type);
	} 
;

BitwiseXor
	: BitwiseAnd //{setType(&$<object_val>1, &$<object_val>0);}
	| BitwiseXor BXO BitwiseAnd{
		objectExpBinary('2', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		
		addOpByType_j("xor", $<object_val>0.type);	
	} 
;

BitwiseAnd
	: Equality //{setType(&$<object_val>1, &$<object_val>0);}
	| BitwiseAnd BAN Equality{
		objectExpBinary('3', &$<object_val>1, &$<object_val>2, &$<object_val>0);

		addOpByType_j("and", $<object_val>0.type);	
	} 
;

Equality
	: Relational //{setType(&$<object_val>1, &$<object_val>0);}
	| Equality EQL Relational{
		objectExpBoolean('3', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		addOpByType_j("eql", $<object_val>0.type);	
	}  
	| Equality NEQ Relational{
		objectExpBoolean('4', &$<object_val>1, &$<object_val>2, &$<object_val>0);
		addOpByType_j("neq", $<object_val>0.type);
	} 
;

Relational
	: Shift 
	| Relational LES Shift{
		printf("LES\n");

		//位元運算
		addOpByType_j("les", $<object_val>0.type);
		$<object_val>0.type = OBJECT_TYPE_BOOL;
	} 
	| Relational GTR Shift{
		printf("GTR\n");

		//位元運算
		addOpByType_j("gtr", $<object_val>0.type);
		$<object_val>0.type = OBJECT_TYPE_BOOL;
	}
	| Relational LEQ Shift{
		printf("LEQ\n");

		//位元運算
		addOpByType_j("leq", $<object_val>0.type);
		$<object_val>0.type = OBJECT_TYPE_BOOL;} 

	| Relational GEQ Shift{
		printf("GEQ\n");

		//位元運算
		addOpByType_j("geq", $<object_val>0.type);
		$<object_val>0.type = OBJECT_TYPE_BOOL;} 

;

Shift
	: Additive
	| Shift SHR Additive{
		printf("SHR\n");
		addOpByType_j("shr", $<object_val>0.type);
	} 
;

Additive
	: Multiplicative //{setType(&$<object_val>1, &$<object_val>0);}
	| Additive ADD Multiplicative{
		printf("ADD\n");

		//輸出 加法指令
		addOpByType_j("add", $<object_val>0.type);}

	| Additive SUB Multiplicative{
		printf("SUB\n");
		
		//輸出 減法指令
		addOpByType_j("sub", $<object_val>0.type);}

;

Multiplicative
	: TypeCast
	| Multiplicative MUL TypeCast{
		printf("MUL\n");

		//輸出 乘法指令
		addOpByType_j("mul", $<object_val>0.type);}
	| Multiplicative DIV TypeCast{
		printf("DIV\n");
		
		//輸出 除法指令
		addOpByType_j("div", $<object_val>0.type);}
	| Multiplicative REM TypeCast{
		printf("REM\n");

		//輸出 模數指令
		addOpByType_j("rem", $<object_val>0.type);
	}

;

TypeCast
	: Unary
	| '(' VARIABLE_T ')' Unary {
		$<object_val>0.type = $<var_type>2;
		printCastInfo($<var_type>2);

		addCast_j($<var_type>2);
	}
;

Unary
	: BNT Unary{
		$<object_val>0.type = $<object_val>1.type;	//傳遞類別
		printf("BNT\n"); 

		//輸出unary negation指令
		addOpByType_j("not", $<object_val>0.type);
	}
	| ADD Unary{
		$<object_val>0.type = $<object_val>1.type;	//傳遞類別
		printf("ADD\n");} 
	| SUB Unary{
		$<object_val>0.type = $<object_val>1.type;	//傳遞類別
		printf("NEG\n");	//輸出資訊

		//輸出unary negation指令
		addOpByType_j("neg", $<object_val>0.type);
	} 
	| NOT Unary{
		$<object_val>0.type = $<object_val>1.type;	//傳遞類別
		printf("NOT\n");
		
		addOpByType_j("not", $<object_val>0.type);} 
	| Post
;

Post
	: Primary
	| Primary INC_ASSIGN {
		printf("INC_ASSIGN\n");

		//設值操作
		addAssign_j(assign_var, "inc");

		//將變數設值
		addLocalVar_j($<s_var>1, 'y', $<object_val>0.type);
	} 
	| Primary DEC_ASSIGN {
		printf("DEC_ASSIGN\n");
		
		//addOpByType_j("dec", $<object_val>0.type);
		addAssign_j(assign_var, "dec");

		//將變數設值
		addLocalVar_j($<s_var>1, 'y', $<object_val>0.type);
	} 
;

Primary
    : INT_LIT{
			$<object_val>0.type = OBJECT_TYPE_INT;
			printf("INT_LIT %d\n", $<i_var>1);

			//輸出 載入整數到stack頂端
			code("ldc %d", $<i_var>1);
		}
	| FLOAT_LIT {
			$<object_val>0.type = OBJECT_TYPE_FLOAT;
			printf("FLOAT_LIT %f\n", $<f_var>1);

			//輸出 載入整數到stack頂端
			code("ldc %f", $<f_var>1);
		}
    | '(' Expression ')' {
			$<object_val>0.type = $<object_val>1.type;
		}
	| BOOL_LIT {
			$<object_val>0.type = OBJECT_TYPE_BOOL; 
			printBool($<b_var>1);

			//輸出 載入整數到stack頂端
			code("ldc %d", $<b_var>1);
		}
	| IDENT {
		//詞性修飾
		ObjectType type = getVarTypeByName($<s_var>1);
		$<object_val>0.type = type;

		//輸出資訊
		printIDByName($<s_var>1, 'v');

		//輸出 載入該變數到stack頂端
		addPushLocalVar_j($<s_var>1, ' ');
		assign_var = $<s_var>1;	//設置當前修改的變數名稱
	}
	| FunctionCall
	| IDENT '[' {
		assign_var = $<s_var>1;

		addPushLocalVar_j($<s_var>1, 'L');	//取得陣列ref	
	} List {
		$<object_val>0.type = $<object_val>3.type;
	}
;

List
	: Expression ']' {
		ObjectType type = getVarTypeByName(assign_var);
		$<object_val>0.type = type;
		printIDByName(assign_var, 'v');

		addPushLocalVar_j(assign_var, 'l');
	}
	| Expression ']' '[' Expression ']' {
		ObjectType type = getVarTypeByName(assign_var);
		$<object_val>0.type = type;
		printIDByName(assign_var, 'v');

		codeRaw("swap");
		codeRaw("ldc 3");
		codeRaw("imul");
		codeRaw("iadd");//count index

		addPushLocalVar_j(assign_var, 'l');
	}
;

/* Function call */

FunctionCall
	: IDENT '(' ArgumentList ')' {
		$<object_val>0.type = getFuncType($<s_var>1);
		printIDByName($<s_var>1, 'f');
		printf("call: %s", $<s_var>1);
		printSigByName($<s_var>1);
		printf("\n");

		code("invokestatic Main/%s%s", $<s_var>1, getSigByName($<s_var>1));
	}
;

ArgumentList
	: ArgumentListNonEmpty
;

ArgumentListNonEmpty
	: Expression
	| ArgumentListNonEmpty ',' Expression
;


/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT {
		createFunction($<var_type>1, $<s_var>2);
		addFunDef_j($<s_var>2, 'n');

		if(strcmp($<s_var>2, "main")==0) isMain = 1;
		else isMain = 0;
	} '(' {
		pushScope();

		para_ct = 0;
	} FunctionParameterStmtList ')' {
		setFuncSig($<s_var>2, $<var_type>1);
		addFunDef_j($<s_var>2, 's');		//傳入函數名稱，在main.j中建立函數
	
		if(isMain == 0) {
			//在函數區塊，重置變數位置
			for(int i=0;i<para_ct;i++) {
				
				SymbolData* sp = para[i]->symbol;
				ObjectType type= para[i]->type;

				//創建並添加該變數
				if(type == OBJECT_TYPE_INT || type == OBJECT_TYPE_BOOL) code("iload %d", i);
				else if(type ==OBJECT_TYPE_FLOAT) code("fload %d", i);
				else if(type ==OBJECT_TYPE_STR) code("aload %d", i);

				addLocalVar_j(sp->name, 'y', type);
			}
		}

	} '{' GlobalStmtList ReturnStmt '}' {
		dumpScope();
		addFunEnd_j();	//添加函數結尾
	}

FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;

FunctionParameterStmt
    : VARIABLE_T IDENT {
		insert($<s_var>2, $<var_type>1, 3);

		para[para_ct] = getObjectByName($<s_var>2, 'v');
		para_ct++;
	}
    | VARIABLE_T IDENT { 
		insert($<s_var>2, $<var_type>1, 4);

		para[para_ct] = getObjectByName($<s_var>2, 'v');
		para_ct++;

	} '[' ']' //支援不帶index的一維陣列
;
%%
/* C code section */