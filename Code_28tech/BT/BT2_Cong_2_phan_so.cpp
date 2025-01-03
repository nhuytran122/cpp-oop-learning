//https://youtu.be/i7qCVd3HmeE 
// 123 456 12 34 => 1609/2584
// 1234/456 + 12/34 = 1609/2584
//su dung main co san
//Nhap 1 phan so va in ra phan so o dang toi gian
//Su dung main co san
//VD: 123 456 => 41/152
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

//UCLN
ll gcd (ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

//BCNN
ll lcm (ll a, ll b){
	return a / gcd(a, b) * b;
}

class PhanSo{
	private:
		ll tu, mau;
	public:
		PhanSo(ll tu, ll mau);
		friend ostream& operator << (ostream&, PhanSo);
		friend istream& operator >> (istream&, PhanSo&);
		void rutgon();
		friend PhanSo operator + (PhanSo, PhanSo);
};

PhanSo::PhanSo(ll tu, ll mau){
	this->tu = tu;
	this->mau = mau;
}

ostream& operator << (ostream& out, PhanSo a){
	out << a.tu << "/" << a.mau << endl;
	return out;
}

istream& operator >> (istream& in, PhanSo &a){
	in >> a.tu >> a.mau;
	return in;
}

void PhanSo::rutgon(){
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}

PhanSo operator + (PhanSo a, PhanSo b){
	PhanSo tong(1, 1);
	ll mc = lcm(a.mau, b.mau);
	tong.tu = mc / a.mau * a.tu + mc / b.mau * b.tu;
	tong.mau = mc;
	ll g = gcd(tong.tu, tong.mau);
	tong.tu /= g; 
	tong.mau /= g;
	return tong;	
}

int main(){
	PhanSo p(1, 1), q(1, 1);
	cin >> p >> q;
	p.rutgon();
	cout << p + q;
	return 0;
}
