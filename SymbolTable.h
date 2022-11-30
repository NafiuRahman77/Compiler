#include<bits/stdc++.h>
#include"SymbolInfo.h"

#include"ScopeTable.h"


using namespace std;
class SymbolTable
{
private:
    ScopeTable *current;
public:
    SymbolTable(ScopeTable *scope) {
    current = scope;
}

ScopeTable* getCurrentScopeTable() const {
    return current;
}
void setCurrentScopeTable(ScopeTable *scope) {
    current = scope;
}

bool insertSymbol(SymbolInfo *symbol) {
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
   // if( current == nullptr ) return;
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
void SymbolTable::enterScope() {
    if(this->currentScopeTable == nullptr){
        cout << "Create a new SymbolTable" << endl << endl;
        return;
    }
    this->current->setChildScopeCount(current->getChildScopeCount() + 1);
    string newID = this->current->getID() + "." + to_string(this->current->getChildScopeCount());
    ScopeTable *newScope = new ScopeTable(this->current->getBucket(), newID);
    newScope->setParentScope(this->current);
    this->current = newScope;
}
};
