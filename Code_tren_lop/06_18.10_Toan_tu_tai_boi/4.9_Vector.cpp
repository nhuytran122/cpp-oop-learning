#include<bits/stdc++.h>
using namespace std;

class Vector{
    private:
        int size;
        int V[50];
    public:
        void nhap();
        void xuat();
        Vector operator + (Vector v2);
        int operator * (Vector v2);
};

void Vector::nhap(){
    cout << "\n\n\tNhap kich thuoc cua vector: "; 
    cin >> size;
    cout << "\tNhap cac thanh phan cua vector: ";
    for(int i=0; i<size; i++){
        cin >> V[i];
    }
}

void Vector::xuat(){
	cout << "\tVector V: ";
    for(int i=0; i<size; i++){
        cout << V[i] << " ";
    }
}

Vector Vector::operator + (Vector v2){
	Vector s;
	if(size != v2.size){
		cout << "\n\t2 vector khong cung kich thuoc!\n";
		exit(1);
	}
	for(int i = 0; i<size; i++){
   		s.V[i] = V[i] + v2.V[i];
  	}
  	s.size = size;
	return s;
}

int Vector::operator * (Vector v2){
	int v = 0;
	if(size != v2.size){
		cout << "\n2 vector khong cung kich thuoc!";
		exit(1);
	}
	else{
		for(int i=0; i<size; i++){
			v += V[i] * v2.V[i];
		}
	}
	return v;
}

int main(){
	Vector v1, v2, v3;
	v1.nhap();
	v1.xuat();
	v2.nhap();
	v2.xuat();
	v3 = v1 + v2;
	int s = v1 * v2;
	cout << "\n\n\tKET QUA CONG 2 VECTOR V1 & V2: ";
	v3.xuat();
	cout << "\n\n\tKET QUA TICH VO HUONG CUA VECTOR V1 & V2: " << s;
}
