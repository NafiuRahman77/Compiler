%option noyywrap

%x STRING_STATE
%x MSTRING_STATE
%x SINGLE_COMMENT_STATE
%x MULTI_COMMENT_STATE

%{

#include "bits/stdc++.h"
#include "1905077_main.h"
#include "y.tab.h"

using namespace std;

int string_start;
int error_count = 0;
int line_count = 1;

string string_token;
string string_log;

string char_token;
string char_log;
int char_length;
bool multiline=false;
string comment;

extern YYSTYPE yylval;
extern SymbolTable table;
void yyerror(char *);

extern FILE *log_output;
extern FILE *error_output;

int bucket_size = 10;
SymbolTable symbolTable(bucket_size);


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
NEWLINE \r?\n
MULTI_CHAR_CONST_ERROR '((([ -~]{-}['\\])|(\\[nt\\afrbv0\"]))*)'
UC '(([ -~]{-}['\\])|(\\[nt\\afrbv0\"]))
UNTERMINATED_CHAR_ERROR {UC}|'[\\]'
EMPTY_CHAR ''
ADDOP [+-] 
MULOP [*/%]
%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}

"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"main"	{return MAIN;}
"println"	{return PRINTLN;}

{CONST_INT} {
    SymbolInfo* symbolInfo = new  SymbolInfo(yytext, "CONST_INT");
    yylval = (YYSTYPE) symbolInfo;
    return CONST_INT;
 }

{CONST_FLOAT} {
    SymbolInfo* symbolInfo = new  SymbolInfo(yytext, "CONST_FLOAT");
    yylval = (YYSTYPE) symbolInfo;
    return CONST_FLOAT;
 }
{CONST_INT}(\.{CONST_INT})+(\.{CONST_INT})+([Ee][+-]?{DIGIT}+)? {
    error_count++;
    fprintf(error_output,"Error at line# %d: TOO_MANY_DECIMAL_POINTS %s\n",line_count,yytext);
}
{CONST_FLOAT}+\.{CONST_INT} {
    error_count++;
	fprintf(error_output,"Error at line# %d: ILLFORMED_NUMBER %s\n",line_count,yytext);
}
{EMPTY_CHAR} {
    error_count++;
    fprintf(error_output,"Error at line# %d: EMPTY_CONST_CHAR %s\n",line_count,yytext);	

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
    SymbolInfo* symbolInfo = new  SymbolInfo(yytext, "CONST_CHAR");
    yylval = (YYSTYPE) symbolInfo;
    return CONST_CHAR;
 
    
}



{IDENTIFIER} {
    SymbolInfo* symbolInfo = new  SymbolInfo(yytext, "ID");
    yylval = (YYSTYPE) symbolInfo;
    return ID;
}
[0-9][A-Za-z0-9_]* {
    error_count++;
    fprintf(error_output,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n",line_count,yytext);

    }

{ADDOP} { 
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}



{MULOP}	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
		}


"=" 	{return ASSIGNOP;}

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
		SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;
	}

"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}
"!"		{	return NOT; }


";" 	{ return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}



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
