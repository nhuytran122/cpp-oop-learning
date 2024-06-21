#include<bits/stdc++.h>
using namespace std;

class Nguoi{
	protected:
		string ho, ten;
		int d, m, y;
	public:
		void Nhap(){
			cout << "\nNhap ho dem: "; getline(cin, ho);
			cout << "Nhap ten: "; getline(cin, ten);
			cout << "Nhap ngay sinh:\n";
			cout << "Nhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			cin.ignore();
		}
		
		void Xuat(){
			cout << "\n\nHo dem: " << ho;
			cout << "\nTen: " << ten;
			cout << "\nNgay sinh: " << d << "/" << m << "/" << y;
		}
		
		int operator > (Nguoi n2){
			if(ten != n2.ten) return ten > n2.ten;
			return ho > n2.ho;
		}
};

class Sinhvien : public Nguoi{
	private:
		string msv;
		float dtb;
	public:
		void nhap(){
			Nhap();
			cout << "Nhap MSV: "; getline(cin, msv);
			cout << "Nhap diem trung binh: "; cin >> dtb;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << "\nMSV: " << msv;
			cout << "\nDiem trung binh: " << dtb;
		}
		
		string getHo(){
            return ho;
        }

        string getTen(){
            return ten;
        }

        string getNs(){
        	string ns;
        	ns = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
            return ns;
        }
		
		string getMsv(){
			return msv;
		}
		
		float getDtb(){
			return dtb;
		}
};

int main(){
	Sinhvien sv[200];
	int n;
	do{
		cout << "Nhap so luong sinh vien: "; cin >> n;
	}while(n<0 || n>200);
	cin.ignore();
	
	for(int i=0; i<n; i++){
		sv[i].nhap();
	}
	
	for(int i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (sv[i] > sv[j]){
	            Sinhvien tmp = sv[i];
	            sv[i] = sv[j];
	            sv[j] = tmp;
        	}
		}
	}
	
	cout << "\nDANH SACH SV TANG DAN THEO TEN VA HO DEM: \n";
	for(int i=0; i<n; i++){
		sv[i].xuat();
	}
	
	float dtbMax = sv[0].getDtb();
	for(int i=0; i<n; i++){
		if(sv[i].getDtb() > dtbMax){
			dtbMax = sv[i].getDtb();
		}
	}
	
	cout << "\nNNHUNG SV CO DIEM TRUNG BINH CAO NHAT: \n";
	for(int i=0; i<n; i++){
		if(sv[i].getDtb() == dtbMax){
			sv[i].xuat();
		}	
	}
}
