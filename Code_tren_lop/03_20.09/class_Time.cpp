#include<bits/stdc++.h>
using namespace std;


class Time{
	private:
		int h, m, s; //gio, phut, giay
	public :
		void Nhap();
		void Xuat();
		Time Tong(Time t2);
};

void Time::Nhap(){
	cout << "Nhap gio phut va giay: ";
	cin >> h >> m >>s;
}

void Time::Xuat(){
	cout << h << "gio " << m << " phut " << s << " giay\n";
}

Time Time::Tong(Time t2){ 
	Time t;
	t.s = s + t2.s;
	t.m = t.s/60  + m + t2.m;
	t.s = t.s%60; //chuan hoa giay
	t.h = t.m/60 + h + t2.h;
	t.m = t.m%60; //chuan hoa phut
return t;
}

int main(){
	Time ob1, ob2, ob3;
	cout << "ob 1 = ";
	ob1.Nhap();
	cout << "ob 2 = ";
	ob2.Nhap();
	ob3 = ob1.Tong(ob2);
	cout<<"ob 3 = ";
	ob3.Xuat();
	return 0;
}
