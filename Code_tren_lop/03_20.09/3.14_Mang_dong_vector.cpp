//Mang dong
#include<bits/stdc++.h>
using namespace std;

class Vector{
    private:
        int size;
        int *V;
    public:
        void nhap();
        void xuat();
        int TichVoHuong(Vector v2);
        float TichModulo();
};

void Vector::nhap(){
    cout << "\tNhap kich thuoc cua vector (size>0): "; 
    cin >> size;
    V = new int[size];
    if (V == NULL){
        cout<<"\n Loi cap phat bo nho!";
        return;
    }
    cout << "\tNhap cac thanh phan cua vector: ";
    for(int i=0; i<size; i++){
        cout << "\n V[" << i << "]: ";
        cin >> V[i];
    }
}

void Vector::xuat(){
	cout << "\tVector V: ";
    for(int i=0; i<size; i++){
        cout << V[i] << " ";
    }
}

float Vector::TichModulo(){
	int s = 0;
	for(int i=0; i<size; i++){
		s += V[i] * V[i];
	}
	return sqrt(s);
}
int Vector::TichVoHuong(Vector v2){
	int v;
	if(size != v2.size){
		cout << "\t2 vector khong cung kich thuoc -> khong the nhan vo huong\n";
	}
	else{
		for(int i=0; i<size; i++){
			v += V[i] * v2.V[i];
		}
	}
	return v;
}

int main(){
   Vector v, v1, v2;
   cout << "\tNhap vector v:\n";   
   v.nhap();
   v.xuat();
   cout << "\n\tTICH MODULO CUA VECTOR V: " << v.TichModulo();
   
   cout << "\n\n\tTICH VO HUONG CUA 2 VECTOR:\n";
   cout << "\tNhap vector thu nhat: \n";
   v1.nhap();
   cout << "\tNhap vector thu hai: \n";
   v2.nhap();
   cout << "\t==> KET QUA: " << v1.TichVoHuong(v2);
   
}
