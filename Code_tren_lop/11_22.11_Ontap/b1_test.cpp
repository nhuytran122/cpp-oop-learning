//thieu sot neu muon in tat ca loai phong da thue, thieu ten loai phong
#include<bits/stdc++.h>
using namespace std;

class Khachsan{
    protected:
        float gia;
        int ngay;

    public:
        void Nhap(){
            cout << "Nhap so ngay thue: "; cin >> ngay;
        }
};

class PhongA : public Khachsan{
    private: 
        float tiendv;
    public:
        void nhap(){
            Nhap();
            cout << "Nhap tien dich vu: "; cin >> tiendv;
        }

        float Tinhtien(){
            if(ngay >= 5)
                gia += (80 * ngay * 0.9) + tiendv;
            else gia += 80 * ngay + tiendv;
            return gia;
        }

};

class PhongB : public Khachsan{
    public:
        void nhap(){
            Nhap();
        }

        float Tinhtien(){
            if(ngay >= 5)
                gia += 60 * ngay * 0.9;
            else gia += 60 * ngay;
            return gia;
        }
};

class PhongC : public Khachsan{
    public:
        void nhap(){
            Nhap();
        }

        float Tinhtien(){
            gia += 40 * ngay;
            return gia;
        }
};

int main(){
	Khachsan *DS[100];
	int i, n, lc;
	long long s = 0;
	cout << "Nhap so luong phong muon thue: "; cin >> n;
	for(i=0; i<n; i++){
		cout << "\nNhap loai phong: 1 - Phong A; 2 - Phong B; 3 - Phong C: ";
		cin >> lc;
		if (lc == 1){
			PhongA *p = new PhongA;
			p->nhap();
			DS[i] = p;
			s += p->Tinhtien();
		}
		else if (lc == 2){
			PhongB *p = new PhongB;
			p->nhap();
			DS[i] = p;
			s += p->Tinhtien();
		}
		else{
			PhongC *p = new PhongC;
			p->nhap();
			DS[i] = p;
			s += p->Tinhtien();
		}	
	}
	cout << "\n\n\t\tTONG TIEN KHACH HANG PHAI TRA: " << s << "USD";
	return 0;
}
