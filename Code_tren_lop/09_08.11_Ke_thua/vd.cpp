#include <iostream>
#include <stdio.h>
using namespace std;
class Nguoi{
    string Ma, Hoten;
    public:
        void Nhap(){
            cout << "\n Nhap Ma: "; getline(cin, Ma);
            cout << "\n Ho ten: "; getline(cin, Hoten);
        }
        void Xuat(){
            cout << "\n Ma: " << Ma;
            cout << "\n Ho ten: " << Hoten;
        }

        virtual int khenthuong() //khenthuong la ham ao va se duoc dinh nghia lai o lop con
        { return 0;}
};

class Sinhvien : public Nguoi{ 
    float Dtb;
    public:
    void Nhap_SV(){
        cout<<"\n Nhap diem trung binh: ";
        cin>>Dtb;
        cin.ignore(1);
    }

    void Xuat_SV(){ 
        cout<<"\n Diem trung binh: "<<Dtb;
    }

    int khenthuong(){
        return Dtb > 8;
    }
};

class Giaovien : public Nguoi{ 
    float sbb;
    public :
    void Nhap_GV(){
        cout << "\nNhap so bai bao: ";
        cin >> sbb;
        cin.ignore(1);
    }

    void Xuat_GV(){
        cout << "\n So bai bao: " << sbb;
    }

    int khenthuong(){
        return sbb > 1;
    }
};

int main(){
    Sinhvien sv[100];
    Giaovien gv[20];
    int m,n;
    cout << "\n Nhap so sinh vien: ";
    cin >> n;
    cin.ignore(1);
    for(int i=0;i<n;++i){
        sv[i].Nhap();
        sv[i].Nhap_SV();
    }

    cout<<"\n Danh sach SV duoc khen thuong :";
    for(int i=0;i<n;++i)
        if (sv[i].khenthuong()){ 
            sv[i].Xuat();
            sv[i].Xuat_SV();
        }

    cout << "\n Nhap so giao vien : ";
    cin >> m;
    cin.ignore(1);
    for(int i=0;i<m;++i){
        gv[i].Nhap();
        gv[i].Nhap_GV();
    }
    cout<<"\n Danh sach GV duoc khen thuong :";
    for(int i=0;i<n;++i)
    if (gv[i].khenthuong()){
        gv[i].Xuat();
        gv[i].Xuat_GV();
    }
    return 0;
}
