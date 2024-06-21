#include <iostream>
using namespace std;
class Date {
	private:
		int D,M,Y; //ngày, tháng, nam
	public:
		int nhuan(); //kiem tra nam nhuan
		int ngaythang(); //tra ve so ngay trong thang
		void nhap(); //co kiem tra du lieu
		void xuat();
		Date cong_1(); //cong 1 ngay vao dtuong
		Date cong_k(int k);
		int ngaynam(); //tra ve so ngay cua nam
		int khoangcach(Date d2);
};
int Date::nhuan() //tra ve 1 neu Y nhuan, 0 neu khong nhuan
{
	return ((Y % 4 == 0 and Y % 100 != 0) || (Y % 400 == 0));
}
int Date::ngaythang(){
	if (M == 4 or M == 6 or M == 9 or M == 11) return 30;
		else if (M == 2) return 28 + nhuan();
	else return 31;
}
void Date::nhap(){
	int S, k;
	do{
		cout << "\nNhap vao ngay thang nam : "<<endl;
		cin >> D >> M >> Y;
		S = ngaythang();
		if ((D > 0) and (D <= S) and (M >= 1) and (M <= 12 ) and Y > 0)
			k = 1; //hop le
		else{ 
			cout << "\nSai ngay! Hay nhap lai. "<<endl;
			k = 0; //khong hop le
		}
	} while(k == 0);
}

void Date::xuat(){
	cout << D << '/' << M << '/' << Y << endl;
}

Date Date::cong_1(){
	int S;
	S = ngaythang();
	if (++D>S){
		D = 1;
		if (++M>12){ 
			M = 1;
			Y = Y + 1;
		}
	}
	return *this; //doi tuong ma this tro toi
}

Date Date::cong_k(int k){
	Date t;
	t.D = D;
	t.M= M;
	t.Y = Y;
	for (int i=1; i<=k; i++)
		t.cong_1();
	return t;
}

int Date::ngaynam(){
	return nhuan()?366:365;
}
//Ham tinh khoang cach giua 2 dt ngay
int Date::khoangcach(Date d2){
	Date d;
	int s1 = 0, s2 = 0, T = 0;
	for (d.M = 1, d.Y = Y; d.M < M; d.M++)
		s1 += d.ngaythang();
	s1 += D;
	//cout<<"\n so ngay cua dt 1 tinh tu moc thang 1: "<<s1; //gia su d1 goi phuong thuc
	for (s2 = 0; d2.M <= 12; d2.M++)
		s2 += d2.ngaythang();
	s2 -= d2.D;
	//cout<<"\n so ngay cua dt 2 tinh den moc cuoi thang 12 la: "<<s2;
	if (d2.Y == Y) // X-----------d2---d1--------X, vd d1 = 20/10/2021, d2 = 15/7/2021
		T = s1 + s2 - ngaynam();
	else //X-------d2----X--------------X------d1-------X
	{ //1 12 1 12
		for (d2.Y++; d2.Y<Y; ++d2.Y)
			T += d2.ngaynam();
	T += s1 + s2;
	}
	return T;
}

int main(){
	Date d; int k;
	cout << "\n Nhap doi tuong ob: ";
	d.nhap();
	cout << "\n Du lieu cua doi tuong: ";
	d.xuat();
	d.cong_1();
	cout <<"\n Sau khi tang 1 ngay: ";
	d.xuat();
	Date d1, d2;
	cout <<"\n Nhap ngay thu nhat"; d1.nhap();
	cout <<"\n Nhap ngay thu hai"; d2.nhap();
	cout <<"\n Khoang cach giua d1 va d2 la: " << d1.khoangcach(d2);
	return 0;
}