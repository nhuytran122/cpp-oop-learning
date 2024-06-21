//https://youtu.be/i7qCVd3HmeE
/*Nhap DSSV va liet ke SV theo khoa
--Input: Dong dau ghi so SV
Moi SV ghi tren 4 dong: ma, ho ten, lop, email
Sau do se co gia tri so Q la so truy van
Tiep theo la Q dong, moi dong ghi 1 khoa:
    + Ke toan - msv co cum ki tu DCKT
    + Cong nghe thong tin - co cum DCCN - tru di cac SV lop bat dau bang chu E
    + An toan thong tin - co cum DCAT - tru di cac SV lop bat dau bang chu E
    + Vien thong - co cum DCVT
    + Dien tu - co cum DCDT

4
0123456789
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
B15DCKT199
Nguyen Trong Tung
D15CQKT02-B
sv4@gmail.com
1
Ke toan
--Output: Voi moi truy van, liet ke DSSV cua khoa do , moi SV ghi tren 1 dong, cac thong tin cach nhau 1 khoang trong thu tu SV giu nguyen nhu ban dau
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
        string getMa(){
            return this->msv;
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

void vietHoa(string &s){
	for(char &x : s){
		x = toupper(x);
	}
}

//Ke toan ==> KT
string Convert(string s){
	stringstream ss(s);
	vector<string> v;
	string tmp, res = "";
	while(ss >> tmp) v.push_back(tmp);
	for(int i = 0; i < 2; i++){
		res += toupper(v[i][0]);
	}
	return res;
}

int main(){
    int n; cin >> n;
    map <string, vector<SinhVien>> mp;
    for(int i = 0; i < n; i++){
    	SinhVien tmp; 
		cin >> tmp;
    	//B15DCKT199
    	//substr(vi tri bat dau lay, do dai ki tu can lay)
    	mp[tmp.getMa().substr(5, 2)].push_back(tmp);
		//mp["KT"].push_back(tmp); (dua nhung SV co ki tu "KT" vao map)
    
    }
    int q; cin >> q;
    cin.ignore();
    while(q--){
        string nganh; getline(cin, nganh);
        vietHoa(nganh);
        cout << "DANH SACH SINH VIEN NGANH " << nganh << ": \n";
		//De lay tu viet tat cua nganh
		string ng = Convert(nganh);
		if(ng == "CN" || ng == "AT"){
			for(SinhVien x : mp[ng]){
				//Tim ki tu "E" trong ma, khong co thi:
				if(x.getMa().find("E") != string :: npos){
					cout << x;	
				}
			}
		}
		else 	
			for(SinhVien x : mp[ng]){
				cout << x;
			}
    }

}
