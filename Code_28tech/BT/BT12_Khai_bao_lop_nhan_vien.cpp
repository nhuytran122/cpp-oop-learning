/* 1 nhan vien lam viec trong cong ty duoc luu lai cac thong tin sau: 
    + Ma nhan vien: duoc gan gia tri la 00001
    + Ho ten: xau ki tu <= 40 chu cai
    + Gioi tinh: nam hoac nu
    + Ngay sinh: dung theo chuan dd/mm/yy
    + Dia chi: xau ki tu khong qua 100 chu cai
    + Ma so thue: day so co dung 10 chu so
    + Ngay ki hop dong: dung theo chuan dd/mm/yy
    Viet chuong trinh nhap 1 nhan vien (khong nhap ma) trong do su dung chong toan tu 
    nhap/ xuat va in ra man hinh thong tin cua nhan vien do 
    Su dung ham main co san
*/
#include<bits/stdc++.h>
using namespace std;
class NhanVien{
    private:
        string ma, ten, gt, ns, diachi, mst, ngayki;
    public:
    	NhanVien();
        friend istream& operator >> (istream &in, NhanVien& a);
		friend ostream& operator << (ostream &out, NhanVien a);
};

NhanVien::NhanVien(){
    ma = ten = gt = ns = diachi = mst = ngayki ="";
}

istream& operator >> (istream &in, NhanVien& a){
    a.ma = "00001";
    getline(in, a.ten);
    in >> a.gt >> a.ns;
    in.ignore();
    getline(in, a.diachi);
    in >> a.mst >> a.ngayki;
    return in;
}

ostream& operator << (ostream &out, NhanVien a){
    out << a.ma << " " << a.ten << " " << a.gt << " " <<  a.ns << " " << a.diachi << " " << a.mst << " " << a.ngayki << endl;
    return out;
}
#define a() a;
int main(){
    NhanVien a();
    cin >> a;
    cout << a;
    return 0;
}
