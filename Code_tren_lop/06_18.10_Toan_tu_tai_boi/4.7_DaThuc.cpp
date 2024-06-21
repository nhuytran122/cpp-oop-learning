#include<bits/stdc++.h>
using namespace std;

class Dathuc{
    private:
        int size;
        int *a;
    public:
    	Dathuc(int b = 0);
    	void nhap();
    	void xuat();
    	Dathuc operator + (Dathuc a2);
    	Dathuc operator - (Dathuc a2);
};

Dathuc::Dathuc(int b){
	size = b;
	a = new int[size];
}

void Dathuc::nhap(){
	cout << "\n\tNhap bac cua da thuc: ";
	cin >> size;
	a = new int[size];
	cout << "\tNhap cac he so cua da thuc: \n";
	for(int i=0; i<=size; i++){
		cout << "\ta[" << i << "]: "; cin >> a[i];
	}
}

void Dathuc::xuat(){
	cout << "\tDA THUC: ";
	for(int i=0; i<=size; i++){
		//He so tu do
		if(i == 0){
			if(a[i] != 0) cout << a[i];
			else cout << "";
		}
		
		//Bac 1: ax
		else if(i == 1){
			if(a[i] > 0){
				cout << " + " << a[i] << "x";	
			}
			else if(a[i] == 0) cout << "";
			else cout << a[i] << "x";		
		}
		
		//Bac >= 2
		else{
			if(a[i] > 0){
				cout << " + " << a[i] << "x^" << i;
			}
			else if(a[i] == 0) cout << "";
			else cout << " " << a[i] << "x^" << i;
		}
	}
}

Dathuc Dathuc::operator + (Dathuc a2){
	Dathuc s;
	s.size = size > a2.size ? size : a2.size;
	
	for(int i = 0; i<=size; i++){
   			s.a[i] = a[i] + a2.a[i];
  	}
	
	//Bac cua  f1 > f2
	if(size > a2.size){
		for(int i = a2.size+1; i <= size; i++){
		   	s.a[i] = a[i];
		}
	}
	//Bac cua  f2 > f1
	else{
		for(int i = size+1; i <= a2.size; i++){
		   	s.a[i] = a2.a[i];
		}
	}
	return s;
}

Dathuc Dathuc::operator - (Dathuc a2){
	Dathuc s;
	s.size = size > a2.size ? size : a2.size;

	for(int i = 0; i<=size; i++){
   			s.a[i] = a[i] - a2.a[i];
  	}
	
	//Bac cua  f1 > f2
	if(size > a2.size){
		for(int i = a2.size+1; i <= size; i++){
		   	s.a[i] = a[i];
		}
	}
	//Bac cua  f2 > f1
	else if(a2.size > size){
		for(int i = size+1; i <= a2.size; i++){
		   	s.a[i] = a2.a[i];
		}
	}
	return s;
}

int main(){
	Dathuc a1, a2, s1, s2;
	a1.nhap();
	a1.xuat();
	a2.nhap();
	a2.xuat();
	
	cout << "\n\n\t1. KET QUA CONG 2 DA THUC CUA TOAN TU + : \n\t";
	s1 = a1 + a2;
	a1.xuat(); cout << "\n\t + \n\t"; a2.xuat(); cout << "\n\t = \n\t"; s1.xuat();
	
	cout << "\n\n\t2. KET QUA TRU 2 DA THUC CUA TOAN TU - : \n\t";
	s2 = a1 - a2;
	a1.xuat(); cout << "\n\t - \n\t"; a2.xuat(); cout << "\n\t = \n\t"; s2.xuat();
}
