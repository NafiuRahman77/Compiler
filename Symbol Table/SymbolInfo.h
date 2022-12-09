#include<bits/stdc++.h>
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
