#include<bits/stdc++.h>
using namespace std;

class Canbo{
	protected:
		string hoten, diachi, gioitinh;
		int tuoi;
	public:
		void Nhap(){
			cout << "\nNhap ho ten: "; getline(cin, hoten);
			cout << "Nhap tuoi: "; cin >> tuoi;
			cin.ignore();
			cout << "Nhap gioi tinh: "; getline(cin, gioitinh);
			cout << "Nhap dia chi: "; getline(cin, diachi);
		}
		
		void Xuat(){
			cout << "\n\nHo ten: " << hoten;
			cout << "\nTuoi: " << tuoi;
			cout << "\nGioi tinh: " << gioitinh;
			cout << "\nDia chi: " << diachi << endl;
		}
		
		string getTen(){
			return hoten;
		}
};

class CongNhan : public Canbo{
	private:
		int bac;
	public: 
		void nhap(){
			Nhap();
			do{
				cout << "Nhap bac (1 - 10): ";
				cin >> bac;
				cin.ignore();
				if(bac < 1 || bac > 10) cout << "Bac ban nhan khong hop le, vui long nhap lai\n";
			}
			while(bac < 1 || bac > 10);
		}
		
		void xuat(){
			Xuat();
			cout << "\nBac: " << bac;
		}
};

class KySu : public Canbo{
	private:
		string nganhdt;
	public:
		void nhap(){
			Nhap();
			cout << "Nhap nganh dao tao: "; getline(cin, nganhdt);
		}
		
		void xuat(){
			Xuat();
			cout << "\nNganh dao tao: " << nganhdt;
		}
};

class NhanVien : public Canbo{
	private:
		string cv;
	public:
		void nhap(){
			Nhap();
			cout << "Nhap cong viec: "; getline(cin, cv);
		}
		
		void xuat(){
			Xuat();
			cout << "\nCong viec: " << cv;
		}
};

class QLCB{
	private:
		Canbo *QL[100];
		int n;
	public:
		void Add(){
			int tl;
			cout << "Nhap so luong n: ";
			cin >> n;
			for (int i=0; i<n; i++){
				cout << "\nNhap can bo: 1 - Cong Nhan, 2 - Ky Su:, 3 - Nhan Vien: ";
				cin >> tl;
				cin.ignore();
				if (tl == 1){
					CongNhan *p = new CongNhan;
					p->nhap();
					QL[i] = p;
				}
				else if(tl == 2){
					KySu *p = new KySu;
					p->nhap();
					QL[i] = p;
				}
				else {
					NhanVien *p = new NhanVien;
					p->nhap();
					QL[i] = p;
				}
			}
		}
		
		void QLXuat(){
			for(int i=0; i<n; i++){
				QL[i]->Xuat();	
			}
		}
		
		void Exit(){
			exit(0);
		}
		
		void Search(string a){
			bool ch = false;
			for(int i=0; i<n; i++){
				if(a == QL[i]->getTen()){
					QL[i]->Xuat();
					ch = true;
				}
			}
			if(ch == false){
				cout << "\nKhong tim thay can bo ten " << a << endl;
			}
		}
};

int main(){
	QLCB ob;
	int lc;
	while(1){
		cout << "\n---------- MENU CHUONG TRINH ----------";
		cout << "\n1. Them moi can bo\n";
		cout << "2. Hien thi thong tin danh sach can bo\n";
		cout << "3. Tim kiem can bo theo ho ten\n";
		cout << "0. Thoat khoi chuong trinh\n";
		cout << "---------------------------------------\n";
		cout << "Nhap lua chon: "; cin >> lc;
		
		if(lc == 1){
			ob.Add();
		}
		else if(lc == 2){
			ob.QLXuat();
		}
		else if(lc == 3){
			string name;
			cin.ignore();
			cout << "\n\nTen muon tim: "; getline(cin, name);
			ob.Search(name);	
		}
		else{
			ob.Exit();
		}
	}
	return 0;
}
