%option noyywrap

%x STRING_STATE
%x MSTRING_STATE
%x SINGLE_COMMENT_STATE
%x MULTI_COMMENT_STATE

%{

#include "bits/stdc++.h"
#include "1905077_main.h"
#include "y.tab.h"
extern YYSTYPE yylval; 

using namespace std;

int string_start;
extern int error_count ;
extern int line_count ;


string string_token;
string string_log;

string char_token;
string char_log;
int char_length;
bool multiline=false;
string comment;

void yyerror(char *);

extern FILE *log_output;
extern FILE *error_output;


char* toUpper(char *s){
    int i;
    char* u= new char;
    for (i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'a' && s[i] <= 'z') {
         u[i] = s[i]-32;
      } else u[i]=s[i];
   }
   return u;
}

   
%}

KEYWORD if|else|for|while|do|break|int|char|float|double|void|return|switch|case|default|continue
LETTER [A-Za-z]
DIGIT [0-9]
WHITESPACE [ \t\r\v\f]+
CONST_INT {DIGIT}+
CONST_FLOAT {DIGIT}*({DIGIT}\.?|\.{DIGIT}){DIGIT}*([Ee][-+]?{DIGIT}+)?
CONST_CHAR '([ -~]{-}['\\])'|'(\\[nt\\afrbv0\"])'
IDENTIFIER [_A-Za-z][A-Za-z0-9_]* 
NEWLINE \n
MULTI_CHAR_CONST_ERROR '((([ -~]{-}['\\])|(\\[nt\\afrbv0\"]))*)'
UC '(([ -~]{-}['\\])|(\\[nt\\afrbv0\"]))
UNTERMINATED_CHAR_ERROR {UC}|'[\\]'
EMPTY_CHAR ''
ADDOP [+-] 
MULOP [*/%]
%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

"if" {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"IF");
            s->setLeftPart("IF");
            s->setRightPart("if");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return IF;}
"else" {SymbolInfo* s= new  SymbolInfo(yytext, (char *)"ELSE");
            s->setLeftPart("ELSE");
            s->setRightPart("else");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;return ELSE;}
"for" {SymbolInfo* s= new  SymbolInfo(yytext, (char *)"FOR");
            s->setLeftPart("FOR");
            s->setRightPart("for");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return FOR;}
"while" {SymbolInfo* s= new  SymbolInfo(yytext, (char *)"WHILE");
            s->setLeftPart("WHILE");
            s->setRightPart("for");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return WHILE;}
"int" {SymbolInfo* s= new  SymbolInfo(yytext, (char *)"INT");
            s->setLeftPart("INT");
            s->setRightPart("int");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;return INT;}
"float" {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"FLOAT");
            s->setLeftPart("FLOAT");
            s->setRightPart("float");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;return FLOAT;}
"double" {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"DOUBLE");
            s->setLeftPart("DOUBLE");
            s->setRightPart("double");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;return DOUBLE;}
"char" {SymbolInfo* s= new  SymbolInfo(yytext, (char *)"CHAR");
            s->setLeftPart("CHAR");
            s->setRightPart("char");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;return CHAR;}
"return" {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"RETURN");
            s->setLeftPart("RETURN");
            s->setRightPart("return");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return RETURN;}
"void" {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"VOID");
            s->setLeftPart("VOID");
            s->setRightPart("void");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return VOID;}

"println"	{SymbolInfo* s= new  SymbolInfo(yytext, (char *)"PRINTLN");
            s->setLeftPart("PRINTLN");
            s->setRightPart("println");
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            return PRINTLN;}

{CONST_INT} {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"CONST_INT");
            s->setLeftPart("CONST_INT");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
	fprintf(log_output,"Line# %d: Token <CONST_INT> Lexeme %s found\n",line_count,yytext);  
    return CONST_INT;
 }

{CONST_FLOAT} {
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"CONST_FLOAT");
            s->setLeftPart("CONST_FLOAT");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
	fprintf(log_output,"Line# %d: Token <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
    return CONST_FLOAT;
 }
{CONST_INT}(\.{CONST_INT})+(\.{CONST_INT})+([Ee][+-]?{DIGIT}+)? {
    error_count++;
    fprintf(error_output,"Line# %d: TOO_MANY_DECIMAL_POINTS %s\n",line_count,yytext);
}
{CONST_FLOAT}+\.{CONST_INT} {
    error_count++;
	fprintf(error_output,"Line# %d: ILLFORMED_NUMBER %s\n",line_count,yytext);
}
{EMPTY_CHAR} {
    error_count++;
    fprintf(error_output,"Line# %d: EMPTY_CONST_CHAR %s\n",line_count,yytext);	

}


{CONST_CHAR} {
    char a;
        if(yytext[1] != '\\')
            a= yytext[1];
         else if(yytext[1] == '\\') {
            if(yytext[2] == 'n')
                a= (char)10;
            else if(yytext[2] == 't')
                a= (char)9;
            else if(yytext[2] == '\\')
                a= (char)92;
            else if(yytext[2] == '\'')
                a= (char)39;
            else if(yytext[2] == 'a')
                a= (char)7;
            else if(yytext[2] == 'f')
                a= (char)12;
            else if(yytext[2] == 'r')
                a= (char)13;
            else if(yytext[2] == 'b')
                a= (char)8;
            else if(yytext[2] == 'v')
                a= (char)11;
            else if(yytext[2] == '0')
                a= (char)0;
            else if(yytext[2] == '\"')
                a= (char)34;    
        }
    string res(yytext);
    //res(yytext);
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"CONST_CHAR");
            s->setLeftPart("CONST_CHAR");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    fprintf(log_output, "Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, a);
    return CHAR;
 
    
}



{IDENTIFIER} {
    SymbolInfo* s= new  SymbolInfo((string)yytext, "ID");
    s->setLeftPart("ID");
    s->setRightPart((string)yytext);
    s->setToken(true);
    s->setStart(line_count);
    s->setEnd(line_count);
    yylval.symbol =s;
    
    fprintf(log_output, "Line# %d: Token <ID> Lexeme %s found\n", line_count, yytext);
    return ID;
}
[0-9][A-Za-z0-9_]* {
    error_count++;
    fprintf(error_output,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n",line_count,yytext);

    }

{ADDOP} { 
			SymbolInfo* s= new  SymbolInfo(yytext, (char *)"ADDOP");
            s->setLeftPart("ADDOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
	        fprintf(log_output,"Line# %d: Token <ADDOP> Lexeme %s found\n",line_count,yytext);
			return ADDOP;
		}



{MULOP}	{
            SymbolInfo* s= new  SymbolInfo(yytext, (char *)"MULOP");
            s->setLeftPart("MULOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;         
	        fprintf(log_output,"Line# %d: Token <MULOP> Lexeme %s found\n",line_count,yytext);		
			return MULOP;
		}


"=" 	{
	fprintf(log_output,"Line# %d: Token <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"ASSIGNOP");
            s->setLeftPart("ASSIGNOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    return ASSIGNOP;}

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
            SymbolInfo* s= new  SymbolInfo(yytext, (char *)"RELOP");
            s->setLeftPart("RELOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
	    fprintf(log_output,"Line# %d: Token <RELOP> Lexeme %s found\n",line_count,yytext);
		return RELOP;
	}

"&&"	|
"||"	{   
             SymbolInfo* s= new  SymbolInfo(yytext, (char *)"LOGICOP");
            s->setLeftPart("LOGICOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
	        fprintf(log_output,"Line# %d: Token <LOGICOP> Lexeme %s found\n",line_count,yytext);
			return LOGICOP;
		}
"!"		{	
    fprintf(log_output,"Line# %d: Token <NOT> Lexeme %s found\n",line_count,yytext);
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"NOT");
            s->setLeftPart("NOT");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    return NOT; }


";" 	{ 
            SymbolInfo* s= new  SymbolInfo(yytext, (char *)"SEMICOLON");
            s->setLeftPart("SEMICOLON");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            fprintf(log_output,"Line# %d: Token <SEMICOLON> Lexeme %s found\n",line_count,yytext);
            return SEMICOLON;}
"," 	{
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"COMMA");
            s->setLeftPart("COMMA");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    fprintf(log_output,"Line# %d: Token <COMMA> Lexeme %s found\n",line_count,yytext);
    return COMMA;}
"(" 	{
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"LPAREN");
            s->setLeftPart("LPAREN");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    fprintf(log_output,"Line# %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext);
    return LPAREN;}
")" 	{
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"RPAREN");
            s->setLeftPart("RPAREN");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    fprintf(log_output,"Line# %d: Token <RPAREN> Lexeme %s found\n",line_count,yytext);
    return RPAREN;}
"{" 	{
    SymbolInfo* s= new  SymbolInfo(yytext, (char *)"LCURL");
            s->setLeftPart("LCURL");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
    fprintf(log_output,"Line# %d: Token <LCURL> Lexeme %s found\n",line_count,yytext);return LCURL;}
"}" 	{
            SymbolInfo* s= new  SymbolInfo(yytext, (char *)"RCURL");
            s->setLeftPart("RCURL");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            fprintf(log_output,"Line# %d: Token <RCURL> Lexeme %s found\n",line_count,yytext);return RCURL;}
"[" 	{SymbolInfo* s= new  SymbolInfo(yytext, (char *)"LTHIRD");
            s->setLeftPart("LTHIRD");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;
            fprintf(log_output,"Line# %d: Token <LTHIRD> Lexeme %s found\n",line_count,yytext);return LTHIRD;}
"]" 	{SymbolInfo* s= new  SymbolInfo(yytext, (char *)"RTHIRD");
            s->setLeftPart("RTHIRD");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;fprintf(log_output,"Line# %d: Token <RTHIRD> Lexeme %s found\n",line_count,yytext);return RTHIRD;}
"++" 	{SymbolInfo* s= new  SymbolInfo(yytext, (char *)"INCOP");
            s->setLeftPart("INCOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;fprintf(log_output,"Line# %d: Token <INCOP> Lexeme %s found\n",line_count,yytext);return INCOP;}
"--" 	{SymbolInfo* s= new  SymbolInfo(yytext, (char *)"DECOP");
            s->setLeftPart("DECOP");
            s->setRightPart((string)yytext);
            s->setToken(true);
            s->setStart(line_count);
            s->setEnd(line_count);
            yylval.symbol =s;fprintf(log_output,"Line# %d: Token <DECOP> Lexeme %s found\n",line_count,yytext);return DECOP;}



\"	{
    string_start=line_count;
    string_log.clear();
    string_log="\"";
	string_token.clear();
    multiline=false;

	BEGIN STRING_STATE;
}
<STRING_STATE>[\\][\\nfratbv0\'\"] {
	string newString=yytext;
	string_log+=newString;
	char ch;
    if(yytext[0]=='\\'){
		if(yytext[1]=='n') string_token+='\n';
		if(yytext[1]=='t') string_token+='\t';
		if(yytext[1]=='\\')string_token+='\\';
		if(yytext[1]=='\'')string_token+='\'';
		if(yytext[1]=='a') string_token+='\a';
		if(yytext[1]=='f') string_token+='\f';
		if(yytext[1]=='r') string_token+='\r';
		if(yytext[1]=='b') string_token+='\b';
		if(yytext[1]=='v') string_token+='\v';
		if(yytext[1]=='0') string_token+='\0';
		if(yytext[1]=='\"')string_token+='\"';
	}
	if(yytext[1]!= '\\'){
         ch=yytext[1];
    }
	else {
        if(yytext[1]=='\"')string_token+='\"';
		if(yytext[2]=='n') string_token+='\n';
		if(yytext[2]=='t') string_token+='\t';
		if(yytext[2]=='\\')string_token+='\\';
		if(yytext[2]=='\'')string_token+='\'';
		if(yytext[2]=='a') string_token+='\a';
		if(yytext[2]=='f') string_token+='\f';
		if(yytext[2]=='r') string_token+='\r';
		if(yytext[2]=='b') string_token+='\b';
		if(yytext[2]=='v') string_token+='\v';
		if(yytext[2]=='0') string_token+='\0';
		
	}
		
}




<STRING_STATE>\\\r\n         { 
	
    line_count++;
	string_log += "\\\r\n" ;
    multiline=true;
    
	
}
<STRING_STATE>\\\n         { 
	
    line_count++;

	string_log += "\\\n" ;
    multiline=true;
	
}
<STRING_STATE>[\r]?\n { 
		line_count++;
		error_count++;
        fprintf(error_output,"Error at line# %d: UNFINISHED_STRING %s\n",string_start,string_log.c_str());
		BEGIN(INITIAL);
	}
<STRING_STATE><<EOF>> { 
		error_count++;
        fprintf(error_output,"Error at line# %d: UNFINISHED_STRING %s\n",string_start,string_log.c_str());	 
		BEGIN(INITIAL);
	}

<STRING_STATE>\" {
        string_log+="\"";
        if(multiline==false){
        //fprintf(token_output,"<SINGLE LINE STRING, %s>\n",string_token.c_str());
        //fprintf(log_output,"Line# %d: Token <SINGLE LINE STRING> Lexeme %s found\n",line_count,string_log.c_str());
        }
        else{

       // fprintf(token_output,"<MULTI LINE STRING, %s>\n",string_token.c_str());
        //fprintf(log_output,"Line# %d: Token <MULTI LINE STRING> Lexeme %s found\n",string_start,string_log.c_str());
        }

		BEGIN(INITIAL);
}

<STRING_STATE>. {
    string_token += yytext[0]; string_log+= yytext[0];
}

\/\/ {

    comment = "//";
    string_start=line_count;  
    BEGIN SINGLE_COMMENT_STATE;
}

<SINGLE_COMMENT_STATE>[\r]?\n  {

    line_count++;
    //fprintf(log_output,"Line# %d: Token <SINGLE LINE COMMENT> Lexeme %s found\n",string_start,comment.c_str());
    BEGIN INITIAL;
}

<SINGLE_COMMENT_STATE><<EOF>> {
    error_count++;  
	fprintf(error_output,"Error at line# %d: UNFINISHED_COMMENT %s\n",string_start,comment.c_str());	
	BEGIN INITIAL;
}

<SINGLE_COMMENT_STATE>\\[\r]?\n {
    line_count++;
    comment+=yytext;
}

<SINGLE_COMMENT_STATE>. {
    comment+=yytext[0];
}

\/\* {

    comment = "/*";
    string_start=line_count;  
    BEGIN MULTI_COMMENT_STATE;
}
<MULTI_COMMENT_STATE>\*\/ {

    comment+="*/";
    //fprintf(log_output,"Line# %d: Token <MULTI LINE COMMENT> Lexeme %s found\n",string_start,comment.c_str());
    BEGIN INITIAL;
}

<MULTI_COMMENT_STATE><<EOF>> {
    error_count++;  
	//fprintf(log_output,"Error at line# %d: UNFINISHED_COMMENT  %s\n",line_count,comment.c_str());	
	BEGIN INITIAL;
}

<MULTI_COMMENT_STATE>\n {
    comment+="\n";
    line_count++;
}
<MULTI_COMMENT_STATE>\r {
    comment+="\r";
}
<MULTI_COMMENT_STATE>. {
    comment+=yytext[0];
}

{MULTI_CHAR_CONST_ERROR} {
    error_count++;
    fprintf(error_output,"Error at line# %d: MULTICHAR_CONST_CHAR %s\n",line_count,yytext);	

}

{UNTERMINATED_CHAR_ERROR} {
    error_count++;
    fprintf(error_output,"Error at line# %d: UNFINISHED_CONST_CHAR %s\n",line_count,yytext);	

}
. {
    error_count++;
	fprintf(error_output,"Error at line# %d: UNRECOGNIZED_CHAR %s\n",line_count,yytext);

}
<INITIAL><<EOF>> {

	//string allScope;
	//allScope=symbolTable.printAllScopeTable(); 
	//fprintf(log_output,"%s",allScope.c_str());
    //fprintf(log_output,"Total lines: %d\n", line_count);	
    //fprintf(log_output,"Total errors: %d\n", error_count);	
    return 0;

}

%%
