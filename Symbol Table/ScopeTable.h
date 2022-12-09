#include<bits/stdc++.h>
#include"SymbolInfo.h"

using namespace std;


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
        hashArray=new SymbolInfo*[n];
         for(int i=0; i<n; i++)
        {
            this->hashArray[i] = nullptr;
        }
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
        delete hashArray[i];
    }
    delete[] hashArray;
}


};
