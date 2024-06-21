#include<bits/stdc++.h>
using namespace std;

class Sach{
	private:
		string ma, ten, tg, nxb;
		int sl;
	public:
		void nhap();
		void xuat();
		
};

void Sach::nhap(){
	cout << "Nhap ma sach: "; getline(cin, ma);
	cout << "Nhap ten sach: "; getline(cin, ten);
	cout << "Nhap tac gia: "; getline(cin, tg);
	cout << "Nhap NXB: "; getline(cin, nxb);
	cout << "Nhap so luong: "; cin >> sl;
	cin.ignore();
}

void Sach::xuat(){
	cout << ma << setw(10) << ten << setw(10) << tg << setw(10) << nxb << setw(10) << sl << endl;
}

int main(){
	int n;
	cout << "Nhap so luong sach: "; cin >> n; 
	cin.ignore();
	Sach a[50];
	for (int i=0; i<n; i++){
		cout << "Quyen sach thu " << i+1 << ": " << endl;
		a[i].nhap();
	}
	
	for (int i=0; i<n; i++){
		a[i].xuat();
	}
}


