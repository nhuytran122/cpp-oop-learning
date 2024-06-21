//https://youtu.be/i7qCVd3HmeE
/*Thong tin cua moi SV gom:
    MSV: day ki tu khong co khoang trong (<=15) dam bao khong trung nhau
    Ho ten: do dai <=100
    Lop: day ki tu khong co khoang trong <=15
    Email: day ki tu khong co khoang trong <=15
Hay nhap DS SV va sap xep theo lop tang dan (thu tu tu dien)
--Input: dong dau ghi so SV
Moi SV ghi tren 4 dong lan luot la: ma, hoten, lop, email
Co <=1000 SV trong DS
--Output: Ghi ra DS SV da sap xep theo lop. Moi SV tren 1 dong, cac thong tin cach nhau 1 khoang trong
Neu 2 SV co cung lop thi sap xep theo ma tang dan (thu tu tu dien)
*/
/*4
B16DCCN001
Nguyen Trong Duc Anh
D16CNPM1
sv1@gmail.com
B15DCCN215
To Ngoc Hieu
D15CNPM3
sv2@gmail.com
B15DCKT150
Nguyen Ngoc Son
D15CQKT02-B
sv3@gmail.com
B15DCK199
Nguyen Trong Tung
D15CQKT03-B
sv4@gmail.com
==>
B15DCCN215 To Ngoc Hieu D15CNPM3 sv2@gmail.com
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@gmail.com
B15DCK199 Nguyen Trong Tung D15CQKT03-B sv4@gmail.com
B16DCCN001 Nguyen Trong Duc Anh D16CNPM1 sv1@gmail.com*/

#include<bits/stdc++.h>

using namespace std;

class SinhVien{
    private: 
        string msv, ten, lop, email;
    public:
        SinhVien(){
            msv = ten = lop = email = "";
        }
        friend ostream& operator << (ostream&, SinhVien);
		friend istream& operator >> (istream&, SinhVien&);
        string getlop(){
            return this->lop;
        }
        
        /*C2: bool operator < (SinhVien another){
        	return this->lop < another.lop;
		}*/
};

ostream& operator << (ostream& out, SinhVien a){
	out << a.msv << " " << a.ten << " " << a.lop << " " <<  a.email << endl;
	return out;
}

istream& operator >> (istream& in, SinhVien &a){
    in >> a.msv;
    in.ignore();
    getline (in, a.ten);
	in >>  a.lop >> a.email;
	return in;
}

bool cmp(SinhVien a, SinhVien b){
    return a.getlop() < b.getlop();
}

int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
	sort(a, a+n, cmp);
    /*C2: sort(a, a+n);*/
    
    for(SinhVien x : a){
        cout << x;
    }
}
