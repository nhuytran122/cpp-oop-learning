#include <bits/stdc++.h>
using namespace std;
class Nguoi{
    string Ma, Hoten;
    public :
        void Nhap(){
            cout<<"\n Nhap Ma: ";
            getline(cin, Ma);
            cout<<"\n Ho ten: ";
            getline(cin, Hoten);
        }
        void Xuat(){
            cout<<"\n Ma: " << Ma;
            cout<<"\n Ho ten: " << Hoten;
        }
};
class Sinhvien : public Nguoi{ 
    float Dtb;
    public :
    void Nhap_SV(){
        cout << "\n Nhap diem trung binh: ";
        cin >> Dtb;
        cin.ignore();
    }

    void Xuat_SV(){ 
        cout<<"\n Diem trung binh: "<< Dtb;
    }

    int khenthuong(){
        return Dtb > 8;
    }
};
class Giaovien : public Nguoi{ 
    float sbb;
    public :
    void Nhap_GV(){
        cout<<"\n Nhap so bai bao: ";
        cin>>sbb;
        cin.ignore();
    }
    void Xuat_GV(){
        cout << "\n So bai bao: " << sbb;
    }
    int khenthuong(){
        return sbb > 1;
    }
};

class Quanly{
    Sinhvien sv[100];
    Giaovien gv[20];
    int m, n;
    public:
        void nhapsv();
        void nhapgv();
        void insv();
        void ingv();
};

void Quanly::nhapsv(){
    cout<<"\n Nhap so sinh vien: ";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;++i){
        sv[i].Nhap();
        sv[i].Nhap_SV();
    }
}

void Quanly::insv(){
    cout<<"\n Danh sach SV duoc khen thuong :";
    for(int i=0;i<n;++i)
        if (sv[i].khenthuong()){ 
            sv[i].Xuat();
            sv[i].Xuat_SV();
        }
}

void Quanly::nhapgv(){
    cout<<"\n\n Nhap so giao vien : ";
    cin>>m;
    cin.ignore();
    for(int i=0;i<m;++i){
        gv[i].Nhap();
        gv[i].Nhap_GV();
    }
}

void Quanly::ingv(){
    cout<<"\n Danh sach GV duoc khen thuong :";
    for(int i=0;i<m;++i)
        if (gv[i].khenthuong()){ 
            gv[i].Xuat();
            gv[i].Xuat_GV();
        }
}

int main(){
    Quanly ob1, ob2;
    ob1.nhapsv();
    ob1.insv();
    
    ob2.nhapgv();
    ob2.ingv();
    return 0;
}
