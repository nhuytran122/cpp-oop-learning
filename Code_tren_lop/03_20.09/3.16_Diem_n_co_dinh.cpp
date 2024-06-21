// n co dinh
#include<bits/stdc++.h>
using namespace std;

#define n 5

class Diem{
    private:
        int D[n];
    public:
        void nhap();
        void xuat();
        float Kc2Diem(Diem d2);
        Diem Cong(Diem d2);
};

void Diem::nhap(){
    cout << "\tNhap cac thanh phan cua diem: ";
    for(int i=0; i<n; i++){
        cin >> D[i];
    }
}

void Diem::xuat(){
	cout << "\tDiem: ";
    cout<<"(";
    for(int i = 0; i < n-1; ++i)
        cout << D[i] << ";";
        cout << D[n-1]<<")" << endl;
}

float Diem::Kc2Diem(Diem d2){
	float s = 0.0;
    for(int i=0; i<n; i++){
        s += pow((d2.D[i] - D[i]), 2);
    }
    return sqrt(s);
}

Diem Diem::Cong(Diem d2){
    Diem d;
    for(int i = 0; i<n; i++)
    d.D[i] = D[i] + d2.D[i];
    return d;
}

int main(){
   Diem d, d1, d2;
   cout << "\tNhap diem:\n";   
   d.nhap();
   d.xuat();
   cout << "\n\n\tKHOANG CACH GIUA 2 DIEM:\n";
   cout << "\tNhap diem thu nhat: \n";
   d1.nhap();
   cout << "\tNhap diem thu hai: \n";
   d2.nhap();
   cout << "\tKET QUA: " << d1.Kc2Diem(d2);
   
   
}
