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
		int operator > (Date d2);
		Date operator ++ ();
		Date operator -- ();
		Date operator += (int k);
		int operator - (Date d2);
};

int Date::Nhuan(){
	if((Y % 400 == 0) || (Y % 4 == 0) && (Y % 100 != 0))
		return 1;
	else return 0;
}

int Date::Ngaytrongthang(){
	return (M == 4 || M == 6 || M == 9 || M == 11)?30:(M == 2)?28+Nhuan():31;
}

void Date::Nhap(){
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

int Date::operator > (Date d2){
	return (Y > d2.Y) ? 1 : (Y < d2.Y)? 0 : (M>d2.M) ? 1:  (M < d2.M) ? 0 : (D > d2.D ) ? 1 : 0;
//	if (Y > d2.Y) return 1;
//	else if(Y == d2.Y && M > d2.M) return 1;
//	else if(Y == d2.Y && M == d2.M && D > d2.D) return 1;
//	else return 0;
}

int Date::operator != (Date d2){
	return(D != d2.D || M != d2.M || Y != d2.Y);
}

Date Date::operator ++ (){
	int daymax = Ngaytrongthang();
	if(++D > daymax){
		D = 1;
		if(++M > 12){
			M = 1;
			Y = Y + 1;
		}	
	}
	return *this;
}

Date Date::operator -- (){
	if(--D == 0){
		--M;
		D = Ngaytrongthang();
		if(M == 0){
			M = 12;
			Y = Y - 1;
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
	
/*	cout <<"\n\t4. TOAN TU - (Khoang cach giua 2 ngay) \n";
	d3.Nhap();
	d3.Xuat();
	d4.Nhap();
	d4.Xuat();
	int d = d3 - d4;
	cout << "\tKhoang cach giua 2 ngay tren la: " << d;*/
	
	cout << "\n\t5. TOAN TU >\n";
	cout << "\td1 > d2 : ";
	if(d1 > d2)
		cout << "d1 > d2\n";
	else cout << "d1 <= d2\n";
	
	cout << "\n\t6. TOAN TU --\n";
	d1.Xuat();
	--d1;
	d1.Xuat();
}
