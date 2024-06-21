#include<bits/stdc++.h>
using namespace std;
class Nhanvien{
	private:
		string manv, hoten, chucvu;
		int phucap, luong;
		float heso;
	public:
		void Nhap(){
			cout << "Nhap Ma NV: ";
			getline(cin, manv);
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			cout << "Nhap chuc vu: ";
			getline(cin, chucvu);
			cout << "Nhap he so luong: ";
			cin >> heso;
			cin.ignore();
			
		}
		
		string getManv(){
			return manv;
		}
		
		int getPhucap(){
			for(int i = 0; i<chucvu.length(); i++){
				chucvu[i] = tolower(chucvu[i]);
			}
			
			if(chucvu == "giam doc"){
				phucap = 5000000;
			}
			else if(chucvu == "pho giam doc"){
				phucap = 3000000;
			}
			else if(chucvu == "truong phong" || chucvu == "pho phong"){
				phucap = 1000000;
			}
			else {
				phucap = 0;
			}
			return phucap;	
		}
		
		int getLuong(){
			luong = heso * 1490000 + phucap;
			return luong;
		}
		
		void Xuat(){
			cout << manv
				<< setw(10) << hoten
				<< setw(22) << chucvu
				<< setw(18) << heso
				<< setw(20) << getPhucap()
				<< setw(24) << getLuong() << endl;
		}		
};

class Quanly{
	private:
		Nhanvien nv[50];
		int N;
	public:
		void nhap();
		void xuat();
		
};

void Quanly::nhap(){
	cout << "Nhap so luong nhan vien: ";
	cin >> N;
	cin.ignore();
	for(int i = 0; i<N; i++){
		cout << "\nNhap thong tin NV thu " << i+1 << endl; 
		nv[i].Nhap();
	}
}

void Quanly::xuat(){
	Nhanvien tmp;
	for(int i = 0; i<N; i++){
		for(int j = i+1; j<N; j++){
			if(nv[i].getManv() > nv[j].getManv()){
				tmp = nv[i];
				nv[i] = nv[j];
				nv[j] = tmp;
			}
		}
	}
	cout << "\nCAC NHAN VIEN TRONG CONG TY DUOC SAP XEP THEO MA NHAN VIEN: \n";
	cout << "MA NV"
		<< setw(10) << "HO TEN"
		<< setw(20) << "CHUC VU"
		<< setw(20) << "HE SO LUONG"
		<< setw(20) << "PHU CAP"
		<< setw(20) << "LUONG THANG" << endl;
	for (int i=0; i<N; i++){
		nv[i].Xuat();
	}
	
	int luongmin = nv[0].getLuong();
	for (int i=0; i<N; i++){
		if(nv[i].getLuong() < luongmin){
			luongmin = nv[i].getLuong();
		}
	}
	cout << "\nNHUNG NHAN VIEN CO LUONG THAP NHAT : \n";
	cout << "MA NV"
		<< setw(10) << "HO TEN"
		<< setw(20) << "CHUC VU"
		<< setw(20) << "HE SO LUONG"
		<< setw(20) << "PHU CAP"
		<< setw(20) << "LUONG THANG" << endl;
	for (int i=0; i<N; i++){
		if(luongmin == nv[i].getLuong()){
			nv[i].Xuat();
		}
	}
}

int main(){
	Quanly ob;
	ob.nhap();
	ob.xuat();
}
