#include <bits/stdc++.h>
using namespace std;

class Nguoi{
    protected:
        string maso, hoten;
        long long luong;
    public:
        void Nhap(){
            cout << "\nNhap ma so: "; getline(cin, maso);
            cout << "Nhap ho ten: "; getline(cin, hoten);
        }

        void Xuat(){
            cout << "\n\nMa so: " << maso;
            cout << "\nHo ten: " << hoten;
            cout << "\nLuong: " << luong;
        }
        
        virtual void Luong(){
        	luong = 0;
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
        
        void Luong(){
        	luong = hsluong * 1350000 + phucap;
		}

//        void xuat(){
//            Xuat();
//            cout << "\nHe so luong: " << hsluong;
//            cout << "\nPhu cap chuc vu: " << phucap;
//            cout << "\nLuong: " << luong;
//        }       
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
        
		void Luong(){
			luong = songaylv * tiencong * hsvuotgio;
		}
		
//        void xuat(){
//            Xuat();
//            cout << "\nTien cong lao dong: " << tiencong;
//            cout << "\nSo ngay lam viec trong thang: " << songaylv;
//            cout << "\nHe so vuot gio: " << hsvuotgio;
//            cout << "\nLuong: " << luong;
//        }    
};

int main(){
	Nguoi *DS[100];
    int n, lc;
    cout << "\nNhap so can bo (bao gom bien che & hop dong): "; cin >> n;
    cin.ignore();
	for (int i=0; i<n; i++){
		cout << "Nhap loai danh muc: 1 - bien che, 2 - hop dong: ";
		cin >> lc;
		cin.ignore();
		if (lc == 1){
			Bienche *p = new Bienche;
			p->nhap();
			DS[i] = p;
		}
		else{
			Hopdong *p = new Hopdong;
			p->nhap();
			DS[i] = p;
		}
	}
	
	cout << "\n\tBANG LUONG CAN BO BIEN CHE: ";
	for (int i=0; i<n; i++){
		DS[i]->Luong();
		DS[i]->Xuat();
	}
		
			
	
//	for(int i=0; i<m; i++){
//    	a[i].xuat();
//	}
//	
//	cout << "\n\n\tBANG LUONG CAN BO HOP DONG: ";
//	for(int i=0; i<n; i++){
//    	b[i].xuat();
//	}
}
