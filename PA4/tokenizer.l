%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
const char* tokenType[] = {"Unknown","Char", "Integer", "Real", "String", "Operator", "Punctuation","Identifier", "Keyword", "Comment", "Error"};
%}
LETTER  [A-Za-z_]
DIGIT   [0-9]
STRING_CONSTANT \"([^\\\'\"\n]|\\[abfnrtv0\\\'\"\?])*\"
CHAR_CONSTANT	\'\\[abfnrtv0\\\'\"\?]\'|\'[^\\\'\"\n]\'
KEYWORD break|case|char|default|do|else|float|for|if|int|return|switch|void|while

INTEGER_CONSTANT        0|(0[xX][0-9a-fA-F]+)|(0[0-7]+)|([1-9][0-9]*)
REAL_CONSTANT	(([0-9]*\.[0-9]+)|([0-9]+\.)|(([0-9]*\.[0-9]+)|([0-9]+\.))(e|E)([\+\-][0-9]+|[0-9]+))[Ff]  

WS      [ \t\n]+
SINGLE_COMMENT  \/\/[^\n]*\n
MULTI_COMMENT   \/\*([^\*]|\*+[^\*\/])*\*+\/

%%

{WS}    {}
if      {return TIF;}
while {return TWHILE;}
int   {return TINT;}
char  {return TCHAR;}
float {return TFLOAT;}
else     {return TELSE;}
for   {return TFOR;}
switch {return TSWITCH;}
case  {return TCASE;}
break {return TBREAK;}
do    {return TDO;}
default {return TDEFAULT;}
return {return TRETURN;}
void  {return TVOID;}
{LETTER}({LETTER}|{DIGIT})*   {yylval.sVal=strdup(yytext);	return TIDENTIFIER; }
{REAL_CONSTANT} {yylval.rVal=atof(yytext);return TREAL;}
{STRING_CONSTANT}       {yylval.sVal=strdup(yytext+1); return STRING;}
{CHAR_CONSTANT}         {yylval.sVal=strdup(yytext+1);return TCHAR;}
{INTEGER_CONSTANT}      {yylval.iVal=atoi(yytext);	return TINTEGER;}

\+\+    {return PLUSPLUS;}
\-\-    {return MINUSMINUS; }
\+=    {return PLUSEQUAL;}
\-=    {return MINUSEQUAL;}
\/=    {return DIVEQUAL;}
\*=    {return TIMESEQUAL;}
\%=    {return MODEQUAL;}
\=\=     { return EQUALEQUAL; }
\!\=     { return NOTEQUAL; }
\<=     { return LESSEQUAL; }
\>=     { return GREATEREQUAL; }
&&     { return LOGICALAND; }
\|\|     { return LOGICALOR; }
\<      {return LESS;}
\>      {return GREAT;}
\+      { return PLUS; }
\-      { return MINUS; }
\*      { return TIMES; }
\/      { return DIV; }
\%      { return MOD; }
\=      { return EQUAL; }
\;      { return SEMICOLON;  }
\(      { return LEFT_PAREN;  }
\)      { return RIGHT_PAREN;  }
\{      { return LEFT_BRACE;  }
\}      { return RIGHT_BRACE; }
\[      { return LEFT_BRACKET; }
\]      { return RIGHT_BRACKET;  }
\:      { return COLON; }
\,      { return COMMA;  }
.       {return TERROR;}
%%
      
