%{
#include "bits/stdc++.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1905077_main.h"
#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp, *log_output, *error_output;
extern int line_count;
extern int error_count;

SymbolTable table;
vector<SymbolInfo*> params;


void yyerror(char *s)
{
	//write your code
}

vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

bool compareTypes(vector<SymbolInfo*> v1, vector<SymbolInfo*> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i]->getType() != v2[i]->getType())
        {
            return false;
        }
    }
    return true;
}


%}



%union{
	SymbolInfo* symbol;
}

%token IF ELSE FOR WHILE INT FLOAT DOUBLE CHAR RETURN VOID PRINTLN DO BREAK SWITCH CASE DEFAULT CONTINUE ASSIGNOP NOT SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP
%token <symbol> ID ADDOP MULOP RELOP LOGICOP CONST_INT CONST_FLOAT
%type <symbol> declaration_list type_specifier var_declaration unit program func_declaration func_definition parameter_list factor variable expression logic_expression argument_list arguments rel_expression simple_expression term unary_expression statement statements compound_statement expression_statement

%left 
%right

%nonassoc 


%%

start : program
	{
		//write your code in this block in all the similar blocks below

		fprintf(log_output, "Line %d: start : program\n\n", line_count);
	}
	;

program : program unit{
	    $$ = new SymbolInfo($1->getName()+"\n"+$2->getName(),"program");
		fprintf(log_output, "Line %d: program : program unit\n\n%s\n\n\n", line_count, $$->getName().c_str());
	} 
	| unit{
		$$ = $1;
		fprintf(log_output, "Line %d: program : unit\n\n%s\n\n\n", line_count, $$->getName().c_str());
	}
	;
	
unit : var_declaration{

		$$ = $1;
		fprintf(log_output, "Line %d: unit : var_declaration\n\n%s\n\n\n", line_count, $$->getName().c_str());
	}
     | func_declaration{

		$$ = $1;
		fprintf(log_output, "Line %d: unit : func_declaration\n\n%s\n\n\n", line_count, $$->getName().c_str());
	 }
     | func_definition{

		$$ = $1;
		fprintf(log_output, "Line %d: unit : func_definition\n\n%s\n\n\n", line_count, $$->getName().c_str());
	 }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON{
			string returnType = $1->getName();
			string funcName = $2->getName();
			SymbolInfo* temp = table.lookUpSymbol(funcName);
			vector<string> paramPair = split($4->getName(), ",");
			vector<string> paramTypeList;
    		vector<string> typeAndName;

    		for (string currentParam: paramPair)
    		{
        		typeAndName = split(currentParam, " ");
        		paramTypeList.push_back(typeAndName[0]);
    		}

			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Error at line %d: Multiple declaration of function %s\n\n", line_count, funcName.c_str());
				fprintf(log_output, "Error at line %d: Multiple declaration of function %s\n\n", line_count, funcName.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
				for (string paramType: paramTypeList) {	
					paramList.push_back(make_pair(" ", paramType));
				}

				SymbolInfo* temp=new SymbolInfo(funcName, funcType, paramList);
			    temp->setDefined(false);
				table.insertSymbol(temp);
			}
			table.enterScope();table.exitScope(); // dummy scope for declaration
			$$ = new SymbolInfo($1->getName()+" "+$2->getName()+"("+$4->getName()+");","func_declaration");
			fprintf(log_output, "Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n%s\n\n\n", line_count, $$->getName().c_str());
}
		| type_specifier ID LPAREN RPAREN SEMICOLON{
			string returnType = $1->getName();
			string funcName = $2->getName();
			SymbolInfo* temp = table.lookUpSymbol(funcName);
			
			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Error at line %d: Multiple declaration of function %s\n\n", line_count, funcName.c_str());
				fprintf(log_output, "Error at line %d: Multiple declaration of function %s\n\n", line_count, funcName.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
				
				SymbolInfo* temp=new SymbolInfo(funcName, funcType, paramList);
			    temp->setDefined(false);
				table.insertSymbol(temp);
			}
			table.enterScope();table.exitScope(); // dummy scope for declaration
			$$ = new SymbolInfo($1->getName()+" "+$2->getName()+"("+$4->getName()+");","func_declaration");
			fprintf(log_output, "Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n%s\n\n\n", line_count, $$->getName().c_str());
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN{
	 string functionType = $1->getName();
     string functionName = $2->getName();
	 vector<pair<string,string>> parameterList;
     vector<string> paramPair = split($4->getSymbolName(), ",");
     vector<string> typeAndName;

    for (string currentParam: paramPair)
    {
        typeAndName = split(currentParam, " ");
        pair<string,string> p(typeAndName[1], typeAndName[0]);
        parameterList.push_back(p);
    }

    SymbolInfo* currentFunction = symbolTable->lookupSymbol(functionName);
	
	if(currentFunction!=nullptr){
		
		if(currentFunction->isFunction()){
			if (currentFunction->isDefined()) // Declared and Defined
				{
					error_count++;

						fprintf(error_output, "Error at line %d: Multiple definition of function %s\n\n", line_count, functionName.c_str());
						fprintf(logout, "Error at line %d: Multiple definition of function %s\n\n", line_count, functionName.c_str());
				}
				else{
					vector<pair<string,string>> declaredList=currentFunction->getParameterList();
					if(parameterList.size()!=currentFunction->getParameterListSize()){
						error_count++;
						fprintf(error_output, "Error at line %d: Total number of arguments mismatch with declaration in function %s\n\n", line_count, functionName.c_str());
						fprintf(log_output, "Error at line %d: Total number of arguments mismatch with declaration in function %s\n\n", line_count, functionName.c_str());
					}
					if(currentFunction->getType()!=functionType){
						error_count++;
						fprintf(error_output, "Error at line %d: Return type mismatch with function declaration in function %s\n\n", line_count, functionName.c_str());
						fprintf(log_output, "Error at line %d: Return type mismatch with function declaration in function %s\n\n", line_count, functionName.c_str());
					}
					if(parameterList.size()==currentFunction->getParameterListSize()){
						if(currentFunction->getParameterListSize()!=0){

						}
					}
					table.removeSymbol(functionName);

                    SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
                    syminfo->setIsFuncDefined(true);
                    table.insertSymbol(syminfo);
                    table.enterScope();

                	bool multipleParamError = false;
                	for(int i=0; i<parameterList.size(); i++)
                	{
                    for(int j=0; j<parameterList.size(); j++)
                    {
                        if(i==j)continue;
                        else
                        {
                            if(parameterList[i].first==parameterList[j].first)
                            {
                                error_count++;
                                string error_msg = "Multiple declaration of " + functionName + " in parameter";
                                fprintf(error_output, "Error at line %d: %s\n", line_count, error_msg.c_str());
                                multipleParamError = true;
                                break;
                            }
                        }
                    }
                    if(multipleParamError)
                        break;
                }


				}
		}
		else{
			table.enterScope();

			error_count++;
			string msg = "Identifier '" + currFunc->getName() + "' is not a function.";
            fprintf(error_output, "Error at line %d: %s\n", line_count, msg.c_str());
			
		}
	}
	else{
		SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
        syminfo->setIsFuncDefined(true);
        table.insertSymbol(syminfo);
        table.enterScope();

        bool multipleParamError = false;
        for(int i=0; i<parameterList.size(); i++)
        {
            // paramInserted = symbolTable->insertSymbol(parameterList[i].getParamName(), parameterList[i].getParamType());
            for(int j=0; j<parameterList.size(); j++)
            {
                if(i==j)continue;
                else
                {
                    if(parameterList[i].first==parameterList[j].first)
                    {
                        error_count++;
                        string error_msg = "Multiple declaration of " + functionName + " in parameter";
                        fprintf(error_output, "Error at line %d: %s\n", line_count, error_msg.c_str());
                        multipleParamError = true;
                        break;
                    }
                }
            }
            if(multipleParamError)
                break;
        }
	}

} compound_statement{
	$$ = new SymbolInfo($1->getName()+" "+$2->getName()+"("+$4->getName()+")"+$7->getName()+"\n","func_definition");
	fprintf(log_output, "Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n%s\n\n\n", line_count, $$->getName().c_str());

}
		| type_specifier ID LPAREN RPAREN compound_statement
 		;				


parameter_list  : parameter_list COMMA type_specifier ID{

				$$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), "parameter_list");
				printLog(logFile, "parameter_list : parameter_list COMMA type_specifier ID", $$->getName(), line_count);
		}
		| parameter_list COMMA type_specifier{

			$$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), $1->getType() + "," + $3->getType());
			fprintf(log_output, "Line %d: parameter_list : parameter_list COMMA type_specifier ID\n\n%s\n\n",  line_count, $$->getName().c_str());
		}
 		| type_specifier ID{

			$$ = new SymbolInfo($1->getName() + " " + $2->getName(), $1->getType());
			fprintf(log_output, "Line %d: parameter_list : type_specifier ID\n\n%s\n\n",  line_count, $$->getName().c_str());
		}
		| type_specifier{

			$$ = $1;
			fprintf(log_output, "Line %d: parameter_list : type_specifier\n\n%s\n\n",  line_count, $$->getName().c_str());
		}
 		;

 		
compound_statement : LCURL statements RCURL{
				$$ = new SymbolInfo("{\n"+$2->getName()+"\n}\n","compound_statement");
				fprintf(log_output, "Line %d: compound_statement : LCURL statements RCURL\n\n%s\n\n",  line_count, $$->getName().c_str());

				fprintf(log_output, "\n\n%s\n\n", table.printAllScopeTable().c_str());
				table.exitScope();
}
 		    | LCURL RCURL{
				$$ = new SymbolInfo("{\n}\n","compound_statement");
				fprintf(log_output, "Line %d: compound_statement : LCURL RCURL\n\n%s\n\n",  line_count, $$->getName().c_str());
          		fprintf(log_output, "\n\n%s\n\n", table.printAllScopeTable().c_str());
				table.exitScope();
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
 		 ;
 		 
type_specifier	: INT{

					$$ = new SymbolInfo("int", "int");

				    fprintf(log_output, "Line %d: type_specifier : INT \n\n%s\n\n",  line_count, $$->getName().c_str());
		}
 		| FLOAT{
					$$ = new SymbolInfo("float", "int");

				    fprintf(log_output, "Line %d: type_specifier : FLOAT \n\n%s\n\n",  line_count, $$->getName().c_str());	
		}
 		| VOID{
					$$ = new SymbolInfo("void", "void");

				    fprintf(log_output, "Line %d: type_specifier : VOID \n\n%s\n\n",  line_count, $$->getName().c_str());
		}
 		;
 		
declaration_list : declaration_list COMMA ID{

					$$ = new SymbolInfo($1->getName() + "," + $3->getName(), "declaration_list");
					fprintf(log_output, "Line %d: declaration_list : declaration_list COMMA ID \n\n%s\n\n",  line_count, $$->getName().c_str());
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
					$$ = new SymbolInfo($1->getName() + "," + $3->getName() + "[" + $5->getName() + "]",	"declaration_list");
					fprintf(log_output, "Line %d: declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n%s\n\n",  line_count, $$->getName().c_str());
					}
 		  | ID{
					$$ = $1;
					fprintf(log_output, "Line %d: declaration_list : ID \n\n%s\n\n",  line_count, $$->getName().c_str());
					}
 		  | ID LTHIRD CONST_INT RTHIRD{
					$$ = new SymbolInfo($1->getName() + "[" + $3->getName() + "]",	"declaration_list");
					fprintf(log_output, "Line %d: declaration_list : COMMA ID LTHIRD CONST_INT RTHIRD  \n\n%s\n\n",  line_count, $$->getName().c_str());
		  }
 		  ;
 		  
statements : statement{
					$$ = $1;
					fprintf(log_output, "Line %d: statements : statement  \n\n%s\n\n",  line_count, $$->getName().c_str());
			}
	   | statements statement{
					$$ = new SymbolInfo($1->getName() + "\n" + $2->getName(), "statements");	
					fprintf(log_output, "Line %d: statements : statements statement  \n\n%s\n\n",  line_count, $$->getName().c_str());	
	   }
	   ;
	   
statement : var_declaration{
		$$=$1;
		fprintf(log_output, "Line %d: statement : var_declaration\n\n%s\n\n", line_count, $$->getName().c_str());	
}
	  | expression_statement{
		$$=$1;
		fprintf(log_output, "Line %d: statement : expression_statement\n\n%s\n\n", line_count, $$->getName().c_str());		
	  }
	  |{ table.enterScope(); }  compound_statement{
		$$ = $2;

		fprintf(log_output, "Line %d: statement : compound_statement\n\n%s\n\n", line_count, $$->getName().c_str());
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement{
		$$ = new SymbolInfo("for("+$3->getName()+$4->getName()+$5->getName()+")"+$7->getName(), "statement");
		fprintf(log_output, "Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n%s\n\n", line_count, $$->getName().c_str());
	  }
	  | IF LPAREN expression RPAREN statement{
		$$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName(), "statement");
		fprintf(log_output, "Line %d: statement : IF LPAREN expression RPAREN statement\n\n%s\n\n", line_count, $$->getName().c_str());
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement{

		$$ = new SymbolInfo("if("+$3->getName()+")"+$5->getName()+ "else\n"+$7->getName(), "statement");
		fprintf(log_output, "Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n\n%s\n\n", line_count, $$->getName().c_str());
	  }
	  | WHILE LPAREN expression RPAREN statement{
		$$ = new SymbolInfo("while("+$3->getName()+")"+$5->getName(), "statement");
		fprintf(log_output, "Line %d: statement : WHILE LPAREN expression RPAREN statement\n\n%s\n\n", line_count, $$->getName().c_str());
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{

	  }
	  | RETURN expression SEMICOLON{

	  }
	  ;
	  
expression_statement 	: SEMICOLON	{
				$$ = new SymbolInfo(";", "expression_statement");
				fprintf(log_output, "Line %d: expression_statement : SEMICOLON\n\n%s\n\n", line_count, $$->getName().c_str());
}		
			| expression SEMICOLON {
					$$ = new SymbolInfo($1->getName() + ";", "expression_statement");
					fprintf(log_output, "Line %d: expression_statement : expression SEMICOLON\n\n%s\n\n", line_count, $$->getName().c_str());
			}
			;
	  
variable : ID 		
	 | ID LTHIRD expression RTHIRD 
	 ;
	 
 expression : logic_expression	
	   | variable ASSIGNOP logic_expression 	
	   ;
			
logic_expression : rel_expression 	
		 | rel_expression LOGICOP rel_expression 	
		 ;
			
rel_expression	: simple_expression 
		| simple_expression RELOP simple_expression	
		;
				
simple_expression : term 
		  | simple_expression ADDOP term 
		  ;
					
term :	unary_expression
     |  term MULOP unary_expression
     ;

unary_expression : ADDOP unary_expression  
		 | NOT unary_expression 
		 | factor 
		 ;
	
factor	: variable 
	| ID LPAREN argument_list RPAREN
	| LPAREN expression RPAREN{
		$$ = new SymbolInfo("("+$2->getName()+")", $2->getType());
		fprintf(log_output, "Line %d: factor : LPAREN expression RPAREN\n\n%s\n\n", line_count, $$->getName().c_str());
	}
	| CONST_INT {

		$$ = $1;
		fprintf(log_output, "Line %d: factor : CONST_INT\n\n%s\n\n", line_count, $$->getName().c_str());
	}
	| CONST_FLOAT{

		$$ = $1;
		fprintf(log_output, "Line %d: factor : CONST_FLOAT\n\n%s\n\n", line_count, $$->getName().c_str());
	}
	| variable INCOP {

		$$ = new SymbolInfo($1->getName()+"++",$1->getType());
		fprintf(log_output, "Line %d: factor : variable INCOP\n\n%s\n\n", line_count, $$->getName().c_str());
	}
	| variable DECOP{

		$$ = new SymbolInfo($1->getName()+"++",$1->getType());
		fprintf(log_output, "Line %d: factor : variable DECOP\n\n%s\n\n", line_count, $$->getName().c_str());
	}
	;
	
argument_list : arguments{

				$$=$1;
				fprintf(log_output, "Line %d: argument_list : arguments\n\n%s\n\n", line_count, $$->getName().c_str());
}
			  |{

				$$=new SymbolInfo("", "void");
				fprintf(log_output, "Line %d: argument_list : \n\n%s\n\n", line_count, $$->getName().c_str());
			  }
			  ;
	
arguments : arguments COMMA logic_expression{

				$$ = new SymbolInfo($1->getName()+","+$3->getName(),$1->getType()+","+$3->getType());
				fprintf(log_output, "Line %d: arguments : arguments COMMA logic_expression\n\n%s\n\n", line_count, $$->getName().c_str());
}
	      | logic_expression{

				$$=$1;
				fprintf(log_output, "Line %d: arguments : logic_expression\n\n%s\n\n", line_count, $1->getName().c_str());
		  }
	      ;
 

%%
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	fp2= fopen(argv[2],"w");
	fclose(fp2);
	fp3= fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a");
	

	yyin=fp;
	yyparse();
	

	fclose(fp2);
	fclose(fp3);
	
	return 0;
}

