// thanhtien = sl * tygia
// Cau 3: thao tac voi getThanhtien()
#include<bits/stdc++.h>
using namespace std;

class Giaodich{
	private:
		string magd, ngaygd;
		long long tiengd;
		
	public:
		Giaodich();
		Giaodich(string ma, string ngay, long long tien);
		void Nhap();
		void Xuat();
		string getMa();
		string getNgay();
		long getTiengd();
		
		void setMa(string ma);
		void setNgay(string ngay);
		void setTien(long long tien);
};

Giaodich::Giaodich(){ }
Giaodich::Giaodich(string ma, string ngay, long long tien){
	magd = ma;
	ngaygd = ngay;
	tiengd = tien;
}

void Giaodich::Nhap(){
	cout << "\nNhap ma giao dich: "; getline(cin, magd);
	cout << "Nhap ngay giao dich (dd/mm/yy): "; getline(cin, ngaygd);
	cout << "Nhap tien giao dich: "; cin >> tiengd;
}

void Giaodich::Xuat(){
	cout << magd
		<< setw(30) << ngaygd
		<< setw(25) << tiengd;
}

string Giaodich::getMa(){ return magd; }
string Giaodich::getNgay(){ return ngaygd; }
long Giaodich::getTiengd(){ return tiengd; }

void Giaodich::setMa(string ma){
	magd = ma;
}
void Giaodich::setNgay(string ngay){
	ngaygd = ngay;
}
void Giaodich::setTien(long long tien){
	tiengd = tien;
}

class Ngoaite : public Giaodich{
	private: 
		int sl;
		long long tygia;
		string loaitien;
	public:
		Ngoaite();
		Ngoaite(string ma, string ngay, long long tien, int sluong, long long tg, string loait);
		void nhap();
		void xuat();
		int getSl();
		long long getTygia();
		string getLoaitien();
		
		void setSl(int sluong);
		void setTygia(long long tg);
		void setLoaitien(string loait);
		
		long long getThanhtien(){
			return sl * tygia;
		}
		
		bool operator == (Ngoaite a){
			return this->getLoaitien() == a.getLoaitien();
		}
};

Ngoaite::Ngoaite(){}

Ngoaite::Ngoaite(string ma, string ngay, long long tien, int sluong, long long tg, string loait) : Giaodich(ma, ngay, tien){
	sl = sluong;
	tygia = tg;
	loaitien = loait;
}

void Ngoaite::nhap(){
	Giaodich::Nhap();
	cout << "Nhap so luong: "; cin >> sl;
	cout << "Nhap ty gia: " ; cin >> tygia;
	cin.ignore();
	cout << "Nhap loai tien: "; getline(cin, loaitien);
}

void Ngoaite::xuat(){
	Giaodich::Xuat();
	cout << setw(25) << sl
		<< setw(20) << tygia
		<< setw(25) << loaitien 
		<< setw(25) << getThanhtien() << endl;
}

int Ngoaite::getSl(){ return sl; }
long long Ngoaite::getTygia(){ return tygia; }
string 	Ngoaite::getLoaitien(){ return loaitien; }

void Ngoaite::setSl(int sluong){
	sl = sluong;
}

void Ngoaite::setTygia(long long tg){
	tygia = tg;
}

void Ngoaite::setLoaitien(string loait){
	loaitien = loait;
}

int main(){
	Ngoaite a[50];
	int i, j, n;
	set <string> s;
	do{
		cout << "Nhap so luong thuoc lop Ngoai te: ";
		cin >> n;
	}while(n<0 || n>50);
	cin.ignore();
	for(i = 0; i<n; i++){
		a[i].nhap();
	}
	
	string tmp2 = a[0].getLoaitien();
	cout << "\n\n\tTONG SO TIEN GIAO DICH CUA TUNG LOAI TIEN: \n";
	cout << "Ma giao dich"
		<< setw(25) << "Ngay giao dich"
		<< setw(25) << "So tien giao dich"
		<< setw(25) << "So luong"
		<< setw(20) << "Ty gia"
		<< setw(20) << "Loai tien"
		<< setw(25) << "Thanh tien" << endl; 
	for(i = 0; i<n-1; i++){
		for(j = i+1; j<n; j++){
			if(a[i].getLoaitien() > a[j].getLoaitien()){
				Ngoaite tmp;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;	
			}
		}
	}
	for(i = 0; i<n; i++){
		if(a[i].getLoaitien() == tmp2){
			cout << "Loai tien: " << tmp2 << endl;
			a[i].xuat();
		}
		else {
			tmp2 = a[i].getLoaitien();
			a[i].xuat();
		}
	}

	bool ch = false;
	cout << "\n\n\tCAC GIAO DICH CO SO TIEN TU 1 TY TRO LEN: \n";
	cout << "Ma giao dich"
		<< setw(25) << "Ngay giao dich"
		<< setw(25) << "So tien giao dich"
		<< setw(25) << "So luong"
		<< setw(20) << "Ty gia"
		<< setw(20) << "Loai tien"
		<< setw(25) << "Thanh tien" << endl; 
	for(i = 0; i<n; i++){
		if(a[i].getThanhtien() >= 1000000000){
			ch = true;
			a[i].xuat();
		}
	}
	if(ch == false) cout << "Khong co giao dich co so tien tu 1 ty tro len";
	
	cout << "\n\n\tDANH SACH GIAM DAN THEO SO TIEN GIAO DICH (THANH TIEN):\n";
		
	for(i = 0; i<n-1; i++){
		for(j = i+1; j<n; j++){
			if(a[i].getThanhtien() < a[j].getThanhtien()){
				Ngoaite tmp;
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	cout << "Ma giao dich"
		<< setw(25) << "Ngay giao dich"
		<< setw(25) << "So tien giao dich"
		<< setw(25) << "So luong"
		<< setw(20) << "Ty gia"
		<< setw(20) << "Loai tien"
		<< setw(25) << "Thanh tien" << endl; 
	for(i=0; i<n; i++){
		a[i].xuat();
	}
	
	
}















