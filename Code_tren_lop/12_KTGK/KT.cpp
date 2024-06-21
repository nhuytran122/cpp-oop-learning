#include<bits/stdc++.h>
using namespace std;

class Computer{
	private:
		string mamt, hangsx;
		int namsx;
		float giaban;
	public:
		string getMa();
		string getHang();
		int getNam();
		float getGia();
		void Nhap();
		void Xuat();
};

string Computer::getMa(){
	return mamt;
}

string Computer::getHang(){
	return hangsx;
}

int Computer::getNam(){
	return namsx;
}

float Computer::getGia(){
	return giaban;
}

void Computer::Nhap(){
	cout << "\nNhap ma may tinh: "; getline(cin, mamt);
	cout << "Nhap hang san xuat: "; getline(cin, hangsx);
	cout << "Nhap nam san xuat: "; cin >> namsx;
	cout << "Nhap gia ban: "; cin >> giaban;
}

void Computer::Xuat(){
	cout << "\n\nMa may tinh: " << mamt;
	cout << "\nHang san xuat: " << hangsx;
	cout << "\nNam san xuat: " << namsx;
	cout << "\nGia ban: " << giaban;
}

class Laptop:public Computer{
	private:
		float w, t, s;
		string hdh;
	public:
		float getW(){return w;}
		float getT(){return t;}
		float getS(){	return s;}
		string getOs(){	return hdh;}
};
