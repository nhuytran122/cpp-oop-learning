#include<bits/stdc++.h>
using namespace std;

class Chuyenxe{
	protected:
		string ms, ten, soxe;
		long long doanhthu;
	public:
		void Nhap(){
			cout << "\nNhap ma so chuyen: ";
			getline(cin, ms);
			cout << "Nhap ho ten tai xe: ";
			getline(cin, ten);
			cout << "Nhap so xe: ";
			getline(cin, soxe);
			cout << "Nhap doanh thu: ";
			cin >> doanhthu;
		}
		
		void Xuat(){
			cout << "\n\nMa so xe: " << ms;
			cout << "\nHo ten tai xe: " << ten;
			cout << "\nSo xe: " << soxe;
			cout << "\nDoanh thu: " << doanhthu;
		}
		
		long long getDoanhthu(){ 
			return doanhthu;
		}
};

class Noithanh : public Chuyenxe{
	private:
		int sotuyen, km;
	public:
		void nhap(){
			Nhap();
			cout << "Nhap so tuyen: ";
			cin >> sotuyen;
			cout << "Nhap so km di duoc: ";
			cin >> km;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << "\nSo tuyen: " << sotuyen;
			cout << "\nSo km di duoc: " << km;
		}
};

class Ngoaithanh : public Chuyenxe{
	private:
		string noiden;
		int songay;
	public:
		void nhap(){
			Nhap();
			cin.ignore();
			cout << "Nhap noi den: "; getline(cin, noiden);
			cout << "Nhap so ngay di duoc: ";
			cin >> songay;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << "\nNoi den: " << noiden;
			cout << "\nSo ngay di duoc: " << songay;
		}
};

int main(){
	Noithanh a[50];
	Ngoaithanh b[50];
	int n, m, i;
	long long s1 = 0, s2 = 0;
	cout << "Nhap so luong chuyen xe noi thanh: ";
	cin >> n; cin.ignore();
	for (i = 0; i<n; i++){
		a[i].nhap();
	}
	
	cout << "\nNhap so luong chuyen xe ngoai thanh: ";
	cin >> m; cin.ignore();
	for (i = 0; i<n; i++){
		b[i].nhap();
	}
	
	cout << "\n\t\tTong doanh thu cua cac chuyen xe noi thanh: ";
	for(i=0; i<n; i++){
		s1 += a[i].getDoanhthu();
	}
	cout << s1;
	
	cout << "\n\n\t\tTong doanh thu cua cac chuyen xe ngoai thanh: ";
	for(i=0; i<m; i++){
		s2 += b[i].getDoanhthu();
	}
	cout << s2;
	
	
}
