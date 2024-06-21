//https://youtu.be/L-BabT96Zmk 38'10s
#include<bits/stdc++.h>
using namespace std;

//class: 
//Thuoc tinh: attribute
//Phuong thuc: method, behavior
//Object: doi tuong
//Constructor: Ham khoi tao (co cung ten voi Class, khong co kieu tra ve)
//Destructor: Ham huy (~ co cung ten voi Class, khong co kieu tra ve)
//This pointer
//setter getter
//bien Static: dung chung cho tat ca objects thuoc cung 1 class
//SV001 => SV002 => SV003

//- Encapsulation: Dong goi
//- Access modifier: 
// + Private
// + Public
// + Protected

class SinhVien{
	private:
		//Thuoc tinh:
		string id, ten, ns;
		double gpa;
		static int dem;
	public:
		SinhVien(); 
		SinhVien(string, string, string, double); //constructor

		void Nhap();
		void In();
		void tangDem();
		int getDem();
		~SinhVien();
};

int SinhVien::dem = 0;

void SinhVien::tangDem(){
	dem++;
}

int SinhVien::getDem(){
	return dem;
}
//Implematation:
SinhVien::SinhVien(){
	//cout << "Doi tuong mac dinh duoc tao o day!\n";
	this->id = this->ten = this->ns = "";
	this->gpa = 0;
	//cout << "Ham khoi tao duoc goi!\n";
}

SinhVien::SinhVien(string id, string ten, string ns, double gpa){
	//cout << "Ham khoi tao co tham so duoc goi!\n";
	this->id = id;
	this->ten = ten;
	this->ns = ns;
	this->gpa = gpa;
}

SinhVien::~SinhVien(){
	//cout << "Doi tuong duoc huy tai day";
}

void SinhVien::Nhap(){
	dem++;
	//de: 001, 012, 118,... :
	this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
	//dem = 1 => "1"
	cout << "Nhap ten: "; getline(cin, this->ten);
	cout << "Nhap ns: "; cin >> this->ns;
	cout << "Nhap diem: "; cin >> this->gpa;
	cin.ignore();
}

void SinhVien::In(){
	cout << this->id << " " << this->ten << " " << this->ns << " " << this->gpa << endl;
}

int main(){
	/*SinhVien x;
	x.tangDem(); //dem = 1
	x.tangDem(); //dem = 2
	SinhVien y;
	cout << y.getDem() << endl;
	y.tangDem();
	SinhVien z;
	cout << x.getDem() << " " << y.getDem() << " " << z.getDem();*/
	
	SinhVien x;
	x.Nhap();
	x.In();
	SinhVien y;
	y.Nhap();
	y.In();
	
	
	
	
}
