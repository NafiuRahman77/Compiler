
#include <bits/stdc++.h>


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
    delete symNext;
 }


};
unsigned long long int SDBMHash(string str) {
	unsigned long long int hash = 0;
	unsigned long long int i = 0;
    unsigned long long int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
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
        hashArray=new SymbolInfo*[n];
         for(int i=0; i<n; i++)
        {
            this->hashArray[i] = nullptr;
        }
        unique_id=id;
        parent=nullptr;
        cout << "ScopeTable#  " << unique_id << " created"<< endl ;

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
        int pos = SDBMHash(symbol->getName())%num_buckets;
        SymbolInfo* symInf=hashArray[pos];

        if( symInf != nullptr){
            int cnt = 1;
            SymbolInfo *current = hashArray[pos];

            while(current!=nullptr)
            {
                if(current->getName() == symbol->getName())
                {
                    //cout << "This word already exists" << endl;
                    cout << "'" << current->getName() << "' "  << "already exists in the current ScopeTable" << endl ;
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
            cout << "Inserted in ScopeTable# " << unique_id << " at position " << pos << ", " << cnt << endl ;
            return true;
        }
        else{
            int cnt = 0;
            hashArray[pos] = symbol;
            cout << "Inserted in ScopeTable# " << unique_id << " at position " << pos << ", " << cnt << endl ;
            return true;
        }
}

bool deleteSym(string symbol) {
      SymbolInfo* lookedUp=lookup(symbol);
      if((lookedUp != nullptr)) {
            //cout << "Found it" << endl;
            int i = SDBMHash(symbol)%num_buckets;

            int count = 0;

            SymbolInfo *current = hashArray[i];

            if(current->getName()==symbol){
                 hashArray[i] = current->getNext();
                 delete current;
                 cout << "Deleted " <<"'"<<symbol<<"' " << "from ScopeTable# " <<unique_id << "at position "<<i+1<<", "<<count+1<<endl;

                 return true;
            }
            else{

                 SymbolInfo *prev = current;
                 while (current != nullptr) {
                     if (current->getName() == symbol) {
                         prev->setNext(current->getNext());
                         cout << "Deleted " <<"'"<<symbol<<"' " << "from ScopeTable# " <<unique_id << "at position "<<i+1<<", "<<count+1<<endl;
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
         cout << "Not found in the current ScopeTable" << endl;
         return false;
     }
 }

    SymbolInfo* lookup(string symbol)
  {
    int flag=0;

    int cnt = 0;
    long long int i = SDBMHash(symbol)%num_buckets;

    SymbolInfo *current = hashArray[i];
    while(current != nullptr)
    {
        if(current->getName() == symbol)
             {
                 cout <<"'"<<symbol<<"'"<< " Found in ScopeTable# " << unique_id <<  " at position " << i << ", " << cnt << endl ;
                 flag=1;
                 return current;
             }
        cnt++;
        current = current->getNext();

     }

     if(!flag){
       return nullptr;
     }
   }

   void printScope() {

    cout << "ScopeTable# " << unique_id << endl;
    for(int i=0; i<num_buckets; i++){
        SymbolInfo *current = hashArray[i];
        cout << i+1 << " --> ";
        while(current!= nullptr){
            cout << "< " << current->getName() << " : " << current->getType() << " > ";
            current = current->getNext();
        }
        cout << endl;
    }
    cout << endl;
}
 ~ScopeTable(){

   // delete parent;
    for (int i=0; i<num_buckets; i++){
        delete hashArray[i];
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
        cout<<"Can't remove the parent scope"<<endl;
        return;
    }
    ScopeTable *deleted = current;
    ScopeTable *parScope = current->getParent();
    current=parScope;
    cout<<"ScopeTable with id "<<deleted->getID()<<" removed"<<endl;
    delete deleted;

}
SymbolInfo* lookUpSymbol(string symbol) {

    ScopeTable *curr = current;
    SymbolInfo *s =  curr->lookup(symbol);
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
    cout<<"Not found in any of the ScopeTables "<<endl;
    return nullptr;
    }

}
void enterScope() {
    if(this->current == nullptr){
        cout << "Create a new SymbolTable" << endl ;
        return;
    }

    counter=counter+1;
    ScopeTable *newScope = new ScopeTable(current->getBucket(), counter);
    newScope->setParent(current);
    current = newScope;
}
};


int main() {
    int bucketSize = 10;
    cin>>bucketSize;
    ScopeTable *scopeTable = new ScopeTable(bucketSize, 1);

    SymbolTable symbolTable(scopeTable);
    string command;
    while(cin>>command){
        if( command == "I" ){
            string name,type;
            cin>>name>>type;
            cout<<command<<" "<<name<<" "<<type<<endl<<endl;
            SymbolInfo* symbolInfo=new SymbolInfo(name,type);
            symbolTable.insertSymbol(symbolInfo);
        }else if( command == "L" ){
            string name;
            cin>>name;
            cout<<command<<" "<<name<<endl<<endl;
            symbolTable.lookUpSymbol(name);
        }else if( command == "D" ){
            string name;
            cin>>name;
            cout<<command<<" "<<name<<endl<<endl;
            symbolTable.removeSymbol(name);
        }else if( command == "P" ){
            string code;
            cin>>code;
            cout<<command<<" "<<code<<endl<<endl;
            if( code == "A" )
                symbolTable.printAllScopeTable();
            else
                symbolTable.printCurrentScopeTable();
        }else if( command == "S" ){
            cout<<command<<endl<<endl;
            symbolTable.enterScope();
        }else if( command == "E" ){
            cout<<command<<endl<<endl;
            symbolTable.exitScope();
        }else if( command == "Q" ){
            return 0;
        }
    }
    return 0;
}
