#include<bits/stdc++.h>
using namespace std;
//Lay tu viet tat
string chuan(string bm){
	string res = "";
	stringstream ss(bm);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}
 
string getname(string name){
	string res, token;
	stringstream ss(name);
	while(ss >> token){
		res = token;
	}
	return res;
}
 
class GiangVien{
	private:
		string ten, bm, ma;
		static int cnt;
	public:
		void nhap();
		void in();
		string getTen(){
			return ten;
		}
		string getMa(){
			return ma;
		}
		string getBm(){
			return bm;
		}
};
 
int GiangVien::cnt = 0;

void GiangVien::nhap(){
	++cnt;
	string s = to_string(cnt);
	if(s.size() < 2) s = "0" + s;
	ma = "GV" + s;
	getline(cin, ten);
	getline(cin, bm);
}
 
void GiangVien::in(){
	cout << ma << " " << ten << " " << chuan(bm) << endl;
}
 
bool cmp(GiangVien a, GiangVien b){
	if(getname(a.getTen()) != getname(b.getTen()))
		return getname(a.getTen()) < getname(b.getTen());
	return a.getMa() < b.getMa();
}
 
 
int main(){
	int n; cin >> n;
	cin.ignore();
	map<string, vector<GiangVien>> mp;
	for(int i = 0; i < n; i++){
		GiangVien tmp;
		tmp.nhap();
		//mp["CNPM"].push_back(tmp)
		mp[chuan(tmp.getBm())].push_back(tmp);
	}
	int q; cin >> q; cin.ignore();
	while(q--){
		string s;
		getline(cin, s);
		cout << "DANH SACH GIANG VIEN BO MON " << chuan(s) << ":\n";
		//for(GiangVien x : mp["CNPM"])
		for(GiangVien x : mp[chuan(s)]){
			x.in();
		}
	}
	return 0;
}
 
//3
//Nguyen Manh Son
//Cong nghe phan mem
//Vu Hoai Nam
//Khoa hoc may tinh
//Dang Minh Tuan
//An toan thong tin