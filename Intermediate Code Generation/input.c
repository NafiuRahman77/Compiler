int foo(int a){
	if(a == 0){
		return 1;
	}
	return foo(a-1) * a;
}
 
 
int main(){
	int i,j,k;
	i = 7;
	j = 3;
 
	k = foo(i) ;
	println(k);
 
	return 0;
}