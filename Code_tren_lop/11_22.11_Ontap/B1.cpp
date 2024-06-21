#include<bits/stdc++.h>
using namespace std;

class Khachsan{
    protected:
    	string loaiphong;
        int ngay;

    public:
    	Khachsan();
    	Khachsan(string lp, int sn);        
        void Xuat();
        virtual float Tien();
};

Khachsan::Khachsan(void){
}

Khachsan::Khachsan(string lp, int sn){
	loaiphong = lp;
	ngay = sn;
}

void Khachsan::Xuat(){
	cout << "\nLoai phong: " << loaiphong;
	cout << "\nSo ngay thue: " << ngay;
}

float Khachsan::Tien(){
	return 0;
}

class PhongA : public Khachsan{
	float tiendv;
	public:
		PhongA();
		PhongA(string lp, int sn, float dv);
		float Tien();
};

PhongA::PhongA(){
}

PhongA::PhongA(string lp, int sn, float dv) : Khachsan(lp, sn){
	tiendv = dv;
}

float PhongA::Tien(){
    if(ngay >= 5)
        return (80 * ngay + tiendv) * 0.9 ;
    else 
		return 80 * ngay + tiendv;
}

class PhongB : public Khachsan{
	public:
		PhongB();
		PhongB(string lp, int sn);
		float Tien();
};

PhongB::PhongB(){
}

PhongB::PhongB(string lp, int sn) : Khachsan(lp, sn){
}

float PhongB::Tien(){
    if(ngay >= 5)
        return (60 * ngay) * 0.9 ;
    else 
		return 60 * ngay;
}

class PhongC : public Khachsan{
	public:
		PhongC();
		PhongC(string lp, int sn);
		float Tien();
};

PhongC::PhongC(){
}

PhongC::PhongC(string lp, int sn) : Khachsan(lp, sn){
}

float PhongC::Tien(){
	return 40 * ngay;
}

int main(){
	Khachsan *DS[100];
	int i, n, tl, sn;
	float s = 0;
	cout << "\nNhap so luong cac phong khach da thue: "; cin >> n;
	for(i = 0; i<n; i++){
		cout << "\nNhap loai phong: 1 - Phong A; 2 - Phong B; 3 - Phong C: ";
		cin >> tl;
		cout << "\nNhap so ngay thue: "; cin >> sn;
		switch(tl){
			case 1:{
				float dv;
				cout << "Tien dich vu: "; cin >> dv;
				cin.ignore();
				PhongA *p = new PhongA("A", sn, dv);
				DS[i] = p;
				s += DS[i]->Tien();	
				break;
			}
			case 2:{
				PhongB *p = new PhongB("B", sn);
				DS[i] = p;
				s += DS[i]->Tien();	
				break;
			}
			case 3:{
				PhongC *p = new PhongC("C", sn);
				DS[i] = p;
				s += DS[i]->Tien();	
				break;
			}
			
		}
	}
	cout << "\n\tCac phong khach da thue: \n"; 
	for(i = 0; i<n; i++)
		DS[i]->Xuat();
	cout << "\n\tTong tien phai tra: " << s;
}
