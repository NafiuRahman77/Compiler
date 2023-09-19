%{
#include "bits/stdc++.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1905077_main.h"
using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp;
FILE *log_output;
FILE *error_output;
 int line_count=1;
 int error_count=0;
ofstream parse_tree;
SymbolTable table(11);
vector<SymbolInfo> params;
vector<SymbolInfo> vars;
vector<SymbolInfo> argumentList;
string type="";
string type_final="";  
string name="";
string name_final="";


void ParseTree(SymbolInfo* s,int t, ostream &os)
    {
        for (int i = 0; i < t; i++)
        {
            os << " ";
        }
        if (s->isToken())
            os << s->getLeftPart() << " :" << s->getRightPart() << "\t<Line: " << s->getStart() << ">\n";
        else
        os << s->getLeftPart()  << " : " << s->getRightPart() << "\t<Line: " << s->getStart()  << "-" << s->getEnd()  << ">\n";
			vector<SymbolInfo*> v=s->getChildren();
            for (SymbolInfo *si : v)
            {
                ParseTree(si,t + 1, os);
            }
        
    }

// Offline 4 code
FILE *asmout;
ifstream asmly;
ofstream optimizely;
// int lineNumber=0;
vector<string> lineVector(1000);
int tempCount=0;
int labelCount=0;
int currentOffset=0; // offset from BP of that particular variable
int parameterCount=0;
bool isMainDefined=false;
string currentFunc="";

void printUtilFunctions() { fprintf(asmout, "\nPRINT PROC ; PRINTS A WORD INTEGER IN AX\nLEA SI, NUMBER_STRING ; IS 00000\nADD SI, 5 ; START FROM ONE'S DIGIT\nCMP AX, 0\nJNL PRINT_LOOP\nMOV FLAG, 1\nNEG AX\nPRINT_LOOP:\nDEC SI\nMOV DX, 0 ; DX:AX = 0000:AX\nMOV CX, 10\nDIV CX\nADD DL, '0'\nMOV [SI], DL\nCMP AX, 0\nJNE PRINT_LOOP\nCMP FLAG, 0\nJNG NOT_NEGATIVE\nMOV AH, 2\nMOV DL, 45\nINT 21H\nMOV FLAG, 0\nNOT_NEGATIVE:\nMOV DX, SI\nMOV AH, 9\nINT 21H\nMOV DX, OFFSET NL ; NEWLINE\nMOV AH, 9\nINT 21H\nRET\nPRINT ENDP\n"); }

void resetCurrentOffset(){
	currentOffset=0;
}

string newTemp() {
	return "temp_"+to_string(tempCount++);
}

string newLabel() {
	return "label_"+to_string(labelCount++);
}

int ifCount=0;
int whileCount=0;
int forCount=0;

stack<int> ifCountStack;
stack<int> whileCountStack;
stack<int> forCountStack;


void yyerror(char *s)
{
	//write your code
}
%}

%union{
	SymbolInfo* symbol;
}

%token<symbol> IF ELSE FOR WHILE INT FLOAT DOUBLE CHAR RETURN VOID PRINTLN DO BREAK SWITCH CASE DEFAULT CONTINUE ASSIGNOP NOT SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP MAIN 
%token <symbol> ID ADDOP MULOP RELOP LOGICOP CONST_INT CONST_FLOAT
%type <symbol> declaration_list type_specifier var_declaration unit program func_declaration func_definition parameter_list factor variable expression logic_expression argument_list arguments rel_expression simple_expression start term unary_expression statement statements compound_statement expression_statement if_expr

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start :{
		fprintf(asmout, ".MODEL SMALL\n");
		fprintf(asmout, "\n.STACK 400H\n");
		fprintf(asmout, "\n.DATA\n\n");
		fprintf(asmout, "\n.CODE\n\tFLAG DB 0\n\tNL DB 13,10,\"$\"\n\tNUMBER_STRING DB \"00000$\" \n");
} program
	{
		//write your code in this block in all the similar blocks below
		$$ = new SymbolInfo("", "program");		
		fprintf(log_output, "start : program\n");
		printUtilFunctions();
		if(isMainDefined) fprintf(asmout, "END MAIN\n");
		
	}
	;

program : program unit{
	    $$ = new SymbolInfo("","program");	
		fprintf(log_output, "program : program unit\n");
	} 
	| unit{
		$$ = new SymbolInfo("","program");
		fprintf(log_output, "program : unit\n");
	}
	;
	
unit : var_declaration{

		$$ =  new SymbolInfo("","program");
		fprintf(log_output, "unit : var_declaration\n");
	}
     | func_declaration{

		$$ =  new SymbolInfo("","program");
		fprintf(log_output, "unit : func_declaration\n");
	 }
     | func_definition{

		$$ =  new SymbolInfo("","program");
		fprintf(log_output, "unit : func_definition\n");
	 }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON{
				 
			//string returnType = $1->getName();
			//string funcName = $2->getName();
			type_final=$1->getDataType();
            name_final=$2->getName();
            
			SymbolInfo* temp = table.lookUpSymbol(type_final);
			vector<string> paramTypeList;
    			vector<string> typeAndName;
			//fprintf(error_output,"%s",name_final.c_str());
			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Line# %d: Multiple declaration of function %s\n", line_count, name_final.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
                	for(int i=0;i<params.size();i++){
                   		 paramList.push_back(make_pair(params[i].getName(), params[i].getDataType()));
                	}
				
				SymbolInfo* temp=new SymbolInfo(name_final, type_final, paramList);
				temp->setDataType(type_final);
			    temp->setIsFuncDefined(false);
				table.insertSymbol(temp);
			}
			
			$$ = new SymbolInfo("","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");

           	params.clear();
}
		| type_specifier ID LPAREN RPAREN SEMICOLON{
				 
			//string returnType = $1->getName();
			//string funcName = $2->getName();
			type_final=$1->getDataType();
           	name_final=$2->getName();
			SymbolInfo* temp = table.lookUpSymbol(name_final);
			vector<string> paramTypeList;
    			vector<string> typeAndName;
			
			if (temp!=nullptr)
			{
				error_count++;
				fprintf(error_output, "Line# %d: Multiple declaration of function %s\n", line_count, name_final.c_str());
			}
			else {
				vector<pair<string,string>> paramList;
                	for(int i=0;i<params.size();i++){
                   		paramList.push_back(make_pair(params[i].getName(), params[i].getDataType()));
                	}
				
				SymbolInfo* temp=new SymbolInfo(name_final, type_final, paramList);
			    temp->setIsFuncDefined(false);
				temp->setDataType(type_final);
				table.insertSymbol(temp);
			}
			$$ = new SymbolInfo("","func_declaration");
			fprintf(log_output, "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
            params.clear();
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
	 string functionType = $1->getName();
     string functionName = $2->getName();
	 vector<pair<string,string>> parameterList;
     //vector<string> paramPair = split($4->getSymbolName(), ",");
     vector<string> typeAndName;
	 type_final=$1->getDataType();
     name_final=$2->getName();
	 currentFunc=functionName;
     

    for (int i=0;i<params.size();i++)
    {
        pair<string,string> p(params[i].getName(), params[i].getDataType());
        parameterList.push_back(p);
    }

    SymbolInfo* currentFunction = table.lookUpSymbol(functionName);
	
	if(currentFunction!=nullptr){
		
		if(currentFunction->isFunction()){
			if (currentFunction->isDefined()) // Declared and Defined
				{
					error_count++;

						fprintf(error_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
				}
			else{
					vector<pair<string,string>> declaredList=currentFunction->getParameterList();
					if(parameterList.size()!=currentFunction->getParameterListSize()){
						error_count++;
						fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
					}
					else if(currentFunction->getType()!=type_final){
						error_count++;
						fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
					}
					else{
                        vector<pair<string, string>> declaredParameter=currentFunction->getParameterList();
                        //table.enterScope();
                        bool inconsistentReturnTypeError = false;
                        for(int i=0; i<parameterList.size(); i++)
					{

					    if(parameterList[i].second!=declaredParameter[i].second)
						{
						    error_count++;
						    //string error_msg = "Inconsistent type of argument" + declaredParameter[i].first + " in parameter";
						    fprintf(error_output, "Line# %d: Inconsistent type of argument %s in parameter\n", line_count, (declaredParameter[i].first).c_str());
						    inconsistentReturnTypeError = true;
						    break;
						}

					}

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
						    //string error_msg = "Multiple declaration of " + parameterList[i] + " in parameter";

							fprintf(error_output, "Line# %d: Redefinition of parameter \'%s\'\n", line_count, (parameterList[i].first).c_str());
						    multipleParamError = true;
						    break;
						}
					    }
					}
                            		if(multipleParamError)
                                		break;
                        	}
                        		if(!inconsistentReturnTypeError || !multipleParamError){                            
                            		currentFunction->setIsFuncDefined(true);
									currentFunction->setDataType(functionType);
                         
                        	}
                   	 }


			}
		}
		else{
			//table.enterScope();

			error_count++;
			//string msg = "Identifier '" + currentFunction->getName() + "' is not a function.";
            fprintf(error_output, "Line# %d: \'%s\' redeclared as different kind of symbol\n", line_count, currentFunction->getName().c_str());
			
		}
	}
	else{
		SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
        syminfo->setIsFuncDefined(true);
		syminfo->setDataType(functionType);
        table.insertSymbol(syminfo);
       	// table.enterScope();
	
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
				fprintf(error_output, "Line# %d: Multiple declaration of %s in parameter\n", line_count, (parameterList[i].first).c_str());
				multipleParamError = true; 
				break;
			    }
			}
		    }

		}
		if( !multipleParamError){
        syminfo->setIsFuncDefined(true);
		syminfo->setDataType(functionType);          
        }

	}
	fprintf(asmout, "\n%s PROC\n", functionName.c_str());
	fprintf(asmout, "\tPUSH BP\n\tMOV BP, SP\n");


} compound_statement{
		$$=new SymbolInfo("", "func_definition");
		fprintf(log_output, "func_definition :type_specifier ID LPAREN parameter_list RPAREN compound_statement \n");
		resetCurrentOffset();
		fprintf(asmout, "%s_EXIT:\n", $2->getName().c_str());
		fprintf(asmout, "\tMOV SP, BP ; Restoring SP\n");
		fprintf(asmout, "\tPOP BP\n");
		fprintf(asmout, "\tRET %d\n", 2*parameterCount);
		fprintf(asmout, "%s ENDP\n", $2->getName().c_str());

}
| type_specifier ID LPAREN RPAREN {
	   	string functionType = $1->getName();
       	string functionName = $2->getName();  
	   	if(functionName == "main") isMainDefined=true;  
       	SymbolInfo* currentFunction = table.lookUpSymbol(functionName);
	   	vector<pair<string,string>> parameterList;
	   	vector<pair<string,string>> paramPair;
       	vector<string> typeAndName;
	   	type_final=$1->getDataType();
       	name_final=$2->getName();
	   	currentFunc=functionName;


	    for (int i=0;i<params.size();i++)
	    {
		pair<string,string> p(params[i].getName(), params[i].getDataType());
		parameterList.push_back(p);
	    }
		if(currentFunction!=nullptr){
				if (currentFunction->isDefined()) // Declared and Defined
					{
						error_count++;

						fprintf(error_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
						fprintf(log_output, "Line# %d: Multiple definition of function %s\n", line_count, functionName.c_str());
					}
				else{   vector<pair<string,string>>parameterList;
						if(parameterList.size()!=currentFunction->getParameterListSize()){
							error_count++;
							fprintf(error_output, "Line# %d: Total number of arguments mismatch with declaration in function %s\n", line_count, functionName.c_str());
							fprintf(log_output, "Line# %d: Total number of arguments mismatch with declaration in function %s\n", line_count, functionName.c_str());
						}
						if(currentFunction->getType()!=functionType){
							error_count++;
							fprintf(error_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
							fprintf(log_output, "Line# %d: Conflicting types for %s\n", line_count, functionName.c_str());
						}
						if(!(parameterList.size()!=currentFunction->getParameterListSize()) && !(currentFunction->getType()!=functionType)){
							table.removeSymbol(functionName);
							SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);      	
							syminfo->setIsFuncDefined(true);
							table.insertSymbol(syminfo);

						}

						}

					}
		else{

		SymbolInfo *syminfo = new SymbolInfo(functionName, functionType, parameterList);
		syminfo->setIsFuncDefined(true);
		table.insertSymbol(syminfo);			
	}
	fprintf(asmout, "\n%s PROC\n", functionName.c_str());
	if(functionName=="main") {
		fprintf(asmout, "\tMOV AX, @DATA\n\tMOV DS, AX\n");
	}
	fprintf(asmout, "PUSH BP\nMOV BP, SP\n");


	}compound_statement{

			$$=new SymbolInfo("", "func_definition");

			fprintf(log_output, "func_definition :type_specifier ID LPAREN RPAREN compound_statement \n");
			resetCurrentOffset();
			fprintf(asmout, "%s_EXIT:\n", $2->getName().c_str());
			fprintf(asmout, "\tMOV SP, BP ; Restoring SP\n");
			fprintf(asmout, "\tPOP BP\n");
			if($2->getName()=="main") {
				fprintf(asmout, "\tMOV AH, 4CH\n\tINT 21H\n");
			} else {
				fprintf(asmout, "\tRET\n");
			}

			fprintf(asmout, "%s ENDP\n", $2->getName().c_str());

		}

;				


parameter_list  : parameter_list COMMA type_specifier ID{

			$$ = new SymbolInfo($1->getName() + "," + $3->getName() + " " + $4->getName(), "parameter_list"); 
			SymbolInfo s($4->getName(),$3->getDataType());   
			s.setDataType($3->getDataType());         
            params.push_back(s);
			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier ID\n");
		}
		| parameter_list COMMA type_specifier{

			$$ = new SymbolInfo($1->getName() + "," + $3->getName() , "parameter_list"); 
			SymbolInfo s("",$3->getDataType()) ; 
			s.setDataType($3->getDataType());    
            params.push_back(s);
			fprintf(log_output, "parameter_list : parameter_list COMMA type_specifier\n");
		}
 		| type_specifier ID{

			$$ = new SymbolInfo($1->getName() + " " + $2->getName(), "parameter_list");    
			SymbolInfo s($2->getName(),$1->getDataType()); 
			s.setDataType($1->getDataType());
            params.push_back(s);
			fprintf(log_output, "parameter_list : type_specifier ID\n");
		}
		| type_specifier{

			$$ = new SymbolInfo($1->getName(), "parameter_list");
			SymbolInfo s("",$1->getDataType());
			s.setDataType($1->getDataType());
            params.push_back(s);
			fprintf(log_output, "parameter_list : type_specifier\n");
		}
 		;

 		
compound_statement : LCURL{
				table.enterScope();
				parameterCount= params.size();
                for(int i=0; i<params.size(); i++) {
					SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
					s->setStackOffset((params.size()-i-1)*2+4); // 2 for BP, 2 for ret address
					s->setGlobal(false);
					s->setDataType(params[i].getDataType());
					table.insertSymbol(s);
                }
				params.clear();
                
				} statements RCURL{
				$$ = new SymbolInfo("{\n }","compound_statement");
				fprintf(log_output, "compound_statement : LCURL statements RCURL\n");

				fprintf(log_output, "\n%s\n", table.printAllScopeTable().c_str());
				string allScope=table.printAllScopeTable();
				fprintf(log_output, "%s",allScope);
				$$->setChildren({$1,$3,$4});
				$$->setLeftPart("compound_statement");
				$$->setRightPart("LCURL statements RCURL");
				$$->setStart($1->getStart());
				$$->setEnd($4->getEnd());
				table.exitScope();
}
 		    | LCURL{
				table.enterScope();	
				parameterCount= params.size();		
                for(int i=0; i<params.size(); i++) {
				SymbolInfo* s=new SymbolInfo(params[i].getName(),params[i].getDataType());
				s->setStackOffset((params.size()-i-1)*2+4); // 2 for BP, 2 for ret address
				s->setGlobal(false);
				table.insertSymbol(s);	
            	}
				params.clear();
					
				} RCURL{
				$$ = new SymbolInfo("{\n}\n","compound_statement");
				fprintf(log_output, "compound_statement : LCURL RCURL\n");
          			fprintf(log_output, "%s", table.printAllScopeTable());
				$$->setChildren({$1,$3});
				$$->setLeftPart("compound_statement");
				$$->setRightPart("LCURL RCURL");
				$$->setStart($1->getStart());
				$$->setEnd($3->getEnd());
				table.exitScope();
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON{

            $$ = new SymbolInfo("", "var_declaration");
            fprintf(log_output, "var_declaration: type_specifier declaration_list SEMICOLON\n");
			string varType = $1->getDataType();
			string varFirst = vars[0].getName();
			if ($1->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d : Variable or field \'%s\' declared void \n", line_count, varFirst.c_str());
				
			}
			else{
			for(int i=0;i<vars.size();i++){
			    if(vars[i].isArray()){

					int arraySize=vars[i].getArraySize();
					string arrayName=vars[i].getName();
					SymbolInfo* temp=new SymbolInfo(arrayName, varType, arraySize);
					temp->setDataType($1->getDataType());
					bool check=table.insertSymbol(temp);
					if (!check ) {
						    SymbolInfo* temp1=table.lookUpSymbol(arrayName);
						    if($1->getDataType()!=temp1->getDataType() ){

							error_count++;
						        fprintf(error_output, "Line# %d: Conflicting types for \'%s\'\n", line_count, vars[i].getName().c_str());
					       }
							else{
								error_count++;
								fprintf(error_output, "Line# %d: Multiple declaration of %s\n", line_count, arrayName.c_str());
							}
					      }
					else{
						if(1==table.getCurrentScopeTable()->getID()) { // global
							fprintf(asmout, "%s DW %d DUP(?) ; %s[%d] decl\n", arrayName.c_str(), arraySize, arrayName.c_str(), arraySize);
						}
						else{
							for(int j=0; j<arraySize; j++){
								fprintf(asmout, "PUSH AX ; %s[%d] decl\n", arrayName.c_str(), arraySize-1-j);
								currentOffset-=2;
							}
							SymbolInfo* temp= table.lookUpSymbol(arrayName);
							temp->setStackOffset(currentOffset); // arrayName[arraySize - 1] is at currentOffset[BP]
							temp->setGlobal(false);
						}

					}

			    }
			    else
				      {
					    SymbolInfo* temp=new SymbolInfo(vars[i].getName(), varType);
					    temp->setDataType($1->getDataType());
					    bool check=table.insertSymbol(temp);
					    if (!check ) {

				            SymbolInfo* temp1=table.lookUpSymbol(vars[i].getName());
					    	if($1->getDataType()!=temp1->getDataType()){

								error_count++;
								fprintf(error_output, "Line# %d: Conflicting types for \'%s\'\n", line_count, vars[i].getName().c_str());
							}
							else{
								error_count++;
								fprintf(error_output, "Line# %d: Multiple declaration of %s\n", line_count, vars[i].getName().c_str());
							}
						}
						else{
							if(1==table.getCurrentScopeTable()->getID()) { // global
								fprintf(asmout, "%s DW ? ; %s decl\n", vars[i].getName().c_str(), vars[i].getName().c_str());
							}
							else{
								fprintf(asmout, "PUSH AX ; %s decl\n", vars[i].getName().c_str());
								currentOffset-=2;
								SymbolInfo* temp= table.lookUpSymbol(vars[i].getName());
								temp->setStackOffset(currentOffset);
								temp->setGlobal(false);
							}
						}
					}
			}
				
			}
			
            vars.clear();
}
 		 ;
 		 
type_specifier	: INT{

					$$ = new SymbolInfo( "int","type_specifier");
					string s="int";
                    $$->setDataType("int");
                    type="int";
				    fprintf(log_output, "type_specifier : INT \n");
		}
 		| FLOAT{
					$$ = new SymbolInfo( "float","type_specifier");
                   	$$->setDataType("float");
                  	type="float";
                   	fprintf(log_output, "type_specifier : FLOAT \n");
		}
 		| VOID{
					$$ = new SymbolInfo( "void","type_specifier");
                   	$$->setDataType("void");
                    type="void";
                    fprintf(log_output, "type_specifier : VOID \n");
		}
 		;

 		
declaration_list : declaration_list COMMA ID{

					$$ = new SymbolInfo( $3->getName(), "declaration_list");
					SymbolInfo s( $3->getName(), "declaration_list");
                    vars.push_back(s);
					fprintf(log_output, "declaration_list : declaration_list COMMA ID\n");
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
					$$ = new SymbolInfo( $3->getName() ,"declaration_list");
                    int size=stoi($5->getName());
					SymbolInfo s( $3->getName(), "declaration_list", size );
                    vars.push_back(s);
					fprintf(log_output, "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",  line_count);
					}
 		  | ID{
					$$ = new SymbolInfo($1->getName(), "declaration_list");
					SymbolInfo s( $1->getName(), "declaration_list");
                    vars.push_back(s);
                    name = $1->getName();
					fprintf(log_output, "declaration_list : ID\n");
					}
 		  | ID LTHIRD CONST_INT RTHIRD{
					$$ = new SymbolInfo($1->getName(),	"declaration_list");
                    int size=stoi($3->getName());
					SymbolInfo s( $1->getName(), "declaration_list", size );
                    vars.push_back(s);
                    name = $1->getName();			
					fprintf(log_output, "declaration_list : COMMA ID LTHIRD CONST_INT RTHIRD\n");
		  }
 		  ;
 		  
statements : statement{
					$$ = new SymbolInfo((string)$1->getName(), "statements");
					fprintf(log_output, "statements : statement\n");
			}
	   | statements statement{
					$$ = new SymbolInfo($1->getName() + " " + $2->getName(), "statements");
					fprintf(log_output, "statements : statements statement\n");	
	   }
	   ;
	   
statement : var_declaration{
		$$=new SymbolInfo((string)$1->getName(), "statement");
		fprintf(log_output, "statement : var_declaration\n");	
}
	  | expression_statement{
		$$=new SymbolInfo((string)$1->getName(), "statement");
		fprintf(log_output, "statement : expression_statement\n");		
	  }
	  | compound_statement{
		$$ = new SymbolInfo((string)$1->getName(), "statement");
		fprintf(log_output, "statement : compound_statement\n");
	  }
	  | FOR LPAREN expression_statement {
		forCount++;
		forCountStack.push(forCount);
		fprintf(asmout, "%s: ; for loop starting label\n", ("label_for_start_"+to_string(forCountStack.top())).c_str());
	  } expression_statement {
	  	fprintf(asmout, "CMP AX, 0\n");
	  	fprintf(asmout, "JE %s ; loop ending condn\n", ("label_for_end_"+to_string(forCountStack.top())).c_str());
	  	fprintf(asmout, "JMP %s ; loop code label\n", ("label_for_stmt_"+to_string(forCountStack.top())).c_str());
	  	fprintf(asmout, "%s: ; loop iterator inc/dec\n", ("label_for_ite_"+to_string(forCountStack.top())).c_str());
	  	
	  } expression RPAREN {
		fprintf(asmout, "JMP %s ; restart loop\n", ("label_for_start_"+to_string(forCountStack.top())).c_str());
		fprintf(asmout, "%s: ; loop code\n", ("label_for_stmt_"+to_string(forCountStack.top())).c_str());
	  } statement
	  {
		$$ = new SymbolInfo("", "statement");
		fprintf(log_output, "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");		//Offline 4 code
		fprintf(asmout, "JMP %s ; update iterator after stmt\n", ("label_for_ite_"+to_string(forCountStack.top())).c_str());
	  	fprintf(asmout, "%s: ; end of for loop\n", ("label_for_end_"+to_string(forCountStack.top())).c_str());
	  	forCountStack.pop();
	  }
	  | if_expr statement %prec LOWER_THAN_ELSE
	  {
		$$ = new SymbolInfo("" ,"statement");
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement\n");
		fprintf(asmout, "%s: ; end if label\n", ("label_else_"+to_string(ifCountStack.top())).c_str());
		ifCountStack.pop();
	  }
	  | if_expr statement ELSE {

		fprintf(asmout, "JMP %s\n", ("label_endif_"+to_string(ifCountStack.top())).c_str());
		fprintf(asmout, "%s: ; else label\n", ("label_else_"+to_string(ifCountStack.top())).c_str());
	  } statement
	  {
		$$ = new SymbolInfo("", "statement");
		fprintf(log_output, "statement : IF LPAREN expression RPAREN statement ELSE statement\n");		fprintf(asmout, "%s: ; end if label\n", ("label_endif_"+to_string(ifCountStack.top())).c_str());
		ifCountStack.pop();
	  }

	  | WHILE 
	  {
		whileCount++;
		whileCountStack.push(whileCount);
		fprintf(asmout, "%s: ; while loop begin\n", ("label_while_start_"+to_string(whileCountStack.top())).c_str());
	  } LPAREN expression RPAREN 
	  {
		fprintf(asmout, "POP CX\nCMP CX, 0\nJE %s\n", ("label_while_end_"+to_string(whileCountStack.top())).c_str());
	  } statement
	  {
		$$ = new SymbolInfo("while("+$4->getName()+")"+$7->getName(), "statement");
		fprintf(log_output, "statement : WHILE LPAREN expression RPAREN statement\n");
		fprintf(asmout, "JMP %s ; back to top of loop\n%s:\n", ("label_while_start_"+to_string(whileCountStack.top())).c_str(), ("label_while_end_"+to_string(whileCountStack.top())).c_str());
		whileCountStack.pop();
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{
		SymbolInfo *temp = table.lookUpSymbol($3->getName());
		$$ = new SymbolInfo("", "statement");
		fprintf(log_output, "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
		if(temp->isGlobal()) fprintf(asmout, "MOV AX, %s\nCALL PRINT ; argument %s in AX\n", temp->getName().c_str(), temp->getName().c_str());
		else fprintf(asmout, "MOV AX, %d[BP]\nCALL PRINT ; argument %s in AX\n", temp->getStackOffset(), temp->getName().c_str());
	  }
	  | RETURN expression SEMICOLON{
			$$ = new SymbolInfo((string)"\t"+(string)"return "+(string)$2->getName()+(string)";"+(string)"\n", "statement");
			fprintf(log_output, "statement : RETURN expression SEMICOLON\n");
			if($2->getDataType() == "void") {
					fprintf(error_output, "Line# %d: Void cannot be used in expression\n", line_count);
                error_count++;
                
            } 
			else if($2->getDataType()!=type_final){
			error_count++;
			fprintf(error_output, "Line# %d: Return type mismatch\n", line_count);
			fprintf(asmout, "POP AX\n");
			fprintf(asmout, "\tJMP %s_EXIT\n", currentFunc.c_str());
		
		}
	  }
	  ;


if_expr :	IF LPAREN expression RPAREN 
	{
		ifCount++;
		ifCountStack.push(ifCount);
		// labelElse= "label_else_"+to_string(ifCount);
		fprintf(asmout, "POP AX ; expr in AX\nCMP AX, 0 ; checking expr\n");
		fprintf(asmout, "JE %s\n", ("label_else_"+to_string(ifCountStack.top())).c_str());
		$$= new SymbolInfo("", "statement");
	} 	
	  
expression_statement 	: SEMICOLON	{
				$$ = new SymbolInfo(";", "expression_statement");
				fprintf(log_output, "Line# %d: expression_statement : SEMICOLON\n%s\n", line_count, $$->getName().c_str());
}		
			| expression SEMICOLON {

				$$ = new SymbolInfo($1->getName() + ";", "expression_statement");
				fprintf(log_output, "Line# %d: expression_statement : expression SEMICOLON\n%s\n", line_count, $$->getName().c_str());
				fprintf(asmout, "POP AX\n");
			}
			;
	  
variable : ID {
				string returnType;
				SymbolInfo* currId = table.lookUpSymbol($1->getName());
				fprintf(log_output, "variable : id\n");
				
				if (currId == nullptr)
				{
					error_count++;
					fprintf(error_output, "Line# %d: Undeclared variable \'%s\'\n", line_count, $1->getName().c_str());
					fprintf(log_output, "Line# %d: Undeclared variable \'%s\'\n", line_count, $1->getName().c_str());
					$$ = new SymbolInfo($1->getName(),"variable");
					
					}
				else
				{
					if(currId->isArray()){
					error_count++;
					//fprintf(error_output, "Line# %d: type mismatch(not variable) \'%s\'\n", line_count, $1->getName().c_str());	
					$$ = new SymbolInfo(currId->getName(), "variable");
					$$->setDataType(currId->getDataType());	
							
					}
					else{
					$$ = new SymbolInfo(currId->getName(), "variable");
					$$->setDataType(currId->getDataType());
					$$->setArraySize(0);
					if(currId->isGlobal()) {
						fprintf(asmout, "MOV AX, %s\nPUSH AX ; %s called\n", currId->getName().c_str(), currId->getName().c_str());
					} else {
						fprintf(asmout, "MOV AX, %d[BP]\nPUSH AX ; %s called\n", currId->getStackOffset(), currId->getName().c_str());
					}
					$$ = new SymbolInfo(currId->getName(), currId->getType());
					$$->setStackOffset(currId->getStackOffset());
					}
					
				}
			}		
	 | ID LTHIRD expression RTHIRD {
		SymbolInfo *temp = table.lookUpSymbol($1->getName());
		$$ = new SymbolInfo($1->getName()+"["+$3->getName()+"]","variable");
		if(temp==nullptr){
			error_count++;
			fprintf(error_output, "Line# %d: Undeclared variable %s\n", line_count, $1->getName().c_str());
			fprintf(log_output, "Line# %d: Undeclared variable %s\n", line_count, $1->getName().c_str());
			
		}
		else{
			if(temp->isArray()){
				if($3->getDataType() != "int") {
				fprintf(error_output, "Line# %d: Array subscript is not an integer\n", line_count, $1->getName().c_str());
				fprintf(log_output, "Line# %d: Array subscript is not an integer", line_count, $1->getName().c_str());
                error_count++;

           		 }
				 else{
					$$ = new SymbolInfo($1->getName()+"["+$3->getName()+"]", "variable");
					$$->setDataType(temp->getDataType());
					$$->setArraySize(temp->getArraySize()); //CHANGE

					if(temp->isGlobal()) {
					fprintf(asmout, "POP BX ; popped index expr\nSHL BX, 1\nMOV SI, %s\nMOV AX, BX[SI]\n ; %s called\n", temp->getName().c_str(), temp->getName().c_str()); 
				} else {
					fprintf(asmout, "POP BX ; popped index expr %s\nSHL BX, 1\nADD BX, %d\n;ADD BX, BP\nPUSH BP\nADD BP, BX\nMOV AX, [BP]\nPOP BP\n;MOV AX, [BX]\nPUSH AX ; value of %s[%s]\nPUSH BX ; index %s\n",
					$3->getName().c_str(), temp->getStackOffset(), temp->getName().c_str(), $3->getName().c_str(), $3->getName().c_str());
				}		
					$$->setStackOffset(temp->getStackOffset());		
				 }
				
			}
			else{
					error_count++;
					fprintf(error_output, "Line# %d: \'%s\' is not an array\n", line_count, $1->getName().c_str());
					fprintf(log_output, "Line# %d: \'%s\' is not an array\'%s\'\n", line_count, $1->getName().c_str());
					
			}

		}

	 }
	 ;
	 
 expression : logic_expression	{

			$$ = new SymbolInfo($1->getName(), "expression");
			type=$1->getDataType();
			$$->setDataType($1->getDataType());
			fprintf(log_output, "expression : logic_expression\n", line_count);

 }
	   | variable ASSIGNOP logic_expression {

			$$ = new SymbolInfo($1->getName()+"="+$3->getName(), "expression");
			if ($1->getDataType()=="void" || $3->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d: Void cannot be used in expression\n", line_count);
				fprintf(log_output, "Line# %d: Void cannot be used in expression\n", line_count);
			}
			else if ($1->getDataType()!=$3->getDataType()){
				string varType= $1->getDataType();
				string exprType= $3->getDataType();
				
				
			    if (varType=="float" && exprType=="int") ;

				else if (varType=="int" && exprType=="float"){

				fprintf(error_output, "Line# %d: Warning: possible loss of data in assignment of FLOAT to INT\n", line_count);
				} 
				else if (varType=="void" && exprType=="int") {
				fprintf(error_output, "Line# %d: Void can't be used in an expression\n", line_count);

				}
				else {
					error_count++;
					//fprintf(error_output, "Line# %d: Type Mismatch\n", line_count);
				}
			}
			else{
				string varType= $1->getDataType();
				string exprType= $3->getDataType();
				if (varType=="int" && exprType=="int") ;
				if (varType=="float" && exprType=="float") ;
				
			}
			$$->setDataType($1->getDataType());
			type=$1->getDataType();

			string varName= $1->getName();
			
			fprintf(asmout, "POP AX ; r-val of assignop %s\n", $3->getName().c_str());
			
			SymbolInfo* temp = table.lookUpSymbol(varName);
			if(temp->isGlobal()){
				fprintf(asmout, "MOV %s, AX\n", temp->getName().c_str());
			} else {
				if ($1->isArray()){
					fprintf(asmout, "POP BX\n");
					fprintf(asmout, ";MOV [BX], AX\nPUSH BP\nADD BP, BX\nMOV [BP], AX\nPOP BP ; assigning to %s\n", $1->getName().c_str());
				}
				else {
					fprintf(asmout, "MOV %d[BP], AX ; assigning %s to %s\n", $1->getStackOffset(), $3->getName().c_str(), $1->getName().c_str());
				}
			}
			fprintf(log_output, "expression : variable ASSIGNOP logic_expression\n");
	   }	
	   ;
			
logic_expression : rel_expression {
			$$ = new SymbolInfo($1->getName(), "logic_expression");
			$$->setDataType($1->getDataType());
			fprintf(log_output, "logic_expression : rel_expression\n");
}	
		 | rel_expression LOGICOP rel_expression {
			if ($1->getDataType()=="void" || $3->getDataType()=="void"){
				error_count++;
				fprintf(error_output, "Line# %d: Void function used in expression\n", line_count);
			}
			if (($1->getDataType() != "int") || ($3->getDataType() != "int"))
				{
					error_count++;
					fprintf(error_output, "Line# %d: Both type of %s should be int\n", line_count,$2->getName().c_str());
				//	fprintf(error_output, "Line# %s: Both type should be int\n", $3->getDataType().c_str());

				}

			$$ = new SymbolInfo($1->getName() + $2->getName() + $3->getName(),	"logic_expression");
			$$->setDataType("int");
			fprintf(log_output, "logic_expression : rel_expression LOGICOP rel_expression\n");

			// Offline 4 code
			fprintf(asmout, "POP BX\nPOP AX ; left side value\n");
			string labelIfTrue=newLabel();
			string labelIfFalse=newLabel(); 

			if($2->getName()=="&&"){
				fprintf(asmout, "CMP AX, 0\nJE %s\nCMP BX, 0\nJE %s\nPUSH 1\nJMP %s\n", labelIfFalse.c_str(), labelIfFalse.c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; total false\n%s:\n", labelIfFalse.c_str(), labelIfTrue.c_str());
			
			} else if($2->getName()=="||"){
				fprintf(asmout, "CMP AX, 0\nJNE %s\nCMP BX, 0\nJNE %s\nPUSH 0\nJMP %s\n", labelIfFalse.c_str(), labelIfFalse.c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 1 ; total false\n%s:\n", labelIfFalse.c_str(), labelIfTrue.c_str());
			
			} 
		 }	
		 ;
			
rel_expression	: simple_expression {
			$$ = new SymbolInfo($1->getName() ,	"rel_expression");
			$$->setDataType($1->getDataType());
			$$->setArraySize($1->getArraySize());
			fprintf(log_output, "Line# %d: rel_expression : simple_expression\n", line_count);
}
		| simple_expression RELOP simple_expression	{

			if ($1->getDataType()=="void" || $3->getDataType()=="void"){
				error_count++;
				//fprintf(error_output, "Line# %d: Void function used in expression\n", line_count);
			}
			$$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), "int");
			$$->setDataType("int");
			fprintf(log_output, "rel_expression : simple_expression RELOP simple_expression\n", line_count);
			// Offline 4 code
			fprintf(asmout, "POP AX\nPOP BX ; left side value\nCMP BX, AX ; evaluating %s\n", $$->getName().c_str());
			string labelIfTrue=newLabel();
			string labelIfFalse=newLabel(); 
			if($2->getName()=="<"){
				fprintf(asmout, "JNL %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
			
			} else if($2->getName()=="<="){
				fprintf(asmout, "JNLE %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
			
			} else if($2->getName()==">"){
				fprintf(asmout, "JNG %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
		
			} else if($2->getName()==">="){
				fprintf(asmout, "JNGE %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
			
			} else if($2->getName()=="=="){
				fprintf(asmout, "JNE %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
			
			} else if($2->getName()=="!="){
				fprintf(asmout, "JE %s\nPUSH 1 ; if %s is true\nJMP %s\n", labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
				fprintf(asmout, "%s:\nPUSH 0 ; if %s is false\n%s:\n",labelIfFalse.c_str(), $$->getName().c_str(), labelIfTrue.c_str());
							
			}
		}
		;
				
simple_expression : term {

		    $$ = new SymbolInfo($1->getName(), "simple_expression");
			$$->setDataType($1->getDataType());
			$$->setArraySize($1->getArraySize());
			fprintf(log_output, "Line# %d: simple_expression : term\n", line_count);


		//fprintf(error_output, "Line# %d: %s found \n",line_count, $1->getDataType().c_str() );
			
}
		  | simple_expression ADDOP term {

			string exprType;
			

			if( ($3->getDataType()=="int") && ($1->getDataType()=="int")) exprType= "int"; 
			else exprType= "float";
			if ($1->getDataType()=="void" || $3->getDataType()=="void"){
				error_count++;
				//fprintf(error_output, "Line# %d: Void function used in expression \n", line_count);
				exprType="void";
			}

			$$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(), "simple_expression");
			$$->setDataType(exprType);

			if($2->getName()=="+")
				fprintf(asmout, "POP AX\nPOP BX\nADD AX, BX\nPUSH AX ; %s+%s pushed\n", $1->getName().c_str(), $3->getName().c_str());
			else 
				fprintf(asmout, "POP AX\nPOP BX\nSUB BX, AX\nPUSH BX ; %s-%s pushed\n", $1->getName().c_str(), $3->getName().c_str()); //! check minus	

			fprintf(log_output, "simple_expression : simple_expression ADDOP term\n", line_count);
		  }
		  ;
					
term :	unary_expression{

		$$=new SymbolInfo($1->getName(), "term");
		$$->setDataType($1->getDataType());
		$$->setArraySize($1->getArraySize());
		fprintf(log_output, "term : unary_expression\n", line_count);

}
     |  term MULOP unary_expression{

		$$ = new SymbolInfo($1->getName()+$2->getName()+$3->getName(),"term");
		
		if($2->getName()=="%"){ 
			if(($1->getDataType()=="void") || ($3->getDataType()=="void")){
				
					error_count++;
					fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
					$$->setDataType("void");
				
			}
			if(($1->getDataType()=="int") && ($3->getDataType()=="int")){
				if($3->getName()=="0"){ 
					error_count++;
					fprintf(error_output, "Line# %d: Division by Zero\n", line_count);
				}
			}
			else { 
				error_count++;
				fprintf(error_output, "Line# %d: Operands of modulus must be integers\n", line_count);
				fprintf(log_output, "Line# %d: Operands of modulus must be integers", line_count);
				
			}
			$$->setDataType("int");
			fprintf(asmout, "MOV DX, 0 ; DX:AX = 0000:AX\nPOP BX\nPOP AX\nIDIV BX\nPUSH DX ; remainder of %s is in DX\n", $$->getName().c_str());

			
		}
		else if($2->getName()=="/"){
			if(($1->getDataType()=="void") && ($3->getDataType()=="void")){
				
					error_count++;
					//fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
				
				
			}
			if($3->getName()=="0"){ 
					error_count++;
					fprintf(error_output, "Line# %d: Division by Zero\n", line_count);
				
				}
				else{
					if(($1->getDataType()=="int")&&($3->getDataType()=="int")){
					$$->setDataType("int");
					}
					else {
						$$->setDataType("float");
					}
				}
			fprintf(asmout, "POP BX\nPOP AX\nIDIV BX\nPUSH AX ; result of %s is in AX, pushed\n", $$->getName().c_str());; //! division
		}
		else{
			
			if(($1->getDataType()=="int")&&($3->getDataType()=="int")){
				$$->setDataType("int");
			}
			else {
			$$->setDataType("float");
			}
			if(($1->getDataType()=="void") || ($3->getDataType()=="void")){
				
					error_count++;
					//fprintf(error_output, "Line# %d: Void cannot be used in an expression\n", line_count);
					
					$$->setDataType("void");
				
			}
			fprintf(asmout, "POP BX\nPOP AX\nIMUL BX\nPUSH AX ; result of %s is in AX, pushed\n", $$->getName().c_str());
		}
		fprintf(log_output, "term : term MULOP unary_expression\n" );

	 }
     ;

unary_expression : ADDOP unary_expression {

			$$ = new SymbolInfo($1->getName()+$2->getName(), "unary_expression");
			$$->setDataType($2->getDataType());
			//Offline 4
			if($1->getName()=="-"){
				//! pls do
				fprintf(asmout, "POP AX\nNEG AX ; -%s\nPUSH AX\n", $2->getName());
			}
			fprintf(log_output, "unary_expression : ADDOP unary_expression\n");
} 
		 | NOT unary_expression {
			
			$$ = new SymbolInfo("!"+$2->getName(), "unary_expression");
			$$->setDataType($2->getDataType());
			$$->setDataType("int");
			string labelIfTrue=newLabel();
			string labelIfFalse=newLabel();
			fprintf(asmout, "POP AX\nCMP AX, 0 ; !%s\nJNE %s\nMOV AX, 1\nJMP %s\n\
				\n%s:\nXOR AX, AX\n%s:\nPUSH AX\n"
				, $2->getName().c_str(), labelIfTrue.c_str(), labelIfFalse.c_str(), labelIfTrue.c_str(), labelIfFalse.c_str());
			fprintf(log_output, "unary_expression : NOT unary_expression\n");
		 }
		 | factor {

			$$ = new SymbolInfo($1->getName(),"unary_expression");
			$$->setDataType($1->getDataType());
			$$->setArraySize($1->getArraySize());
			
			fprintf(log_output, "unary_expression : factor\n");

		 }
		 ;
	
factor	: variable {

		$$=new SymbolInfo("("+$1->getName()+")", "factor");
		$$->setDataType($1->getDataType());
		$$->setArraySize($1->getArraySize());
		if($$->isArray()){
			fprintf(asmout, "POP BX ; r-value, no need for index\n");
		}
		fprintf(log_output, "factor : variable\n");
}
	| ID LPAREN argument_list RPAREN{
		
            $$ = new SymbolInfo((string)$1->getName()+(string)"("+(string)$3->getName()+(string)")", "factor");
			SymbolInfo* temp = table.lookUpSymbol($1->getName());
			

            if(temp == nullptr) {
                error_count++;
				fprintf(error_output, "Line# %d: Undeclared function \'%s\' \n", line_count, $1->getName().c_str());
                //$$->setDataType("float");  

            }
			else{
				if(temp->isDefined()){
					vector<pair<string,string>> declaredParameter=temp->getParameterList();
					
					if(temp->getParameterListSize()==1 && argumentList.size()==0 && declaredParameter[0].second=="void") {
                    $$->setDataType(temp->getDataType());

                	}
					if(temp->getParameterListSize() > argumentList.size()) {
                    
                    error_count++;
					fprintf(error_output, "Line# %d: Too few arguments to function \'%s\'\n", line_count, temp->getName().c_str());
                   // $$->setDataType("float"); 

               		 }
					else if(temp->getParameterListSize() < argumentList.size()) {
                    
                    error_count++;

					fprintf(error_output, "Line# %d: Too many arguments to function \'%s\'\n", line_count, temp->getName().c_str());
                    //$$->setDataType("float"); 

                	}
				 	else {
                   
						bool err=false;
					
                    	for(int i=0; i<argumentList.size(); i++) {
                        if(declaredParameter[i].second != argumentList[i].getDataType()) {
                            err=true;
							fprintf(error_output, "Line# %d: Type mismatch for argument %d of \'%s\'\n", line_count, i+1,temp->getName().c_str());
                        	
                        }
						if(argumentList[i].isArray()) {
                            err=true;
							fprintf(error_output, "Line# %d: Type mismatch for argument %d of \'%s\'\n", line_count, i+1,temp->getName().c_str());
                        	
                        }
						
                    }

                    if(err) {
						error_count++;
                       // $$->setDataType("float");  

                    } else {
                        $$->setDataType(temp->getDataType());
						fprintf(asmout, "CALL %s\n", $1->getName().c_str());
						if(temp->getDataType()!="void"){
							fprintf(asmout, "PUSH AX ; return value of %s\n", $1->getName().c_str());
						}
                    }
                } 
				}
				else{
				error_count++;
				fprintf(error_output, "Line# %d: Inconsistent function call\n", line_count);
                //$$->setDataType("float");  
				}
			}
			fprintf(log_output, "Line# %d: factor : ID LPAREN argument_list RPAREN\n");
			argumentList.clear();
	}
	| LPAREN expression RPAREN{
		$$ = new SymbolInfo("("+$2->getName()+")", "factor");
		$$->setDataType($2->getDataType());
		
		fprintf(log_output, "Line# %d: factor : LPAREN expression RPAREN\n", line_count, $$->getName().c_str());
	}
	| CONST_INT {

		$$ = new SymbolInfo($1->getName(), "factor");
		$$->setDataType("int");
		fprintf(asmout, "PUSH %s\n", $$->getName().c_str());
		fprintf(log_output, "factor : CONST_INT\n");
	}
	| CONST_FLOAT{

		$$ = new SymbolInfo($1->getName(), "factor");

		$$->setDataType("float");
		fprintf(log_output, "factor : CONST_FLOAT\n");
	}
	| variable INCOP {

		$$ = new SymbolInfo($1->getName()+"++","variable");
		$$->setDataType($1->getDataType());
		if ($1->isArray()){
			fprintf(asmout, "POP BX\nPOP AX\nINC AX ; %s++\n", $1->getName().c_str());
			fprintf(asmout, "PUSH BP\nADD BP, BX\nMOV [BP], AX\nPOP BP\n");
		}
		else {
			fprintf(asmout, "INC AX\nMOV %d[BP], AX\n", $1->getStackOffset());
		}
		fprintf(log_output, "factor : variable INCOP\n");
	}
	| variable DECOP{

		$$ = new SymbolInfo($1->getName()+"++","variable");
		$$->setDataType($1->getDataType());
		if ($1->isArray()){
			fprintf(asmout, "POP BX\nPOP AX\nDEC AX ; %s++\n", $1->getName().c_str());
			fprintf(asmout, "PUSH BP\nADD BP, BX\nMOV [BP], AX\nPOP BP\n");
		}
		else {
			fprintf(asmout, "DEC AX\nMOV %d[BP], AX\n", $1->getStackOffset());
		}
		fprintf(log_output, "factor : variable DECOP\n");
	}
	;
	
argument_list : arguments{

				$$ = new SymbolInfo($1->getName(), "argument_list");

				fprintf(log_output, "argument_list : arguments\n");
				
}
			  |{

				$$=new SymbolInfo("", "argument_list");
				
				fprintf(log_output, "argument_list : \n");
			  }
			  ;
	
arguments : arguments COMMA logic_expression{

				$$ = new SymbolInfo($1->getName()+","+$3->getName(), "arguments");
				fprintf(log_output, "arguments : arguments COMMA logic_expression\n");
				//$$->setDataType($3->getDataType());
				SymbolInfo s("",$3->getDataType());
				s.setDataType($3->getDataType());
				s.setArraySize($3->getArraySize());
				
				argumentList.push_back(s);
}
	      | logic_expression{
				$$ = new SymbolInfo($1->getName(), "arguments");
				//$$->setDataType($1->getDataType());
				fprintf(log_output, "arguments : logic_expression\n");
				SymbolInfo s("",$1->getDataType());
				s.setDataType($1->getDataType());
				s.setArraySize($1->getArraySize());
				
				argumentList.push_back(s);
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

	log_output= fopen("log_output.txt","w");
	error_output= fopen("error_output.txt","w");
	parse_tree.open("parse_tree.txt",ios::out);
	asmout= fopen("code.asm","w");
	fclose(asmout);
	asmout= fopen("code.asm","a");

	yyin=fp;
	yyparse();
	
	
	fclose(log_output);
	fclose(error_output);
	parse_tree.close();
	fclose(asmout);

	return 0;
}

