//https://youtu.be/i7qCVd3HmeE
/*Nhap DSSV va liet ke SV theo lop
--Input: Dong dau ghi so SV
Moi SV ghi tren 4 dong: ma, ho ten, lop, email
Sau do se co gia tri so Q la so truy van
Tiep theo la Q dong, moi dong ghi 1 lop
--Output: Voi moi truy van, liet ke DSSV cua lop do , moi SV ghi tren 1 dong, cac thong tin cach nhau 1 khoang trong thu tu SV giu nguyen nhu ban dau
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
    int n; cin >> n;
    map <string, vector<SinhVien>> mp;
    for(int i = 0; i < n; i++){
    	SinhVien tmp; cin >> tmp;
    	mp[tmp.getlop()].push_back(tmp);
    
    }
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        cout << "DANH SACH SINH VIEN LOP " << s << ": \n";
        for(SinhVien x: mp[s]){
        	cout << x;
		} 
    }

}
