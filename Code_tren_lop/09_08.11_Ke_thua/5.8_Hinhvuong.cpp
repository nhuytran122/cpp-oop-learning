#include <bits/stdc++.h>
using namespace std;

class Hvuong{
    protected:
        float d;
    public:
        void Nhap1(){
            cout << "\nNhap do dai canh 1: "; cin >> d;
        }

        void In1(){
            cout << "\nDo dai canh: " << d;
            cout << "\nChu vi: " << Chuvi();
            cout << "\nDien tich: " << Dientich() << endl;
        }

        float Chuvi(){
            return d*4;
        }

        float Dientich(){
            return d*d;
        }
};

class Chunhat:public Hvuong{
    private:
        float r;
    public:
        void Nhap2(){
            Hvuong::Nhap1();
            cout << "Nhap do dai canh 2: "; cin >> r;
        }

        void In2(){
            cout << "\nDo dai canh 1: " << d;
            cout << "\nDo dai canh 2: " << r << endl;
            cout << "Chu vi: " << Chuvi() << endl;
            cout << "Dien tich: " << Dientich() << endl;
        }

        float Chuvi(){
            return (d+r)*2;
        }

        float Dientich(){
            return d*r;
        }
};

int main(){
    Hvuong a;
    Chunhat b;
    a.Nhap1();
    a.In1();
    
    b.Nhap2();
    b.In2();
}
