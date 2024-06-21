#include<bits/stdc++.h>
using namespace std;

struct Phanso{
	int tu, mau;
};

void Nhap(Phanso &x){
	cout << "Tu so: "; cin >> x.tu;
	do{
		cout << "Mau so: "; 
		cin >> x.mau;	
		if(x.mau == 0) cout << "Nhap sai, yeu cau nhap lai mau so: ";		
	} while(x.mau == 0);
}

void Nhap(int *a, int n){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

float Nhan(Phanso a1, Phanso a2){
	int Tu, Mau;
	Tu = a1.tu * a2.tu;
	Mau = a1.mau * a2.mau;
	return (float)Tu/Mau;
}

int Nhan(int n, int *a, int *b){
	int s = 0;
	for(int i=0; i<n; i++){
		s += a[i] * b[i];
	}
	return s;
}

int main(){
    int n;
	cout << "NHAN VO HUONG CUA 2 VECTOR: \n";
	cout << "Kich thuoc cua vector: ";
	cin >> n;
	int *a = new int [n];
	int *b = new int [n];
	cout << "Vector thu nhat: ";
	Nhap(a, n);
	cout << "Vector thu hai: ";
	Nhap(b, n);
    cout << "KET QUA: " << Nhan(n, a, b);
	Phanso ps1, ps2;
	cout << "\nCONG 2 PHAN SO: ";
	cout << "\nPhan so thu 1: \n"; Nhap(ps1);
	cout << "Phan so thu 2: \n"; Nhap(ps2);
	cout << "KET QUA: " << Nhan(ps1, ps2);
	delete a, b;
	return 0;
}
