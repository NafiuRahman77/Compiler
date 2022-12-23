%option noyywrap

%x STRING_STATE
%x MSTRING_STATE
%x SINGLE_COMMENT_STATE
%x MULTI_COMMENT_STATE

%{

#include "bits/stdc++.h"
#include "1905077_main.h"

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

FILE *log_output;
FILE *token_output;

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
%%

{WHITESPACE} {}

{NEWLINE} {line_count++;}
{KEYWORD} {
    char* str=toUpper(yytext);

    fprintf(token_output,"<%s, %s>\n",str, yytext);
	fprintf(log_output,"Line# %d: Token <%s> Lexeme %s found\n",line_count,str,yytext);
 }
{CONST_INT} {
    fprintf(token_output,"<CONST_INT, %s>\n", yytext);
	fprintf(log_output,"Line# %d: Token <CONST_INT> Lexeme %s found\n",line_count,yytext);
	
	
 }

{CONST_FLOAT} {
    fprintf(token_output,"<CONST_FLOAT, %s>\n", yytext);
	fprintf(log_output,"Line# %d: Token <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);

	
 }
{CONST_INT}(\.{CONST_INT})+(\.{CONST_INT})+([Ee][+-]?{DIGIT}+)? {
    error_count++;
    fprintf(log_output,"Error at line# %d: TOO_MANY_DECIMAL_POINTS %s\n",line_count,yytext);
}
{CONST_FLOAT}+\.{CONST_INT} {
    error_count++;
	fprintf(log_output,"Error at line# %d: ILLFORMED_NUMBER %s\n",line_count,yytext);
}
{EMPTY_CHAR} {
    error_count++;
    fprintf(log_output,"Error at line# %d: EMPTY_CONST_CHAR %s\n",line_count,yytext);	

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

    fprintf(token_output, "<CONST_CHAR, %c>\n",a);
    fprintf(log_output, "Line# %d: Token <CONST_CHAR> Lexeme %c found\n", line_count, a);
 
    
}



{IDENTIFIER} {
    fprintf(token_output, "<ID, %s>\n", yytext);
    fprintf(log_output, "Line# %d: Token <ID> Lexeme %s found\n", line_count, yytext);
    string name= yytext;
    bool flag=symbolTable.insertSymbol(name,"ID");
	if(flag){
		string allScope;
		allScope=symbolTable.printAllScopeTable(); 
		fprintf(log_output,"%s",allScope.c_str());
	}
	else{
		fprintf(log_output,"\t%s already exisits in the current ScopeTable\n",yytext);
	}
}
[0-9][A-Za-z0-9_]* {
    error_count++;
    fprintf(log_output,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n",line_count,yytext);

    }
"+"|"-" {
	fprintf(token_output,"<ADDOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <ADDOP> Lexeme %s found\n",line_count,yytext);
}

"*"|"/"|"%" {
	fprintf(token_output,"<MULOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <MULOP> Lexeme %s found\n",line_count,yytext);
}

"++"|"--" {
	fprintf(token_output,"<INCOP, %s> \n",yytext);
	fprintf(log_output,"Line# %d: Token <INCOP> Lexeme %s found\n",line_count,yytext);
}

"<"|"<="|">"|">="|"=="|"!=" {
	fprintf(token_output,"<RELOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <RELOP> Lexeme %s found\n",line_count,yytext);
}
"&"|"|"|"^"|"<<"|">>" {
	fprintf(token_output,"<BITOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <BITOP> Lexeme %s found\n",line_count,yytext);
}

"=" {
	fprintf(token_output,"<ASSIGNOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
}

"&&"|"||" {
	fprintf(token_output,"<LOGICOP, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <LOGICOP> Lexeme %s found\n",line_count,yytext);
}

"!" {
	fprintf(token_output,"<NOT, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <NOT> Lexeme %s found\n",line_count,yytext);
}

"(" {
	fprintf(token_output,"<LPAREN, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext);
    
}

")" {
	fprintf(token_output,"<RPAREN, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <RPAREN> Lexeme %s found\n",line_count,yytext);
    
}

"{" { 
	// scope
	fprintf(token_output,"<LCURL, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <LCURL> Lexeme %s found\n",line_count,yytext);
	symbolTable.enterScope();
}

"}" {
	// scope
	fprintf(token_output,"<RCURL, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <RCURL> Lexeme %s found\n",line_count,yytext);
	symbolTable.exitScope();
}

"[" {
	fprintf(token_output,"<LSQUARE, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <LSQUARE> Lexeme %s found\n",line_count,yytext);
}

"]" {
	fprintf(token_output,"<RSQUARE, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <RSQUARE> Lexeme %s found\n",line_count,yytext);
}

"," {
	fprintf(token_output,"<COMMA, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <COMMA> Lexeme %s found\n",line_count,yytext);
}

";" {
	fprintf(token_output,"<SEMICOLON, %s>\n",yytext);
	fprintf(log_output,"Line# %d: Token <SEMICOLON> Lexeme %s found\n",line_count,yytext);
}

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
    multiline=true;  // BEGIN MSTRING_STATE;
    
	
}
<STRING_STATE>\\\n         { 
	
    line_count++;

	string_log += "\\\n" ;
    multiline=true;
    //BEGIN MSTRING_STATE;
	
}
<STRING_STATE>[\r]?\n { 
		line_count++;
		error_count++;
        fprintf(log_output,"Error at line# %d: UNFINISHED_STRING %s\n",string_start,string_log.c_str());
		BEGIN(INITIAL);
	}
<STRING_STATE><<EOF>> { 
		error_count++;
        fprintf(log_output,"Error at line# %d: UNFINISHED_STRING %s\n",string_start,string_log.c_str());	 
		BEGIN(INITIAL);
	}

<STRING_STATE>\" {
        string_log+="\"";
        if(multiline==false){
        fprintf(token_output,"<SINGLE LINE STRING, %s>\n",string_token.c_str());
        fprintf(log_output,"Line# %d: Token <SINGLE LINE STRING> Lexeme %s found\n",line_count,string_log.c_str());
        }
        else{

        fprintf(token_output,"<MULTI LINE STRING, %s>\n",string_token.c_str());
        fprintf(log_output,"Line# %d: Token <MULTI LINE STRING> Lexeme %s found\n",string_start,string_log.c_str());
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
    fprintf(log_output,"Line# %d: Token <SINGLE LINE COMMENT> Lexeme %s found\n",string_start,comment.c_str());
    BEGIN INITIAL;
}

<SINGLE_COMMENT_STATE><<EOF>> {
    error_count++;  
	fprintf(log_output,"Error at line# %d: UNFINISHED_COMMENT %s\n",string_start,comment.c_str());	
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
    fprintf(log_output,"Line# %d: Token <MULTI LINE COMMENT> Lexeme %s found\n",string_start,comment.c_str());
    BEGIN INITIAL;
}

<MULTI_COMMENT_STATE><<EOF>> {
    error_count++;  
	fprintf(log_output,"Error at line# %d: UNFINISHED_COMMENT  %s\n",line_count,comment.c_str());	
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
    fprintf(log_output,"Error at line# %d: MULTICHAR_CONST_CHAR %s\n",line_count,yytext);	

}

{UNTERMINATED_CHAR_ERROR} {
    error_count++;
    fprintf(log_output,"Error at line# %d: UNFINISHED_CONST_CHAR %s\n",line_count,yytext);	

}
. {
    error_count++;
	fprintf(log_output,"Error at line# %d: UNRECOGNIZED_CHAR %s\n",line_count,yytext);

}
<INITIAL><<EOF>> {

	string allScope;
	allScope=symbolTable.printAllScopeTable(); 
	fprintf(log_output,"%s",allScope.c_str());
    fprintf(log_output,"Total lines: %d\n", line_count);	
    fprintf(log_output,"Total errors: %d\n", error_count);	
    return 0;

}

%%

int main(int argc, char *argv[])    
{
    if(argc!=2) {
        printf("PLease gib input file name \n");
        return 0;
    }

    FILE *file_in = fopen(argv[1], "r");
    if(file_in==NULL){
        printf("Cannot open file\n");
        return 0;
    }

    log_output = fopen("1905077_log.txt", "w");
    token_output = fopen("1905077_token.txt", "w");

    yyin = file_in;
    yylex();
    fclose(yyin);
    fclose(token_output);
    fclose(log_output);
    return 0;
}