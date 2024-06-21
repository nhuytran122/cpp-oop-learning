#include <bits/stdc++.h>
using namespace std;

class Nguoi{
    protected:
        string maso, hoten;
        float luong;
    public:
        void Nhap(){
            cout << "\nNhap ma so: "; getline(cin, maso);
            cout << "Nhap ho ten: "; getline(cin, hoten);
        }

        void Xuat(){
            cout << "\n\nMa so: " << maso;
            cout << "\nHo ten: " << hoten;
        }

        virtual float Luong(){
            return 0;
        }
};

class Bienche:public Nguoi{
    private:
        float hsluong, phucap;
    public:
        void nhap(){
            Nhap();
            cout << "Nhap he so luong: "; cin >> hsluong;
            cout << "Nhap phu cap chuc vu: "; cin >> phucap;
            cin.ignore();
        }

        void xuat(){
            Xuat();
            cout << "\nHe so luong: " << hsluong;
            cout << "\nPhu cap chuc vu: " << phucap;
            cout << "\nLuong: " << Luong();
        } 
		float Luong(){
			return hsluong * 1350000 + phucap;
		}      
};

class Hopdong:public Nguoi{
    private:
        float tiencong, hsvuotgio;
        int songaylv;
    public:
        void nhap(){
            Nhap();
            cout << "Nhap tien cong: "; cin >> tiencong;
            cout << "So ngay lam viec trong thang: "; cin >> songaylv;
            cout << "He so vuot gio: "; cin >> hsvuotgio;
            cin.ignore();
        }
		
        void xuat(){
            Xuat();
            cout << "\nTien cong lao dong: " << tiencong;
            cout << "\nSo ngay lam viec trong thang: " << songaylv;
            cout << "\nHe so vuot gio: " << hsvuotgio;
            cout << "\nLuong: " << Luong();
        }    
        
        float Luong(){
        	return songaylv * tiencong * hsvuotgio;
		}
};

int main(){
    Bienche a[50];
    Hopdong b[50];
    int m, n;
    cout << "\nNhap so can bo bien che: "; cin >> m;
    cin.ignore();
    for(int i=0; i<m; i++){
    	a[i].nhap();
	}
	
	cout << "\nNhap so can bo hop dong: "; cin >> n;
	cin.ignore();
    for(int i=0; i<n; i++){
    	b[i].nhap();
	}
	
	cout << "\n\tBANG LUONG CAN BO BIEN CHE: ";
	for(int i=0; i<m; i++){
    	a[i].xuat();
	}
	
	cout << "\n\n\tBANG LUONG CAN BO HOP DONG: ";
	for(int i=0; i<n; i++){
    	b[i].xuat();
	}
}
