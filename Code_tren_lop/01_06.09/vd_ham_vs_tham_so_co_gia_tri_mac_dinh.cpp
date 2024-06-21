#include <iostream>
using namespace std;
void ht(char *dc="TRUNG TAM", int n=5){
	for(int i=0;i<n;++i)
		cout<<"\n" <<dc;
}
int main(){
	ht();//
	ht("ABC",3); //3 lan ABC
	ht("DEF"); // 5 lan DEF
	return 0;
}
