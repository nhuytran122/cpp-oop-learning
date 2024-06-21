https://www.youtube.com/watch?v=zVEdrZlDBuI&t=2578s
#include<bits/stdc++.h>
using namespace std;

class Canbo{
	protected:
		string ten;
		float phucap, hsluong;
	public:
		void Nhap(){
			cout << "Nhap ho ten: "; getline(cin, ten);
			cout << "Nhap phu cap: "; cin >> phucap;
			cout << "Nhap he so luong: "; cin >> hsluong;
		}
		
		void Xuat(){
			cout << "\nHo ten: " << ten;
			cout << "\nPhu cap: " << phucap;
			cout << "\nHe so luong: " << hsluong;
		}
};

class Giangvien : public Canbo{
	private:
		string khoa, trinhdo;
		int sotiet;
	public:
		void nhap(){
			Nhap();
			cout << "Nhap khoa: "; getline(cin, khoa);
			cout << "Nhap trinh do: ";
			int lc;
			do{
				cout << "Nhap trinh do: ";
				cout << "1. Cu nhan"
				cout << "\n2. Thac si";
				cout << "\n3. Tien si";
				cout << "Nhap lua chon: "; cin >> lc;
				if(lc == 1)
					trinhdo = "Cu nhan";
				else if(lc == 2)
					trinhdo = "Thac si";
				else
					trinhdo = "Tien si";
			}while(lc < 0 || lc > 3);
			cout << "Nhap so tiet: "; cin >> sotiet;
		}
};

class Nhanvien : public Canbo{
	private:
		string phongban;
};
