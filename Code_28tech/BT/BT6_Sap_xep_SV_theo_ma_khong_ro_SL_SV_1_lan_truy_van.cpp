//https://youtu.be/i7qCVd3HmeE
/*Thong tin cua moi SV gom:
    MSV: day ki tu khong co khoang trong (<=15) dam bao khong trung nhau
    Ho ten: do dai <=100
    Lop: day ki tu khong co khoang trong <=15
    Email: day ki tu khong co khoang trong <=15
Hay nhap DS SV va sap xep theo msv tang dan (thu tu tu dien)
--Input: dong dau ghi so SV
Moi SV ghi tren 4 dong lan luot la: ma, hoten, lop, email
Co <=1000 SV trong DS
Khong biet so luong SV 
--Output: Ghi ra DS SV da sap xep theo ma. Moi SV tren 1 dong, cac thong tin cach nhau 1 khoang trong
Neu 2 SV co cung lop thi sap xep theo ma tang dan (thu tu tu dien)
*/
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
        
        bool operator < (SinhVien another){
        	return this->msv < another.msv;
		}
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

int main(){
    vector <SinhVien> v;
    SinhVien tmp;
    while(cin >> tmp){
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(SinhVien x : v){
        cout << x;
    }
}
