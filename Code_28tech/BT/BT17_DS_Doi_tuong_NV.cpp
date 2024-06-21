//Gan giong BT13
/* 1 nhan vien lam viec trong cong ty duoc luu lai cac thong tin sau: 
    + Ma nhan vien: duoc gan gia tri tu dong tang, bat dau tu 00001
    + Ho ten: xau ki tu <= 40 chu cai
    + Gioi tinh: nam hoac nu
    + Ngay sinh: dung theo chuan dd/mm/yy
    + Dia chi: xau ki tu khong qua 100 chu cai
    + Ma so thue: day so co dung 10 chu so
    + Ngay ki hop dong: dung theo chuan dd/mm/yy
    Viet chuong trinh nhap DS nhan vien (khong nhap ma) trong do su dung chong toan tu 
    nhap/ xuat va in ra DS vua nhap
*/
#include<bits/stdc++.h>
using namespace std;
class NhanVien{
	private:
		string ten, gt, ns, dc, mst, hd;
		int ma;
	public:
		static int cnt;
 
	friend ostream& operator << (ostream &out, NhanVien a){
		out << setfill('0') << setw(5) << a.ma << " " << 
		a.ten << " " << a.gt << " " << a.ns << " " << a.dc << " " << a.mst << " " << a.hd << endl;
		return out;
	}
 
	friend istream& operator >> (istream &in, NhanVien &a){
		++cnt;
		a.ma = cnt;
		in.ignore();
		getline(in, a.ten);
		in >> a.gt >> a.ns;
		in.ignore();
		getline(in, a.dc);
		in >>a.mst >> a.hd;
		return in;
	}
};
 
int NhanVien::cnt = 0;
 
int main(){
    NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) cin >> ds[i];
    for(i = 0; i < N; i++) cout << ds[i];
    return 0;
}
