//https://youtu.be/L-BabT96Zmk 1h11'58s
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

class SoPhuc{
	private:
		int thuc, ao;
	public:
		friend istream& operator >> (istream& in, SoPhuc &a);
		friend ostream& operator << (ostream& out, SoPhuc a);
		//C1: 
		SoPhuc operator + (SoPhuc another);
		SoPhuc operator - (SoPhuc another);
		/*C2: friend SoPhuc operator + (SoPhuc a, SoPhuc b);
		friend SoPhuc operator - (SoPhuc a, SoPhuc b);*/
		
};

istream& operator >> (istream& in, SoPhuc &a){
	in >> a.thuc >> a.ao;
	return in;
}

ostream& operator << (ostream& out, SoPhuc a){
	out << a.thuc << " " << a.ao;
	return out;
}

SoPhuc SoPhuc::operator + (SoPhuc another){
	SoPhuc Tong;
	Tong.thuc = this->thuc + another.thuc;
	Tong.ao = this->ao + another.ao;
	return Tong;
}

SoPhuc SoPhuc::operator - (SoPhuc another){
	SoPhuc Hieu;
	Hieu.thuc = this->thuc - another.thuc;
	Hieu.ao = this->ao - another.ao;
	return Hieu;
}

int main(){
	SoPhuc a, b; 
	cin >> a >> b;
	SoPhuc Tong = a + b;
	SoPhuc Hieu = a - b;
	cout << Tong << endl << Hieu << endl;
}


