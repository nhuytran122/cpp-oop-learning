#include<bits/stdc++.h>
using namespace std;

class Dathuc{
    private:
        int size;
        int a[100];
    public:
    	void nhap();
    	void xuat();
    	Dathuc Cong(Dathuc f2);
    	Dathuc Tru(Dathuc f2);
};

void Dathuc::nhap(){
	cout << "Nhap bac cua da thuc: ";
	cin >> size;
	cout << "Nhap cac he so cua da thuc: \n";
	for(int i=0; i<=size; i++){
		cout << "\ta[" << i << "]: "; cin >> a[i];
	}
}

void Dathuc::xuat(){
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
			else cout << " + (" << a[i] << ")x";		
		}
		
		//Bac >= 2
		else{
			if(a[i] > 0){
				cout << " + " << a[i] << "x^" << i;
			}
			else if(a[i] == 0) cout << "";
			else cout << " + (" << a[i] << ")x^" << i;
		}
	}
}

Dathuc Dathuc::Cong(Dathuc a2){
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

Dathuc Dathuc::Tru(Dathuc a2){
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
	Dathuc f1, f2, f3, f4;
	cout << "\tNhap da thuc thu nhat:\n";
	f1.nhap();
	cout << "\n\tNhap da thuc thu hai:\n";
	f2.nhap();
	f3 = f1.Cong(f2);
	cout << "\n\tKET QUA CONG 2 DA THUC: \n\t";
	f1.xuat(); cout << "\n+\n\t"; f2.xuat(); cout << "\n=\n\t"; f3.xuat();
	
	f4 = f1.Tru(f2);
	cout << "\n\n\tKET QUA TRU 2 DA THUC: \n\t";
	f1.xuat(); cout << "\n-\n\t"; f2.xuat(); cout << "\n=\n\t"; f4.xuat();
}
    	
