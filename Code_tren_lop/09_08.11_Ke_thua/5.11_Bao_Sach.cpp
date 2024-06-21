//khong can gop, lam tuong tu nhu file vd.cpp cua cung folder
#include <bits/stdc++.h>
using namespace std;

class Thuvien{
    protected:
        string nhande, tgia;
        int slthamkhao;
    public:
        void Nhap(){
            cout << "\nNhap nhan de: "; getline(cin, nhande);
            cout << "Nhap tac gia: "; getline(cin, tgia);
            cout << "Nhap so lan tham khao: "; cin >> slthamkhao;
            cin.ignore();
        }

        void Xuat(){
            cout << "\nNhan de: " <<  nhande;
            cout << "\nTac gia: "<< tgia;
            cout << "\nSo lan tham khao: " <<  slthamkhao << endl;
        }

        int getSlTK(){
            return slthamkhao;
        }

        string getTgia(){
            return tgia;
        }

};

class Bao:public Thuvien{
    private:
        string tapchi;
        int sotapchi;
    public:
        void nhap(){
            Nhap();
            cout << "Nhap tap chi dang bai bao: "; getline(cin, tapchi);
            cout << "Nhap so tap chi: "; cin >> sotapchi;
            cin.ignore();
        }

        void xuat(){
            Xuat();
            cout << "Tap chi dang bai bao: " << tapchi;
            cout << "\nSo tap chi: " << sotapchi << endl;
        }
};

class Sach:public Thuvien{
    private:
        string NXB;
        int version;
    public:
        void nhap(){
            Nhap();
            cout << "Nhap NXB: "; getline(cin, NXB);
            cout << "Nhap version: "; cin >> version;
            cin.ignore();
        }

        void xuat(){
            Xuat();
            cout << "NXB: " << NXB;
            cout <<"\nVersion: " << version << endl;
        }
};

int main(){
    Bao b[100];
    Sach s[100];
    int m, n, b1 = 0, s1 = 0;
    map <string, int> mp1, mp2;
    cout << "Nhap so luong bai bao: "; cin >> m;
    cin.ignore();
    for(int i=0; i<m; i++){
        b[i].nhap();
        b1 += b[i].getSlTK();
        mp1[b[i].getTgia()] += b[i].getSlTK();
    }

    cout << "\nNhap so luong sach: "; cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        s[i].nhap();
        s1 += s[i].getSlTK();
        mp2[s[i].getTgia()] += s[i].getSlTK();
    }

    cout << "\n\n\tDANH MUC BAI BAO: ";
    for(int i=0; i<m; i++){
        b[i].xuat();
    }

    cout << "\n\n\tDANH MUC SACH: ";
    for(int i=0; i<n; i++){
        s[i].xuat();
    }

    cout << "\n\n\tDANH MUC CO SO LUONG THAM KHAO LON NHAT: ";
    if(b1 > s1) cout << "Bai bao\n";
    else cout << "Sach\n";

    cout << "\n\n\tTAC GIA CUA DANH MUC BAI BAO DUOC THUONG: \n";
	for (auto it : mp1){
        if(it.second > 10){
            cout << "\t" << it.first << ": " << it.second << endl;
        }
	}

    cout << "\n\n\tTAC GIA CUA DANH MUC SACH DUOC THUONG: \n";
	for (auto it : mp2){
        if(it.second > 20){
		    cout << "\t" << it.first << " " << it.second << endl;
        }
	}
}
