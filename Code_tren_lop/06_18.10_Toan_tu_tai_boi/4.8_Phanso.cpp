#include<bits/stdc++.h>
using namespace std;
class Phanso{
	private:
		int t, m;
	public:
		Phanso(int a=0, int b=0);
		void Nhap();
		void Xuat();
		void rutgon();
		float TuchiaMau(){
			return (float)t/m;
		}
		int getTu(){
			return t;
		}
		Phanso operator + (Phanso p2);
		Phanso operator - (Phanso p2);
		Phanso operator * (Phanso p2);
		Phanso operator / (Phanso p2);
		Phanso operator = (Phanso p2);
		Phanso operator += (Phanso p2);
		Phanso operator -= (Phanso p2);
		Phanso operator *= (Phanso p2);
		Phanso operator /= (Phanso p2);
		int operator == (Phanso p2);
		int operator < (Phanso p2);
		int operator > (Phanso p2);
		int operator <= (Phanso p2);
		int operator >= (Phanso p2);
		int operator != (Phanso p2);
};

Phanso::Phanso(int a, int b){
	t = a;
	m = b;
}

int UCLN (int a, int b){
	if(b == 0) return a;
	return UCLN(b, a%b);
}

void Phanso::rutgon(){
	int g = UCLN(t, m);
	t /= g;
	m /= g;
}

void Phanso::Nhap(){
	cout << "\n\tNhap Tu so: "; cin >> t;
	do{
		cout << "\tNhap Mau so: "; 
		cin >> m;	
		if(m == 0) cout << "\tNhap sai, vui long nhap lai mau so: \n";		
	} while(m == 0);
}

void Phanso::Xuat(){
	cout << "\t" << t << "/" << m;
}

Phanso Phanso::operator + (Phanso p2){
	Phanso p;
	p.t = t*p2.m + m*p2.t;
	p.m = m*p2.m;
	p.rutgon();
	return p;
}

Phanso Phanso::operator - (Phanso p2){
	Phanso p;
	p.t = t*p2.m - m*p2.t;
	p.m = m*p2.m;
	p.rutgon();
	return p;
}

Phanso Phanso::operator * (Phanso p2){
	Phanso p;
	p.t = t*p2.t;
	p.m = m*p2.m;
	p.rutgon();
	return p;
}

Phanso Phanso::operator / (Phanso p2){
	Phanso p;
	p.t = t*p2.m;
	p.m = m*p2.t;
	p.rutgon();
	return p;
}

Phanso Phanso::operator = (Phanso p2){
	//s5 = s5.operator =(p1);
	t = p2.t;
	m = p2.m;
	return p2;
}

Phanso Phanso::operator += (Phanso p2){
	t = t*p2.m + m*p2.t;
	m = m*p2.m;
	rutgon();
	return *this;
}

Phanso Phanso::operator -= (Phanso p2){
	t = t*p2.m - m*p2.t;
	m = m*p2.m;
	rutgon();
	return *this;
}

Phanso Phanso::operator *= (Phanso p2){
	t = t * p2.t;
	m = m * p2.m;
	rutgon();
	return *this;
}

Phanso Phanso::operator /= (Phanso p2){
	t = t * p2.m;
	m = m * p2.t;
	rutgon();
	return *this;
}

int Phanso::operator == (Phanso p2){
	return (TuchiaMau() == p2.TuchiaMau());
}

int Phanso::operator < (Phanso p2){
	return (TuchiaMau() < p2.TuchiaMau());
}

int Phanso::operator > (Phanso p2){
	return (TuchiaMau() > p2.TuchiaMau());
}

int Phanso::operator <= (Phanso p2){
	return (TuchiaMau() <= p2.TuchiaMau());
}

int Phanso::operator >= (Phanso p2){
	return (TuchiaMau() >= p2.TuchiaMau());
}

int Phanso::operator != (Phanso p2){
	return (TuchiaMau() != p2.TuchiaMau());
}

int main(){
	Phanso p1, p2, s1, s2, s3, s4, s5 , s6, s7, s8, s9;
	p1.Nhap();
	p1.Xuat();
	p2.Nhap();
	p2.Xuat();
	
	cout << "\n\t1. TOAN TU + \n";
	s1 = p1 + p2;
	p1.Xuat(); cout << "\t+" ; p2.Xuat(); cout << "\t=";
	if(s1.getTu() == 0)
		cout << "\t0";
	else s1.Xuat();
	
	cout << "\n\n\t2. TOAN TU - \n";
	s2 = p1 - p2;
	p1.Xuat(); cout << "\t-" ; p2.Xuat(); cout << "\t=";
	if(s2.getTu() == 0)
		cout << "\t0";
	else s2.Xuat();
	
	cout << "\n\n\t3. TOAN TU * \n";
	s3 = p1 * p2;
	p1.Xuat(); cout << "\t*" ; p2.Xuat(); cout << "\t=";
	if(s3.getTu() == 0)
		cout << "\t0";
	else s3.Xuat();
	
	cout << "\n\n\t4. TOAN TU / \n";
	s4 = p1 / p2;
	p1.Xuat(); cout << "\t/" ; p2.Xuat(); cout << "\t=";
	if(s4.getTu() == 0)
		cout << "\t0";
	else s4.Xuat();
	
	cout << "\n\n\t5. TOAN TU = \n";
	s5 = p1; //s5 = s5.operator =(p1);
	p1.Xuat(); cout << "\t="; s5.Xuat();
	
	cout << "\n\n\t6. TOAN TU += (s6 += p1)\n";
	cout << "\tNhap s6: "; s6.Nhap();
	s6.Xuat(); 
	s6 += p1;
	cout << "\t+=" ; p1.Xuat(); cout << "\t="; s6.Xuat();
	
	cout << "\n\n\t7. TOAN TU -= (s7 -= p1)\n";
	cout << "\tNhap s7: "; s7.Nhap();
	s7.Xuat(); 
	s7 -= p1;
	cout << "\t-=" ; p1.Xuat(); cout << "\t="; s7.Xuat();
	
	cout << "\n\n\t8. TOAN TU *= (s7 *= p1)\n";
	cout << "\tNhap s8: "; s8.Nhap();
	s8.Xuat(); 
	s8 *= p1; 
	cout << "\t*=" ; p1.Xuat(); cout << "\t="; s8.Xuat();
	
	cout << "\n\n\t9. TOAN TU /= (s8 /= p1)\n";
	cout << "\tNhap s9: "; s9.Nhap();
	s9.Xuat(); 
	s9 /= p1;
	cout << "\t/=" ; p1.Xuat(); cout << "\t="; s9.Xuat();
	
	cout << "\n\n\t10. KET QUA SO SANH P1 VA P2: \n";
	cout << "\tP1 == P2 ? " << (p1 == p2) << endl << "\t"
		<< "P1 != P2 ? " << (p1 != p2) << endl << "\t"
		<< "P1 <  P2 ? " << (p1 < p2) << endl << "\t"
		<< "P1 >  P2 ? " << (p1 > p2) << endl << "\t"
		<< "P1 <= P2 ? " << (p1 <= p2) << endl << "\t"
		<< "P1 >= P2 ? " << (p1 >= p2) << endl;	
}

