#include <iostream>
using namespace std;
int z; //z la bien toan cuc
int &f()//ham tra ve mot bi danh cua bien toan cuc z
{ 
	return z; 
}
int main(){
	z = 10;
	cout << "\n f() = " << f(); //f() = 10
	f() = 20; //luc nay z = ? = 20
	cout << "\nz = " << z;
	return 0;
}
