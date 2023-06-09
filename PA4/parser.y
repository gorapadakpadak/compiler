%{
        #include "taclib.h"
        #include <stdio.h>
        #include <stdlib.h>
        STACK *stack;
        int yylex(void);
        int yyerror(char* s);
        int inLoop=0;
        int inSwitch=0;
        int inFunction=0;
       
%}
%start Program
%union{
        int iVal;
        float rVal;
        char* sVal;
}
%token <iVal> TINTEGER
%token <rVal> TREAL
%token <sVal> TIDENTIFIER TINT TFLOAT TCHAR STRING TBREAK TCASE TDEFAULT TDO TFOR TRETURN TWHILE TIF TELSE TSWITCH TVOID
%token <iVal> PLUSEQUAL MINUSEQUAL TIMESEQUAL DIVEQUAL MODEQUAL
%token <iVal> LOGICALOR LOGICALAND
%token <iVal> LESS GREAT LESSEQUAL GREATEREQUAL EQUALEQUAL NOTEQUAL
%token <iVal> PLUSPLUS MINUSMINUS
%token <iVal> PLUS MINUS TIMES DIV MOD EQUAL
%token <iVal> LEFT_PAREN
%token <iVal> RIGHT_PAREN
%token <iVal> SEMICOLON
%token <iVal> LEFT_BRACE
%token <iVal> RIGHT_BRACE
%token <iVal> LEFT_BRACKET
%token <iVal> RIGHT_BRACKET
%token <iVal> COLON
%token <iVal> COMMA
%token TERROR
%token <sVal> TCOMMENT

%%
Program:DecList {
        ASTNode* DecList=pop(stack);
        ASTNode* programNode = makeASTNode(_PROG);
        push(stack,setChild(programNode, DecList));
}
DecList:DecList Dec	{
        ASTNode* Dec=pop(stack);
        ASTNode* DecList=pop(stack);
        push(stack,setLastSibling(DecList,Dec));
}
|Dec
;
Dec:VarDec
|FuncDec	{inFunction=1;}
;
FuncDec: VarType TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN CpndStmt   {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNodeID($2);
        ASTNode* CpndStmt = pop(stack);
        ASTNode* Params = pop(stack);
        ASTNode* Type = pop(stack);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type,setSibling(ID,setSibling(Params, CpndStmt)))));
}
| VarType TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN SEMICOLON       {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* Params = pop(stack);
        ASTNode* ID=makeASTNodeID($2);
        ASTNode* Type = pop(stack);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type, setSibling(ID, Params))));
}
| TVOID TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN CpndStmt     {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNodeID($2);
        ASTNode* CpndStmt = pop(stack);
        ASTNode* Params = pop(stack);
        ASTNode* Type = makeASTNodeTYPE(TYPE_VOID);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type, setSibling(ID, setSibling(Params, CpndStmt)))));

}
| TVOID TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN SEMICOLON         {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNode(_ID);
        ASTNode* Params = pop(stack);
        ASTNode* Type = makeASTNodeTYPE(TYPE_VOID);
        inFunction=1;
	push(stack,setChild(FuncDec, setSibling(Type,setSibling(ID, Params) )));
	}
;
Params:ParamList        {
        ASTNode* Params=makeASTNode(_PARAMS);
        ASTNode* ParamList=pop(stack);
        push(stack,setChild(Params, ParamList));
	}
|TVOID   {
	push(stack,makeASTNode(_PARAMS));
	}
|       {
	push(stack,makeASTNode(_PARAMS));
	}
;
ParamList:ParamList COMMA Param     {
        ASTNode* newParam=pop(stack);
        ASTNode* ParamList=pop(stack);
        push(stack,setLastSibling(ParamList,newParam));
}
|Param
;
Param:VarType Value     {
        ASTNode* Param=makeASTNode(_PARAM);
        ASTNode* Value=pop(stack);
        ASTNode* Type=pop(stack);
        push(stack,setChild(Param,setSibling(Type,Value)));
}
;
CpndStmt: LEFT_BRACE LDecList StmtList RIGHT_BRACE        {
        ASTNode* CpndStmt=makeASTNode(_CPNDSTMT);
        ASTNode* StmtList=pop(stack);
	ASTNode* LDecList=pop(stack);
        push(stack, setChild(CpndStmt,setSibling(LDecList,StmtList)));
}
;
LDecList:LDecList VarDec         {
        ASTNode* VarDec=pop(stack);
        ASTNode* LDecList=pop(stack);
        if(getChild(LDecList)==NULL){
		push(stack,setChild(LDecList,VarDec));
	}
	else{push(stack,setLastSibling(LDecList,VarDec));}
}
|        {
        push(stack,makeASTNode(_LDECLIST));
}
;
VarDec:VarType IDs SEMICOLON    {
        ASTNode* VarDec=makeASTNode(_VARDEC);
        ASTNode* IDs=pop(stack);
        ASTNode* Type=pop(stack);
        push(stack,setChild(VarDec,setSibling(Type,IDs)));
}
;
VarType:TINT      {
       push(stack,makeASTNodeTYPE(TYPE_INT));
}
|TFLOAT   {
	push(stack,makeASTNodeTYPE(TYPE_FLOAT));
}
;
IDs:IDs COMMA Value  {
        ASTNode* Value=pop(stack);
        ASTNode* IDs=pop(stack);
        push(stack,setLastSibling(IDs,Value));
}
|Value
;
Value:TIDENTIFIER LEFT_BRACKET TINTEGER RIGHT_BRACKET  {
        ASTNode* Array=makeASTNode(_ARRAY);
        ASTNode* ID=makeASTNodeID($1);
        ASTNode* INTEGER=makeASTNodeINT($3);
        push(stack,setChild(Array,setSibling(ID,INTEGER)));
}
|TIDENTIFIER     {
        push(stack,makeASTNodeID($1));
	}
;
StmtList:StmtList Stmt   {
        ASTNode* Stmt=pop(stack);
        ASTNode* StmtList=pop(stack);
	if(getChild(StmtList)==NULL){
		push(stack,setChild(StmtList,Stmt));
	}else{
        	push(stack,setLastSibling(StmtList,Stmt));
	}
}
|        {
        push(stack,makeASTNode(_STMTLIST));
	}
;
Stmt:MatchedStmt
|OpenStmt
;
MatchedStmt : ExprStmt
| ForMatchedStmt	{inLoop=1;}
| WhileMatchedStmt	{inLoop=1;}
| DoWhileStmt	{inLoop=1;}
| ReturnStmt
| CpndStmt
| BreakStmt
| SwitchStmt	{inSwitch=1;}
| TIF LEFT_PAREN Expr RIGHT_PAREN MatchedStmt TELSE MatchedStmt         {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* Stmt2=pop(stack);
        ASTNode* Stmt1=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,setSibling(Stmt1,Stmt2))));
}
;
OpenStmt : ForOpenStmt {inLoop=1;}
| WhileOpenStmt	{inLoop=1;}
| TIF LEFT_PAREN Expr RIGHT_PAREN Stmt  {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,Stmt)));
}
| TIF LEFT_PAREN Expr RIGHT_PAREN  MatchedStmt TELSE OpenStmt    {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* OStmt=pop(stack);
        ASTNode* MStmt=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,setSibling(MStmt,OStmt))));
}
;
SwitchStmt:TSWITCH LEFT_PAREN Expr RIGHT_PAREN LEFT_BRACE CaseList DefaultCase RIGHT_BRACE   {
        ASTNode* SwitchStmt=makeASTNode(_SWSTMT);
        ASTNode* Default=pop(stack);
        ASTNode* Case=pop(stack);
        ASTNode* Expr=pop(stack);
        inSwitch=1;
	push(stack,setChild(SwitchStmt,setSibling(Expr,setLastSibling(Case,Default))));
}
;
CaseList:CaseList TCASE TINTEGER COLON StmtList      {
        ASTNode* StmtList=pop(stack);
        ASTNode* CaseList=pop(stack);
        ASTNode* Case=makeASTNode(_CASE);
        ASTNode* Integer=makeASTNodeINT($3);
	inSwitch=1;
       	push(stack,setLastSibling(CaseList,setChild(Case,setSibling(Integer,StmtList))));
}
|TCASE TINTEGER COLON StmtList       {
        ASTNode* Case=makeASTNode(_CASE);
        ASTNode* Integer=makeASTNodeINT($2);
        ASTNode* StmtList=pop(stack);
	inSwitch=1;

        push(stack,setChild(Case,setSibling(Integer,StmtList)));
}
;
DefaultCase:TDEFAULT COLON StmtList  {
        ASTNode* Default=makeASTNode(_DEFAULT);
        ASTNode* StmtList=pop(stack);
        push(stack,setChild(Default,StmtList));
	inSwitch=1;
}
|        {
        push(stack,makeASTNode(_DEFAULT));
	inSwitch=1;
}
;



ReturnStmt:TRETURN Expr SEMICOLON       {
        ASTNode* RTStmt=makeASTNode(_RTSTMT);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(RTStmt,Expr));
	if (!inFunction) {
        yyerror("return statement used outside of a function");
   }
	
}
|TRETURN SEMICOLON      {
        push(stack,makeASTNode(_RTSTMT));
	if (!inFunction) {
        yyerror("return statement used outside of a function");
	}
	
}
;
BreakStmt:TBREAK SEMICOLON       {
	push(stack,makeASTNode(_BRKSTMT));
	if(!inSwitch&&!inLoop){
                yyerror("break error!!");
        }

}
;



ExprStmt:Expr SEMICOLON {
        ASTNode* ExprStmt=makeASTNode(_EXPRSTMT);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(ExprStmt,Expr));
}
|SEMICOLON      {
        push(stack,makeASTNode(_EXPRSTMT));
}
;
Expr:AssignExpr
|SimpleExpr
;
AssignExpr:Variable EQUAL Expr       {
        ASTNode* Assign=makeASTNodeOP(ASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(Assign,setSibling(Variable,Expr)));
}
|Variable PLUSEQUAL Expr        {
        ASTNode* AddAssign=makeASTNodeOP(ADDASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(AddAssign,setSibling(Variable,Expr)));
}
|Variable MINUSEQUAL Expr        {
        ASTNode* SubAssign=makeASTNodeOP(SUBASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(SubAssign,setSibling(Variable,Expr)));
}
| Variable TIMESEQUAL Expr     {
        ASTNode* MultAssign=makeASTNodeOP(MULTASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(MultAssign,setSibling(Variable,Expr)));
}
| Variable DIVEQUAL Expr     {
        ASTNode* DivAssign=makeASTNodeOP(DIVASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(DivAssign,setSibling(Variable,Expr)));
}
| Variable MODEQUAL Expr     {
        ASTNode* ModAssign=makeASTNodeOP(MODASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(ModAssign,setSibling(Variable,Expr)));
}
;
Variable:TIDENTIFIER LEFT_BRACKET Expr RIGHT_BRACKET   {
        ASTNode* Array=makeASTNode(_ARRAY);
        ASTNode* ID=makeASTNodeID($1);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(Array,setSibling(ID,Expr)));
}
|TIDENTIFIER     {
        push(stack,makeASTNodeID($1));
}
;
SimpleExpr:SimpleExpr LOGICALOR AndExpr         {
        ASTNode* Or=makeASTNodeOP(OR_);
        ASTNode* AndExpr=pop(stack);
        ASTNode* SimpleExpr=pop(stack);
        push(stack,setChild(Or,setSibling(SimpleExpr,AndExpr)));
}
|AndExpr
;
AndExpr : AndExpr LOGICALAND RelExpr   {
        ASTNode* And=makeASTNodeOP(AND_);
        ASTNode* RelExpr=pop(stack);
        ASTNode* AndExpr=pop(stack);
        push(stack,setChild(And,setSibling(AndExpr,RelExpr)));
}
| RelExpr
;
RelExpr : RelExpr LESS AddExpr    {
        ASTNode* LT=makeASTNodeOP(LT_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(LT,setSibling(RelExpr,AddExpr)));
}
| RelExpr LESSEQUAL AddExpr   {
        ASTNode* LE=makeASTNodeOP(LE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(LE,setSibling(RelExpr,AddExpr)));
}
| RelExpr GREAT AddExpr    {
        ASTNode* GT=makeASTNodeOP(GT_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(GT,setSibling(RelExpr,AddExpr)));
}
| RelExpr GREATEREQUAL AddExpr          {
        ASTNode* GE=makeASTNodeOP(GE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(GE,setSibling(RelExpr,AddExpr)));
}
| RelExpr EQUALEQUAL AddExpr   {
        ASTNode* EQ=makeASTNodeOP(EQ_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(EQ,setSibling(RelExpr,AddExpr)));
}
| RelExpr NOTEQUAL AddExpr   {
        ASTNode* NE=makeASTNodeOP(NE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(NE,setSibling(RelExpr,AddExpr)));
}
| AddExpr
;
AddExpr : AddExpr PLUS Term       {
        ASTNode* Plus=makeASTNodeOP(PLUS_);
        ASTNode* Term=pop(stack);
        ASTNode* AddExpr=pop(stack);
        push(stack,setChild(Plus,setSibling(AddExpr,Term)));
}
| AddExpr MINUS Term       {
        ASTNode* Minus=makeASTNodeOP(MINUS_);
        ASTNode* Term=pop(stack);
        ASTNode* AddExpr=pop(stack);
        push(stack,setChild(Minus,setSibling(AddExpr,Term)));
}
| Term
;
Term : Term TIMES Factor   {
        ASTNode* MULT=makeASTNodeOP(MULT_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(MULT,setSibling(Term,Factor)));
}
| Term DIV Factor        {
        ASTNode* Div=makeASTNodeOP(DIV_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(Div,setSibling(Term,Factor)));
}
| Term MOD Factor        {
        ASTNode* Mod=makeASTNodeOP(MOD_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(Mod,setSibling(Term,Factor)));
}
| Factor
;
Factor : LEFT_PAREN Expr RIGHT_PAREN
| FuncCall      {
}
| Variable
| NumberLiteral
| MINUS Factor  {
        ASTNode* Minus=makeASTNodeOP(MINUS_);
        ASTNode* Factor=pop(stack);
        push(stack,setChild(Minus,Factor));
}
| Variable IncDec       {
        ASTNode* IncDecExp=makeASTNode(_INCDECEXP);
        ASTNode* IncDec=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(IncDecExp,setSibling(Variable,IncDec)));
}
| IncDec Variable       {
        ASTNode* IncDecExp=makeASTNode(_INCDECEXP);
        ASTNode* Variable=pop(stack);
        ASTNode* IncDec=pop(stack);
        push(stack,setChild(IncDecExp,setSibling(IncDec,Variable)));
}
;
NumberLiteral:TINTEGER {
        push(stack,makeASTNodeINT($1));
}
|TREAL  {
        push(stack,makeASTNodeREAL($1));
}
;
IncDec:PLUSPLUS      {
        push(stack,makeASTNodeOP(INC_));
}
|MINUSMINUS    {
        push(stack,makeASTNodeOP(DEC_));
}
;

WhileMatchedStmt : TWHILE LEFT_PAREN Expr RIGHT_PAREN MatchedStmt       {
        ASTNode* WhileStmt=makeASTNode(_WHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(WhileStmt,setSibling(Expr,Stmt)));
}
;
WhileOpenStmt : TWHILE LEFT_PAREN Expr RIGHT_PAREN OpenStmt     {
        ASTNode* WhileStmt=makeASTNode(_WHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(WhileStmt,setSibling(Expr,Stmt)));
}
;
DoWhileStmt : TDO Stmt TWHILE LEFT_PAREN Expr RIGHT_PAREN SEMICOLON   {
        ASTNode* DoWhileStmt=makeASTNode(_DOWHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(DoWhileStmt,setSibling(Expr,Stmt)));
}
;
ForMatchedStmt : TFOR LEFT_PAREN Expr SEMICOLON Expr SEMICOLON Expr RIGHT_PAREN MatchedStmt         {
        ASTNode* ForStmt=makeASTNode(_FORSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr3=pop(stack);
        ASTNode* Expr2=pop(stack);
        ASTNode* Expr1=pop(stack);
	inLoop=1;
        push(stack,setChild(ForStmt,setSibling(Expr1,setSibling(Expr2,setSibling(Expr3,Stmt)))));
}
;
ForOpenStmt : TFOR LEFT_PAREN Expr SEMICOLON Expr SEMICOLON Expr RIGHT_PAREN OpenStmt         {
        ASTNode* ForStmt=makeASTNode(_FORSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr3=pop(stack);
        ASTNode* Expr2=pop(stack);
        ASTNode* Expr1=pop(stack);
	inLoop=1;
        push(stack,setChild(ForStmt,setSibling(Expr1,setSibling(Expr2,setSibling(Expr3,Stmt)))));
}
;
FuncCall : TIDENTIFIER LEFT_PAREN Arguments RIGHT_PAREN         {
        ASTNode* FuncCall=makeASTNode(_FUNCCALL);
        ASTNode* ID=makeASTNodeID($1);
        ASTNode* Args=pop(stack);
        push(stack,setChild(FuncCall,setSibling(ID,Args)));
}
;
Arguments : ArgumentList         {
        ASTNode* Args=makeASTNode(_ARGS);
        ASTNode* ArgList=pop(stack);
        push(stack,setChild(Args,ArgList));
}
|        {
        push(stack,makeASTNode(_ARGS));
}
;
ArgumentList : ArgumentList COMMA Expr     {
        ASTNode* expr=pop(stack);
        ASTNode* ArgList=pop(stack);
        push(stack,setLastSibling(ArgList,expr));
}
| Expr
;
%%
int main(int argc, char* argv[]){
        ASTNode* root;
        extern FILE *yyin;
        stack = initStack();
        yyin = fopen(argv[1], "r");
        yyparse();
        fclose(yyin);
        root = pop(stack);
        delStack(stack);
        generate(root, argv[1]);
        delAST(root);
        return 0;
}

int yyerror(char *s){
        printf("Parse error : %s\n", s);
        return 0;
}


