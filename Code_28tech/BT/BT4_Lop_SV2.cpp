//https://youtu.be/i7qCVd3HmeE
/* Khai bao lop SinhVien gom: Ma SV, Ho ten, Lop, Ngay sinh, diem GPA (float).
Ham khoi tao khong co tham so, gan cac gia tri thuoc tinh o trang thai mac dinh (xau ki tu rong, gia tri so = 0)
Yeu cau su dung chong toan tu nhap va xuat de nhap doi tuong SV voi cin va in ra doi tuong SV voi cout
Doc thong tin 1 SV tu ban phim (Khong co MSV) va in ra man hinh. Trong do MSV duoc gan la 21T1020105. Ngay sinh duoc chuan hoa ve dang dd/mm/yy
*/
#include<bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string msv, hoten, lop, ngaysinh;
        float gpa;
    public:
        SinhVien(){
            msv = hoten = lop = ngaysinh = "";
            gpa = 0;
        }
        friend ostream& operator << (ostream&, SinhVien);
		friend istream& operator >> (istream&, SinhVien&);
};

ostream& operator << (ostream& out, SinhVien a){
	out << a.msv << " " << a.hoten << " " << a.lop << " " <<  a.ngaysinh << " " << fixed << setprecision(2) << a.gpa << endl;
	return out;
}

istream& operator >> (istream& in, SinhVien &a){
    a.msv = "21T1020105";
    getline (in, a.hoten);
	in >>  a.lop >> a.ngaysinh >> a.gpa;
    if (a.ngaysinh[2] != '/') a.ngaysinh = "0" + a.ngaysinh;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ngaysinh[5] != '/') a.ngaysinh.insert(3, "0");
	return in;
}

int main(){
    SinhVien a;
    cin >> a;
    cout << a;
}