#include<bits/stdc++.h>
using namespace std;

struct Phanso{
	int tu, mau;
};

void Nhap(Phanso &x){
	cout << "Nhap Tu so: "; cin >> x.tu;
	do{
		cout << "Nhap Mau so: "; 
		cin >> x.mau;	
		if(x.mau == 0) cout << "Nhap sai, vui long nhap lai mau so: ";		
	} while(x.mau == 0);
}

void XuatPS(Phanso x){
	cout << x.tu << "/" << x.mau;
}

void Nhap(int *a, int n){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int* Plus(int n, int *a, int *b){
	int *s = new int [n];
	for(int i=0; i<n; i++){
		s[i] = a[i] + b[i];
	}
	return s;
}

float Plus(Phanso x1, Phanso x2){
	int Tu, Mau;
	Tu = x1.tu * x2.mau + x1.mau * x2.tu;
	Mau = x1.mau * x2.mau;
	return (float)Tu/Mau;
}

int main(){
	int n;
	cout << "CONG 2 VECTOR: \n";
	cout << "Nhap kich thuoc cua vector: ";
	cin >> n;
	int *a = new int [n];
	int *b = new int [n];
	cout << "Nhap vector thu nhat: ";
	Nhap(a, n);
	cout << "Nhap vector thu hai: ";
	Nhap(b, n);
	cout << "Ket qua cong 2 vector: "; 
	int *c = Plus(n, a, b);
	for(int i=0; i<n; i++){
		cout << c[i] << " ";
	}
	
	Phanso ps1, ps2;
	cout << "\n\nCONG 2 PHAN SO: ";
	cout << "\nNhap phan so thu 1: \n"; Nhap(ps1);
	cout << "Nhap phan so thu 2: \n"; Nhap(ps2);
	cout << "Ket qua: " ; XuatPS(ps1); cout << " + " ; XuatPS(ps2); cout << " = " << Plus(ps1, ps2);
	delete a, b, c;
	return 0;
}
