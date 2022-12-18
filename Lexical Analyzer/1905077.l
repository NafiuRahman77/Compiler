%option noyywrap
%{

#include "bits/stdc++.h"
#include "1905077_main.h"

using namespace std;

int global_line_count = 1;
int error_count = 0;
int line_count = 0;

string string_token;
string string_log;

string char_token;
string char_log;
int char_length;
string comment;

ofstream logout;
ofstream tokenout;


int bucket_size = 7;
SymbolTable symbolTable(bucket_size);

int lineCount = 0;

string toUpper(string s){
    for(auto &c:s) c = toupper(c);
    return s;
}
char processChar(const char* s){
   // '(\\[nt\\afrbv0\"])'
    if( strlen(s) == 3 ) return s[1];
    if( s[2] == 'n' ) return '\n';
    if( s[2] == 't' ) return '\t';
    if( s[2] == '\\' ) return '\\';
    if( s[2] == 'a' ) return '\a';
    if( s[2] == 'f' ) return '\f';
    if( s[2] == 'r' ) return '\r';
    if( s[2] == 'b' ) return '\b';
    if( s[2] == 'v' ) return '\v';
    if( s[2] == '0' ) return '\0';
    if( s[2] == '\"' ) return '\"';
}
%}

KEYWORD if|for|do|int|float|void|switch|default|else|while|break|char|double|return|case|continue
LETTER [A-Za-z]
DIGIT [0-9]
WHITESPACE [ \t\r\v\f]+
CONST_INT {DIGIT}+
CONST_FLOAT {DIGIT}*({DIGIT}\.?|\.{DIGIT}){DIGIT}*([Ee][-+]?{DIGIT}+)?
SPECIAL_CHAR '(\\[nt\\\'\"afrbv0'])'
CHAR '([ -~]{-}['\\])'
CONST_CHAR {SPECIAL_CHAR}|{CHAR}
%%

{WHITESPACE} {}

{NEWLINE} {lineCount++;}

{KEYWORD} {
    tokenout<<"<"<<toUpper(yytext)<<"> ";
    logout<<"Line# "<< global_line_count <<": Token " <<"<"<<toUpper(yytext)<< ">"<<" Lexeme "<<yytext<<" found\n"<<endl;
 }
 CONST_INT{
    tokenout<<"<CONST_INT, "<<yytext<<"> ";
    logout<<"Line# "<< global_line_count <<": Token " <<"<CONST_INT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
	bool inserted = symbolTable.insertSymbol(SymbolInfo(yytext,"CONST_INT"),logout);
    if( inserted ) symbolTable.printAllScopeTable(logout);
 }

 {CONST_FLOAT} {
    tokenout<<"<CONST_FLOAT, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<CONST_FLOAT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
    bool inserted = symbolTable.insertSymbol(SymbolInfo(yytext,"CONST_FLOAT"),logout);
    if( inserted ) symbolTable.printAllScopeTable(logout);
 }
{CONST_INT}(\.{CONST_INT})(\.{CONST_INT})+ {
    error_count++;
    logout<<"Error at line no "<< global_line_count <<": Too many decimal points "<<yytext<<"\n"<<endl;
}
{CONST_FLOAT}+\.{CONST_INT} {
    error_count++;
	logout<<"Error at line no "<< global_line_count <<": Ill formed number "<<yytext<<"\n"<<endl;
}

[_A-Za-z][A-Za-z0-9_]* {
    tokenout<<"<ID, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<ID>"<<" Lexeme "<<yytext<<" found\n"<<endl;
	bool inserted = symbolTable.insertSymbol(SymbolInfo(yytext,"ID"),logout);
    if( inserted ) symbolTable.printAllScopeTable(logout);

}
[0-9][A-Za-z0-9_]* {
    error_count++;
    logout<<"Error at line no "<<global_line_count<<": Invalid prefix on ID or invalid suffix on Number "<<yytext<<"\n"<<endl;
}
"+"|"-" {
    tokenout<<"<ADDOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<ADDOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"*"|"/"|"%"  {
    tokenout<<"<MULOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<MULOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"++"|"--"  {
    tokenout<<"<INCOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<INCOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"<"|"<="|">"|">="|"=="|"!="  {
    tokenout<<"<RELOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<RELOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"="  {
    tokenout<<"<ASSIGNOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<ASSIGNOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"&&"|"||"  {
    tokenout<<"<LOGICOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<LOGICOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"&"|"|"|"^"|"<<"|">>" {
    tokenout<<"<BITOP, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<LOGICOP>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"!"  {
    tokenout<<"<NOT, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<NOT>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"("  {
    tokenout<<"<LPAREN, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<LPAREN>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
")"  {
    tokenout<<"<RPAREN, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<RPAREN>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"{"  {
    tokenout<<"<LCURL, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<LCURL>"<<" Lexeme "<<yytext<<" found\n"<<endl;
    //symbolTable.enterScope();
}
"}"  {
    tokenout<<"<RCURL, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<RCURL>"<<" Lexeme "<<yytext<<" found\n"<<endl;
   // symbolTable.exitScope();
}
"["  {
    tokenout<<"<LSQUARE, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<LTHIRD>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
"]"  {
    tokenout<<"<RSQUARE, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<RTHIRD>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
","  {
    tokenout<<"<COMMA, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<COMMA>"<<" Lexeme "<<yytext<<" found\n"<<endl;
}
";"  {
    tokenout<<"<SEMICOLON, "<<yytext<<"> ";
    logout<<"Line no "<< global_line_count <<": Token " <<"<SEMICOLON>"<<" Lexeme "<<yytext<<" found\n"<<endl;
} 