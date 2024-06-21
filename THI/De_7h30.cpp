#include<bits/stdc++.h>
using namespace std;

class Canbo{
	private:
		string ma, ten;
		int d, m, y;
	public:
		Canbo(){}
		Canbo(string mcb, string hoten, int dd, int mm, int yy){
			ma = mcb;
			ten = hoten;
			d = dd;
			m = mm;
			y = yy;
		}
		
		void Nhap(){
			cout << "\nNhap ma can bo: "; getline(cin, ma);
			cout << "Nhap ho ten: "; getline(cin, ten);
			cout << "Nhap ngay vao co quan: \n";
			cout << "Nhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			cin.ignore();
		}
		
		void Xuat(){
			cout << ma
				<< setw(20) << ten
				<< setw(25) << d << "/" << m << "/" << y;		
		}
		
		string getMa(){ return ma;	}
		string getTen(){ return ten;	}
		int getD(){ return d;	}
		int getM(){ return m;	}
		int getY(){ return y;	}
		
		void setMa(string mcb){
			ma = mcb;
		}
		void setTen(string hten){
			ten = hten;
		}
		void setD(int dd){
			d = dd;
		}
		void setM(int mm){
			m = mm;
		}
		
		void setY(int yy){
			y = yy;
		}
		
		int operator > (Canbo a){
			if(y > a.y) return 1;
			if(y == a.y && m > a.m) return 1;
			if(y == a.y && m == a.m && d > a.d) return 1;
			return 0;
		}
};

class Giangvien : public Canbo{
	private:
		string dv;
		float hsluong, phucap;
	public:
		Giangvien(){		}
		Giangvien(string mcb, string hoten, int dd, int mm, int yy, string dvi, float hso, float pc) : Canbo(mcb, hoten, dd, mm, yy){
			dv = dvi;
			hso = hsluong;
			phucap = pc;
		}
		void nhap(){
			Nhap();
			cout << "Nhap don vi: "; getline(cin, dv);
			cout << "Nhap he so luong: "; cin >> hsluong;
			cout << "Nhap phu cap: "; cin >> phucap;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << setw(20)  << dv
				<< setw(22) << hsluong
				<< setw(20) << phucap 
				<< setw(22) << getLuong() << endl;
		}
		
		string getDv(){ return dv;	}
		float getHsluong(){ return hsluong;	}
		float getPhucap(){ return phucap;	}
		
		long long getLuong(){
			return hsluong * 1490000 + phucap;
		}
		
		void setDv(string dvi){
			dv = dvi;
		}
		void setHsluong(float hs){
			hsluong = hs;
		}
		void setPhucap(float pc){
			phucap = pc;
		}	
		
			
		
};

int main(){
	int n, i;
	Giangvien gv[50];
	do{
		cout << "Nhap so luong giang vien: ";
		cin >> n;
	}while(n<0 || n>50);
	cin.ignore();
	for(i = 0; i<n; i++){
		gv[i].nhap();
	}
	
	for(i = 0; i < n-1; i++){
		for(int j = i+1; j<n; j++){
			if(gv[i] > gv[j]){
				Giangvien tmp;
				tmp = gv[i];
				gv[i] = gv[j];
				gv[j] = tmp;
			}
		}
	}
	
	cout << "\n\tDANH SACH GIANG VIEN TANG DAN THEP TIEU CHI NGAY VAO CO QUAN:\n";
	cout << "Ma can bo"
		<< setw(15) << "Ho ten"
		<< setw(25) << "Ngay vao co quan"
		<< setw(20) << "Don vi"
		<< setw(22) << "He so luong"
		<< setw(20) << "Phu cap"
		<< setw(22) << "Luong" << endl;
	long long S_luong = 0;
	for(i = 0; i<n; i++){
		gv[i].xuat();
		S_luong += gv[i].getLuong();
	}
	
	cout << "\n\tLUONG TRUNG BINH CUA CAC GIANG VIEN: " << S_luong/n;
	
	
	
	cout << "\n\t BANG LUONG CUA CAC GIANG VIEN THEO TUNG DON VI: \n";
	//sap xep can bo theo don vi
	for (i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if(gv[i].getDv() > gv[j].getDv()){
				Giangvien temp;
				temp = gv[i];
				gv[i] = gv[j];
				gv[j] = temp;
			}
		
		//in theo don vi
	for(i=0 ; i<n ; i++){
		if (i == 0 || gv[i].getDv() != gv[i-1].getDv())
			cout<<"\n DON VI : "<< gv[i].getDv()<<endl;
			gv[i].xuat();
	}
}
	
		
		
