//https://youtu.be/L-BabT96Zmk 
// > : giam dan
// < tang dan
//KHAI NIEM CO BAN
#include<bits/stdc++.h>
using namespace std;

//class: 
//Thuoc tinh: attribute
//Phuong thuc: method, behavior
//Object: doi tuong
//Constructor: Ham khoi tao (co cung ten voi Class, khong co kieu tra ve)
//Destructor: Ham huy (~ co cung ten voi Class, khong co kieu tra ve)


//- Encapsulation: Dong goi
//- Access modifier: 
// + Private: cac atrribute ma ben ngoai class khong duoc truy cap truc tiep (phai qua cac ham getter de lay va setter de thay doi)
// + Public
// + Protected: thuong duoc su dung trong class cha de class con ke thua

class SinhVien{
	private:
		//Thuoc tinh:
		string id, ten, ns;
		double gpa;
	public:
		//Constructor:
		SinhVien(); 
		SinhVien(string, string, string, double);

		//Phuong thuc:
		void xinchao();
		void dihoc();
		~SinhVien();
};

//Implematation:
SinhVien::SinhVien(){
	cout << "Doi tuong mac dinh duoc tao o day!\n";
	id = ten = ns = "";
	gpa = 0;
	cout << "Ham khoi tao duoc goi!\n";
}

SinhVien::SinhVien(string ma, string name, string birth, double diem){
	cout << "Ham khoi tao co tham so duoc goi!\n";
	id = ma;
	ten = name;
	ns = birth;
	gpa = diem;
}

SinhVien::~SinhVien(){
	cout << "Doi tuong duoc huy tai day";
}

void SinhVien::xinchao(){
	cout << "Hello!\n";
}

void SinhVien::dihoc(){
	cout << "Di hoc!\n";
}

int main(){
	//Khoi tao khong truyen tham so: 
	//SinhVien x;
	
	//Khoi tao co truyen tham so
	SinhVien x("123", "Nhu Y", "12/02/2003", 3.5);
	x.dihoc();
	x.xinchao();
}
