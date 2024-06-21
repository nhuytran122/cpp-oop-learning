#include<bits/stdc++.h>
using namespace std;

class Mang{
	private:
		int size;
		int *A;
	public:
		Mang(int a = 0);
		void nhap();
		void xuat();
		Mang operator + (Mang a2);
		Mang operator - (Mang a2);
		int operator == (Mang a2);
		int operator != (Mang a2);
};

Mang::Mang(int a){
	size = a;
	A = new int[size];
}

void Mang::nhap(){
    cout << "\n\tNhap kich thuoc cua Mang: "; 
    cin >> size;
    A = new int[size];
    cout << "\tNhap cac phan tu cua mang: ";
    for(int i=0; i<size; i++){
        cin >> A[i];
    }
}

void Mang::xuat(){
	cout << "\t";
    for(int i=0; i<size; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

Mang Mang::operator + (Mang a2){
	Mang s;
	s.size = size > a2.size ? size : a2.size;
	for(int i = 0; i<size; i++){
   		s.A[i] = A[i] + a2.A[i];
  	}
  	
  	if(size > a2.size){
		for(int i = a2.size; i < size; i++){
		   	s.A[i] = A[i];
		}
	}
	else{
		for(int i = size; i < a2.size; i++){
		   	s.A[i] = a2.A[i];
		}
	}
	return s;
}

Mang Mang::operator - (Mang a2){
	Mang s;
	s.size = size > a2.size ? size : a2.size;
	for(int i = 0; i<size; i++){
   		s.A[i] = A[i] - a2.A[i];
  	}
  	
  	if(size > a2.size){
		for(int i = a2.size; i < size; i++){
		   	s.A[i] = A[i];
		}
	}
	else{
		for(int i = size; i < a2.size; i++){
		   	s.A[i] = a2.A[i];
		}
	}
	return s;
}

int Mang::operator == (Mang a2){
	if(size != a2.size) return 0;
	else {
		for(int i=0; i<size; i++){
			if(A[i] != a2.A[i]){
				return 0;
				exit(0);
			}
		}
		return 1;
	}
}

int Mang::operator != (Mang a2){
	if(size != a2.size) return 1;
	else {
		for(int i=0; i<size; i++){
			if(A[i] != a2.A[i]){
				return 1;
				exit(1);
			}
		}
		return 0;
	}
}

int main(){
	Mang a1, a2, s1, s2;
	a1.nhap();
	a2.nhap();
	a1.xuat();
	a2.xuat();
	
	cout << "\n\t1. TOAN TU + \n";
	s1 = a1 + a2;
	s1.xuat();
	
	cout << "\n\t2. TOAN TU - \n";
	s2 = a1 - a2;
	s2.xuat();
	
	cout << "\n\t3. TOAN TU ==\n";
	cout << "\ta1 == a2 : ";
	if(a1 == a2)
		cout << "Dung\n";
	else cout << "Sai\n";
	
	cout << "\n\t4. TOAN TU !=\n";
	cout << "\ta1 != a2 : ";
	if(a1 != a2)
		cout << "Dung\n";
	else cout << "Sai\n";
}
