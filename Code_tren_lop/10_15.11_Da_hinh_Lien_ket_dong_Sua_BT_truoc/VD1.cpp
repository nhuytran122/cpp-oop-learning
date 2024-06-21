#include<bits/stdc++.h>
using namespace std;

class A{
	public:
		// * them tu virtual de bien thanh ham ao
		virtual void xuat(){
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
	a.xuat(); //goi ham lop A
	b.xuat(); // goi ham lop B
	b.A::xuat();//goi ham lop B
	
	cout << "\nCon tro: ";
	//Con tro p co kieu cua lop A:
	A *p;
	p = &a;
	p->xuat(); // goi ham lop A
	// sau khi them keyword virtual vao ham xuat o lop cha -> se goi ham xuat o lop B
	p = &b;
	p->xuat(); // goi ham cua lop B
}
