#include<bits/stdc++.h>
#include"SymbolInfo.h"

#include"ScopeTable.h"


using namespace std;

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

~SymbolTable(){
    while(current!=nullptr){

        cout<<"ScopeTable# "<<current->getID()<<" removed"<<endl;
        ScopeTable* par=current->getParent();
        delete current;
        current=par;
    }
}
};
