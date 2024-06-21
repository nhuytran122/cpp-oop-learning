#include<bits/stdc++.h>
using namespace std;

class Canbo{
	protected:
		string macb, ten, gt;
	public:
		void Nhap(){
			cout << "\nNhap ma can bo: "; getline(cin, macb);
			cout << "Nhap ho ten: "; getline(cin, ten);
			cout << "Nhap gioi tinh: "; getline(cin, gt);
		}
		
		void Xuat(){
			cout << "\nMa can bo: " << macb;
			cout << "\nHo ten: " << ten;
			cout << "\nGioi tinh: " << gt;
		}
		
		string getMa(){
			return macb;
		}
		
		string getTen(){
			return ten;
		}
		
		string getGt(){
			return gt;
		}
};

class Date {
	private:
		int d, m, y;
	public:
		Date() {};
		Date(int d, int m, int y){
			this -> d = d;
			this -> m = m;
			this -> y = y;
		}
		bool operator > (Date ob){
			if (y > ob.y) return true;
			if (y == ob.y and m > ob.m) return true;
			if (y == ob.y and m == ob.m and d > ob.d) return true;
			return false;
		}
		
		void nhap_date(){
			cout << "\nNhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			cin.ignore();
		}
		
		void xuat_date(){
			cout << d << "/" << m << "/" << y;
		}
};
class Congnhan : public Canbo{
	private:
		int bac, sn;
		Date ngayki;
	public:
		void nhap(){
			Nhap();
			do{
				cout << "Nhap bac (1-3): "; cin >> bac;
				if(bac < 1 || bac > 3) cout << "Du lieu khong dung! Vui long nhap lai!\n";
			}
			while(bac < 1 || bac > 3);
			cout << "Nhap so ngay lam viec: "; cin >> sn;
			cout << "Nhap ngay ki hop dong: "; ngayki.nhap_date();
		}
		
		void xuat(){
			Xuat();
			cout << "\nBac: " << bac;
			cout << "\nSo ngay lam viec: " << sn;
			cout << "\nNgay ki hop dong: "; ngayki.xuat_date();
			
			cout << "\nTien luong: " << getLuong() << endl;
		}
		
		long long getLuong(){
			long long tiencong;
			if (bac == 1){
				tiencong = 300000;
			}
			else if(bac == 2) tiencong = 350000;
			else tiencong = 400000;
			return tiencong* sn;
		}
		
		bool operator > (Congnhan ob2){
			return ngayki > ob2.ngayki;
		}		
			
};

int main(){
	int i, n;
	Congnhan b[50];
	cout << "\nNhap so luong can bo thuoc lop cong nhan: "; cin >> n;
	cin.ignore();
	for(i = 0; i<n; i++){
		b[i].nhap();
	}
	for(i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (b[i] > b[j]){
	            Congnhan tmp = b[i];
	            b[i] = b[j];
	            b[j] = tmp;
        	}
		}
	}
	
	for(i = 0; i<n; i++){
		b[i].xuat();
	}
	
	long long luongMax = b[0].getLuong();
	for (i=0; i<n ; i++){
		if(b[i].getLuong() > luongMax){
			luongMax = b[i].getLuong();
		}
	}
	cout << "Can bo nam co luong cao nhat: \n";
	for (i=0; i<n ; i++){
		if(luongMax == b[i].getLuong() && b[i].getGt() == "Nam"){
			b[i].xuat();
		}
	}
	
	
}
