#include <bits/stdc++.h>
using namespace std;
class Airship{
    protected:
		int khachMax, hangMax;
	public:
		void Nhap(){
			cout << "\nNhap so luong khach toi da: "; cin >> khachMax;
			cout << "Nhap trong luong hang hoa toi da: "; cin >> hangMax;
		}
		
		void Xuat(){
			cout << "\nSo luong khach toi da: " << khachMax;
			cout << "\nTrong luong hang hoa toi da: " << hangMax << endl;
		}
};

class Airplane:public Airship{
	private:
		string kieuDC;
	public:
		void NhapAP(){
			Nhap();
			cout << "Cac kieu dong co: ";
			cout << "\n1. Dong co canh quat";
			cout << "\n2. Dong co phan luc";
			cout << "\nLUA CHON (Mac dinh: Dong co canh quat): ";
			int lc;
			cin >> lc;
			if(lc == 1) kieuDC = "Dong co canh quat";
			else if(lc == 2) kieuDC = "Dong co phan luc";
			else kieuDC = "Dong co canh quat";
		}
		
		void XuatAP(){
			Xuat();
			cout << "Kieu dong co: " << kieuDC << endl;
		}		
};
 //Khinh khi cau
class Ballon:public Airship{
	private:
		string loaiNL;
	public:
		void NhapBL(){
			Nhap();
			cout << "Cac loai nhien lieu: \n";
			cout << "1. Nhien lieu hydrogen";
			cout << "\n2. Nhien lieu helium";
			int lc;
			cout << "\nLUA CHON (Mac dinh: Nhien lieu hydrogen): ";
			cin >> lc;
			if(lc == 1) loaiNL = "Nhien lieu hydrogen";
			else if(lc == 2) loaiNL = "Nhien lieu helium";	
			else loaiNL = "Nhien lieu hydrogen";
		}
		
		void XuatBL(){
			Xuat();
			cout << "Loai nhien lieu: " << loaiNL << endl;
		}
};

int main(){
	Airplane a[50];
	Ballon b[50];
	int m, n;
	cout << "\nNhap so luong AIRPLANE: ";
	cin >> m;
	for(int i=0; i<m; i++){
		a[i].NhapAP();
	}
	
	cout << "\nNhap so luong BALLON: ";
	cin >> n;
	for(int i=0; i<n; i++){
		b[i].NhapBL();
	}
	
	cout << "\n THONG TIN AIRPLANE: ";
	for(int i=0; i<m; i++){
		a[i].XuatAP();
	}
	
	cout << "\n THONG TIN BALLON: ";
	for(int i=0; i<n; i++){
		b[i].XuatBL();
	}
}
