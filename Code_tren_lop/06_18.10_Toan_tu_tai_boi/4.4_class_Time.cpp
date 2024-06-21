#include<bits/stdc++.h>
using namespace std;

class Time{
	private:
		int H, M, S;
	public:
		Time(int a=0, int b=0, int c=0);
		void nhap();
		void xuat();
		void chuanhoa();
		int operator == (Time t2);
		int operator != (Time t2);
		Time operator += (int);
};

Time::Time(int a, int b, int c){
	H = a;
	M = b; 
	S = c;
}

void Time::chuanhoa(){
	if(S >= 60){
		M = M + S/60;
		S = S%60;
		
	}
	if(H >= 24){
		H = H % 24;
	}
}
void Time::nhap(){
	do{
		cout << "Nhap thoi gian: \n";
		cout << "Nhap gio: "; cin >> H;
		cout << "Nhap phut: "; cin >> M;
		cout << "Nhap giay: "; cin >> S;
		if(H < 0 || H >=24 || M < 0 || M >= 60 || S < 0 || S >= 60) cout << "Thoi gian khong hop le!\n\n";
	} while(H < 0 || H >=24 || M < 0 || M >= 60 || S < 0 || S >= 60);
}

void Time::xuat(){
		string hour = to_string(H);
		string minute = to_string(M);
		string second = to_string(S);
		if (hour.length() == 1)
			hour = "0" + hour;
		if (minute.length() == 1)
			minute = "0" + minute;
		if (second.length() == 1)
			second = "0" + second;
		cout << "\n\t\tTIME: " << hour << ":" << minute << ":" << second << endl;
}

int Time::operator == (Time t2){
	return (H == t2.H) && (M == t2.M) && (S == t2.S);
}

int Time::operator != (Time t2){
	return (H != t2.H) || (M != t2.M) || (S != t2.S);
}

Time Time::operator += (int k){
	S += k;
	chuanhoa();
	return *this;
}

int main(){
	Time t1, t2;
	t1.nhap();
	cout << "\nt1: ";
	t1.xuat();
	t2.nhap();
	cout << "\nt2: ";
	t2.xuat();
	cout << "1. TOAN TU ==\n";
	cout << "t1 == t2 : ";
	if(t1 == t2)
		cout << "Dung\n";
	else cout << "Sai\n";
	
	cout << "\n2. TOAN TU !=\n";
	cout << "t1 != t2 : ";
	if(t1 != t2)
		cout << "Dung\n";
	else cout << "Sai\n";
	
	cout <<"\n3. TOAN TU += \n";
	int k;
	cout << "\nNhap so giay can tang: "; cin >> k;
	t1 += k;
	cout << "\nt1 = t1 + " << k << "s" ; t1.xuat();
}
