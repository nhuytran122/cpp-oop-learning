//https://youtu.be/i7qCVd3HmeE
/*Nhap DSSV va liet ke SV theo khoa
--Input: Dong dau ghi so SV
Moi SV ghi tren 4 dong: ma, ho ten, lop, email
Sau do se co gia tri so Q la so truy van
Tiep theo la Q dong, moi dong ghi 1 khoa
--Output: Voi moi truy van, liet ke DSSV cua khoa do , moi SV ghi tren 1 dong, cac thong tin cach nhau 1 khoang trong thu tu SV giu nguyen nhu ban dau

	4
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
1
2015
==>
DANH SACH SINH VIEN KHOA 2015:
B15DCCN215 To Ngoc Hieu D15CNPM3 sv2@gmail.com
B15DCKT150 Nguyen Ngoc Son D15CQKT02-B sv3@gmail.com
B15DCK199 Nguyen Trong Tung D15CQKT03-B sv4@gmail.com
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
        string getLop(){
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
    map <int, vector<SinhVien>> mp;
    for(int i = 0; i < n; i++){
    	SinhVien tmp; cin >> tmp;
    	//stoi: chuyen chuoi thanh so
    	//substr(vi tri bat dau lay, do dai ki tu can lay)
        //chen vao map cac khóa học
    	mp[stoi(tmp.getLop().substr(1, 2))].push_back(tmp);
    
    }
    int q; cin >> q;
    cin.ignore();
    while(q--){
        int nam; cin >> nam;
        cout << "DANH SACH SINH VIEN KHOA " << nam << ": \n";
		for(SinhVien x : mp[nam % 100]){
			cout << x;
		}
		
    }

}
