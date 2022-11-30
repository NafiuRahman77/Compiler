#include<bits/stdc++.h>
#include"SymbolInfo.h"

using namespace std;

class ScopeTable{

private:
    int num_buckets;
    SymbolInfo** hashArray;
    ScopeTable* parent;
    string unique_id;
public:
    ScopeTable(int n, string id){
        num_buckets=n;
        hashArray=new SymbolInfo*[n]();
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
    string getID(){
        return unique_id;
    }
    void setID(string id){
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
    int ScopeTable::getChildCounter() const {
    return childCounter;
}

void ScopeTable::setChildCounter(int childCounter) {
    ScopeTable::childCounter = childCounter;
}


    long long int int SDBMHash(string str) {
	unsigned int hash = 0;
	unsigned int i = 0;
	unsigned int len = str.length();

	for (i = 0; i < len; i++)
	{
		hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
	}

	return hash%num_buckets;

}

    bool insertSym(SymbolInfo *symbol)
    {
        long long int pos = SDBMHash(symbol->getName());
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
            int i = SDBMHash(symbol);

            int count = 0;

            SymbolInfo *current = hashArray[i];

            if(current->getName()==symbol){
                 hashArray[i] = current->getNext();
                 delete current;
                 cout << "Deleted " <<"'"<<symbol<<"' " << "from ScopeTable# " <<unique_id << "at position "<<i+1<<", "<<count+1<<endl;
                       endl ;
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
    long long int i = SDBMHash(symbol);

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
