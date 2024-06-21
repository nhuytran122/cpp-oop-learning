//https://youtu.be/L-BabT96Zmk 22'55s 31'
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
	public:
		//Constructor: (Khoi tao khong truyen tham so - mac dinh)
		SinhVien(); 
		//Khoi tao co truyen tham so
		SinhVien(string id, string ten, string ns, double gpa);

		void Nhap();
		void In();
		double getGpa();
		string getName();
		string getNs();
		void setGpa(double);
		~SinhVien();
};

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
	cout << "Nhap ID: "; cin >> this->id;
	cin.ignore();
	cout << "Nhap ten: "; getline(cin, this->ten);
	cout << "Nhap ns: "; cin >> this->ns;
	cout << "Nhap diem: "; cin >> this->gpa;
}

void SinhVien::In(){
	cout << this->id << " " << this->ten << " " << this->ns << " " << this->gpa << endl;
}

double SinhVien::getGpa(){
	return this->gpa;
}

void SinhVien::setGpa(double gpa){
	this->gpa = gpa;
}

//Sap xep theo GPA giam dan
bool Cmp(SinhVien a, SinhVien b){
	return a.getGpa() > b.getGpa();
}


int main(){
	/*SinhVien x;
	x.Nhap();
	x.In();*/
	
	//1 MANG DANH SACH CAC SV
/*	int n;
	cout << "Nhap so luong SV: "; cin >> n;
	SinhVien a[100];
	for(int i = 0; i < n; i++){
		a[i].Nhap();
	}
	
	sort(a, a+n, Cmp);
	
	for(int i = 0; i < n; i++){
		a[i].In();
	}
*/
	
	/*SinhVien x;
	x.setGpa(3.5);*/
	
	/*Co the gan 2 SV cho nhau:
	SinhVien x;
	x.Nhap();
	SinhVien y = x;
	y.In();*/
	
}
