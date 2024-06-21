#include<bits/stdc++.h>
using namespace std;

class Diem{
	private:
		int x, y;
	public:
		void nhap();
		void xuat();
		int getY();
		int getX();
		float Kc2Diem(Diem d1);
		Diem Doixung();
};

void Diem::nhap(){
	cout << "\nNhap x: "; cin >> this->x;
	cout << "Nhap y: "; cin >> this->y;
}

void Diem::xuat(){
	cout << "(" << this->x << "; " <<  this->y << ")" << endl;
}

int Diem::getX(){
	return x;
}

int Diem::getY(){
	return y;
}

float Diem::Kc2Diem(Diem d2){
	return sqrt(pow(x-d2.x, 2) + pow(y-d2.y, 2));
	
}

Diem Diem::Doixung(){
	Diem d;
	d.x = -x;
	d.y = -y;
	return d;
}


int main(){
	Diem a[50];
	int n;
	cout<<"\n Nhap so diem: ";
	cin>>n;
	for (int i = 0; i<n; i++){
		cout << "x" << i+1 << ": ";
		a[i].nhap(); 
	}

	cout<<"\nDanh sach cac diem thuoc truc hoanh :\n";
	for (int i=0; i<n ; i++){
		if(a[i].getY() == 0){
			a[i].xuat();
		}
	}
	
	cout << "\nKHOANG CACH GIUA 2 DIEM: ";
	Diem d1, d2;
	cout << "\nNhap diem thu nhat: ";
	d1.nhap();
	cout << "Nhap diem thu hai: ";
	d2.nhap();
	cout << "Khoang cach giua 2 diem: " << d1.Kc2Diem(d2);
	
	cout << "\nDIEM DOI XUNG QUA GOC TOA DO CUA DIEM D1:\n";
	Diem dx = dx = d1.Doixung();
	dx.xuat();
	
	
	
}
