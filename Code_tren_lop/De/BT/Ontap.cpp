#include<bits/stdc++.h>
using namespace std;

class Nguoi{
	private:
		string ho, ten, sdt;
		int d, m, y;
	public:
		void Nhap(){
			cout << "\nNhap ho dem: "; getline(cin, ho);
			cout << "Nhap ten: "; getline(cin, ten);
			cout << "Nhap ngay sinh: \n";
			cout << "Nhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			cin.ignore();
			cout << "Nhap so dien thoai: "; getline(cin, sdt);
		}
		
		void Xuat(){
			cout << "\nHo dem: " << ho;
			cout << "\nTen: " << ten;
			cout << "\nNgay sinh: " << d << "/" << m << "/" << y;
			cout << "\nSo dien thoai: " << sdt;
		}
		
		Nguoi(){}
		string getHo(){ return ho;	}
		string getTen(){ return ten;	}
		int getD(){ return d;	}
		int getM(){ return m;	}
		int getY(){ return y;	}
		string getSdt(){ return sdt;	}
};

class SV : public Nguoi{
	private:
		string msv;
		float dtb;
	public:
		SV(){}
		void nhap(){
			Nhap();
			cout << "Nhap MSV: "; getline(cin, msv);
			cout << "Nhap diem trung binh: "; cin >> dtb;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << "\nMSV: " << msv;
			cout << "\nDiem trung binh: " << dtb;
		}
		
		string getMsv(){ return msv;	}
		float getDtb(){ return dtb;	}
		
		int operator > (SV a){
			if(this->getY() > a.getY()) return 1;
			if(this->getY() == a.getY() && this->getM() > a.getM()) return 1;
			if(this->getY() == a.getY() && this->getM() == a.getM() && this->getD() > a.getD()) return 1;
			return 0;
		}
		
		int operator >= (SV a){
			return dtb >= a.dtb;
		}
		
		int operator < (SV a){
			if(this->getTen() != a.getTen()) 
				return this->getTen() < a.getTen();
			else return this->getHo() < a.getHo();
		}
};

int main(){
	SV sv[100];
	int n, i;
	do{
		cout << "Nhap so luong SV: "; cin >> n;
	}while(n<0 || n > 100);
	cin.ignore();
	for(i = 0; i<n; i++){
		sv[i].nhap();
	}
	
	for(i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (sv[i] < sv[j]){
	            SV tmp = sv[i];
	            sv[i] = sv[j];
	            sv[j] = tmp;
        	}
		}
	}
	
	cout << "\nDANH SACH SV THEO THU TU TANG DAN CUA TEN & HO DEM: \n";
	for(i = 0; i<n; i++){
		sv[i].xuat();
	}
	
	
	for(i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (sv[i] >= sv[j]){
	            SV tmp = sv[i];
	            sv[i] = sv[j];
	            sv[j] = tmp;
        	}
		}
	}
	cout << "\n\nDANH SACH SV THEO THU TU GIAM DAN CUA DTB: \n";
	for(i = 0; i<n; i++){
		sv[i].xuat();
	}
}
