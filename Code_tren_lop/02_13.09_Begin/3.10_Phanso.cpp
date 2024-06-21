#include<bits/stdc++.h>
using namespace std;
class PhanSo{
	private:
		int tu, mau;
	public:
		void Nhap();
		void Xuat();
		int getTu(){
			return tu;
		}
		int getMau(){
			return mau;
		}
		void rutgon();
		PhanSo Cong(PhanSo b);
		PhanSo Tru(PhanSo b);
		PhanSo Nhan(PhanSo b);
		PhanSo Chia(PhanSo b);
};

void PhanSo::Nhap(){
	cout << "\tNhap Tu so: "; cin >> tu;
	do{
		cout << "\tNhap Mau so: "; 
		cin >> mau;	
		if(mau == 0) cout << "\tNhap sai, vui long nhap lai mau so: \n";		
	} while(mau == 0);
}

void PhanSo::Xuat(){
	cout << "\t" << tu << "/" << mau;
}

int UCLN (int a, int b){
	if(b == 0) return a;
	return UCLN(b, a%b);
}
void PhanSo::rutgon(){
	int g = UCLN(tu, mau);
	tu /= g;
	mau /= g;
}

PhanSo PhanSo::Cong(PhanSo p){
	PhanSo s ;
	s.tu = (tu * p.mau) + (mau * p.tu);
	s.mau =  mau * p.mau;
    return s;
}

PhanSo PhanSo::Tru(PhanSo p){
	PhanSo s ;
	s.tu = (tu * p.mau) - (mau * p.tu);
	s.mau =  mau * p.mau;
    return s;
}

PhanSo PhanSo::Nhan(PhanSo p){
	PhanSo s;
	s.tu = tu * p.tu;
	s.mau = mau * p.mau;
    return s;
}
 
PhanSo PhanSo::Chia(PhanSo p){
	PhanSo s;
	s.tu = tu * p.mau;
	s.mau = mau * p.tu;
    return s;
}

int main(){
	PhanSo p1, p2, tong, hieu, tich, thuong;
	cout << "\tNhap phan so thu nhat: \n";
	p1.Nhap();
	cout << "\tNhap phan so thu hai: \n";
	p2.Nhap();
	tong = p1.Cong(p2);
	tong.rutgon();
	cout << "\t\tKET QUA: \n";
	p1.Xuat(); cout << "\t+" ; p2.Xuat(); cout << "\t=";
	if(tong.getTu() == 0){
		cout << "\t0";
	}
	else tong.Xuat();
	
	hieu = p1.Tru(p2);
	hieu.rutgon();
	cout <<"\n"; p1.Xuat(); cout << "\t-" ; p2.Xuat(); cout << "\t=";
	if(hieu.getTu() == 0){
		cout << "\t0";
	}
	else hieu.Xuat();
	
	tich = p1.Nhan(p2);
	tich.rutgon();
	cout <<"\n"; p1.Xuat(); cout << "\t*" ; p2.Xuat(); cout << "\t=";
	if(tich.getTu() == 0){
		cout << "\t0";
	}
	else tich.Xuat();
	
	thuong = p1.Chia(p2);
	thuong.rutgon();
	cout <<"\n"; p1.Xuat(); cout << "\t/" ; p2.Xuat(); cout << "\t=";
	if(thuong.getTu() == 0){
		cout << "\t0";
	}
	else thuong.Xuat();
	return 0;
}

