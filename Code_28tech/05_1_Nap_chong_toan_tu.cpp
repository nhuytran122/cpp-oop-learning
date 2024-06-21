//https://youtu.be/L-BabT96Zmk 59'
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

//Operator overloading
//<< >>
//cout : ostream
//cin : istream

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
		friend istream& operator >> (istream &in, SinhVien& a);
		friend ostream& operator << (ostream &out, SinhVien a);
		//Nap chong toan tu nho hon:
		//c1:bool operator < (SinhVien a);
		friend bool operator < (SinhVien a, SinhVien b);
};

/*c1: bool  SinhVien::operator < (SinhVien a){
	return this->gpa < a.gpa;
}*/

bool operator < (SinhVien a, SinhVien b){
	return a.gpa < b.gpa;
}

istream& operator >> (istream &in, SinhVien& a){
	cout << "Nhap id: "; in >> a.id;
	cout << "Nhap ten: "; in.ignore();
	getline(in, a.ten);
	cout << "Nhap ns: "; in >> a.ns;
	cout << "Nhap gpa: "; in >> a.gpa;
	return in;
}

ostream& operator << (ostream &out, SinhVien a){
	cout << a.id << " " << a.ten << " " << a.ns << " " << fixed <<setprecision(2) << a.gpa << endl;
	return out;

}


int main(){
	/*c1: SinhVien x, y;
	cin >> x >> y;
	cout << x << y;
	if(x < y) cout << "YES";
	else cout << "NO";*/
	
	int n; cin >> n;
	SinhVien a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	//<theo operator thi se sap xep tang>
	sort(a, a+n);
	
	for(SinhVien x:a){
		cout << x;
	}
	
	
	
	
	
}
