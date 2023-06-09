%{
#include <stdio.h>
#include <stdlib.h>
union {
    int iVal;
    char* sVal;
    double rVal;
} yylval;
enum tnumber    {TEOF,TKEYWORD,TIDENTIFIER,TCHAR_CONSTANT,TINTEGER_CONSTANT,TREAL_CONSTANT,TSTRING_CONSTANT,TOPERATOR,TOCT,THEX,TCOMMENT,TPUNCTUATION,TERROR};
const char* tokenType[] = {"Unknown","Char", "Integer", "Real", "String", "Operator", "Punctuation","Identifier", "Keyword", "Comment", "Error"};
%}
LETTER  [A-Za-z_]
DIGIT   [0-9]
KEYWORD break|case|char|default|do|else|float|for|if|int|return|switch|void|while

STRING_CONSTANT \"([^\"\n]|(\\\\\")|(\\\\n)|(\\\\t)|(\\\\\\')|(\\\\\\\\))*\"
CHAR_CONSTANT \'([^\'\n]|(\\\\\')|(\\\\n)|(\\\\t)|(\\\\\\')|(\\\\\\\\))*\'


INTEGER_CONSTANT        0|(0[xX][0-9a-fA-F]+)|(0[0-7]+)|([1-9][0-9]*)
REAL_CONSTANT {DIGIT}*\.?{DIGIT}+([eE][+-]?{DIGIT}+)?[Ff]?
WS      [ \t\n]+
SINGLE_COMMENT  \/\/[^\n]*
MULTI_COMMENT   \/\*([^*]|\*+[^*/])*\*+\/
OPERATOR        [-+*/%!]|[=<>]=?|\+{2}|-{2}|[&|]{2}|\+\+|\-\-|\+\=|\-\=|\*\=|\/\=|\%\=|,               
PUNCTUATION     [(){}\[\];:]
%%

{WS}    {}
{KEYWORD}       {return TKEYWORD;}
{LETTER}({LETTER}|{DIGIT})*     {return TIDENTIFIER;}
{CHAR_CONSTANT}         {return TCHAR_CONSTANT;}
{INTEGER_CONSTANT}      {return TINTEGER_CONSTANT;}
{STRING_CONSTANT}       {return TSTRING_CONSTANT;}
{SINGLE_COMMENT}        {return TCOMMENT;}
{MULTI_COMMENT} {return TCOMMENT;}
{OPERATOR}      {return TOPERATOR;}
{PUNCTUATION}   {return TPUNCTUATION;}
{REAL_CONSTANT} {return TREAL_CONSTANT;}
.       {return TERROR;}



%%
int main(int argc,char* argv[]) {
        enum tnumber tn;
        if(!argc)       exit(0);
        yyin = fopen(argv[1], "r");
        while((tn=yylex())!=TEOF){
                switch(tn){
                case TINTEGER_CONSTANT:
                        yylval.iVal = strtol(yytext, NULL, 0);
 if (yytext[0] == '0') {
                        if (yytext[1] == 'x' || yytext[1] == 'X') {
                                yylval.iVal=strtol(yytext,NULL,16);
                                printf("%-15s:%19s,%5d\n", yytext, tokenType[2], yylval.iVal);
                        }else {
                                yylval.iVal=strtol(yytext,NULL,8);
                                printf("%-15s:%19s,%5d\n", yytext, tokenType[2], yylval.iVal);
                        }
                } else {
                        yylval.iVal = atoi(yytext);
                        printf("%-15s:%19s,%d\n", yytext, tokenType[2], yylval.iVal);
                }
                        break;
                case TCHAR_CONSTANT :
                        if (*(yytext + 1) != '\\') {
        yylval.iVal = *(yytext + 1);
    } else {
        switch (*(yytext + 2)) {
            case 'n':
                yylval.iVal = '\n';
                break;
            case 't':
                yylval.iVal = '\t';
                break;
            case 'r':
                yylval.iVal = '\r';
                break;
            case 'f':
                yylval.iVal = '\f';
                break;
            case 'a':
                yylval.iVal = '\a';
                break;
            case 'b':
                yylval.iVal = '\b';
                break;
            case '\\':
                yylval.iVal = '\\';
                break;
            case '\'':
                yylval.iVal = '\'';
                break;
            case '\"':
                yylval.iVal = '\"';
                break;
            case '0':
                yylval.iVal = '\0';
                break;
            case 'v':
                yylval.iVal = '\v';
                break;
            default:
                break;
        }
    }
 printf("%-15s:%19s,%5d\n",yytext,tokenType[2],yylval.iVal);
                        break;
                case TREAL_CONSTANT :
                        yylval.rVal=atof(yytext);
                        printf("%-15s:%19s,%5.2f\n",yytext,tokenType[3],yylval.rVal);
                        break;
                case TSTRING_CONSTANT :
                       {

        int len = yyleng - 2;
            char *str = (char*) malloc(len + 1);
        char *ptr = str;
        char *end = yytext + yyleng - 1;

        for (char *c = yytext + 1; c < end - 1; ++c) {
                if (*c == '\\') {
                ++c;
            switch (*c) {
                case 'n':
                    *ptr++ = '\n';
                    break;
                case 't':
                    *ptr++ = '\t';
                    break;
                case 'r':
                    *ptr++ = '\r';
                    break;
                case 'b':
                    *ptr++ = '\b';
                    break;
                case 'v':
                    *ptr++ = '\v';
                    break;
                case 'f':
                    *ptr++ = '\f';
                    break;
                case 'a':
                    *ptr++ = '\a';
                    break;
                case '0':
                    *ptr++ = '\0';
                    break;
                default:
                    *ptr++ = *c;
            }
        } else {
            *ptr++ = *c;
        }
    }

    *ptr = '\0';
    yylval.sVal = str;
    printf("%-15s:%19s,%s\n",yytext,tokenType[4],yylval.sVal);
    break;
}
                case TOPERATOR :
                        printf("%-15s:%19s\n",yytext,tokenType[5]);
                        break;
                case TPUNCTUATION :
                        printf("%-15s:%19s\n",yytext,tokenType[6]);
                        break;
                case TIDENTIFIER :
                        printf("%-15s:%19s\n",yytext,tokenType[7]);
                        break;
                case TKEYWORD :
                        printf("%-15s:%19s\n",yytext,tokenType[8]);
                        break;
                case TCOMMENT :
                        printf("%-15s:%19s\n",yytext,tokenType[9]);
                        break;
                case TERROR :
                        printf("Error occured\n");
                        return 0;
                default :
                        printf("%-15s:%19s\n",yytext,tokenType[0]);
                        break;
                }

        }
        fclose(yyin);
        return 0;
}

