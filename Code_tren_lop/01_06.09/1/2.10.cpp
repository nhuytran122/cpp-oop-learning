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

int* Cong(int n, int *a, int *b){
	int *s = new int [n];
	for(int i=0; i<n; i++){
		s[i] = a[i] + b[i];
	}
	return s;
}

float Cong(Phanso a1, Phanso a2){
	int Tu, Mau;
	Tu = a1.tu * a2.mau + a1.mau * a2.tu;
	Mau = a1.mau * a2.mau;
	return (float)Tu/Mau;
}

int main(){
	int n;
	cout << "CONG 2 VECTOR: \n";
	cout << "Kich thuoc cua vector: ";
	cin >> n;
	int *a = new int [n];
	int *b = new int [n];
	cout << "Vector thu nhat: ";
	Nhap(a, n);
	cout << "Vector thu hai: ";
	Nhap(b, n);
	int *c = Cong(n, a, b);
	cout << "KET QUA: "; 
	for(int i=0; i<n; i++){
		cout << c[i] << " ";
	}
	Phanso ps1, ps2;
	cout << "\nCONG 2 PHAN SO: ";
	cout << "\nPhan so thu 1: \n"; Nhap(ps1);
	cout << "Phan so thu 2: \n"; Nhap(ps2);
	cout << "KET QUA: " << Cong(ps1, ps2);
	delete a, b, c;
	return 0;
}
