#include<bits/stdc++.h>
using namespace std;

class Stack{
	private:
		int top = -1, size = 100, a[100];
	public: 
		void push(int value);
		void Xuat();
		bool isEmpty();
		bool isFull();
		void pop();
};

void Stack::Xuat(){
	cout << "\t";
	for(int i=0; i<=top; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

bool Stack::isFull(){
    if(top >= size-1){
        return true;
    }
	else return false;
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
	else return false;
}

void Stack::push(int value){
	if(isFull() == true){
		cout << "\tStack da Full! Khong the them\n";
	}
	else{
		top++;
		a[top] = value;
	}
}

void Stack::pop(){
    if(isEmpty() == true){
        cout << "\tStack da rong. Khong the xoa!\n";
    }else{
        top--;
    }
}


int main(){
	Stack s1;
	int lc;
	while(1){
		cout << "\n\t1. Nhap 1 de nap 1 phan tu vao Stack.\n";
		cout << "\t2. Nhap 2 de in noi xung Stack.\n";
		cout << "\t3. Nhap 3 de lay ra (xoa) 1 phan tu khoi Stack.\n";
		cout << "\t4. Nhap 4 de kiem tra Stack co rong khong.\n";
		cout << "\t0. Nhap 0 de ket thuc.\n";
		cout << "\n\tNhap lua chon: "; cin >> lc;
		if(lc == 1){
			int a;
			cout << "\tNhap phan tu can them: "; cin >> a;
			s1.push(a);
		}
		else if(lc == 2){
			s1.Xuat();
		}
		else if(lc == 3){
			s1.pop();
		}
		else if(lc == 4){
			if(!s1.isEmpty()) cout << "\tNO\n";
			else cout << "\tYES\n";
		}
		else if(lc == 0) break;
	}
}
