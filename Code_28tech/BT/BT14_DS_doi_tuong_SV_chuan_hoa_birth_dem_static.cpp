/*Viet chuong trinh khai bao lop SV gom cac thong tin: msv, 
ho ten, lop, gpa. Ham khoi tao khong co gia tri tham so, gan cac gia tri o trang thai mac dinh
Yeu cau su dung chong toan tu nhap va xuat de nhap doi tuong voi cin va in ra voi cout
Doc thong tin N thi sinh tu ban phim (khong co ma sv) va in ra lan luot man hinh moi dong 1 SV 
theo dung thu tu ban dau. Trong do ma sv duoc tao ra theo quy tac them ma B20DCCN sau do gia tri 
nguyen tu dong tang tu 001 (toi da la 099). Ngay sinh duoc chuan hoa ve dang dd/mm/yy
-- Input: Dongdau ghi so SV (0 < N < 50)
Moi SV ghi tren 4 dong thong tin. Trong do
    + Ho ten: <= 30 chu cai
    + Ngay sinh co du 3 phan ngay thang nam nhung co the chua dung chuan dd/mm/yy
    + Diem GPA dam bao trong thang 4 voi nhieu nhat 2 so sau dau phay

*/
#include<bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string ma, ten, lop, ns;
        float gpa;
    public:
        SinhVien(){
            ma = ten = lop = ns = "";
            gpa = 0;
        }
        static int cnt;
        friend istream& operator >> (istream &in, SinhVien& a){
			cnt++;
			string tmp = to_string(cnt);
			tmp = string(3 - tmp.size(), '0') + tmp;
			a.ma = "B20DCCN" + tmp;
			in.ignore();
		    getline(in, a.ten);
			in >> a.lop >> a.ns >> a.gpa;
			return in;	
		}
		friend ostream& operator << (ostream &out, SinhVien a);
    
};

int SinhVien::cnt = 0;

ostream& operator << (ostream &out, SinhVien a){
    if (a.ns[2] != '/') a.ns = "0" + a.ns;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ns[5] != '/') a.ns.insert(3, "0");
	cout << a.ma << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed <<setprecision(2) << a.gpa << endl;
	return out;
}

int main(){
    int N; cin >> N;
    SinhVien a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cout << a[i];
    }
}
