#include<bits/stdc++.h>
using namespace std;
int f(int &a, int b){
	++a;
	++b;
	return a+b;
}
int main(){
	int m = 3, n = 5;
	cout << "\n f = " << f(m,n); // f =10
	cout << "\n m = " << m; // m = 4
	cout << "\n n = " << n; // n = 5
	return 0;
}
