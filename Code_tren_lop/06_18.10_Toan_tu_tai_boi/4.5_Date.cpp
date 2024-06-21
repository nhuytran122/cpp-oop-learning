#include<bits/stdc++.h>
using namespace std;

class Date{
	private:
		int D, M, Y;
	public:
		void Nhap();
		void Xuat();
		int Ngaytrongthang();
		int Nhuan();
		int operator == (Date d2);
		int operator != (Date d2);
		Date operator ++ ();
		Date operator += (int k);
		int operator - (Date d2);
};

int Date::Nhuan(){
	if((Y % 400 == 0) || (Y % 4 == 0) && (Y % 100 != 0))
		return 1;
	else return 0;
}

int Date::Ngaytrongthang(){
	switch(M){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
		break;
		
		case 4: case 6: case 9: case 11:
		return 30;
		break;
		
		case 2:
			return((Y % 400 == 0 || Y % 4 == 0 && Y % 100 != 0))?29:28;
		default:
			return -1;
    }
}

void Date::Nhap(){
	bool ch;
	do{
		cout << "\n\tNhap ngay: "; cin >> D;
		cout << "\tNhap thang: "; cin >> M;
		cout << "\tNhap nam: "; cin >> Y;
		if(D < 0 || D > Ngaytrongthang() || M < 1 || M > 12) cout << "Du lieu khong hop le! \n";
	}while (D < 0 || D > Ngaytrongthang() || M < 1 || M > 12); 
}

void Date::Xuat(){
	cout <<"\tDATE:  " << D << "/" << M << "/" << Y << endl;
}

int Date::operator == (Date d2){
	return(D == d2.D && M == d2.M && Y == d2.Y);
}

int Date::operator != (Date d2){
	return(D != d2.D || M != d2.M || Y != d2.Y);
}

Date Date::operator ++ (){
	int daymax = Ngaytrongthang();
	if(D++ > daymax){
		D = 1;
		if(++M > 12){
			M = 1;
			Y = Y + 1;
		}	
	}
	return *this;
}

Date Date::operator += (int k){
	for(int i=1; i <= k; i++){
		++(*this);
	}
	return *this;
}

int Date::operator - (Date d2){
	int s = 0;
	while(D != d2.D || M != d2.M || Y != d2.Y){
		s++;
		++d2;
	}
	return s;
}

int main(){
	Date d1, d2, d3, d4;
	d1.Nhap();
	d1.Xuat();
	d2.Nhap();
	d2.Xuat();
	cout << "\n\t1. TOAN TU ==\n";
	cout << "\td1 == d2 : ";
	if(d1 == d2)
		cout << "Dung\n";
	else cout << "Sai\n";
	
	cout << "\n\t2. TOAN TU !=\n";
	cout << "\td1 != d2 : ";
	if(d1 != d2)
		cout << "Dung\n";
	else cout << "Sai\n";
	
	cout <<"\n\t3. TOAN TU += \n";
	int k;
	cout << "\n\tNhap so ngay can tang: "; cin >> k;
	d1 += k;
	cout << "\n\td1 = d1 + " << k << " ngay" ; d1.Xuat();
	
	cout <<"\n\t4. TOAN TU - (Khoang cach giua 2 ngay) \n";
	d3.Nhap();
	d3.Xuat();
	d4.Nhap();
	d4.Xuat();
	int d = d3 - d4;
	cout << "\tKhoang cach giua 2 ngay tren la: " << d;
}
