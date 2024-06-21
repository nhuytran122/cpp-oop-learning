//https://youtu.be/L-BabT96Zmk 55'43s
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
//Friend function, friend class : khong phai ham cua class hien tai, nhung co the truy cap cac thuoc tinh private cua class
//deNg    lUn => Deng Lun

//forward declaration


//- Encapsulation: Dong goi
//- Access modifier: 
// + Private
// + Public
// + Protected

class GiaoVien;
class SinhVien;

class SinhVien{
	friend class GiaoVien;
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
		friend void inthongtin(SinhVien);
		friend void ChuanHoa(SinhVien&);
		~SinhVien();
};

void inthongtin(SinhVien a){
	cout << a.id << " " << a.ten << " " << endl;
}

void ChuanHoa (SinhVien &a){
	string res = "";
	stringstream ss(a.ten);
	string tmp;
	while(ss >> tmp){
		res += toupper(tmp[0]);
		for(int i = 1; i < tmp.length(); i++){
			res += tolower(tmp[i]);
		}
		res += " ";
	}
	res.erase(res.length() - 1);
	a.ten = res;
}

int SinhVien::dem = 0;

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

class GiaoVien{
	private:
		string khoa;
	public:
		void update(SinhVien&);
};

void GiaoVien::update(SinhVien &x){
	x.gpa = 4.0;
}

int main(){
	SinhVien x;
	x.Nhap();
	GiaoVien y;
	y.update(x);
	x.In();

	
	
	
	
}
