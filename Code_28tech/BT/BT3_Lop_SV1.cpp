//https://youtu.be/i7qCVd3HmeE
/* Khai bao lop SinhVien gom: Ma SV, Ho ten, Lop, Ngay sinh, diem GPA (float).
Ham khoi tao khong co tham so, gan cac gia tri thuoc tinh o trang thai mac dinh (xau ki tu rong, gia tri so = 0)
Doc thong tin 1 SV tu ban phim (khong co ma SV) va in ra man hinh.
Trong do Ma SV duoc gan la 21T1020105. Ngay sinh duoc chuan hoa ve dang dd/mm/yy
--Input: Gom 4 dong lan luot la ca thong tin
Trong do:
    + Ho ten khong qua 30 chu cai
    + Lop theo dung dinh dang dung o HUSC
    + Ngay sinh co du 3 phan ngay thang nam nhunng co the chua dung chuan dd/mm/yy
-- Output: Ghi thong tin SV tren 1 dong, moi thong tin cach nhau 1 khoang trong
Su dung ham main co san
int main(){
    SinhVien a();
    nhap(a);
    in(a);
    2 ham nhap va in khong phai thuoc class SinhVien, vi neu la cua class SV thi da la a.Nhap(), a.In()
    return 0;
}
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
        friend void nhap (SinhVien&);
        friend void in (SinhVien);
};

void nhap(SinhVien &a){
	a.msv = "21T1020105";
	getline(cin, a.hoten);
	cin >> a.lop >> a.ngaysinh >> a.gpa;
	if (a.ngaysinh[2] != '/') a.ngaysinh = "0" + a.ngaysinh;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ngaysinh[5] != '/') a.ngaysinh.insert(3, "0");
}

void in(SinhVien a){
	cout << a.msv << " " << a.hoten << " " <<  a.lop << " " <<  a.ngaysinh << " " << fixed << setprecision(2) << " "   << a.gpa << endl;
}

#define a() a
int main(){
    SinhVien a();
    nhap(a);
    in(a);
    //==>2 ham nhap va in khong phai thuoc class SinhVien, vi neu la cua class SV thi da la a.Nhap(), a.In()
    return 0;
}


