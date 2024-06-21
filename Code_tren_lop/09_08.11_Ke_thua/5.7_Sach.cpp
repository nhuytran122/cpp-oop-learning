#include <bits/stdc++.h>
using namespace std;

class Sach{
    private:
        string tensach, tacgia;
        int sotrang, giaban;
    public:
        void Nhap_sach(){
            cout << "\nNhap ten sach: "; getline(cin, tensach);
            cout << "Nhap tac gia: "; getline(cin, tacgia);
            cout << "Nhap so trang sach: "; cin >> sotrang;
            cout << "Nhap gia ban: "; cin >> giaban;
            cin.ignore();
        }
        
        void Xuat_sach(){
        	cout <<"\n\nTen sach: " << tensach;
        	cout << "\nTac gia: " << tacgia;
        	cout << "\nSo trang sach: " << sotrang;
        	cout << "\nGia ban: " << giaban;
		}
};

class Bia : public Sach{
    private:
        string mahinhanh;
        int tienve;
    public:
        void Nhap_b(){
        	Nhap_sach();
            cout << "Nhap ma hinh anh: "; getline(cin, mahinhanh);
            cout << "Nhap tien ve: "; cin >> tienve;
            cin.ignore();
        }
        
        void Xuat_b(){
        	Xuat_sach();
        	cout << "\nMa hinh anh: " << mahinhanh;
        	cout << "\nTien ve: " << tienve;
		}
};

class Hoasy{
    private:
        string hoten, diachi;

    public:
        void Nhap_hoasy(){
            cout << "Nhap ho ten hoa sy: "; getline(cin, hoten);
            cout << "Nhap dia chi: "; getline(cin, diachi);
        }
        
        void Xuat_hoasy(){
        	cout << "\nHo ten tac gia: " << hoten;
        	cout << "\nDia chi: " << diachi;
		}
};

class Sachvebia:public Bia, public Hoasy{
	public:
		void nhap(){
			Nhap_b();
			Nhap_hoasy();
		}
		
		void xuat(){
			Xuat_b();
			Xuat_hoasy();
		}
};

int main(){
	Sach s1[100];
	Sachvebia s2[100];
	int m, n; 
	cout << "\nNhap so luong sach khong ve bia: "; cin >> m;
	cin.ignore();
	for(int i=0; i<m; i++){
		s1[i].Nhap_sach();
	}
	
	cout << "\nNhap so luong sach ve bia: "; cin >> n;
	cin.ignore();
	for(int i=0; i<n; i++){
		s2[i].nhap();
	}
	
	cout << "\n\n\tDANH SACH SACH KHONG VE BIA: \n";
	for(int i=0; i<m; i++){
		s1[i].Xuat_sach();
	}
	
	cout << "\n\n\tDANH SACH SACH VE BIA: \n";
	for(int i=0; i<n; i++){
		s2[i].xuat();
	}
}
