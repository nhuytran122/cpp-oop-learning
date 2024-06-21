#include<bits/stdc++.h>
using namespace std;

class A{
	public:
		// * them tu virtual de bien thanh ham ao
		void xuat(){
			cout << "\n Lop A";
		}
};

class B : public A{
	public:
		void xuat(){
			cout << "\n Lop B";
		}
};

int main(){
	A a;
	B b;
	B ob; // ob là d?i tu?ng c?a l?p con B
ob.xuat(); // G?i t?i hàm thành ph?n xuat() c?a l?p B
ob.A::xuat() ; // G?i t?i hàm thành ph?n xuat() c?a l?p A
	
//	cout << "\nCon tro: ";
//	//Con tro p co kieu cua lop A:
//	A *p;
//	p = &a;
//	p->xuat(); // goi ham lop A
//	// sau khi them keyword virtual vao ham xuat o lop cha -> se goi ham xuat o lop B
//	p = &b;
//	p->xuat(); // van la goi lop A
}
