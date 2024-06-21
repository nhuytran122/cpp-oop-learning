#include<bits/stdc++.h>
using namespace std;

class Nhanvien{
	private:
		string Manv, hoten;
		int sdt;
	public:
		Nhanvien(){
			Manv = hoten = "";
			sdt = 0;
		}
		
		void NhapMNV(){
			cout << "Nhap manv: ";
			getline(cin, Manv);
		}
		void Nhap(){
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "Nhap sdt: ";
			cin >> sdt;
			cin.ignore();
		}
		
		void Xuat(){
			cout << setw(10) << Manv
				<< setw(40) << hoten
				<< setw(50) << sdt << endl;
		}
		
		string getMa(){
			return Manv;
		}
		string getTen(){
			return hoten;
		}
};

class Quanly{
	private:
		Nhanvien nv[100];
		int N;
	public:
		void nhap();
		void xuat();
		
};

bool cmpTen(Nhanvien a, Nhanvien b){
    return a.getTen() < b.getTen();
}

void Quanly::nhap(){
	N = 0;
	do{
		cout << "\nNhap thong tin NV thu " << N+1 <<":\n";
		nv[N].NhapMNV();
		if(nv[N].getMa() != ""){
			nv[N].Nhap();
		}
		N++;
	}
	while(nv[N-1].getMa() != "");
	// de bo di doi tuong rong o cuoi
	N--;
	sort(nv, nv+N, cmpTen);
}

void Quanly::xuat(){
	cout << "\nDANH SACH NV DUOC SAP XEP THEO HO TEN:\n";
	cout << setw(10) << " MNV"
		<< setw(40) << " Ho va ten"
		<< setw(50) << "SDT\n"; 
	for(int i=0; i<N; i++){
		nv[i].Xuat();
	}
	string f;
	cout << "\nTIM KIEM NV THEO MA NHAN VIEN: \n";
	cout << "Nhap ma NV ban muon tim: ";
	getline(cin, f);
	
	bool ch = false;
	for(int i=0; i<N; i++){
		if(nv[i].getMa() == f){
			nv[i].Xuat();
			ch = true;
		}
	}
	if(ch == false)
		cout << "Khong tim thay NV co ma NV ban can tim!\n";
	
}

int main(){
	Quanly ob;
	ob.nhap();
	ob.xuat();
} 



