%{
        #include <stdio.h>
        #include <stdlib.h>
        int yylex(void);
        int yyerror(char* s);
%}
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
Program:DecList {printf("Program -> DecList\n");}
DecList:DecList Dec     {printf("DecList -> DecLsit Dec\n");}
|Dec     {printf("DecList -> Dec\n");}
;
Dec:VarDec      {printf("Dec -> VarDec\n");}
|FuncDec     {printf("Dec -> FuncDec\n");}
;
FuncDec: VarType TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN CpndStmt   {printf("FuncDec -> VarType %s ( Params ) CpndStmt\n", $2);}
| VarType TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN SEMICOLON       {printf("FuncDec -> VarType %s ( Params ) ;\n", $2);}
| TVOID TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN CpndStmt     {printf("FuncDec -> void %s ( Params ) CpndStmt\n", $2);}
| TVOID TIDENTIFIER LEFT_PAREN Params RIGHT_PAREN SEMICOLON         {printf("FuncDec -> void %s ( Params ) ;\n", $2);}
;
Params:ParamList        {printf("Params -> ParamList\n");}
|TVOID   {printf("Params -> void\n");}
|       {printf("Params -> Empty\n");}
;
ParamList:ParamList COMMA Param     {printf("ParamList -> ParamList , Param\n");}
|Param         {printf("ParamList -> Param\n");}
;
Param:VarType Value     {printf("Param -> VarType Value\n");}
;
CpndStmt: LEFT_BRACE LDecList StmtList RIGHT_BRACE        {printf("CpndStmt -> { LDecList StmtList }\n");}
LDecList:LDecList VarDec         {printf("LDecList -> LDecList VarDec\n");}
|        {printf("LDecList -> Empty\n");}
;
VarDec:VarType IDs SEMICOLON    {printf("VarDec -> VarType IDs ;\n");}
;
VarType:TINT      {printf("VarType -> int\n");}
|TCHAR    {printf("VarType -> char\n");}
|TFLOAT   {printf("VarType -> float\n");}
;
IDs:IDs COMMA Value  {printf("IDs -> IDs , Value\n");}
|Value   {printf("IDs -> Value\n");}
;
Value:TIDENTIFIER LEFT_BRACKET TINTEGER RIGHT_BRACKET  {printf("Value -> %s [ TINTEGER ]\n", $1);}
|TIDENTIFIER     {printf("Value -> %s\n",$1);}
;
StmtList:StmtList Stmt   {printf("Stmt -> StmtList Stmt\n");}
|        {printf("Stmt -> Empty\n");}
;
Stmt:MatchedStmt         {printf("Stmt -> MatchedStmt\n");}
|OpenStmt        {printf("Stmt -> OpenStmt\n");}
;
MatchedStmt : ExprStmt   {printf("MatchedStmt -> ExprStmt\n");}
| ForMatchedStmt         {printf("MatchedStmt -> ForMatchedStmt\n");}
| WhileMatchedStmt       {printf("MatchedStmt -> WhileMatchedStmt\n");}
| DoWhileStmt    {printf("MatchedStmt -> DoWhileStmt\n");}
| ReturnStmt     {printf("MatchedStmt -> ReturnStmt\n");}
| CpndStmt       {printf("MatchedStmt -> CpndStmt\n");}
| BreakStmt      {printf("MatchedStmt -> BreakStmt\n");}
| SwitchStmt     {printf("MatchedStmt -> SwitchStmt\n");}
| TIF LEFT_PAREN Expr RIGHT_PAREN MatchedStmt TELSE MatchedStmt         {printf("MatchedStmt -> TIF ( Expr ) MatchedStmt TELSE MatchedStmt\n");}
;
OpenStmt : ForOpenStmt   {printf("OpenStmt -> ForOpenStmt\n");}
| WhileOpenStmt  {printf("OpenStmt -> WhileOpenStmt\n");}
| TIF LEFT_PAREN Expr RIGHT_PAREN Stmt  {printf("OpenStmt -> TIF ( Expr ) Stmt\n");}
| TIF LEFT_PAREN Expr RIGHT_PAREN  MatchedStmt TELSE OpenStmt    {printf("OpenStmt -> TIF ( Expr ) MatchedStmt TELSE OpenStmt\n");}
;
SwitchStmt:TSWITCH LEFT_PAREN Expr RIGHT_PAREN LEFT_BRACE CaseList DefaultCase RIGHT_BRACE   {printf("SwitchStmt -> TSWITCH ( Expr ) { CaseList DefaultCase }\n");}
;
CaseList:CaseList TCASE TINTEGER COLON StmtList      {printf("CaseList -> CaseList TCASE TINTEGER : StmtList\n");}
|TCASE TINTEGER COLON StmtList       {printf("CaseList -> TCASE TINTEGER : StmtList\n");}
;
DefaultCase:TDEFAULT COLON StmtList  {printf("DefaultCase -> TDEFAULT : StmtList\n");}
|        {printf("DefaultCase -> Empty\n");}
;
ReturnStmt:TRETURN Expr SEMICOLON       {printf("ReturnStmt -> TRETURN Expr ;\n");}
|TRETURN SEMICOLON      {printf("ReturnStmt -> TRETURN ;\n");}
;
BreakStmt:TBREAK SEMICOLON       {printf("BreakStmt -> TBREAK ;\n");}
;
ExprStmt:Expr SEMICOLON	{printf("ExprStmt -> Expr ;\n");}
|SEMICOLON	{printf("ExprStmt -> ;\n");}
;
Expr:AssignExpr  {printf("Expr -> AssignExpr\n");}
|SimpleExpr      {printf("Expr -> SimpleExpr\n");}
;
AssignExpr:Variable EQUAL Expr       {printf("AssignExpr -> Variable = Expr\n");}
|Variable PLUSEQUAL Expr        {printf("Variable += Expr\n");}
|Variable MINUSEQUAL Expr        {printf("Variable -= Expr\n");}
| Variable TIMESEQUAL Expr     {printf("Variable *= Expr\n");}
| Variable DIVEQUAL Expr     {printf("Variable /= Expr\n");}
| Variable MODEQUAL Expr     {printf("Variable %%= Expr\n");}
;
Variable:TIDENTIFIER LEFT_BRACKET Expr RIGHT_BRACKET   {printf("Variable -> %s [ Expr ]\n",$1);}
|TIDENTIFIER     {printf("Variable -> %s\n",$1);}
;
SimpleExpr:SimpleExpr LOGICALOR AndExpr         {printf("SimpleExpr -> SimpleExpr || AndExpr\n");}
|AndExpr         {printf("SimpleExpr -> AndExpr\n");}
;
AndExpr : AndExpr LOGICALAND RelExpr   {printf("AndExpr -> AndExpr && RelExpr\n");}
| RelExpr        {printf("AndExpr -> RelExpr\n");}
;
RelExpr : RelExpr LESS AddExpr    {printf("RelExpr -> RelExpr < AddExpr\n");}
| RelExpr LESSEQUAL AddExpr   {printf("RelExpr -> RelExpr <= AddExpr\n");}
| RelExpr GREAT AddExpr    {printf("RelExpr -> RelExpr > AddExpr\n");}
| RelExpr GREATEREQUAL AddExpr   {printf("RelExpr -> RelExpr >= AddExpr\n");}
| RelExpr EQUALEQUAL AddExpr   {printf("RelExpr -> RelExpr == AddExpr\n");}
| RelExpr NOTEQUAL AddExpr   {printf("RelExpr -> RelExpr != AddExpr\n");}
| AddExpr        {printf("RelExpr -> AddExpr\n");}
;
AddExpr : AddExpr PLUS Term       {printf("AddExpr -> AddExpr + Term\n");}
| AddExpr MINUS Term       {printf("AddExpr -> AddExpr - Term\n");}
| Term   {printf("AddExpr -> Term\n");}
;
Term : Term TIMES Factor   {printf("Term -> Term * Factor\n");}
| Term DIV Factor        {printf("Term -> Term / Factor\n");}
| Term MOD Factor        {printf("Term -> Term %% Factor\n");}
| Factor         {printf("Term -> Factor\n");}
;
Factor : LEFT_PAREN Expr RIGHT_PAREN   {printf("Factor -> ( Expr )\n");}
| FuncCall       {printf("Factor -> FuncCall\n");}
| MINUS Factor     {printf("Factor -> - Factor\n");}
| Variable       {printf("Factor -> Variable\n");}
| Variable IncDec        {printf("Factor -> Variable IncDec\n");}
| IncDec Variable        {printf("Factor -> IncDec Variable\n");}
| NumberLiteral  {printf("Factor -> NumberLiteral\n");}
;
NumberLiteral:TINTEGER {printf("NumberLiteral -> %d\n", $1);}
|TREAL  {printf("NumberLiteral -> %.2f\n", $1);}
;
IncDec:PLUSPLUS      {printf("IncDec -> ++\n");}
|MINUSMINUS    {printf("IncDec -> --\n");}
;
WhileMatchedStmt : TWHILE LEFT_PAREN Expr RIGHT_PAREN MatchedStmt       {printf("WhileMatchedStmt -> TWHILE ( Expr ) MatchedStmt\n");}
;
WhileOpenStmt : TWHILE LEFT_PAREN Expr RIGHT_PAREN OpenStmt     {printf("WhileOpenStmt -> TWHILE ( Expr ) OpenStmt\n");}
;
DoWhileStmt : TDO Stmt TWHILE LEFT_PAREN Expr RIGHT_PAREN SEMICOLON   {printf("DoWhileStmt -> TDO Stmt TWHILE ( Expr ) ;\n");}
;
ForMatchedStmt : TFOR LEFT_PAREN Expr SEMICOLON Expr SEMICOLON Expr RIGHT_PAREN MatchedStmt         {printf("ForMatchedStmt -> TFOR ( Expr ; Expr ; Expr ) MatchedStmt\n");}
;
ForOpenStmt : TFOR LEFT_PAREN Expr SEMICOLON Expr SEMICOLON Expr RIGHT_PAREN OpenStmt       {printf("ForOpenStmt -> TFOR ( Expr ; Expr ; Expr ) OpenStmt\n");}
;
FuncCall : TIDENTIFIER LEFT_PAREN Arguments RIGHT_PAREN         {printf("FuncCall -> %s ( Arguments )\n",$1);}
;
Arguments : ArgumentList         {printf("Arguments -> ArgumentList\n");}
|        {printf("Arguments -> Empty\n");}
;
ArgumentList : ArgumentList COMMA Expr     {printf("ArgumentList -> ArgumentList , Expr\n");}
| ArgumentList COMMA STRING        {printf("ArgumentList -> ArgumentList , %s\n",$3);}
| Expr   {printf("ArgumentList -> Expr\n");}
| STRING         {printf("ArgumentList -> %s\n",$1);}
;
%%
int main(int argc, char* argv[]){
        extern FILE *yyin;
        yyin = fopen(argv[1], "r");
        yyparse();
        fclose(yyin);
        return 0;
}

int yyerror(char *s){
        printf("Parse error : %s\n", s);
        return 0;
}

