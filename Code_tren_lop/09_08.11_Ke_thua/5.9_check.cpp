#include <bits/stdc++.h>
using namespace std;

class Canbo{
    protected:
        string macb, madv, hoten, ngaysinh;
    public:
        void Nhap(){
            cout << "\nNhap ma can bo: "; getline(cin, macb);
            cout << "Nhap ma don vi: "; getline(cin, madv);
            cout << "Nhap ho ten: "; getline(cin, hoten);
            cout << "Nhap ngay sinh: "; getline(cin, ngaysinh);
        }

        void Xuat(){
            cout << "\nMa Can Bo: " << macb;
            cout << "\nMa Don Vi: " << madv;
            cout << "\nHo ten: " << hoten;
            cout << "\nNgay sinh: " << ngaysinh << endl;
        }
        
        string getMadv(){
        	return madv;
		}
};

class Luong:public Canbo{
    private:
        float phucap, hsluong, baohiem;

    public:
        long long getLuong(){
            return hsluong*1350000 + phucap - baohiem;
        }

        void nhap(){
        	Nhap();
            cout << "\nNhap phu cap: "; cin >> phucap;
            cout << "Nhap he so luong: "; cin >> hsluong;
            cout << "Nhap bao hiem: "; cin >> baohiem;
            cin.ignore();
        }

        void xuat(){
        	Xuat();
            cout << "Phu cap: " << phucap;
            cout << "\nHe so luong: " << hsluong;
            cout << "\nBao hiem: " << baohiem;
            cout << "\nLuong: " << getLuong() << endl;
        }
};

int main(){
    Luong cb[50];
    int n;
    //set <string> s;
    cout << "Nhap so luong can bo: "; cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
    	cb[i].nhap();
    	//s.insert(cb[i].getMadv());
	}

    //sap xep can bo theo don vi
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if(cb[i].getMadv() > cb[j].getMadv()){
                Luong tam;
                tam = cb[i];
                cb[i] = cb[j];
                cb[j] = tam;
            }
//in theo don vi
    for(int i=0 ; i<n ; i++){
        if (i==0 || cb[i].getMadv() != cb[i-1].getMadv())
            cout << "\n Don vi : " << cb[i].getMadv() << endl;
        cb[i].xuat();
    }
    	
    // for(auto x : s){
    // 	cout << "\n\t----- DON VI " << x << " -----\n";
    // 	for(int i=0; i<n; i++){
    // 		if(cb[i].getMadv() == x){
    // 			cb[i].xuat();
	// 		}
	// 	}
	// }
		
}
