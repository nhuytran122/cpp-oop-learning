#include<bits/stdc++.h>
#include<conio.h>
#define N 50 // so phan tu cua stack
using namespace std;

class Stack{
	int a[N];
	int top; // dinh cua stack
	public:
		Stack(){
			top = -1; // khoi tao stack rong
		}
		void push(int k); // nap 1 phan tu vao stack
		int pop(); // lay ra 1 ptu
		int getTop(){
			return top;
		}
};

void Stack::push(int k){
	if(top == N-1){
		cout << "\nStack day!";
		return ;
	}
	a[++top] = k; // cong roi moi dung
}

int Stack::pop(){
	if(top == -1){
		cout << "\nStack rong!";
		return 0;
	}
	return a[top--]; //dung roi moi tru
}

class Chuyendoi : public Stack{
	int n, k; //n: so nguyen duong he 10, k: co so(2/8/16)
	public:
		void Doicoso(){
			cout << "\nNhap so nguyen duong he 10: "; cin >> n;
			cout << "Nhap so so: (2/8/16): "; cin >> k;
			while(n != 0){
				int i = n % k;
				push(i);
				n = n/k;
			}
		}
		
		int getCs(){
			return k;
		}
		
		void xuat(){
			cout << "\nChuyen qua co so he " << k << " la: ";
			while(getTop() != -1){
				if(k == 16) cout << hex << pop(); // dung hex de doi sang he 16
				else cout << pop();
			}
		}
};

int main(){
	char ch;
	Chuyendoi ob;
	do{
		cout << "\nCHUONG TRINH CHUYEN DOI SO HE 10 SANG CO SO HE 2, HE 8, HE 16:\n";
		ob.Doicoso();
		ob.xuat();
		cout << "\nTiep tuc (y/n)? ";
		ch = getch();
	}while( ch != 'n');
	return 0;
}
