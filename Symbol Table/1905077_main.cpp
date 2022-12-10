#include <bits/stdc++.h>
#include<sstream>

using namespace std;
class SymbolInfo{
private:
    string symName;
    string symType;
    SymbolInfo* symNext;

public:

    SymbolInfo(string name, string type)
   {
    symName = name;
    symType = type;
    symNext= nullptr;
   }
   string getName(){
      return symName;
   }
   void setName(string name){
       symName=name;
   }
   string getType(){
      return symType;
   }
   void setType(string type){
      symType=type;
   }
   SymbolInfo* getNext(){
      return symNext;
   }
   void setNext(SymbolInfo* next ){
      symNext=next;
   }
   ~SymbolInfo(){
    //delete symNext;
 }


};
unsigned long long int SDBMHash(string str, int n) {
	unsigned long long int hash = 0;
	unsigned long long int i = 0;
    unsigned long long int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
		hash%=n;
	}

	return hash;

}
class ScopeTable{

private:
    int num_buckets;
    SymbolInfo** hashArray;
    ScopeTable* parent;
    int unique_id;
public:
    ScopeTable(int n, int id){
        num_buckets=n;
        hashArray=new SymbolInfo*[n]();

        unique_id=id;
        parent=nullptr;
        cout << "\tScopeTable# " << unique_id << " created"<< endl ;

    }

    int getBucket(){
        return num_buckets;
    }
    void setBucket(int num){
        num_buckets=num;
    }
    int getID(){
        return unique_id;
    }
    void setID(int id){
        unique_id=id;
    }
    ScopeTable* getParent() {
    return parent;
    }
    void setParent(ScopeTable* par){
        parent=par;
    }
    SymbolInfo **getHashArray() {
        return hashArray;
    }

    void setHashArray(SymbolInfo **hashArr) {
        hashArray = hashArr;
    }


    bool insertSym(SymbolInfo *symbol)
    {
        int pos = SDBMHash(symbol->getName(),num_buckets)%num_buckets;
        SymbolInfo* symInf=hashArray[pos];

        if( symInf != nullptr){
            int cnt = 1;
            SymbolInfo *current = hashArray[pos];

            while(current!=nullptr)
            {
                if(current->getName() == symbol->getName())
                {

                    cout << "\t'" << current->getName() << "' "  << "already exists in the current ScopeTable" << endl ;
                    return false;
                }
            current = current->getNext();
            }
            current = hashArray[pos];
            while(current->getNext()!=nullptr)
            {
                current = current->getNext();
                cnt++;
            }
            current->setNext(symbol);
            cout << "\tInserted in ScopeTable# " << unique_id << " at position " << pos+1 << ", " << cnt+1 << endl ;
            return true;
        }
        else{
            int cnt = 0;
            hashArray[pos] = symbol;
            cout << "\tInserted in ScopeTable# " << unique_id << " at position " << pos+1 << ", " << cnt+1 << endl ;
            return true;
        }
}

bool deleteSym(string symbol) {
    int flag=0;
    int cnt = 0;
    long long int i = SDBMHash(symbol,num_buckets)%num_buckets;

    SymbolInfo *current = hashArray[i];
    SymbolInfo* lookedUp;
    while(current != nullptr)
    {
        if(current->getName() == symbol)
             {
                 flag=1;
                 break;
             }
        cnt++;
        current = current->getNext();

     }

     if(!flag){
       lookedUp= nullptr;
     }
     else{

        lookedUp= current;
     }

      if((lookedUp != nullptr)) {

            int i = SDBMHash(symbol,num_buckets)%num_buckets;

            int count = 0;

            SymbolInfo *current = hashArray[i];


            if(current->getName()==symbol){
                 hashArray[i] = current->getNext();
                 delete current;
                 cout << "\tDeleted " <<"'"<<symbol<<"' " << "from ScopeTable# " <<unique_id << " at position "<<i+1<<", "<<count+1<<endl;

                 return true;
            }
            else{

                 SymbolInfo *prev = current;
                 while (current != nullptr) {
                     if (current->getName() == symbol) {
                         prev->setNext(current->getNext());
                         cout << "\tDeleted " <<"'"<<symbol<<"' " << "from ScopeTable# " <<unique_id << " at position "<<i+1<<", "<<count+1<<endl;
                         delete current;
                         return true;
                     }
                     count++;
                     prev=current;
                     current = current->getNext();

                 }
             }
    return true;

     }
     else  {
         cout << "\tNot found in the current ScopeTable" << endl;
         return false;
     }
 }

    SymbolInfo* lookup(string symbol)
  {
    int flag=0;
    int cnt = 0;
    long long int i = SDBMHash(symbol,num_buckets)%num_buckets;

    SymbolInfo *current = hashArray[i];
    while(current != nullptr)
    {
        if(current->getName() == symbol)
             {
                 flag=1;
                 break;
             }
        cnt++;
        current = current->getNext();

     }

     if(!flag){
       return nullptr;
     }
     else{
        cout <<"\t'"<<symbol<<"'"<< " found in ScopeTable# " << unique_id <<  " at position " << i+1 << ", " << cnt+1 << endl ;
        return current;
     }
   }

   void printScope() {

    cout << "\tScopeTable# " << unique_id << endl;
    for(int i=0; i<num_buckets; i++){
        SymbolInfo *current = hashArray[i];
        cout <<"\t"<< i+1 << "--> ";
        while(current!= nullptr){
            cout << "<" << current->getName() << "," << current->getType() << "> ";
            current = current->getNext();
        }
        cout << endl;
    }

}
 ~ScopeTable(){


    for (int i=0; i<num_buckets; i++){
        //delete hashArray[i];
        SymbolInfo *curr = hashArray[i];
        while(curr!=nullptr){
            SymbolInfo *s = curr->getNext();
            delete curr;
            curr = s;
        }
    }
    delete[] hashArray;
}


};

class SymbolTable
{
private:
    ScopeTable *current;
    int counter;
public:
    SymbolTable(ScopeTable *scope) {
    current = scope;
    counter=1;
}

ScopeTable* getCurrentScopeTable() const {
    return current;
}
void setCurrentScopeTable(ScopeTable *scope) {
    current = scope;
}

bool insertSymbol(SymbolInfo* symbol) {
     bool flag=current->insertSym(symbol);
     return flag;
}
bool removeSymbol(string symbol) {
    bool flag = current->deleteSym(symbol);
    return flag;
}
void printCurrentScopeTable() {
    current->printScope();
}
void printAllScopeTable() {
    ScopeTable *curr = current;
    while (curr!= nullptr){
        curr->printScope();
        curr = curr->getParent();
    }
}

void exitScope() {
    if( current->getID() == 1 ){
        cout<<"\tScopeTable# 1 cannot be removed"<<endl;
        return;
    }
    ScopeTable *deleted = current;
    ScopeTable *parScope = current->getParent();
    current=parScope;
    cout<<"\tScopeTable# "<<deleted->getID()<<" removed"<<endl;
    delete deleted;

}
SymbolInfo* lookUpSymbol(string symbol) {

    ScopeTable *curr = current;
    SymbolInfo* s;
    int flag=0;

    while (curr!= nullptr){
        s =  curr->lookup(symbol);
        if( s!= nullptr ){
            flag=1;
            break;
        }
        curr = curr->getParent();
    }
    if(flag){
        return s;
    }
    else{
    cout<<"\t'"<<symbol<<"'"<< " not found in any of the ScopeTables"<<endl;
    return nullptr;
    }

}
void enterScope() {
    if(this->current == nullptr){
        cout << "\tCreate a new SymbolTable" << endl ;
        return;
    }

    counter=counter+1;
    ScopeTable *newScope = new ScopeTable(current->getBucket(), counter);
    newScope->setParent(current);
    current = newScope;
}

~SymbolTable(){
    while(current!=nullptr){

        cout<<"\tScopeTable# "<<current->getID()<<" removed"<<endl;
        ScopeTable* par=current->getParent();
        delete current;
        current=par;
    }
}
};


int main() {

ifstream file;
file.open("in.txt");
if(!file.is_open())
{
cout<<"Unable to open the file."<<endl;
return 0;
}

ofstream out("out.txt");
streambuf *coutbuf = cout.rdbuf();
cout.rdbuf(out.rdbuf());


string line, command, word2, word3, word4;
istringstream iss;
getline(file, line);
int bucketSize = stoi(line);
ScopeTable *scopeTable = new ScopeTable(bucketSize, 1);
SymbolTable symbolTable(scopeTable);
int commandCount=1;

while(getline(file, line))
{
    iss.clear();
    iss.str(line);;
    iss>>command;
     if( command == "I" ){
            string name,type, extra;
            iss>>name>>type>>extra;
            if(name.empty() || type.empty() || !(extra.empty())){
                if(name.empty()){
                  cout<<"Cmd "<<commandCount<<": "<<command<<endl;
                }
                else if(type.empty()){
                    cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<endl;
                }
                else{
                cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<" "<<type<<" "<<extra;
                while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                }
                cout<<"\tNumber of parameters mismatch for the command I"<<endl;
            }
            else{
            cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<" "<<type<<endl;
            SymbolInfo* symbolInfo=new SymbolInfo(name,type);
            symbolTable.insertSymbol(symbolInfo);
            }
        }else if( command == "L" ){
            string name,extra;
            iss>>name>>extra;
            if(name.empty() || !(extra.empty())){
                if(name.empty()){
                  cout<<"Cmd "<<commandCount<<": "<<command<<endl;
                }
                else {

                 cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<" "<<extra;
                 while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                }
                 cout<<"\tNumber of parameters mismatch for the command L"<<endl;
            }else{
            cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<endl;
            symbolTable.lookUpSymbol(name);
            }
        }else if( command == "D" ){
            string name,extra;
            iss>>name>>extra;
            if(name.empty() || !(extra.empty())){
                 if(name.empty()){
                  cout<<"Cmd "<<commandCount<<": "<<command<<endl;
                }
                else {

                 cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<" "<<extra;
                 while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                }
                cout<<"\tNumber of parameters mismatch for the  command D"<<endl;
            }else{
            cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<endl;
            symbolTable.removeSymbol(name);
            }
        }else if( command == "P" ){
            string name,extra;
            iss>>name>>extra;
            if(name.empty() || !(extra.empty())){
                 if(name.empty()){
                  cout<<"Cmd "<<commandCount<<": "<<command<<endl;
                }
                else {

                 cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<" "<<extra;
                 while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                }
                 cout<<"\tNumber of parameters mismatch for the command P"<<endl;
            }
            else{
            cout<<"Cmd "<<commandCount<<": "<<command<<" "<<name<<endl;
            if( name == "A" )
                symbolTable.printAllScopeTable();
            else
                symbolTable.printCurrentScopeTable();
            }
        }else if( command == "S" ){
            string extra;
            iss>>extra;
            if( !(extra.empty())){
                cout<<"Cmd "<<commandCount<<": "<<command<<" "<<extra;
                while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                cout<<"\tNumber of parameters mismatch for the command S"<<endl;
            }

            else{
            cout<<"Cmd "<<commandCount<<": "<<command<<endl;
            symbolTable.enterScope();
            }
        }else if( command == "E" ){
            string extra;
            iss>>extra;
            if( !(extra.empty())){
                 cout<<"Cmd "<<commandCount<<": "<<command<<" "<<extra;
                 while(iss.good()){
                    iss>>extra;
                    cout<<" "<<extra;
                }
                cout<<endl;
                cout<<"\tNumber of parameters mismatch for the command E"<<endl;
            }
            else{

            cout<<"Cmd "<<commandCount<<": "<<command<<endl;
            symbolTable.exitScope();
            }
        }else if( command == "Q" ){
            cout<<"Cmd "<<commandCount<<": "<<command<<endl;
            return 0;
        }
        commandCount++;


}

file.close();
return 0;
}
