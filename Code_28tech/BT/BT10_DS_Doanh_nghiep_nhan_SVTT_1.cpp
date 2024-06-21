//https://youtu.be/i7qCVd3HmeE
// > : giam dan
// < tang dan
//Sap xep cac doanh nghiep theo so luong SV co the nhan giam dan
/*--Input: dong dau ghi so doanh nghiep
Moi doanh nghiep ghi tren 3 dong:
    + Ma doanh nghiep: xau ki tu khong co khoang cach, do dai <=10
    + Ten doanh nghiep: xau ki tu do dai <=150
    + So SV co the nhan: gia tri nguyen <=1000
-- Output:
Ghi ra DS da duoc sap xep theo so luong giam dan, moi thong tin ghi tren 1 dong. Trong 
truong hop co cung so luong thi sap xep theo ma doanh nghiep (thu tu tu dien tang dan)

4
VIETTEL
TAP DOAN VIEN THONG QUAN DOI VIETTEL
40
FSOFT
CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE
300
VNPT
TAP DOAN BUU CHINH VIEN THONG VIETNAM
200
SUN
SUN*
40

==> FSOFT CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE 300
VNPT TAP DOAN BUU CHINH VIEN THONG VIETNAM 200
SUN SUN* 40
VIETTEL TAP DOAN VIEN THONG QUAN DOI VIETTEL 40
*/
#include<bits/stdc++.h>
using namespace std;
class DoanhNghiep{
    private: 
        string ma, ten;
        int soluong;
    public:
        void nhap();
        void xuat();
        int getSoluong(){
            return this->soluong;
        }
        string getMa(){
        	return this->ma;
		}
};

void DoanhNghiep::nhap(){
    cin >> ma;
    cin.ignore();
    getline(cin, ten);
    cin >> soluong;
}

void DoanhNghiep::xuat(){
    cout << ma << " " << ten << " " << soluong << endl;
}

//khac so luong: xep giam dan theo so luong
//cung so luong: xep tang dan theo ma
bool cmp(DoanhNghiep a, DoanhNghiep b){
    if(a.getSoluong() != b.getSoluong())
    	return a.getSoluong() > b.getSoluong();
    return a.getMa() < b.getMa();
}

int main(){
    int n; cin >> n;
    DoanhNghiep a[n];
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }
    sort(a, a+n, cmp);

    for(DoanhNghiep x : a){
        x.xuat();
    }
}
